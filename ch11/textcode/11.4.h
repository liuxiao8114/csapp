#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stdlib.h>
#include "./10.h"

#define MAXLINE 1000

/*
// IPv4 addreess struct
struct in_addr {
  uint32_t s_addr;
};

// IPv4 socket
struct sockaddr_in {
  uint16_t       sin_family;
  uint16_t       sin_port;
  struct in_addr sin_addr;
  char           sin_zero[8];
};

// IPv6 addreess struct
struct in6_addr {
  unsigned char[16] s6_addr;
};

// IPv6 socket
struct sockaddr_in6 {
  uint16_t        sin6_family;
  uint16_t        sin6_port;
  u_int32_t       sin6_flowinfo;
  struct in6_addr sin6_addr;
  u_int32_t       sin6_scope_id;
};

// Generic socket
struct sockaddr {
  uint16_t sa_family;
  char     sa_data[14];
};

//
struct addrinfo {
  int ai_flags; // Hint args
  int ai_family; // IPv4 or IPv6
  int ai_socktype; // datagrams or stream
  int ai_protocol; // ?
  char *ai_canonname; // Canonical hostname
  size_t ai_addrlen;
  struct sockaddr *ai_addr;
  struct addrinfo *ai_next;
};

int getaddrinfo(const char *host, const char *service, const struct addrinfo *hints, struct addrinfo **result);
int getnameinfo(const struct sockaddr *sa, socklen_t salen, char *host, size_t hostlen, char *service, size_t servlen, int flags);
void freeaddrinfo(struct addrinfo *result);

int socket(int sockfamily, int socktype, int protocol)
returned: sockfd

int connect()

int bind(int sockfd, struct sockaddr *addr, socklen_t addrlen)
int listen(int sockfd, int backlog)
int accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen)
returned: -1/0

*/


typedef struct sockaddr SA;

// sockaddr_storage;

int open_listenfd(char *port);
int open_clientfd(char *hostname, char *port);
