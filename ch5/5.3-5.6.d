
5.3-5.6.o:     file format elf64-x86-64
5.3-5.6.o
architecture: i386:x86-64, flags 0x00000011:
HAS_RELOC, HAS_SYMS
start address 0x0000000000000000

Sections:
Idx Name          Size      VMA               LMA               File off  Algn
  0 .text         00000358  0000000000000000  0000000000000000  00000040  2**0
                  CONTENTS, ALLOC, LOAD, RELOC, READONLY, CODE
  1 .data         00000000  0000000000000000  0000000000000000  00000398  2**0
                  CONTENTS, ALLOC, LOAD, DATA
  2 .bss          00000000  0000000000000000  0000000000000000  00000398  2**0
                  ALLOC
  3 .comment      00000025  0000000000000000  0000000000000000  00000398  2**0
                  CONTENTS, READONLY
  4 .note.GNU-stack 00000000  0000000000000000  0000000000000000  000003bd  2**0
                  CONTENTS, READONLY
  5 .note.gnu.property 00000020  0000000000000000  0000000000000000  000003c0  2**3
                  CONTENTS, ALLOC, LOAD, READONLY, DATA
  6 .eh_frame     00000138  0000000000000000  0000000000000000  000003e0  2**3
                  CONTENTS, ALLOC, LOAD, RELOC, READONLY, DATA
SYMBOL TABLE:
0000000000000000 l    df *ABS*	0000000000000000 5.3-5.6.c
0000000000000000 l    d  .text	0000000000000000 .text
0000000000000000 l    d  .data	0000000000000000 .data
0000000000000000 l    d  .bss	0000000000000000 .bss
0000000000000000 l    d  .note.GNU-stack	0000000000000000 .note.GNU-stack
0000000000000000 l    d  .note.gnu.property	0000000000000000 .note.gnu.property
0000000000000000 l    d  .eh_frame	0000000000000000 .eh_frame
0000000000000000 l    d  .comment	0000000000000000 .comment
0000000000000000 g     F .text	0000000000000087 new_vec
0000000000000000         *UND*	0000000000000000 _GLOBAL_OFFSET_TABLE_
0000000000000000         *UND*	0000000000000000 malloc
0000000000000000         *UND*	0000000000000000 calloc
0000000000000000         *UND*	0000000000000000 free
0000000000000087 g     F .text	0000000000000015 vec_length
000000000000009c g     F .text	000000000000005c get_vec_element
00000000000000f8 g     F .text	0000000000000093 combine1
0000000000000000         *UND*	0000000000000000 __stack_chk_fail
000000000000018b g     F .text	000000000000009b combine2
0000000000000226 g     F .text	0000000000000016 get_vec_start
000000000000023c g     F .text	0000000000000084 combine3
00000000000002c0 g     F .text	0000000000000085 combine4
0000000000000345 g     F .text	0000000000000013 combine5



Disassembly of section .text:

0000000000000000 <new_vec>:
   0:	f3 0f 1e fa          	endbr64
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 83 ec 20          	sub    $0x20,%rsp
   c:	48 89 7d e8          	mov    %rdi,-0x18(%rbp)
  10:	bf 10 00 00 00       	mov    $0x10,%edi
  15:	e8 00 00 00 00       	callq  1a <new_vec+0x1a>
			16: R_X86_64_PLT32	malloc-0x4
  1a:	48 89 45 f8          	mov    %rax,-0x8(%rbp)
  1e:	48 c7 45 f0 00 00 00 	movq   $0x0,-0x10(%rbp)
  25:	00
  26:	48 83 7d f8 00       	cmpq   $0x0,-0x8(%rbp)
  2b:	75 07                	jne    34 <new_vec+0x34>
  2d:	b8 00 00 00 00       	mov    $0x0,%eax
  32:	eb 51                	jmp    85 <new_vec+0x85>
  34:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  38:	48 8b 55 e8          	mov    -0x18(%rbp),%rdx
  3c:	48 89 10             	mov    %rdx,(%rax)
  3f:	48 83 7d e8 00       	cmpq   $0x0,-0x18(%rbp)
  44:	7e 2f                	jle    75 <new_vec+0x75>
  46:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
  4a:	be 08 00 00 00       	mov    $0x8,%esi
  4f:	48 89 c7             	mov    %rax,%rdi
  52:	e8 00 00 00 00       	callq  57 <new_vec+0x57>
			53: R_X86_64_PLT32	calloc-0x4
  57:	48 89 45 f0          	mov    %rax,-0x10(%rbp)
  5b:	48 83 7d f0 00       	cmpq   $0x0,-0x10(%rbp)
  60:	75 13                	jne    75 <new_vec+0x75>
  62:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  66:	48 89 c7             	mov    %rax,%rdi
  69:	e8 00 00 00 00       	callq  6e <new_vec+0x6e>
			6a: R_X86_64_PLT32	free-0x4
  6e:	b8 00 00 00 00       	mov    $0x0,%eax
  73:	eb 10                	jmp    85 <new_vec+0x85>
  75:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  79:	48 8b 55 f0          	mov    -0x10(%rbp),%rdx
  7d:	48 89 50 08          	mov    %rdx,0x8(%rax)
  81:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  85:	c9                   	leaveq
  86:	c3                   	retq

0000000000000087 <vec_length>:
  87:	f3 0f 1e fa          	endbr64
  8b:	55                   	push   %rbp
  8c:	48 89 e5             	mov    %rsp,%rbp
  8f:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
  93:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  97:	48 8b 00             	mov    (%rax),%rax
  9a:	5d                   	pop    %rbp
  9b:	c3                   	retq

000000000000009c <get_vec_element>:
  9c:	f3 0f 1e fa          	endbr64
  a0:	55                   	push   %rbp
  a1:	48 89 e5             	mov    %rsp,%rbp
  a4:	48 83 ec 18          	sub    $0x18,%rsp
  a8:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
  ac:	48 89 75 f0          	mov    %rsi,-0x10(%rbp)
  b0:	48 89 55 e8          	mov    %rdx,-0x18(%rbp)
  b4:	48 83 7d f0 00       	cmpq   $0x0,-0x10(%rbp)
  b9:	78 12                	js     cd <get_vec_element+0x31>
  bb:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  bf:	48 89 c7             	mov    %rax,%rdi
  c2:	e8 00 00 00 00       	callq  c7 <get_vec_element+0x2b>
			c3: R_X86_64_PLT32	vec_length-0x4
  c7:	48 39 45 f0          	cmp    %rax,-0x10(%rbp)
  cb:	7c 07                	jl     d4 <get_vec_element+0x38>
  cd:	b8 00 00 00 00       	mov    $0x0,%eax
  d2:	eb 22                	jmp    f6 <get_vec_element+0x5a>
  d4:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  d8:	48 8b 40 08          	mov    0x8(%rax),%rax
  dc:	48 8b 55 f0          	mov    -0x10(%rbp),%rdx
  e0:	48 c1 e2 03          	shl    $0x3,%rdx
  e4:	48 01 d0             	add    %rdx,%rax
  e7:	48 8b 10             	mov    (%rax),%rdx
  ea:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
  ee:	48 89 10             	mov    %rdx,(%rax)
  f1:	b8 01 00 00 00       	mov    $0x1,%eax
  f6:	c9                   	leaveq
  f7:	c3                   	retq

00000000000000f8 <combine1>:
  f8:	f3 0f 1e fa          	endbr64
  fc:	55                   	push   %rbp
  fd:	48 89 e5             	mov    %rsp,%rbp
 100:	48 83 ec 30          	sub    $0x30,%rsp
 104:	48 89 7d d8          	mov    %rdi,-0x28(%rbp)
 108:	48 89 75 d0          	mov    %rsi,-0x30(%rbp)
 10c:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
 113:	00 00
 115:	48 89 45 f8          	mov    %rax,-0x8(%rbp)
 119:	31 c0                	xor    %eax,%eax
 11b:	48 8b 45 d0          	mov    -0x30(%rbp),%rax
 11f:	48 c7 00 01 00 00 00 	movq   $0x1,(%rax)
 126:	48 c7 45 f0 00 00 00 	movq   $0x0,-0x10(%rbp)
 12d:	00
 12e:	eb 32                	jmp    162 <combine1+0x6a>
 130:	48 8d 55 e8          	lea    -0x18(%rbp),%rdx
 134:	48 8b 4d f0          	mov    -0x10(%rbp),%rcx
 138:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
 13c:	48 89 ce             	mov    %rcx,%rsi
 13f:	48 89 c7             	mov    %rax,%rdi
 142:	e8 00 00 00 00       	callq  147 <combine1+0x4f>
			143: R_X86_64_PLT32	get_vec_element-0x4
 147:	48 8b 45 d0          	mov    -0x30(%rbp),%rax
 14b:	48 8b 10             	mov    (%rax),%rdx
 14e:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
 152:	48 0f af d0          	imul   %rax,%rdx
 156:	48 8b 45 d0          	mov    -0x30(%rbp),%rax
 15a:	48 89 10             	mov    %rdx,(%rax)
 15d:	48 83 45 f0 01       	addq   $0x1,-0x10(%rbp)
 162:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
 166:	48 89 c7             	mov    %rax,%rdi
 169:	e8 00 00 00 00       	callq  16e <combine1+0x76>
			16a: R_X86_64_PLT32	vec_length-0x4
 16e:	48 39 45 f0          	cmp    %rax,-0x10(%rbp)
 172:	7c bc                	jl     130 <combine1+0x38>
 174:	90                   	nop
 175:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
 179:	64 48 33 04 25 28 00 	xor    %fs:0x28,%rax
 180:	00 00
 182:	74 05                	je     189 <combine1+0x91>
 184:	e8 00 00 00 00       	callq  189 <combine1+0x91>
			185: R_X86_64_PLT32	__stack_chk_fail-0x4
 189:	c9                   	leaveq
 18a:	c3                   	retq

000000000000018b <combine2>:
 18b:	f3 0f 1e fa          	endbr64
 18f:	55                   	push   %rbp
 190:	48 89 e5             	mov    %rsp,%rbp
 193:	48 83 ec 30          	sub    $0x30,%rsp
 197:	48 89 7d d8          	mov    %rdi,-0x28(%rbp)
 19b:	48 89 75 d0          	mov    %rsi,-0x30(%rbp)
 19f:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
 1a6:	00 00
 1a8:	48 89 45 f8          	mov    %rax,-0x8(%rbp)
 1ac:	31 c0                	xor    %eax,%eax
 1ae:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
 1b2:	48 89 c7             	mov    %rax,%rdi
 1b5:	e8 00 00 00 00       	callq  1ba <combine2+0x2f>
			1b6: R_X86_64_PLT32	vec_length-0x4
 1ba:	48 89 45 f0          	mov    %rax,-0x10(%rbp)
 1be:	48 8b 45 d0          	mov    -0x30(%rbp),%rax
 1c2:	48 c7 00 01 00 00 00 	movq   $0x1,(%rax)
 1c9:	48 c7 45 e8 00 00 00 	movq   $0x0,-0x18(%rbp)
 1d0:	00
 1d1:	eb 32                	jmp    205 <combine2+0x7a>
 1d3:	48 8d 55 e0          	lea    -0x20(%rbp),%rdx
 1d7:	48 8b 4d e8          	mov    -0x18(%rbp),%rcx
 1db:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
 1df:	48 89 ce             	mov    %rcx,%rsi
 1e2:	48 89 c7             	mov    %rax,%rdi
 1e5:	e8 00 00 00 00       	callq  1ea <combine2+0x5f>
			1e6: R_X86_64_PLT32	get_vec_element-0x4
 1ea:	48 8b 45 d0          	mov    -0x30(%rbp),%rax
 1ee:	48 8b 10             	mov    (%rax),%rdx
 1f1:	48 8b 45 e0          	mov    -0x20(%rbp),%rax
 1f5:	48 0f af d0          	imul   %rax,%rdx
 1f9:	48 8b 45 d0          	mov    -0x30(%rbp),%rax
 1fd:	48 89 10             	mov    %rdx,(%rax)
 200:	48 83 45 e8 01       	addq   $0x1,-0x18(%rbp)
 205:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
 209:	48 3b 45 f0          	cmp    -0x10(%rbp),%rax
 20d:	7c c4                	jl     1d3 <combine2+0x48>
 20f:	90                   	nop
 210:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
 214:	64 48 33 04 25 28 00 	xor    %fs:0x28,%rax
 21b:	00 00
 21d:	74 05                	je     224 <combine2+0x99>
 21f:	e8 00 00 00 00       	callq  224 <combine2+0x99>
			220: R_X86_64_PLT32	__stack_chk_fail-0x4
 224:	c9                   	leaveq
 225:	c3                   	retq

0000000000000226 <get_vec_start>:
 226:	f3 0f 1e fa          	endbr64
 22a:	55                   	push   %rbp
 22b:	48 89 e5             	mov    %rsp,%rbp
 22e:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
 232:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
 236:	48 8b 40 08          	mov    0x8(%rax),%rax
 23a:	5d                   	pop    %rbp
 23b:	c3                   	retq

000000000000023c <combine3>:
 23c:	f3 0f 1e fa          	endbr64
 240:	55                   	push   %rbp
 241:	48 89 e5             	mov    %rsp,%rbp
 244:	48 83 ec 30          	sub    $0x30,%rsp
 248:	48 89 7d d8          	mov    %rdi,-0x28(%rbp)
 24c:	48 89 75 d0          	mov    %rsi,-0x30(%rbp)
 250:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
 254:	48 89 c7             	mov    %rax,%rdi
 257:	e8 00 00 00 00       	callq  25c <combine3+0x20>
			258: R_X86_64_PLT32	vec_length-0x4
 25c:	48 89 45 f0          	mov    %rax,-0x10(%rbp)
 260:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
 264:	48 89 c7             	mov    %rax,%rdi
 267:	e8 00 00 00 00       	callq  26c <combine3+0x30>
			268: R_X86_64_PLT32	get_vec_start-0x4
 26c:	48 89 45 f8          	mov    %rax,-0x8(%rbp)
 270:	48 8b 45 d0          	mov    -0x30(%rbp),%rax
 274:	48 c7 00 01 00 00 00 	movq   $0x1,(%rax)         # *dest = IDENT
 27b:	48 c7 45 e8 00 00 00 	movq   $0x0,-0x18(%rbp)    # i = 0
 282:	00
 283:	eb 2d                	jmp    2b2 <combine3+0x76>
 285:	48 8b 45 d0          	mov    -0x30(%rbp),%rax
 289:	48 8b 10             	mov    (%rax),%rdx
 28c:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
 290:	48 8d 0c c5 00 00 00 	lea    0x0(,%rax,8),%rcx
 297:	00
 298:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
 29c:	48 01 c8             	add    %rcx,%rax
 29f:	48 8b 00             	mov    (%rax),%rax
 2a2:	48 0f af d0          	imul   %rax,%rdx          # %rax: data[i], %rdx: dest
 2a6:	48 8b 45 d0          	mov    -0x30(%rbp),%rax
 2aa:	48 89 10             	mov    %rdx,(%rax)
 2ad:	48 83 45 e8 01       	addq   $0x1,-0x18(%rbp)   # i++
 2b2:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
 2b6:	48 3b 45 f0          	cmp    -0x10(%rbp),%rax
 2ba:	7c c9                	jl     285 <combine3+0x49>
 2bc:	90                   	nop
 2bd:	90                   	nop
 2be:	c9                   	leaveq
 2bf:	c3                   	retq

00000000000002c0 <combine4>:
 2c0:	f3 0f 1e fa          	endbr64
 2c4:	55                   	push   %rbp
 2c5:	48 89 e5             	mov    %rsp,%rbp
 2c8:	48 83 ec 30          	sub    $0x30,%rsp
 2cc:	48 89 7d d8          	mov    %rdi,-0x28(%rbp)
 2d0:	48 89 75 d0          	mov    %rsi,-0x30(%rbp)
 2d4:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
 2d8:	48 89 c7             	mov    %rax,%rdi
 2db:	e8 00 00 00 00       	callq  2e0 <combine4+0x20>
			2dc: R_X86_64_PLT32	vec_length-0x4
 2e0:	48 89 45 f0          	mov    %rax,-0x10(%rbp)
 2e4:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
 2e8:	48 89 c7             	mov    %rax,%rdi
 2eb:	e8 00 00 00 00       	callq  2f0 <combine4+0x30>
			2ec: R_X86_64_PLT32	get_vec_start-0x4
 2f0:	48 89 45 f8          	mov    %rax,-0x8(%rbp)
 2f4:	48 c7 45 e8 01 00 00 	movq   $0x1,-0x18(%rbp)
 2fb:	00
 2fc:	48 c7 45 e0 00 00 00 	movq   $0x0,-0x20(%rbp)
 303:	00
 304:	eb 27                	jmp    32d <combine4+0x6d>
 306:	48 8b 45 e0          	mov    -0x20(%rbp),%rax
 30a:	48 8d 14 c5 00 00 00 	lea    0x0(,%rax,8),%rdx
 311:	00
 312:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
 316:	48 01 d0             	add    %rdx,%rax
 319:	48 8b 00             	mov    (%rax),%rax
 31c:	48 8b 55 e8          	mov    -0x18(%rbp),%rdx
 320:	48 0f af c2          	imul   %rdx,%rax
 324:	48 89 45 e8          	mov    %rax,-0x18(%rbp)
 328:	48 83 45 e0 01       	addq   $0x1,-0x20(%rbp)
 32d:	48 8b 45 e0          	mov    -0x20(%rbp),%rax
 331:	48 3b 45 f0          	cmp    -0x10(%rbp),%rax
 335:	7c cf                	jl     306 <combine4+0x46>
 337:	48 8b 45 d0          	mov    -0x30(%rbp),%rax
 33b:	48 8b 55 e8          	mov    -0x18(%rbp),%rdx
 33f:	48 89 10             	mov    %rdx,(%rax)
 342:	90                   	nop
 343:	c9                   	leaveq
 344:	c3                   	retq

0000000000000345 <combine5>:
 345:	f3 0f 1e fa          	endbr64
 349:	55                   	push   %rbp
 34a:	48 89 e5             	mov    %rsp,%rbp
 34d:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
 351:	48 89 75 f0          	mov    %rsi,-0x10(%rbp)
 355:	90                   	nop
 356:	5d                   	pop    %rbp
 357:	c3                   	retq
