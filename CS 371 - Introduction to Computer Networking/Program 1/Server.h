#include <limits.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <sys/stat.h>
#include <unistd.h>

#define ERROR -1
#define MAX_CLIENTS 5
#define MAX_DATA 1024
#define MAX_RESPONSE 1024*1024
#define MAX_PATH_LENGTH 512
#define NUM_THREADS 4
#define FALSE 0
#define TRUE 1
#define NOT_FOUND 404
#define BAD_METHOD 4040
#define BAD_URI 4041
#define BAD_HTTP_VERSION 4042
#define NUM_OF_FILE_TYPES 8

/* Struct Definitions */
struct HTTPParameters {
        char *Method;
        char *URI;
        char *httpVersion;
};

struct ServerConfig {
        int PortNumber;
        char DocRoot[MAX_PATH_LENGTH];
        char DefaultPage[20];
        char Extensions[NUM_OF_FILE_TYPES + 1][512];
        char Encodings[NUM_OF_FILE_TYPES + 1][512];
};

void ServerSetup(struct ServerConfig *ServerConfig, char* Root, int Port);
int SocketSetup(int Port_Number, int Max_Clients);
void ClientHandler(int Client, struct ServerConfig *Config);
int GetFilePath(char *Path, char *Body, struct ServerConfig *Config, int *ResultStatus);
void ServeFile(char *Full_Path, int Client);