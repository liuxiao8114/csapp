#include "../textcode/12.h"

void testReadnb(char *);
void testReadlineb(char *);
void testWritten(char *);

int main() {
  char *filename = "testfile";

  testReadnb(filename);
  testReadlineb(filename);
  testWritten(filename);
}

void testReadnb(char *filename) {
  rio_t rp;
  char buf[RIO_BUFSIZE];

  int test = open(filename, O_RDONLY, 0);
  int step = 10;
  int n = 6;
  int i, j;
  ssize_t rc;

  rio_readinitb(&rp, test);

  // test rio_readnb
  for(i = 0; i < n; i++) {
    rc = rio_readnb(&rp, buf, step);
    buf[rc] = 0;

    printf("%d: ", i);
    for(j = 0; j < rc; j++)
      printf("%2x ", buf[j]);
    printf("\n");
  }
}

void testReadlineb(char *filename) {
  rio_t rp;
  char buf[RIO_BUFSIZE];

  int test = open(filename, O_RDONLY, 0);
  int step = 10;
  int n = 6;
  int i;

  rio_readinitb(&rp, test);
  printf("------------------------\n");

  // test rio_readlineb
  for(i = 0; i < n; i++) {
    rio_readlineb(&rp, buf, MAXLINE);
    printf("%d: %s\n", i, buf);
  }
}

void testWritten(char *filename) {
  rio_t rp;
  int test = open(filename, O_RDWR | O_APPEND, 0);
  char *content = "add this content in the end.";
  rio_readinitb(&rp, test);

  rio_written(&rp, content, sizeof(content));
}

void testOpenClient(char *hostname, char *port) {
  int clientfd = open_clientfd(hostname, port);
  rio_t rio;

  rio_readinitb(&rio, clientfd);
  
}

void testOpenListen(char *port) {
  int listenfd = open_listenfd(port);

  while(1) {

  }
}
