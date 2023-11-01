
p5.5.o:     file format elf64-x86-64
p5.5.o
architecture: i386:x86-64, flags 0x00000011:
HAS_RELOC, HAS_SYMS
start address 0x0000000000000000

Sections:
Idx Name          Size      VMA               LMA               File off  Algn
  0 .text         00000085  0000000000000000  0000000000000000  00000040  2**0
                  CONTENTS, ALLOC, LOAD, READONLY, CODE
  1 .data         00000000  0000000000000000  0000000000000000  000000c5  2**0
                  CONTENTS, ALLOC, LOAD, DATA
  2 .bss          00000000  0000000000000000  0000000000000000  000000c5  2**0
                  ALLOC
  3 .comment      00000025  0000000000000000  0000000000000000  000000c5  2**0
                  CONTENTS, READONLY
  4 .note.GNU-stack 00000000  0000000000000000  0000000000000000  000000ea  2**0
                  CONTENTS, READONLY
  5 .note.gnu.property 00000020  0000000000000000  0000000000000000  000000f0  2**3
                  CONTENTS, ALLOC, LOAD, READONLY, DATA
  6 .eh_frame     00000038  0000000000000000  0000000000000000  00000110  2**3
                  CONTENTS, ALLOC, LOAD, RELOC, READONLY, DATA
SYMBOL TABLE:
0000000000000000 l    df *ABS*	0000000000000000 p5.5.c
0000000000000000 l    d  .text	0000000000000000 .text
0000000000000000 l    d  .data	0000000000000000 .data
0000000000000000 l    d  .bss	0000000000000000 .bss
0000000000000000 l    d  .note.GNU-stack	0000000000000000 .note.GNU-stack
0000000000000000 l    d  .note.gnu.property	0000000000000000 .note.gnu.property
0000000000000000 l    d  .eh_frame	0000000000000000 .eh_frame
0000000000000000 l    d  .comment	0000000000000000 .comment
0000000000000000 g     F .text	0000000000000085 poly



Disassembly of section .text:

0000000000000000 <poly>:
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 89 7d d8          	mov    %rdi,-0x28(%rbp)
   c:	f2 0f 11 45 d0       	movsd  %xmm0,-0x30(%rbp)
  11:	48 89 75 c8          	mov    %rsi,-0x38(%rbp)
  15:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
  19:	f2 0f 10 00          	movsd  (%rax),%xmm0
  1d:	f2 0f 11 45 f0       	movsd  %xmm0,-0x10(%rbp)
  22:	f2 0f 10 45 d0       	movsd  -0x30(%rbp),%xmm0
  27:	f2 0f 11 45 f8       	movsd  %xmm0,-0x8(%rbp)
  2c:	48 c7 45 e8 01 00 00 	movq   $0x1,-0x18(%rbp)
  33:	00 
  34:	eb 3e                	jmp    74 <poly+0x74>
  36:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
  3a:	48 8d 14 c5 00 00 00 	lea    0x0(,%rax,8),%rdx
  41:	00 
  42:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
  46:	48 01 d0             	add    %rdx,%rax
  49:	f2 0f 10 00          	movsd  (%rax),%xmm0
  4d:	f2 0f 59 45 f8       	mulsd  -0x8(%rbp),%xmm0
  52:	f2 0f 10 4d f0       	movsd  -0x10(%rbp),%xmm1
  57:	f2 0f 58 c1          	addsd  %xmm1,%xmm0
  5b:	f2 0f 11 45 f0       	movsd  %xmm0,-0x10(%rbp)
  60:	f2 0f 10 45 f8       	movsd  -0x8(%rbp),%xmm0
  65:	f2 0f 59 45 d0       	mulsd  -0x30(%rbp),%xmm0
  6a:	f2 0f 11 45 f8       	movsd  %xmm0,-0x8(%rbp)
  6f:	48 83 45 e8 01       	addq   $0x1,-0x18(%rbp)
  74:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
  78:	48 3b 45 c8          	cmp    -0x38(%rbp),%rax
  7c:	7e b8                	jle    36 <poly+0x36>
  7e:	f2 0f 10 45 f0       	movsd  -0x10(%rbp),%xmm0
  83:	5d                   	pop    %rbp
  84:	c3                   	retq   
