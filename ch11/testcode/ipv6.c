#include <stdio.h>

int main(int argc, char **argv) {
  if(argc != 2) {
    printf("USAGE\n");
    return;
  }

  char *hostname = argv[1];
  int status;
  struct sockaddr_in6 sa6;
  struct addrinfo hints, *p, *listp;

  memset(&hints, 0, sizeof hints);
  hints.ai_family = AF_UNSPEC;
  hints.ai_socktype = SOCK_STREAM;
  hints.ai_flags = AI_PASSIVE;

  if(status = getaddrinfo(hostname, NULL, &hints, &listp) != 0) {
    fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(status));
    return 2;
  }

  printf("IP addresses for %s:\n\n", argv[1]);

  for(p = listp; p; p = p->ai_next) {
    socket(p->ai_family, p->ai_socktype, p->ai_protocol);
  }
}
