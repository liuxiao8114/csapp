#include <string.h>
#include <stdio.h>
#include <unistd.h>

#define MAXLINE    1024   /* max line size */
#define MAXARGS     128   /* max args on a command line */

int parseline(char *cmdline, char **argv) {
  static char array[MAXLINE];
  char *buf = array;
  char *delim;
  int argc;
  int bg;

  strcpy(buf, cmdline);
  buf[strlen(buf) - 1] = ' ';
  while(*buf && (*buf == ' '))
    buf++;

    /* Build the argv list */
    argc = 0;
    if (*buf == '\'') {
	     buf++;
	     delim = strchr(buf, '\'');
    }
    else {
	     delim = strchr(buf, ' ');
    }

    while (delim) {
    	argv[argc++] = buf;
    	*delim = '\0';
    	buf = delim + 1;
    	while (*buf && (*buf == ' ')) /* ignore spaces */
    	    buf++;

    	if (*buf == '\'') {
    	    buf++;
    	    delim = strchr(buf, '\'');
    	}
    	else {
    	    delim = strchr(buf, ' ');
    	}
    }
    argv[argc] = NULL;

    if (argc == 0)  /* ignore blank line */
	     return 1;

    /* should the job run in the background? */
    if ((bg = (*argv[argc-1] == '&')) != 0) {
	     argv[--argc] = NULL;
    }
    return bg;
}

int main(int argc, char **argv) {
  char *argv2[MAXARGS];
  char buf[MAXLINE];
  int bg;
  pid_t pid;

  strcpy(buf, "/bin/echo tsh> quit\n");

  parseline(buf, argv2);
  printf("argv0: %s\n", *argv2);
  printf("argv1: %s\n", argv2[1]);
  printf("argv2: %s\n", argv2[2]);
}
