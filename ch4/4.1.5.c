long sum(long *start, long count) {
  long sum = 0;
  while(count) {
    sum += *start;
    start++;
    count--;
  }

  return sum;
}

/* x86-64
  .L1
    movl $0, %eax
    jmp .L2

  .L3
    addq (%rdi), %rax
    addq $8, %rdi
    subq $1, %rsi

  .L2
    testq %rsi, %rsi
    jne  .L3
    rep; ret
*/

/* Y86-64
  sum:
    irmovq $8, %r8
    irmovq $1, %r9
    xorq %rax, %rax
    andq %rsi, %rsi
    jmp test
  loop:
    mrmovq (%rdi), %r10
    addq %r10, %rax
    addq %r8, %rdi
    subq %r9, %rsi
  test:
    jne loop
    ret
*/

/* p4.3
  sum:
    xorq %rax, %rax
    andq %rsi, %rsi
    jmp test
  loop:
    mrmovq (%rdi), %r10
    addq %r10, %rax
    iaddq $8, %rdi
    iaddq $1, %rsi
  test:
    jne loop
    ret
*/
