/***************************************************************************************
        Dylan Jenkins           Project 5
        mcput.c                Cloud Server - Save File Program

        This program is run with command line arguments,
                argv[0] -->     mcput -- Default.
                argv[1] -->     Machine Name -- Host Name.
                argv[2] -->     TCPport -- Port Number.
                argv[3] -->     Secret Key -- Server Password.
		argv[4]	-->	Filename.
        It accepts these values and connects to the server, if succesful
        it sends the data over and awaits a response in the form of,
        Status being 0 for success and -1 for fail, Bytes being the number
        of bytes the display the files. Lastly, the Filename to save the data to.
****************************************************************************************/
#include "csapp.h"
#define MAXFILE 100000
#define NAMESIZE 80

int main(int argc, char **argv)
{
	int clientfd, port;				// Integer port to contain TCPport.
	char *host = (char *) calloc(1, 40);		// Host (Never more than 40 Bytes/Characters).
	char *Buffer = (char *) calloc(1, MAXLINE);	// Buffer to contain "file" to be sent over to the server.
	rio_t rio;

	if (argc != 5) {
		fprintf(stderr, "usage: %s <MachineName> <TCPport> <SecretKey> <Filename>\n", argv[0]);
		return(0);
    	}

    	host = argv[1];		// Read Hostname from argument list.
    	port = atoi(argv[2]);	// Read port # from argument list.

        uint32_t Key = atoi(argv[3]);		// Read Secret Key from argument list and convert to integer.
        uint32_t Type = 1, Status = 1, Size = 0;

        char *filename = (char *) calloc(1, NAMESIZE);	// Allocate space for filename.
        strcpy(filename, argv[4]);			// Read Filename from argument list.

    	if ( (clientfd = Open_clientfd(host, port)) < 0 )	// Open connection to provided Host and Port.
		return(-1);

    	Rio_readinitb(&rio, clientfd);		// ready for I/O.

	while (fread(Buffer, 1, MAXLINE, stdin) > 0) {		// While the user has not hit Ctrl-D
		if (feof(stdin)) {				// Read input from stdin
			break;
		}
		strcat(Buffer, Buffer);				// Saves to string to be sent to server.
	}

	Key = htonl(Key);
	Rio_writen(clientfd, &Key, sizeof(Key));		// Send key over to the server.

        Type = htonl(Type);
	Rio_writen(clientfd, &Type, sizeof(Type));		// Send type over to the server.

	Rio_writen(clientfd, filename, NAMESIZE);		// Send filename over to the server.

	Size = strlen(Buffer);
        uint32_t Size2 = htonl(Size);
	Rio_writen(clientfd, &Size2, sizeof(Size2));		// Send file size over to the server.

	Rio_writen(clientfd, Buffer, Size);			// Send file contents over to the server.

	Rio_readnb(&rio, &Status, sizeof(Status));		// Read the Status of the program,
	Status = ntohl(Status);					//	0 for Success, -1 for Failure.
	if (Status == -1) {
		Close(clientfd);		// Closes the client connection.
		return(-1);			// Exit ERROR status.
	}

	Close(clientfd);	// Closes the client connection.
	return(0);		// Exit Success!
}
