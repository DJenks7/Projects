/***************************************************************************************
	Dylan Jenkins		Project 5
	mclist.c		Cloud Server - List Program

	This program is run with command line arguments,
		argv[0]	-->	mclist -- Default
		argv[1]	-->	Machine Name -- Host Name
		argv[2]	-->	TCPport -- Port Number
		argv[3]	-->	Secret Key -- Server Password
	It accepts these values and connects to the server, if succesful
	it sends the data over and awaits a response in the form of,
	Status being 0 for success and -1 for fail, Bytes being the number
	of bytes the display the files. Lastly, the files on the server are
	sent over and displayed for the user to see.
****************************************************************************************/
#include "csapp.h"

int main(int argc, char **argv)
{
	int clientfd, port;			// Integer port to contain TCPport.
	char *host = (char *) calloc(1, 40);	// Host (Never more than 40 Bytes/Characters.
	rio_t rio;

	if (argc != 4) {
		fprintf(stderr, "usage: %s <MachineName> <TCPport> <SecretKey>\n", argv[0]);
		return(0);
    	}

    	host = argv[1];		// Read Hostname from argument list.
    	port = atoi(argv[2]);	// Read Port # from argument list.

        uint32_t Key = atoi(argv[3]);	// Read Secret Key from argument list and convert to integer.
        uint32_t Type = 3, Status, Bytes;

        if ( (clientfd = Open_clientfd(host, port)) < 0 )	// Open connection to provided Host and Port.
		return(-1);

        Rio_readinitb(&rio, clientfd);          // ready for I/O.

        Key = htonl(Key);
	Rio_writen(clientfd, &Key, sizeof(Key));	// Write the Secret Key to the server.

        Type = htonl(Type);
	Rio_writen(clientfd, &Type, sizeof(Type));	// Write the Type to the server.
						// Used by the server to determine which program is run.
	Rio_readnb(&rio, &Status, sizeof(Status));	// Read the Status of the program,
	Status = ntohl(Status);				//	0 for Success, -1 for Failure.
	if (Status == -1) {
		Close(clientfd);	// Closes the client connection.
		return(-1);		// Exit ERROR status.
	}

	Rio_readnb(&rio, &Bytes, sizeof(Bytes));	// Read the number of Bytes in the list.
	Bytes = ntohl(Bytes);

	char *buf = (char *) calloc(1, Bytes);;
	Rio_readnb(&rio, buf, Bytes);			// Read the files on the server into buf.
	Fputs(buf, stdout);				// Prints buf to stdout.

	Close(clientfd);	// Closes the client connection.
	return(0);
}
