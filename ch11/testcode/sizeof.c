#include <stdio.h>

typedef struct nodeA {
  struct node *next;
  int content[10];
} NodeA;

typedef struct nodeB {
  struct node *next;
  int *content;
} NodeB;

int main() {
  printf("structA: %ld\n", sizeof(struct nodeA));
  printf("unionA: %ld\n", sizeof(NodeA));
  printf("structB: %ld\n", sizeof(struct nodeB));
  printf("unionB: %ld\n", sizeof(NodeB));

  NodeB n;
  n.content = malloc(16);
}
