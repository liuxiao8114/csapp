#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int atoh(char *s) {
  int ret = 0;

  for(; *s != '\0'; s++) {
    if(*s >= '0' && *s <= '9')
      ret = ret * 16 + *s - '0';
    else if((*s >= 'a' && *s <= 'f'))
      ret = ret * 16 + *s - 'a' + 10;
    else if((*s >= 'A' && *s <= 'F'))
      ret = ret * 16 + *s - 'A' + 10;
    else {
      printf("error s: %s\n", s);
      return -1;
    }
  }

  return ret;
}

int main() {
  /*
  // array and pointer set value.
  char c[10];
  char *s = c;
  *s++ = '1';
  *s++ = '1';
  *s = '\0';
  printf("%s\n", s);
  printf("%s\n", c);
  */

  /*
  // atoh
  printf("ff: 0x%d\n", atoh("ff"));
  printf("01: 0x%d\n", atoh("01"));
  printf("100: 0x%d\n", atoh("100"));
  */

  /*


  */
  char *s = malloc(10);
  if(!*s)
    printf("ifs%s\n", s);
  if((s+1) == NULL)
    printf("ifs%s\n", s);
}
