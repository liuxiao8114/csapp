/* Fig 8.24 eval evaluates the shell command line. */
void eval(char *cmdline) {
  char *argv[MAXARGS];
  char buf[MAXLINE];
  int bg;
  pid_t pid;

  strcpy(buf, cmdline);
  bg = parseline(buf, argv);

  if(argv[0] == NULL)
    return;

  if(!builtin_command(argv)) {
    if((pid = fork()) == 0) {
      if(execve(argv[0], argv, environ) < 0) {
        printf("%s\n", argv[0]);
        exit(0);
      }
    }

    if(!bg) {

    }
    else

  }

  return;
}

int builtin_command(char **argv) {
  return 0; // Note a builtin command
}
