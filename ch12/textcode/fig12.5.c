/* Figure 12.5 Concurrent echo server based on processes */
#include <sys/wait.h>
#include "./12.h"

void sigchld_handler(int);
typedef void handler_t(int);

handler_t *Signal(int sig, handler_t *handler) {
  struct sigaction action, old_action;

  action.sa_handler = handler;
  sigemptyset(&action.sa_mask);
  action.sa_flags = SA_RESTART;

  if(sigaction(sig, &action, &old_action) < 0)
    perror("Signal error");

  return old_action.sa_handler;
}

void sigchld_handler(int sig) {
  while (waitpid(-1, 0, WNOHANG) > 0)
    ;
  return;
}

int main(int argc, char** argv) {
  int listenfd, connfd;
  struct sockaddr_storage clientaddr;
  socklen_t clientlen;
  char client_hostname[MAXLINE], client_port[MAXLINE];

  if (argc != 2) {
    fprintf(stderr, "Usage: %s <port>\n", argv[0]);
    exit(0);
  }

  Signal(SIGCHLD, sigchld_handler);
  listenfd = open_listenfd(argv[1]);

  while(1) {
    clientlen = sizeof(struct sockaddr_storage);
    connfd = accept(listenfd, (SA *)&clientaddr, &clientlen);

    if(fork() == 0) {
      close(listenfd);
      getnameinfo(
        (SA *)&clientaddr, clientlen,
        client_hostname, MAXLINE,
        client_port, MAXLINE, 0
      );
      printf("Connected to (%s, %s)\n", client_hostname, client_port);
      echo(connfd);
      printf("Connection(%s, %s) will close.\n", client_hostname, client_port);
      close(connfd);
      exit(0);
    }

    close(connfd);
  }
}
