#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

#define SIZE 100
#define MAXARGS 100
#define MAXLINE 100

void handler(int sig) {

}

int parseline(const char *cmdline, char **argv)
{
    static char array[MAXLINE];   /* holds local copy of command line */
    char *buf = array;            /* ptr that traverses command line */
    char *delim;                  /* points to first space delimiter */
    int argc;                     /* number of args */
    int bg;                       /* background job? */

    strcpy(buf, cmdline);
    buf[strlen(buf)-1] = ' ';     /* replace trailing '\n' with space */
    while (*buf && (*buf == ' ')) /* ignore leading spaces */
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

void binkill() {
  char *argv[MAXARGS];
  char *cmd = malloc(SIZE);
  // pid_t pid = 10;
  pid_t pid;

  if((pid = fork()) == 0)
    while(1)
      ;

  snprintf(cmd, SIZE, "/bin/kill -9 %d\n", pid);
  printf("%s", cmd);

  parseline(cmd, argv);
  execve(*argv, argv, NULL);
}

int main() {
  binkill();
}
