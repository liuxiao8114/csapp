movq $0, %rax
movq $0, %r2
movq $0, %r3
movq $0, %r4

1
cmovq $1, %rax
2
cmovq $1, %r2
3
cmovq $1, %r3
4
cmovq $1, %r4

add %r3, %r4
add %r2, %rax
add %r4, %rax
