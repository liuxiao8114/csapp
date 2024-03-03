#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 1000

int main() {
  char *FILENAME = "yi.trace";
  FILE *file = fopen(FILENAME, "r");
  char c;
  char buf[MAXLINE];

  // while((c = fgetc(file)) != EOF) {
  //   if(c == '\n')
  //     printf("\n");
  //   else
  //     printf("%c", c);
  // }
  while(fgets(buf, MAXLINE, file) != NULL) {
    printf("%s", buf);
  }
}
