
typedef struct {
  int maxfd;
  fd_set read_set;
  fd_set ready_set;
  int maxi;
  int clientfd[FD_SETSIZE];
  rio_t clientrio[FD_SETSIZE];
} Pool;

void init_pool(int, Pool *);


int byte_cnt = 0;

int main() {
  int listenfd, connfd;
  socklen_t clientlen;
  struct sockaddr_storage clientaddr;
  static Pool pool;

  if (argc != 2) {
    fprintf(stderr, "usage: %s <port>\n", argv[0]);
    exit(0);
  }

  listenfd = Open_listenfd(argv[1]);
  init_pool(listenfd, &pool);

  while(1) {
    pool.ready_set = pool.read_set;
    pool.nready = select(pool.maxfd + 1, &pool.ready_set, NULL, NULL, NULL);
  }
}

void init_pool(int fd, Pool *p) {
  for() {
    
  }

  p->maxfd = listenfd;
  FD_ZERO(&p->read_set);
  FD_SET(listen, p->read_set);
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
 /* Wait for listening/connected descriptor(s) to become ready */
 pool.ready_set = pool.read_set;
 pool.nready = Select(pool.maxfd+1, &pool.ready_set, NULL, NULL, NULL);

 /* If listening descriptor ready, add new client to pool */
 if (FD_ISSET(listenfd, &pool.ready_set)) {
 clientlen = sizeof(struct sockaddr_storage);
 connfd = Accept(listenfd, (SA *)&clientaddr, &clientlen);
 add_client(connfd, &pool);
 }

 /* Echo a text line from each ready connected descriptor */
 check_clients(&pool);
 }
 }
*/
