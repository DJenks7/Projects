% Daniel Carroll's implementation of citypath predicates from Prolog Assignment 1.
%	Edited by Dylan Jenkins.
% CS 463	Prolog Assignment 2
% SWI-PROLOG

% Citypath takes the start location ( X1 & Y1 ), Maze, a Path, and Score variable.
% If the starting and ending location are the same, the solution is found unless
% there is a jenny blocking the square. Otherwise the program finds the Egg and moves
% to its location. Then the program finds the Pikachu and moves to the location. Followed
% by finding the MasterBall and moving to its location. Lastly, it finds the location of MewTwo
% and moves to its location and checks if all the items have been "obtained" and if so finishes
% and returns the Path and the Score.

% NOTE1: The output will be in column, row format like Dr. Goldsmith had mentioned it should be in class.
%		[ [1,1],[2,1],[3,1],[4,1],[5,1], ... ]
%		[ [1,2],[2,2],[3,2],[4,2], ... ]
%		[ [1,3],[2,3],[3,3], ... ]
%		[ [1,4],[2,4], ... ]
%		[ [1,5], ... ]
% NOTE2: You will have to hit ; a few times (should be 3 exactly) before the program displays the Path and Score.
%			It cycles through a few tests first before ultimately displaying the solution.

:- dynamic obtained/1.

% This calls a version of the function that has
%	a variable to store the current path.
citypath( X1, Y1, Maze, Path, Score ) :-
	% Removes any previous runs assertions of obtained items.
	abolish(obtained/1),

	% Asserts initial obtained nothing so check predicates can work.
	assert(obtained(nothing)),

	CurrentPath = [ [ X1, Y1 ] ],
	validMove( X1, Y1, Maze ),
	
	% Find egg location. First Item to Find.
	nth1( X2, Maze, Column ), nth1( Y2, Column, e ),
	
	% Find pikachu's location. Second Item to Find.
	nth1( X3, Maze, Column2 ), nth1( Y3, Column2, p ),
	
	% Find masterball's location. Third Item to Find.
	nth1( X4, Maze, Column3 ), nth1( Y4, Column3, mb ),
	
	% Find mewtwo's locaton. Last to Find!
	nth1( X5, Maze, Column4 ), nth1( Y5, Column4, mt ),

	citypath( X1, Y1, X2, Y2, X3, Y3, X4, Y4, X5, Y5, Maze, Path, Score, CurrentPath ).

% Checks to see we are at the destination, then if there
%	is a Jenny at the destination, then returns the path if no Jenny.
citypath( X1, Y1, X2, Y2, X3, Y3, X4, Y4, X5, Y5, Maze, Path, Score, CurrentPath ) :-
	% If current location is at the Egg, assert obtained Egg.
	checkEgg( X1, Y1, X2, Y2 ) ; 
	
	% If current location is at the Pikachu, assert obtained Pikachu.
	checkPika( X1, Y1, X3, Y3 ) ;
	
	% If current location is at the MasterBal, assert obtained MasterBall.
	checkMB( X1, Y1, X4, Y4 ) ;
	
	% If the current location is at MewTwo AND we have obtained the egg, pikachu, masterball, GOOOAAALLLLL!!
	% Egg will have gone at the least three moves IF we have obtained all thee items due to finding the egg first, 
	%	then pikachu, then masterball, and lastly mewtwo. Even if spaces are next to eachother that is minimum of three moves.
	checkMewTwo( X1, Y1, X5, Y5 ),
	obtained(egg), obtained(pika), obtained(mb) -> ( validMove( X1, Y1, Maze ), Score = 11, reverse( CurrentPath, Path ) ).

% If current location is at the Egg, assert obtained Egg.
checkEgg( X1, Y1, X2, Y2 ) :-
	\+ obtained(egg) -> ( ( X1 == X2, Y1 == Y2 ) -> assert(obtained(egg)) ).
	
% If current location is at the Pikachu, assert obtained Pikachu.		
checkPika( X1, Y1, X3, Y3 ) :-
	\+ obtained(pika) -> ( ( X1 == X3, Y1 == Y3 ) -> assert(obtained(pika)) ).

% If current location is at the MasterBal, assert obtained MasterBall.
checkMB( X1, Y1, X4, Y4 ) :-
	\+ obtained(mb) -> ( ( X1 == X4, Y1 == Y4) -> assert(obtained(mb)) ).

% If curent location is at MewTwo.
checkMewTwo( X1, Y1, X5, Y5 ) :-
	X1 == X5, Y1 == Y5.
	
% Tries to move in the X + 1 direction. Fails if that location
%	was already explored, or if the location is invalid. 
citypath( X1, Y1, X2, Y2, X3, Y3, X4, Y4, X5, Y5, Maze, Path, Score, CurrentPath ) :- 
	NewX is X1 + 1, validMove( NewX, Y1, Maze ), 
	\+ member( [ Y1, NewX ], CurrentPath ), 
	append( [ [ Y1, NewX ] ], CurrentPath, NewPath ), 
	citypath( NewX, Y1, X2, Y2, X3, Y3, X4, Y4, X5, Y5, Maze, Path, Score, NewPath ).

% Tries to move in the Y + 1 direction. Fails if that location
%	was already explored, or if the location is invalid. 
citypath( X1, Y1, X2, Y2, X3, Y3, X4, Y4, X5, Y5, Maze, Path, Score, CurrentPath ) :- 
	NewY is Y1 + 1, validMove( X1, NewY, Maze ), 
	\+ member( [ NewY, X1 ], CurrentPath ), 
	append( [ [ NewY, X1 ] ], CurrentPath, NewPath ), 
	citypath( X1, NewY, X2, Y2, X3, Y3, X4, Y4, X5, Y5, Maze, Path, Score, NewPath ).

% Tries to move in the X - 1 direction. Fails if that location 
%	was already explored, or if the location is invalid. 
citypath( X1, Y1, X2, Y2, X3, Y3, X4, Y4, X5, Y5, Maze, Path, Score, CurrentPath ) :- 
	NewX is X1 - 1, validMove( NewX, Y1, Maze ), 
	\+ member( [ Y1, NewX ], CurrentPath ), 
	append( [ [ Y1, NewX ] ], CurrentPath, NewPath ), 
	citypath( NewX, Y1, X2, Y2, X3, Y3, X4, Y4, X5, Y5, Maze, Path, Score, NewPath ).

% Tries to move in the Y - 1 direction. Fails if that location
%	was already explored, or if the location is invalid. 
citypath( X1, Y1, X2, Y2, X3, Y3, X4, Y4, X5, Y5, Maze, Path, Score, CurrentPath ) :- 
	NewY is Y1 - 1, validMove( X1, NewY, Maze ), 
	\+ member( [ NewY, X1 ], CurrentPath ), 
	append( [ [ NewY, X1 ] ], CurrentPath, NewPath ), 
	citypath( X1, NewY, X2, Y2, X3, Y3, X4, Y4, X5, Y5, Maze, Path, Score, NewPath ).

% If the coordinate in question is out of range, this fails through one of the nth1 calls. 
% If the coordinate is valid, it checks for Jenny, and fails if she is there.
% If the coordinate is valid and there is no Jenny, the space can be moved to.
validMove( X1, Y1, Maze ) :- 
	nth1( X1, Maze, Column ), nth1( Y1, Column, IsJenny ), IsJenny \== j .