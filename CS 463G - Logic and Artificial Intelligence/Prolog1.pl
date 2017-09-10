citypath(_,_,_,_,[],_) :-
	fail.

citypath(Xval, Yval, Xval2, Yval2, [Head|Tail], Path) :-
	% Removes any previous blocks and set maze sizes.
	abolish(wall/2),
	abolish(mazeSize/2),

	% Sets the size of the maze.
	length([Head|Tail], Ysize),
	length(Head, Xsize),
	
	assert(mazeSize(Xsize,Ysize)),
	
	% Checks to see if input start and end positions are in the maze.
	insideMaze(Xval,Yval),
	insideMaze(Xval2,Yval2),
	
	% Issue with this, it runs through once and prints when not all
	%	block(X,Y) have been asserted. so ; runs through this process.
	
	%	It does in fact provide the correct solution in solving the maze,
	%	the last run of the program. I think I was overthinking how to get
	%	this to reapeatedly assert my wall fact for all walls before
	%	solving and printing.
	buildWall([Head|Tail],1),
	
	solve([Xval,Yval], [Xval2,Yval2], Path).

% Validates input is within the maze's bounds.
insideMaze(X1,Y1) :-
	mazeSize(A,B),
	X1 >= 1,
	X1 =< A,
	Y1 >= 1,
	Y1 =< B.
	
% ISSUES HERE!?	
buildWall(Maze,Value) :-
	nth1(R,Maze,MazeRow),
	nth1(C,MazeRow,Value),
	assert(wall(R,C)).

% "Solves" the maze using given start and end points.
solve(Start, End, Path) :-
 	possibleSpace(Start),
 	possibleSpace(End),
 	pathFind(Start, End, [End], Path),
 	\+ shorterPath(Start, End, Path),
 	printMaze(Path),
	length(Path,Moved), nl,
	format('~nNumber of Moves: ~d ~n', [Moved]).

% Checks if location is open (not a wall).
possibleSpace([X,Y]) :-
	possibleSpace(X,Y).
possibleSpace(X0,Y0) :-
	insideMaze(X0,Y0),
	\+ wall(X0,Y0).
	
% Finds a valid path to travel.
pathFind(Start, Start, Path, Path):-
 	!.
pathFind(Start,Current,T,Path) :-
 	possibleMove(Current, Start),
 	Path = [Start|T], !.
pathFind(Start,Current,T,Path) :-
	possibleMove(Current, D),
 	\+ memberchk(D, T),
 	pathFind(Start,D,[D|T],Path).
	
% Checks for a shorter path.
shorterPath(Start,End,Path) :-
 	pathFind(Start,End,[End],GoalPath),
	length(Path,N),
 	length(GoalPath,M),
 	(M < N), !.

% Sets the location of the next possible move.
possibleMove([X0,Y0], [X1,Y1]) :-
	adjacent([X0,Y0], [X1,Y1]),
	possibleSpace(X1,Y1).

% Sets locations accordingly for possibleMove.
adjacent([X0,Y0], [X0,Y1]) :-
	(Y1 is Y0-1).
adjacent([X0,Y0], [X1,Y0]) :-
	(X1 is X0-1).
adjacent([X0,Y0], [X0,Y1]) :-
	(Y1 is Y0+1).
adjacent([X0,Y0], [X1,Y0]) :-
	(X1 is X0+1).

% Prints the maze.
printMaze :-
	print_maze([]).
printMaze(Path) :-
	mazeSize(I,J), nl,
	printHead(1,J), nl,
	printInnerMaze(1,I,J,Path).

printHead(From,To) :-
	format('Streets-> Rows~nAvenues-> Columns'), 
	nl, nl, write('  '),
	printColumnHead(From,To).
	
% Prints the inside of the maze.
printInnerMaze(Row,Row,Columns,Path) :-
	printRow(Row,1,Columns,Path).
printInnerMaze(Row,RowTo,_,_) :-
	Row >= RowTo.
printInnerMaze(Row,RowTo,Columns,Path) :-
	printRow(Row,1,Columns,Path), nl,
	RowNext is Row+1,
	printInnerMaze(RowNext,RowTo,Columns,Path), !.

% Prints column head until false.
printColumnHead(To,To) :-
	write(To).
printColumnHead(From,To) :-
	From >= To.
printColumnHead(From,To) :-
	write(From), printInnerSpace(From),
	Next is From+1,
	printColumnHead(Next,To), !.
	
printRow(Row,ColumnFrom,ColumnTo,Path) :-
	write(Row),
	printInnerRow(Row,ColumnFrom,ColumnTo,Path).
	
printInnerSpace(Row) :-
	Row > 9 ; write(' '),
	true.
	
% Prints a row of the maze, stopping at mazeSize.
printInnerRow(Row,Column,Column,Path):-
	write(' '),
	printSymbols(Row,Column,Path).
printInnerRow(_,Column,ColumnTo,_) :-
	Column>=ColumnTo.
printInnerRow(Row,Column,ColumnTo,Path) :-
	write(' '), printSymbols(Row,Column,Path),
	NextColumn is Column+1,
	printInnerRow(Row,NextColumn,ColumnTo,Path), !.
	
% Prints 'o' for the path
% Prints 'x' for a wall
% Prints '.' for an empty space
printSymbols(Row, Column,Path) :-
	memberchk([Row,Column],Path), write('o').
printSymbols(Row,Column,_) :-
	wall(Row,Column), write('x').
printSymbols(_,_,_) :-
	write('.').