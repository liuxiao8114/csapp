struct ACE {
  short v;
  struct ACE *p;
}

short test(struct ACE *ptr) {
  int i;
  i = 1;

  while(ptr) {
    i *= ptr->v;
    ptr = ptr->p;
  }

  return i;
}

/*
1     test:
2         movl $1, %eax
3         jmp .L2
4     .L3:
5         imulq (%rdi), %rax
6         movq 2(%rdi), %rdi
7     .L2:
8         testq %rdi, %rdi
9         jne .L3
10        rep; ret
*/
