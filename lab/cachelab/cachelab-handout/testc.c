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

void testMalloc(char *s) {
  if(s != NULL)
    printf("s is not NULL\n");
  else {
    s = malloc(20);
    strcpy(s, "01234567890123456789");
  }
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
  char **s = malloc(32);
  testMalloc(*s++);
  testMalloc(*s);

  printf("s0: %s, s1: %s\n", *s, *(s+1));
  return 1;
  */

  // char *s = calloc(4, sizeof(char));
  /*
  // sizeof struct
  struct char2 { char id; char counter; };
  struct charShort { char id; short counter; };
  struct charInt { char id; int counter; };
  struct charLong { char id; long counter; };
  struct charDouble { char id; double counter; };
  struct shortInt { short id; int counter; };
  struct int2 { int id; int counter; };
  struct intLong { int id; long counter; };

  printf("char2: %ld\n", sizeof(struct char2));
  printf("charShort: %ld\n", sizeof(struct charShort));
  printf("charInt: %ld\n", sizeof(struct charInt));
  printf("charLong: %ld\n", sizeof(struct charLong));
  printf("charDouble: %ld\n", sizeof(struct charDouble));
  printf("shortInt: %ld\n", sizeof(struct shortInt));
  printf("int2: %ld\n", sizeof(struct int2));
  printf("intLong: %ld\n", sizeof(struct intLong));

  */

  /*
  struct line {
    int id;
    int counter;
  } l1, l2, *ls;

  ls = (struct line *)malloc(1);

  l1.counter = 1;
  l2.counter = 2;
  *ls = l1;
  *(ls + 1) = l2;

  printf("%d\n", l1.counter);
  printf("%d\n", l2.counter);
  printf("%d\n", ls->counter);
  printf("%d\n", (ls+1)->counter);
  */
  /*

  */
}
