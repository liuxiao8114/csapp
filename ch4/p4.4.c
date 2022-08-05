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
    subq $1, %rsi
    addq $8, %rdi
    call .L1
    imulq %rbx, %rax
    popq %rbx
  .L2:
    ret

.LFB0:
  pushq %rbp
  movq %rsp, %rbp
  pushq %rbx
  subq $24, %rsp
  movq %rdi, -24(%rsp)
  movq %rsi, -32(%rsp)
  cmpq $1, -32(%rsp)
  jg .L2
  movl $1, %eax
  jmp .L3
.L2

*/

/*
  .L1:
    push %rbp
    push %r10
    irmovq $1, %rbp
    rrmovq %rsi, %r10
    irmovq $1, %rax
    subq $1, %r10
    jge
  .L2:
    push %rbx

*/
