#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINE 1000

int main() {
  char cmdline[MAXLINE];
  char *prompt = "tsh> ";
  int emit_prompt = 1; /* emit prompt (default) */

  if(emit_prompt) {
    printf("%s", prompt);
    fflush(stdout);
  }

  fgets(cmdline, MAXLINE, stdin);
  printf("strlen: %ld\n", strlen(cmdline));
  cmdline[strlen(cmdline) - 1] = '\0';
  printf("strlen: %ld\n", strlen(cmdline));

  printf("%s: Command not found.\n", cmdline);
  fflush(stdout);
  fflush(stdout);
}
