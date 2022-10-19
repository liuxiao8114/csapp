#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[], char *envp[]) {
  int i;
  printf("Command-line arguments: \n");
  for(i = 0; *argv != NULL; argv++, i++)
    printf("\targv[%2d]: %s\n", i, *argv);

  printf("\n");
  printf("Environment variables: \n");
  for(i = 0; *envp != NULL; envp++, i++)
    printf("\tenvp[%2d]: %s\n", i, *envp);
}
