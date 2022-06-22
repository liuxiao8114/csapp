#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  char shellcode[] = "mov (6044e4), %rdi; mov $addr %rax; ret";
  int ret = 123;  // set ret to touch2()
  char *command = (char *)malloc(200);

  strcpy(command, "./ctarget -q ");
  // strcat(command, "\'");
  system(command);

  return 0;
}

// ./ ctarget
