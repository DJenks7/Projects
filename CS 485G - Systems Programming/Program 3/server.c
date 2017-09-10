/***************************************************************************************
        Dylan Jenkins           Project 5
        server.c                Cloud Server - Server Program

        This program is run with command line arguments,
                argv[0] -->     server -- Default.
                argv[1] -->     TCPport -- Port Number.
                argv[2] -->     Secret Key -- Server Password.
        It accepts these values and creates a server on the current machine,
	using port number provided and sets a secret key as a "password",
	then it simply waits for a connection.

	The program is designed to act as a cloud server that can retrieve (case 0)
	a file, save (case 1) a file, delete (case 2) a file, and list (case 3)
	the files on the server.
****************************************************************************************/
#include "csapp.h"
#define MAXFILE 100000
#define NAMESIZE 80

void Print_State(uint32_t K, uint32_t T, uint32_t S, char* F);

int main(int argc, char **argv)
{
	int listenfd, connfd, port;
	int i = 0;			// Integer i is used as a counter while server the is running.
	uint32_t key;			// Integer to be used to  be the key or "password" to the server.

	socklen_t clientlen;
	struct sockaddr_in clientaddr;
	rio_t rio;

	if (argc != 3) {
		fprintf(stderr, "usage: %s <TCPport> <SecretKey>\n", argv[0]);
		return(-1);
	}

	port = atoi(argv[1]);	// Read Port # from argument list.
	key = atoi(argv[2]);	// Read key from argument list.

	if ( (listenfd = Open_listenfd(port)) < 0 )
		return(-1);

	// Once/If connected create variables needed.
        uint32_t Bytes = 0, Bytes2 = 0, Status = -1;	// Bytes used to read size of file, Bytes2 used to send to
							// server(htonl), Status is 0 for Success or -1 for Failure.
	uint32_t Key, Type;				// Key to read Client sent key, Type to determine request.
	int j;						// Integer j used as a loop counter.
	char *Filename = (char *) calloc(1, NAMESIZE);	// Allocate space for Filename.
	char Server_Fnames[NAMESIZE][NAMESIZE];	// Assumption 80 Files at most...? Acceptable?
	char Server_Files[NAMESIZE][MAXFILE];	// Assumption 80 Files at most...? Acceptable?
	// ^ Need to use calloc/malloc...

	while (1) {
		clientlen = sizeof(clientaddr);
		connfd = Accept(listenfd, (SA *)&clientaddr, &clientlen);
		if (connfd < 0) {
                        Status = htonl(Status);			// Failed to connect.
                        Rio_writen(connfd, &Status, 4);		// Send Failure status to Client.
		}
		else {
			Rio_readinitb(&rio, connfd);		// ready for I/O.

			Rio_readnb(&rio, &Key, 4);		// Read Key sent from Client.
			Key = ntohl(Key);

			if (Key != key) {
				Status = htonl(Status);			// If bad secret key,
				Rio_writen(connfd, &Status, 4);		// Send Failure status to Client.
			}
			else {
				Rio_readnb(&rio, &Type, 4);	// Read Type from Client to determine request.
				Type = ntohl(Type);

				switch(Type) {
					// Retrieve a File.
					case 0 :
	       	                        	Rio_readnb(&rio, Filename, NAMESIZE);	// Read Filename from Client.

						// Allocate space for File to return to Client.
						char *File2 = (char *) calloc(1, MAXFILE);

						// Loop through files, if it exists, copy string to File2.
						for (j = 0; j < i; j++) {
							if (strcmp(Server_Fnames[j], Filename) == 0) {
								strcpy(File2, Server_Files[j]);
							}
						}

						// If File was NOT found.
						if(strcmp(File2, "") == 0) {
							Status = -1;
							Status = htonl(Status);
							Rio_writen(connfd, &Status, 4);	// Send Failure Status to Client.

							Bytes = strlen(File2);
							Bytes2 = htonl(Bytes);
							Rio_writen(connfd, &Bytes2, 4);	// Send File size Bytes2 to Client.

							Rio_writen(connfd, File2, Bytes);	// Send File data to Client.
						}
						// File WAS found.
						else {

							Status = 0;
							Status = htonl(Status);
							Rio_writen(connfd, &Status, 4);	// Send Status to Client.

							Bytes = strlen(File2);
							Bytes2 = htonl(Bytes);
							Rio_writen(connfd, &Bytes2, 4);	// Send File size Bytes2 to Client.

							Rio_writen(connfd, File2, Bytes);	// Send File data to Client.
						}

						free(File2);
						break;
					// Save a File.
					case 1 :
		                                Rio_readnb(&rio, Filename, NAMESIZE);	// Read Filename.

						Rio_readnb(&rio, &Bytes, 4);		// Read File size Bytes.
						Bytes = ntohl(Bytes);

						char *File = (char *) calloc(1, Bytes);	// Allocate space for File.
						Rio_readnb(&rio, File, Bytes);		// Read File from Client.

						// Determine if the file exists.
						int Found = -1;
						for (j = 0; j < i; j++) {
							if (strcmp(Server_Fnames[j], Filename) == 0) {
								Found = j;
							}
						}

						// If the File existed overwrite it Else create a new file.
						if (Found != -1) {
							strcpy(Server_Files[Found], File);
						}
						else {
							strcpy(Server_Fnames[i], Filename);	// Stores Filenames.
							strcpy(Server_Files[i], File);	// Stores Files according to
											// Filenames locations in array.
							i++;
						}

			                        Status = 0;			// Set Status to Success value.
                			        Status = htonl(Status);
			                        Rio_writen(connfd, &Status, 4);	// Send return Status to Client.

						free(File);
						break;
					// Delete File.
					case 2 :
						Rio_readnb(&rio, Filename, NAMESIZE);

						// BUG IN DELETE - Needs to adjust i counter accordingly...
						//	Atm, it will leave a blank space in the deleted spot.
                                                for (j = 0; j < i; j++) {
                                                        if (strcmp(Server_Fnames[j], Filename) == 0) {
                                                                strcpy(Server_Fnames[j], "");
								strcpy(Server_Files[j], "");
                                                        }
                                                }

						Status = 0;
						Status = htonl(Status);
						Rio_writen(connfd, &Status, 4);		// Send Status to Client.

						break;
					// List Files.
					case 3 :
						Status = 0;
						Status = htonl(Status);
						Rio_writen(connfd, &Status, 4);		// Send Status to Client.

						// Determine total size of list.
						for (j = 0; j < i; j++) {
							Bytes += strlen(Server_Fnames[j]);
						}

                                                Bytes2 = htonl(Bytes);
                                                Rio_writen(connfd, &Bytes2, 4);		// Send file size Bytes2 to Client.

						char *Buffer = (char *) calloc(1, MAXFILE);	// Allocate space for Buffer.

						// Create list of files on server.
						for (j = 0; j < i; j++) {
							strcat(Buffer, Server_Fnames[j]);
							strcat(Buffer, "\n");
						}

						Bytes = strlen(Buffer);
						Rio_writen(connfd, Buffer, Bytes);	// Send File Data to Client.

						free(Buffer);
						break;
				}

				Close(connfd);
			}

			Print_State(Key, Type, Status, Filename);

		}
	}

	// Close/Free memory.
	free(Filename);
	free(Server_Fnames);
	free(Server_Files);

	Close(listenfd);
	return(0);
}

// Used to print the "State" of the program. Success or Failure status.
void Print_State(uint32_t K, uint32_t T, uint32_t S, char* F) {

	char *State;
	if (S == 0)
		State = "Success";
	else
		State = "Failure";

	char *Request;
	if (T == 0)
		Request = "Retrieve";
	if (T == 1)
		Request = "Store";
	if (T == 2)
		Request = "Delete";
	if (T == 3)
		Request = "List";

	printf("-----------------------------\n");
	printf("Secret Key = %d\n", K);
	printf("Request Type = %s\n", Request);
	printf("Filename = %s\n", F);
	printf("Operation Status = %s\n", State);
	printf("-----------------------------\n");
}
