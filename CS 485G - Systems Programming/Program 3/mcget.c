/***************************************************************************************
        Dylan Jenkins          Project 5
        mcget.c                Cloud Server - File Retrieval Program

        This program is run with command line arguments,
                argv[0] -->     mcget -- Default.
                argv[1] -->     Machine Name -- Host Name.
                argv[2] -->     TCPport -- Port Number.
                argv[3] -->     Secret Key -- Server Passwor.
		argv[4]	-->	Filename.
        It accepts these values and connects to the server, if succesful
        it sends the data over and awaits a response in the form of,
        Status being 0 for success and -1 for fail, Bytes being the number
        of bytes the display the files. Lastly, the Filename to be read.
****************************************************************************************/
#include "csapp.h"
#define NAMESIZE 80
int main(int argc, char **argv)
{
	int clientfd, port;			// Integer port to contain TCPport.
	char *host = (char *) calloc(1, 40);	// Host (Never more than 40 Bytes/Characters).
	rio_t rio;

	if (argc != 5) {
		fprintf(stderr, "usage: %s <MachineName> <TCPport> <SecretKey> <Filename>\n", argv[0]);
		return(0);
    	}

    	host = argv[1];		// Read Hostname from argument list.
    	port = atoi(argv[2]);	// Read Port # from argument list.

        uint32_t Key = atoi(argv[3]);	// Read Secret Key from argument list and convert to integer.
        uint32_t Type = 0, Status = 1, Bytes = 0;

        char *filename = (char *) calloc(1, NAMESIZE);	// Allocate space for filename.
        strcpy(filename, argv[4]);			// Read Filename from argument list.

    	if ( (clientfd = Open_clientfd(host, port)) < 0 )	// Open connection to provided Host and Port.
		return(-1);

    	Rio_readinitb(&rio, clientfd);		// ready for I/O

        Key = htonl(Key);
	Rio_writen(clientfd, &Key, sizeof(Key));	// Writes the Secret Key to the server.

        Type = htonl(Type);
	Rio_writen(clientfd, &Type, sizeof(Type));	// Write program Type to server.

	Rio_writen(clientfd, filename, NAMESIZE);	// Write the Filename to the server.

	Rio_readnb(&rio, &Status, sizeof(Status));	// Read the Status of the program,
	Status = ntohl(Status);				//	0 for Success, -1 for Failure.
	if (Status == -1) {
		Close(clientfd);	// Closes the client connection.
		return(-1);		// Exit ERROR status.
	}

	Rio_readnb(&rio, &Bytes, sizeof(Bytes));	// Read the number of Bytes in the file.
	Bytes = ntohl(Bytes);

	char *buf = (char *) calloc(1, Bytes);
	Rio_readnb(&rio, buf, Bytes);		// Read the contents of the file to buf.
	Fputs(buf, stdout);			// Prints buf to stdout.

	Close(clientfd);	// Closes the client connection.
	return(0);		// Exit Success!
}
