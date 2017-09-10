/*      Dylan Jenkins           Program 1
        CS 371                  Spring 2017
        2/20/2017               Server.c

        Program is designed to act as a webserver to any client who sends a valid request
                to an existing file of the extetions supported on the server. Returning the
                page/info if it exists.
*/
#include "Server.h"

int main(int argc, char ** argv) {
        /* Test for correct number of arguments */
        if (argc < 3) {
                fprintf(stderr, "Usage: %s <Root Dir> <Port Number>\n", argv[0]);
                exit(0);
        }

        struct ServerConfig serverConfig;
        ServerSetup(&serverConfig, argv[1], atoi(argv[2]));
        struct sockaddr_in client;
        int pid, cli;
        int listenfd;
        unsigned int sockaddr_len = sizeof(struct sockaddr_in);

        listenfd = SocketSetup(serverConfig.PortNumber, MAX_CLIENTS);

        printf("**************************************\n");
        printf("| SERVER Started: \n");
        printf("| Port: %d\n", serverConfig.PortNumber);
        printf("| Root: %s\n", serverConfig.DocRoot);
        printf("| Default: %s\n", serverConfig.DefaultPage);
        printf("**************************************\n");

        while (1) {
                if ((cli = accept(listenfd, (struct sockaddr *)&client, &sockaddr_len)) < 0) {
                        perror("ERROR on accept");
                        exit(1);
                }

                pid = fork();
                if (pid < 0) {
                        perror("ERROR on fork");
                        exit(1);
                }

                /* Creates new process with a new copy */
                if (pid == 0) {
                        close(listenfd);
                        ClientHandler(cli, &serverConfig);
                        close(cli);
                        exit(0);
                }

                /*  Wait for the child to finish before reaping */
                if (pid > 0) {
                        close(cli);
                        waitpid(0, NULL, WNOHANG);
                }
        }
        close(listenfd);
        return 1;
}

void ServerSetup(struct ServerConfig *ServerConfig, char* Root, int Port) {
        ServerConfig->PortNumber = Port;
        strcpy(ServerConfig->DefaultPage, "/index.html");
        strcpy(ServerConfig->DocRoot, Root);
}

/* Sets up the server to communicate over to the Client when request received.*/
int SocketSetup(int Port_Number, int Max_Clients) {
        struct sockaddr_in Server;
        int Sock;

        Server.sin_family = AF_INET;
        Server.sin_port = htons(Port_Number);
        Server.sin_addr.s_addr = INADDR_ANY;

        memset(Server.sin_zero, '\0', sizeof(Server.sin_zero));

        if ((Sock = socket(AF_INET, SOCK_STREAM, 0)) == ERROR) {
                perror("server socket: ");
                exit(-1);
        }
        if ((bind(Sock, (struct sockaddr *)&Server, sizeof(struct sockaddr_in))) == ERROR) {
                perror("bind : ");
                exit(-1);
        }
        if ((listen(Sock, Max_Clients)) == ERROR) {
                perror("Listen");
                exit(-1);
        }
        return Sock;
}

void SendResponse(int Client, int StatusCode, struct HTTPParameters *Parameters, char *URL) {
        char NotFoundResponse[] = "HTTP/1.1 404 Not Found:%s\r\nContent-Type: text/html; charset=UTF-8\r\n\r\n"
                "<!DOCTYPE html><html><head><title>404 Not Found</title>"
                "<body><h1>404 Not Found:%s</h1></body></html>\r\n";
        char ActualResponse[sizeof(NotFoundResponse) + (2 * (sizeof(Parameters->URI))) + 256];
        memset(&ActualResponse, 0, sizeof(ActualResponse));

        switch (StatusCode) {
        case 200:
                ServeFile(URL, Client);
                break;
        case 404:
                snprintf(ActualResponse, sizeof(ActualResponse), NotFoundResponse, Parameters->URI, Parameters->URI);
                write(Client, ActualResponse, sizeof(ActualResponse));
                break;
        }
}

void ParameterExtraction(char *Response, struct HTTPParameters *Parameters) {
        char *saveptr, *thePath;

        /* Used to extract specific data from the get request from the browser */
        thePath = strtok_r(Response, "\n", &saveptr);
        thePath = strtok_r(thePath, " ", &saveptr);

        Parameters->Method = malloc(strlen(thePath) + 1);
        strcpy(Parameters->Method, thePath);

        thePath = strtok_r(NULL, " ", &saveptr);

        Parameters->URI = malloc(strlen(thePath) + 1);

        strcpy(Parameters->URI, thePath);
        Parameters->httpVersion = malloc(strlen(saveptr) + 1);
        strcpy(Parameters->httpVersion, saveptr);
}

/* This uses the file path sent by the browser to get the actual file from the server.
                If the user passes '/' you get the default index.html file from the server */
int GetFilePath(char *Path, char *Body, struct ServerConfig *Config, int *ResultStatus) {
        int FileSupport;

        FileSupport = FALSE;

        char FilePath[PATH_MAX + 1];
        char *FileExtension;
        struct stat Buffer;

        strcpy(FilePath, Config->DocRoot);
        strcat(FilePath, Path);
        FileExtension = strrchr(FilePath, '.');

        if (((strcmp(Path, "/index")) == 0) || ((strcmp(Path, "/")) == 0) || ((strcmp(Path, "/index.html")) == 0)) {
                if ((strcmp(Path, "/index")) == 0)
                        strcat(FilePath, ".html");

                if ((strcmp(Path, "/")) == 0)
                        strcat(FilePath, "index.html");

                *ResultStatus = 200;
                strcpy(Body, FilePath);

                return 0;
        }

        if ((stat(FilePath, &Buffer) == 0)) {
                *ResultStatus = 200;
                strcpy(Body, FilePath);

                return 0;
        }
        else {
                *ResultStatus = 404;
                strcpy(Body, FilePath);

                return 0;
        }
}

void ClientHandler(int Client, struct ServerConfig *Config) {
        struct HTTPParameters ParameterRequest;
        int Length, StatusCode;
        char reqData[MAX_DATA], absFilePath[MAX_PATH_LENGTH];

        if ((Length = recv(Client, reqData, MAX_DATA, 0)) < 0) {
                perror("Recv: ");
                exit(-1);
        }
        if (Length) {
                ParameterExtraction((char *)&reqData, &ParameterRequest);

                GetFilePath((ParameterRequest.URI), (char *)&absFilePath, Config, &StatusCode);
                SendResponse(Client, StatusCode, &ParameterRequest, (char *)&absFilePath);

                free(ParameterRequest.Method);
                free(ParameterRequest.URI);
                free(ParameterRequest.httpVersion);
        }
}

void ServeFile(char *absFilePath, int client) {
        char *fileExtension;
        char buffer[1024];
        long fileSize;
        FILE *requestedFile;
        size_t ReadBytes, BytesRead;
        fileExtension = strchr(absFilePath, '.');

        /* Responses for different file extensions */
        char gifResponse[] = "HTTP/1.1 200 OK:\r\n" "Content-Type: image/gif; charset=UTF-8\r\n\r\n";
        char htmlResponse[] = "HTTP/1.1 200 OK:\r\n" "Content-Type: text/html; charset=UTF-8\r\n\r\n";
        char textResponse[] = "HTTP/1.1 200 OK:\r\n" "Content-Type: text/plain; charset=UTF-8\r\n\r\n";
        char jpgResponse[] = "HTTP/1.1 200 OK:\r\n" "Content-Type: image/jpeg; charset=UTF-8\r\n\r\n";

        requestedFile = fopen(absFilePath, "r");
        fseek(requestedFile, 0, SEEK_END);
        fileSize = ftell(requestedFile);
        fseek(requestedFile, 0, SEEK_SET);

        if ((strcmp(fileExtension, ".gif")) == 0)
                send(client, gifResponse, sizeof(gifResponse) - 1, 0);

        if ((strcmp(fileExtension, ".html")) == 0)
                send(client, htmlResponse, sizeof(htmlResponse) - 1, 0);

        if ((strcmp(fileExtension, ".jpg")) == 0)
                send(client, jpgResponse, sizeof(jpgResponse) - 1, 0);

        if ((strcmp(fileExtension, ".txt")) == 0)
                send(client, textResponse, sizeof(textResponse) - 1, 0);

        BytesRead = 0;

        /* Loops untill the end of file, fills the buffer and sends it to the Client */
        while (!feof(requestedFile)) {
                ReadBytes = fread(buffer, 1, 1024, requestedFile);
                BytesRead += ReadBytes;
                send(client, buffer, ReadBytes, 0);
        }

        fclose(requestedFile);
}
