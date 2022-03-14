long rproduct(long *start, long count) {
  if(count <= 1)
    return 1;
  return *start * rproduct(start + 1, count - 1);
}

/* x86-64
  .L1:
    movq $1, %rax
    cmpq $1, %rsi
    jle .L2
    pushq %rbx
    movq (%rdi), %rbx
    addq $8, %rdi
    subq $1, %rsi
    call .L1
    imulq %rbx, %rax
    popq %rbx
    ret


  .L2:
    ret
*/

/*
  .L1:
    push %rbp
    push %r10
    movq $1, %rbp
    movq %rsi, %r10
    irmovq $1, %rax
    subq $1, %r10
    jge
  .L2:
    push %rbx

*/
