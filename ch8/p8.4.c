#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
  int status;
  pid_t pid;

  printf("Start\n");      // line++
  pid = fork();
  printf("%d\n", !pid);   // line += 2
  if(pid == 0)
    printf("Child\n");    // line++
  else if((waitpid(-1, &status, 0) > 0) && ())
    printf("%s\n");       // line++
  printf("Stop\n");       // line += 2
  exit(2);
}

/*
Start
0 / 1
1 / 0
Child
Stop
<status>
Stop
*/
