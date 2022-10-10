/* Fig 8.23 The main routine for a simple shell program. */
void eval(char *cmdline);

int main() {
  char cmdline[MAXLINE];

  while(1) {
    // Read
    printf("> ");
    fgets(cmdline, MAXLINE, stdin);
    if(feof(stdin))
      exit(0);

    // Evaluate
    eval(cmdline);
  }
}
