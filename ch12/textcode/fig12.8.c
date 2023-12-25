/* Figure 12.8 Concurrent echo server based on I/O multiplexing */
#include "12.h"

typedef struct {
  int maxfd;
  fd_set read_set;
  fd_set ready_set;
  int nready;
  int maxi;
  int clientfd[FD_SETSIZE];
  rio_t clientrio[FD_SETSIZE];
} Pool;

void init_pool(int, Pool *);

int byte_cnt = 0;

int main(int argc, char *argv[]) {
  int listenfd, connfd;
  socklen_t clientlen;
  struct sockaddr_storage clientaddr;
  static Pool pool;

  if (argc != 2) {
    fprintf(stderr, "usage: %s <port>\n", argv[0]);
    exit(0);
  }

  listenfd = open_listenfd(argv[1]);
  init_pool(listenfd, &pool);

  while(1) {
    pool.ready_set = pool.read_set;
    pool.nready = select(pool.maxfd + 1, &pool.ready_set, NULL, NULL, NULL);

    /* If the listenfd is ready, add the client into pool.*/
    if(FD_ISSET(listenfd, &pool.ready_set)) {
      clientlen = sizeof(struct sockaddr_storage);
      connfd = accept(listenfd, (SA *)&clientaddr, &clientlen);
      add_client(connfd, &pool);
    }

    check_clients(&pool);
  }
}

/* Figure 12.9 init_pool initializes the pool of active clients. */
void init_pool(int fd, Pool *p) {
  int i;
  p->maxi = -1;
  for(i = 0; i < FD_SETSIZE; i++)
    p->clientfd[i] = -1;

  p->maxfd = fd;
  FD_ZERO(&p->read_set);
  FD_SET(fd, &p->read_set);
}

/* Figure 12.10 add_client adds a new client connection to the pool. */
void add_client(int connfd, Pool *p) {
  int i;
  p->nready--;

  for (i = 0; i < FD_SETSIZE; i++) { /* Find an available slot */
    if(p->clientfd[i] < 0) {
      p->clientfd[i] = connfd;
      FD_SET(connfd, &p->read_set);
    }
  }

  if(i == FD_SETSIZE)
    app_error("add_client error: Too many clients");
}

/* Figure 12.11 check_clients services ready client connections */
void check_clients(Pool *p) {
  int i, connfd, n;
  char buf[MAXLINE];
  rio_t rio;

  for(i = 0; i < ) {
    
  }
}

/*

 int listenfd, connfd;
 socklen_t clientlen;
 struct sockaddr_storage clientaddr;
 static pool pool;

 if (argc != 2) {
 fprintf(stderr, "usage: %s <port>\n", argv[0]);
 exit(0);
 }
 listenfd = Open_listenfd(argv[1]);
 init_pool(listenfd, &pool);

 while (1) {
 pool.ready_set = pool.read_set;
 pool.nready = Select(pool.maxfd+1, &pool.ready_set, NULL, NULL, NULL);

 if (FD_ISSET(listenfd, &pool.ready_set)) {
 clientlen = sizeof(struct sockaddr_storage);
 connfd = Accept(listenfd, (SA *)&clientaddr, &clientlen);
 add_client(connfd, &pool);
 }

 check_clients(&pool);
 }
 }
*/
