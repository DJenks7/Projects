/*****************************************************************************************************************
	Dylan Jenkins		CS 485
	Program Assignment 4	11/6/2016
	main.c

	This program is designed to act as a very simple shell with valid commands:

		%					-> comment
		set variable value	-> sets given input value to given input variable.
		defprompt prompt	-> sets the prompt to given input prompt.
		cd directoryName	-> changes directory to given input directoryName.
		listprocs			-> lists the background processes.
		done				-> exits.

		run cmd param [&]	-> run program given input cmd with optional
								given input param and optional flag (&)
								to run in the background.

		assignto variable cmd param	-> runs program given input cmd, with
										optional given input param and
										sets the output to given input variable.

	NOTE: Calling cd with no parameters changes to the home directory.
	ASSUMPTION: When user sets a variable if they input " " with the value the variable will contain " "
******************************************************************************************************************/
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <string.h>

#define BUFSIZE 256
#define TOKEN_BUFSIZE 64
#define TOKEN_DELIM " \t\r\n\a"

// Function Declarations for builtin shell commands:
int sish_comment(char **args);
int sish_cd(char **args);
int sish_set(char **args);
int sish_defprompt(char **args);
int sish_processes(char **args);
int sish_launch(char **args);
int sish_assignto(char **args);
int sish_done(char **args);

// Size to hold the number of arguments passed.
// bucket_count simply holds the number of arguments passed with each command.
// prompt is simply the prompt displayed while running.
int Size;
int bucket_count = 0;
char prompt[] = "sish";
// id_bucket holds the pid of background processes.
pid_t id_bucket[TOKEN_BUFSIZE];

// List of builtin commands, followed by their corresponding functions.
char *builtin_str[] = {
	"%",
	"cd",
	"set",
	"defprompt",
	"listprocs",
	"run",
	"assignto",
	"done"
};

int (*builtin_func[]) (char **) = {
	&sish_comment,
	&sish_cd,
	&sish_set,
	&sish_defprompt,
	&sish_processes,
	&sish_launch,
	&sish_assignto,
	&sish_done
};

int sish_num_builtins() {
	return sizeof(builtin_str) / sizeof(char *);
}

// ***************************************
// Builtin function implementations.
// ***************************************

// Builtin command: comment. Parameters: args[0] is "%".
int sish_comment(char **args) {
	// Simply do nothing.
	return 1;
}

// Builtin command: change directory. Parameters: List of args.
//	args[0] is "cd".  args[1] is the directory.
//	Always returns 1, to continue executing.
int sish_cd(char **args) {
	char *string = args[1];

	if (args[1] == NULL) {
		chdir(getenv("HOME"));
	} else if (string[0] == '$') {
		chdir(getenv(string+1));
	} else {
		if (chdir(args[1]) != 0) {
			fprintf(stderr, "%s: ", args[1]);
			perror("");
		}
	}

	return 1;
}

// Builtin command: set variable. Parameters: variable and value.
//	args[0] is "set". args[1] is the variable name to be set.
//	args[2] is the value to set variable to. Always returns 1, to continue.
int sish_set(char **args) {
	if (args[1] == NULL) {
		printf("expected 3 tokens, got 1 token.\n");
	} else if (args[2] == NULL) {
		printf("expected 3 tokens, got 2 tokens.\n");
	} else
		setenv(args[1], args[2], 1);

	return 1;
}

// Builtin command: change prompt. Parameters: prompt.
//	args[0] is "defprompt". args[1] is the new prompt.
//	Always returns 1, to continue execution.
int sish_defprompt(char **args) {
	strcpy(prompt, args[1]);
	return 1;
}

// Builtin command: list background processes. Parameters: None.
//	args[0] is "listprocs". Always returns 1 to continue execution.
// Lists processes if they are running, none if all have completed or there are none.
int sish_processes(char **args) {
	printf("listprocs command.\n");
	int i;

	// Assumption: won't have more than 64 background programs running.
	//	More than enough :)
	for(i = 0; i < TOKEN_BUFSIZE; i++) {
		if (id_bucket[i] != 0) {
			printf("\t%d\n", id_bucket[i]);
			return 1;
		}
	}

	printf("\tNo background processes.\n");
}

// Builtin command: exit. Parameters: List of args. Unexamined.
//	Always returns 0, to terminate execution.
int sish_done(char **args) {
	exit(0);
}

// Handler to erase the pid of background process when it finishes.
void handler(int sig) {
	pid_t pid2;
	int i;

	pid2 = wait(NULL);

	// Assumption: won't have more than 64 background programs running.
	//	More than enough :)
	for (i=0; i < TOKEN_BUFSIZE; i++) {
		if (pid2 == id_bucket[i]) {
			id_bucket[i] = 0;
		}
	}

}

// Builtin command: run program. Parameters: Null terminated list of arguments.
//	Always returns 1, to continue execution.
int sish_launch(char **args) {
	pid_t pid, wpid;
	int status;
	int background = 0;
	char *string = args[2];

	signal(SIGCHLD, handler);

	// Checks if token list (args) contains '&' at the end,
	//	if so, set background process true.
	if (Size >= 3) {
		if ( strcmp(args[Size-1], "&") == 0 ) {
			background = 1;
		}
	}

	if (strcmp(args[1], "echo") == 0 && string[0] == '$') {
		printf("%s\n", getenv(string+1));
	} else {

		pid = fork();

		if (pid == 0) {
			// Child process.
			if (execvp(args[1], args+1) == -1) {
				fprintf(stderr, "%s: ", args[1]);
				perror("");
			}
			exit(1);
		} else if (pid < 0) {
			// Error forking.
			fprintf(stderr, "%s: ", args[1]);
			perror("");
		} else {
			// Parent process.
			do {
				if (background) {
					id_bucket[bucket_count++] = pid;
				}
					// If NOT background process, wait.
				if (!background) {
					wpid = waitpid(pid, &status, WUNTRACED);
				}
			} while (!WIFEXITED(status) && !WIFSIGNALED(status));
		}
	}

	return 1;
}

// Builtin command: run and assign output to variable.
//	Parameters: args[0] = "assignto". args[1] is the variable name to save the output to.
//		args[2] is the program to be run. args[3] is optional and is the parameters.
//	Always returns 1 to continue execution.
int sish_assignto(char **args) {
	if (args[1] == NULL || args[2] == NULL)
		printf("Insufficient parameters.\n");
	else {
		int fd[2];
		int i;

		pipe(fd);

		if (fork() == 0) {
			dup2(fd[1], STDOUT_FILENO);
			char *string = args[2];

			if (string[0] == '$') {
				execvp(getenv(string+1), args+2);
			} else
				execvp(args[2], args+2);
		} else {
			char buffer[1000];
			ssize_t size = read(fd[0], buffer, 1000);

			// Replaces the '\n' character at the end of the array with '\0'
			for (i=1; i<1000; i++) {
				if (buffer[i] == '\n')
					buffer[i] = '\0';
			}

			setenv(args[1], buffer, 1);
		}
	}

	return 1;
}

// Execute shell built-in or launch program.
// Parameters: Null terminated list of arguments.
// Returns 1 if the shell should continue running, 0 if it should terminate.
int sish_execute(char **args) {
	int i;

	if (args[0] == NULL) {
		// An empty command was entered.
		return 1;
	}

	if (strcmp(getenv("ShowTokens"), "1") == 0) {
		for (i = 0; i < Size; i++)
			printf("\tToken = %s\n", args[i]);
	}

	for (i = 0; i < sish_num_builtins(); i++) {
		if (strcmp(args[0], builtin_str[i]) == 0) {
			return (*builtin_func[i])(args);
		}
	}

	printf("Invalid command.\n");
	return 1;
}

// Read a line of input from stdin.
//	Return the line from stdin.
char *sish_read_line(void) {
	int bufsize = BUFSIZE;
	int position = 0;
	char *buffer = malloc(sizeof(char) * bufsize);
	int c;

	if (!buffer) {
		fprintf(stderr, "sish: allocation error\n");
		exit(1);
	}

	while (1) {
		// Read a character.
		c = getchar();

		// If we hit EOF, replace it with a null character and return.
		if (c == EOF || c == '\n') {
			buffer[position] = '\0';
			return buffer;
		} else {
			buffer[position] = c;
		}
		position++;

		// If we have exceeded the buffer, reallocate.
		if (position >= bufsize) {
			bufsize += BUFSIZE;
			buffer = realloc(buffer, bufsize);

			if (!buffer) {
				fprintf(stderr, "sish: allocation error\n");
	        		exit(1);
			}
    		}
	}

}

// Splits a line into tokens. Parameters: The line.
//	Returns Null-terminated array of tokens.
char **sish_split_line(char *line) {
	int bufsize = TOKEN_BUFSIZE, position = 0;
	char **tokens = malloc(bufsize * sizeof(char*));
	char *token;

	if (!tokens) {
		fprintf(stderr, "sish: allocation error\n");
		exit(1);
	}

	token = strtok(line, TOKEN_DELIM);
	while (token != NULL) {
		tokens[position] = token;
		position++;

		if (position >= bufsize) {
			bufsize += TOKEN_BUFSIZE;
      			tokens = realloc(tokens, bufsize * sizeof(char*));

			if (!tokens) {
			        fprintf(stderr, "sish: allocation error\n");
			        exit(1);
			}
		}

		token = strtok(NULL, TOKEN_DELIM);
 	 }

	Size = position;
	tokens[position] = NULL;
	return tokens;
}

// Handler for Segmentation faults in case of Ctrl-D in mid command.
void ctrlD_Handler(int signum) {
	exit(0);
}

// Loop to get input and execute it.
void sish_loop(void) {
	char *line;
	char **args;
	int status;

	signal(SIGSEGV, ctrlD_Handler);

	do {
                printf("%s > ", prompt);
                line = sish_read_line();
		args = sish_split_line(line);

		if (args[0] == '\0')
			exit(0);

		status = sish_execute(args);

		free(line);
		free(args);
	} while (status);
}

// Parameter argc: Argument count.
// Parameter argv: Argument vector.
// Returns status code.
int main(int argc, char **argv) {
	// Used to determine if tokens need to be printed.
	setenv("ShowTokens", "0", 1);

	// Run command loop.
	sish_loop();

	return 0;
}
