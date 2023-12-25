#include <netdb.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/socket.h>
#include <sys/mman.h>
#include "./10.h"

#define MAXLINE 1000
#define MAXBUF 1000

typedef struct sockaddr SA;

int open_listenfd(char *port);
int open_clientfd(char *hostname, char *port);
