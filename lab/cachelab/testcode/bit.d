
bits:     file format elf64-x86-64


Disassembly of section .init:

0000000000001000 <_init>:
    1000:	f3 0f 1e fa          	endbr64
    1004:	48 83 ec 08          	sub    $0x8,%rsp
    1008:	48 8b 05 d9 2f 00 00 	mov    0x2fd9(%rip),%rax        # 3fe8 <__gmon_start__>
    100f:	48 85 c0             	test   %rax,%rax
    1012:	74 02                	je     1016 <_init+0x16>
    1014:	ff d0                	callq  *%rax
    1016:	48 83 c4 08          	add    $0x8,%rsp
    101a:	c3                   	retq

Disassembly of section .plt:

0000000000001020 <.plt>:
    1020:	ff 35 9a 2f 00 00    	pushq  0x2f9a(%rip)        # 3fc0 <_GLOBAL_OFFSET_TABLE_+0x8>
    1026:	f2 ff 25 9b 2f 00 00 	bnd jmpq *0x2f9b(%rip)        # 3fc8 <_GLOBAL_OFFSET_TABLE_+0x10>
    102d:	0f 1f 00             	nopl   (%rax)
    1030:	f3 0f 1e fa          	endbr64
    1034:	68 00 00 00 00       	pushq  $0x0
    1039:	f2 e9 e1 ff ff ff    	bnd jmpq 1020 <.plt>
    103f:	90                   	nop

Disassembly of section .plt.got:

0000000000001040 <__cxa_finalize@plt>:
    1040:	f3 0f 1e fa          	endbr64
    1044:	f2 ff 25 ad 2f 00 00 	bnd jmpq *0x2fad(%rip)        # 3ff8 <__cxa_finalize@GLIBC_2.2.5>
    104b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

Disassembly of section .plt.sec:

0000000000001050 <__stack_chk_fail@plt>:
    1050:	f3 0f 1e fa          	endbr64
    1054:	f2 ff 25 75 2f 00 00 	bnd jmpq *0x2f75(%rip)        # 3fd0 <__stack_chk_fail@GLIBC_2.4>
    105b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

Disassembly of section .text:

0000000000001060 <_start>:
    1060:	f3 0f 1e fa          	endbr64
    1064:	31 ed                	xor    %ebp,%ebp
    1066:	49 89 d1             	mov    %rdx,%r9
    1069:	5e                   	pop    %rsi
    106a:	48 89 e2             	mov    %rsp,%rdx
    106d:	48 83 e4 f0          	and    $0xfffffffffffffff0,%rsp
    1071:	50                   	push   %rax
    1072:	54                   	push   %rsp
    1073:	4c 8d 05 b6 05 00 00 	lea    0x5b6(%rip),%r8        # 1630 <__libc_csu_fini>
    107a:	48 8d 0d 3f 05 00 00 	lea    0x53f(%rip),%rcx        # 15c0 <__libc_csu_init>
    1081:	48 8d 3d 82 01 00 00 	lea    0x182(%rip),%rdi        # 120a <main>
    1088:	ff 15 52 2f 00 00    	callq  *0x2f52(%rip)        # 3fe0 <__libc_start_main@GLIBC_2.2.5>
    108e:	f4                   	hlt
    108f:	90                   	nop

0000000000001090 <deregister_tm_clones>:
    1090:	48 8d 3d 79 2f 00 00 	lea    0x2f79(%rip),%rdi        # 4010 <__TMC_END__>
    1097:	48 8d 05 72 2f 00 00 	lea    0x2f72(%rip),%rax        # 4010 <__TMC_END__>
    109e:	48 39 f8             	cmp    %rdi,%rax
    10a1:	74 15                	je     10b8 <deregister_tm_clones+0x28>
    10a3:	48 8b 05 2e 2f 00 00 	mov    0x2f2e(%rip),%rax        # 3fd8 <_ITM_deregisterTMCloneTable>
    10aa:	48 85 c0             	test   %rax,%rax
    10ad:	74 09                	je     10b8 <deregister_tm_clones+0x28>
    10af:	ff e0                	jmpq   *%rax
    10b1:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)
    10b8:	c3                   	retq
    10b9:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

00000000000010c0 <register_tm_clones>:
    10c0:	48 8d 3d 49 2f 00 00 	lea    0x2f49(%rip),%rdi        # 4010 <__TMC_END__>
    10c7:	48 8d 35 42 2f 00 00 	lea    0x2f42(%rip),%rsi        # 4010 <__TMC_END__>
    10ce:	48 29 fe             	sub    %rdi,%rsi
    10d1:	48 89 f0             	mov    %rsi,%rax
    10d4:	48 c1 ee 3f          	shr    $0x3f,%rsi
    10d8:	48 c1 f8 03          	sar    $0x3,%rax
    10dc:	48 01 c6             	add    %rax,%rsi
    10df:	48 d1 fe             	sar    %rsi
    10e2:	74 14                	je     10f8 <register_tm_clones+0x38>
    10e4:	48 8b 05 05 2f 00 00 	mov    0x2f05(%rip),%rax        # 3ff0 <_ITM_registerTMCloneTable>
    10eb:	48 85 c0             	test   %rax,%rax
    10ee:	74 08                	je     10f8 <register_tm_clones+0x38>
    10f0:	ff e0                	jmpq   *%rax
    10f2:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)
    10f8:	c3                   	retq
    10f9:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

0000000000001100 <__do_global_dtors_aux>:
    1100:	f3 0f 1e fa          	endbr64
    1104:	80 3d 05 2f 00 00 00 	cmpb   $0x0,0x2f05(%rip)        # 4010 <__TMC_END__>
    110b:	75 2b                	jne    1138 <__do_global_dtors_aux+0x38>
    110d:	55                   	push   %rbp
    110e:	48 83 3d e2 2e 00 00 	cmpq   $0x0,0x2ee2(%rip)        # 3ff8 <__cxa_finalize@GLIBC_2.2.5>
    1115:	00
    1116:	48 89 e5             	mov    %rsp,%rbp
    1119:	74 0c                	je     1127 <__do_global_dtors_aux+0x27>
    111b:	48 8b 3d e6 2e 00 00 	mov    0x2ee6(%rip),%rdi        # 4008 <__dso_handle>
    1122:	e8 19 ff ff ff       	callq  1040 <__cxa_finalize@plt>
    1127:	e8 64 ff ff ff       	callq  1090 <deregister_tm_clones>
    112c:	c6 05 dd 2e 00 00 01 	movb   $0x1,0x2edd(%rip)        # 4010 <__TMC_END__>
    1133:	5d                   	pop    %rbp
    1134:	c3                   	retq
    1135:	0f 1f 00             	nopl   (%rax)
    1138:	c3                   	retq
    1139:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

0000000000001140 <frame_dummy>:
    1140:	f3 0f 1e fa          	endbr64
    1144:	e9 77 ff ff ff       	jmpq   10c0 <register_tm_clones>

0000000000001149 <trans>:
    1149:	f3 0f 1e fa          	endbr64
    114d:	55                   	push   %rbp
    114e:	48 89 e5             	mov    %rsp,%rbp
    1151:	89 7d dc             	mov    %edi,-0x24(%rbp) # M
    1154:	89 75 d8             	mov    %esi,-0x28(%rbp) # N
    1157:	48 89 55 d0          	mov    %rdx,-0x30(%rbp) # A[][]
    115b:	48 89 4d c8          	mov    %rcx,-0x38(%rbp) # B[][]
    115f:	8b 45 d8             	mov    -0x28(%rbp),%eax # rax = N
    1162:	48 63 d0             	movslq %eax,%rdx        # rdx = N
    1165:	48 83 ea 01          	sub    $0x1,%rdx        # rdx--
    1169:	48 89 55 f0          	mov    %rdx,-0x10(%rbp) #
    116d:	48 63 d0             	movslq %eax,%rdx        # rdx = N
    1170:	49 89 d2             	mov    %rdx,%r10        # r10 = N
    1173:	41 bb 00 00 00 00    	mov    $0x0,%r11d       # r11d= 0
    1179:	8b 55 dc             	mov    -0x24(%rbp),%edx # rdx = M
    117c:	48 63 ca             	movslq %edx,%rcx        # rcx = M
    117f:	48 83 e9 01          	sub    $0x1,%rcx        # rcx--
    1183:	48 89 4d f8          	mov    %rcx,-0x8(%rbp)  #
    1187:	48 63 ca             	movslq %edx,%rcx        # rcx = M
    118a:	49 89 c8             	mov    %rcx,%r8         # r8  = M
    118d:	41 b9 00 00 00 00    	mov    $0x0,%r9d        # r9d = 0
    1193:	c7 45 ec 00 00 00 00 	movl   $0x0,-0x14(%rbp) #
    119a:	eb 63                	jmp    11ff <trans+0xb6>#
    119c:	c7 45 e8 00 00 00 00 	movl   $0x0,-0x18(%rbp)
    11a3:	eb 4e                	jmp    11f3 <trans+0xaa>
    11a5:	8b 4d e8             	mov    -0x18(%rbp),%ecx # rcx = 0
    11a8:	48 63 f1             	movslq %ecx,%rsi        # rsi = 0
    11ab:	48 63 c8             	movslq %eax,%rcx        # rcx = N
    11ae:	48 0f af ce          	imul   %rsi,%rcx        # rcx = N * 0
    11b2:	48 8d 34 8d 00 00 00 	lea    0x0(,%rcx,4),%rsi
    11b9:	00
    11ba:	48 8b 4d d0          	mov    -0x30(%rbp),%rcx # rcx = A
    11be:	48 01 ce             	add    %rcx,%rsi        
    11c1:	8b 4d ec             	mov    -0x14(%rbp),%ecx #
    11c4:	48 63 f9             	movslq %ecx,%rdi
    11c7:	48 63 ca             	movslq %edx,%rcx
    11ca:	48 0f af cf          	imul   %rdi,%rcx
    11ce:	48 8d 3c 8d 00 00 00 	lea    0x0(,%rcx,4),%rdi
    11d5:	00
    11d6:	48 8b 4d c8          	mov    -0x38(%rbp),%rcx
    11da:	48 01 cf             	add    %rcx,%rdi
    11dd:	8b 4d ec             	mov    -0x14(%rbp),%ecx
    11e0:	48 63 c9             	movslq %ecx,%rcx
    11e3:	8b 34 8e             	mov    (%rsi,%rcx,4),%esi
    11e6:	8b 4d e8             	mov    -0x18(%rbp),%ecx
    11e9:	48 63 c9             	movslq %ecx,%rcx
    11ec:	89 34 8f             	mov    %esi,(%rdi,%rcx,4)
    11ef:	83 45 e8 01          	addl   $0x1,-0x18(%rbp)
    11f3:	8b 4d e8             	mov    -0x18(%rbp),%ecx
    11f6:	3b 4d dc             	cmp    -0x24(%rbp),%ecx # for-loop-condiction
    11f9:	7c aa                	jl     11a5 <trans+0x5c># if( < M)
    11fb:	83 45 ec 01          	addl   $0x1,-0x14(%rbp)
    11ff:	8b 4d ec             	mov    -0x14(%rbp),%ecx
    1202:	3b 4d d8             	cmp    -0x28(%rbp),%ecx # for-loop-condiction
    1205:	7c 95                	jl     119c <trans+0x53># if( < N)
    1207:	90                   	nop
    1208:	5d                   	pop    %rbp
    1209:	c3                   	retq

000000000000120a <main>:
    120a:	f3 0f 1e fa          	endbr64
    120e:	55                   	push   %rbp
    120f:	48 89 e5             	mov    %rsp,%rbp
    1212:	41 57                	push   %r15
    1214:	41 56                	push   %r14
    1216:	41 55                	push   %r13
    1218:	41 54                	push   %r12
    121a:	53                   	push   %rbx
    121b:	48 81 ec c8 00 00 00 	sub    $0xc8,%rsp
    1222:	89 bd 7c ff ff ff    	mov    %edi,-0x84(%rbp)
    1228:	48 89 b5 70 ff ff ff 	mov    %rsi,-0x90(%rbp)
    122f:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
    1236:	00 00
    1238:	48 89 45 c8          	mov    %rax,-0x38(%rbp)
    123c:	31 c0                	xor    %eax,%eax
    123e:	48 89 e0             	mov    %rsp,%rax
    1241:	48 89 85 18 ff ff ff 	mov    %rax,-0xe8(%rbp)
    1248:	c7 45 8c 17 00 00 00 	movl   $0x17,-0x74(%rbp)
    124f:	c7 45 88 1d 00 00 00 	movl   $0x1d,-0x78(%rbp)
    1256:	8b 75 8c             	mov    -0x74(%rbp),%esi
    1259:	8b 7d 88             	mov    -0x78(%rbp),%edi
    125c:	48 63 c6             	movslq %esi,%rax
    125f:	48 83 e8 01          	sub    $0x1,%rax
    1263:	48 89 45 a0          	mov    %rax,-0x60(%rbp)
    1267:	48 63 c6             	movslq %esi,%rax
    126a:	48 89 c1             	mov    %rax,%rcx
    126d:	bb 00 00 00 00       	mov    $0x0,%ebx
    1272:	48 63 c6             	movslq %esi,%rax
    1275:	48 8d 1c 85 00 00 00 	lea    0x0(,%rax,4),%rbx
    127c:	00
    127d:	48 63 c7             	movslq %edi,%rax
    1280:	48 83 e8 01          	sub    $0x1,%rax
    1284:	48 89 45 98          	mov    %rax,-0x68(%rbp)
    1288:	48 63 c6             	movslq %esi,%rax
    128b:	49 89 c2             	mov    %rax,%r10
    128e:	41 bb 00 00 00 00    	mov    $0x0,%r11d
    1294:	48 63 c7             	movslq %edi,%rax
    1297:	49 89 c0             	mov    %rax,%r8
    129a:	41 b9 00 00 00 00    	mov    $0x0,%r9d
    12a0:	4c 89 da             	mov    %r11,%rdx
    12a3:	49 0f af d0          	imul   %r8,%rdx
    12a7:	4c 89 c8             	mov    %r9,%rax
    12aa:	49 0f af c2          	imul   %r10,%rax
    12ae:	48 8d 0c 02          	lea    (%rdx,%rax,1),%rcx
    12b2:	4c 89 d0             	mov    %r10,%rax
    12b5:	49 f7 e0             	mul    %r8
    12b8:	48 01 d1             	add    %rdx,%rcx
    12bb:	48 89 ca             	mov    %rcx,%rdx
    12be:	48 63 c6             	movslq %esi,%rax
    12c1:	49 89 c6             	mov    %rax,%r14
    12c4:	41 bf 00 00 00 00    	mov    $0x0,%r15d
    12ca:	48 63 c7             	movslq %edi,%rax
    12cd:	49 89 c4             	mov    %rax,%r12
    12d0:	41 bd 00 00 00 00    	mov    $0x0,%r13d
    12d6:	4c 89 fa             	mov    %r15,%rdx
    12d9:	49 0f af d4          	imul   %r12,%rdx
    12dd:	4c 89 e8             	mov    %r13,%rax
    12e0:	49 0f af c6          	imul   %r14,%rax
    12e4:	48 8d 0c 02          	lea    (%rdx,%rax,1),%rcx
    12e8:	4c 89 f0             	mov    %r14,%rax
    12eb:	49 f7 e4             	mul    %r12
    12ee:	48 01 d1             	add    %rdx,%rcx
    12f1:	48 89 ca             	mov    %rcx,%rdx
    12f4:	48 63 d6             	movslq %esi,%rdx
    12f7:	48 63 c7             	movslq %edi,%rax
    12fa:	48 0f af c2          	imul   %rdx,%rax
    12fe:	48 8d 14 85 00 00 00 	lea    0x0(,%rax,4),%rdx
    1305:	00
    1306:	b8 10 00 00 00       	mov    $0x10,%eax
    130b:	48 83 e8 01          	sub    $0x1,%rax
    130f:	48 01 d0             	add    %rdx,%rax
    1312:	be 10 00 00 00       	mov    $0x10,%esi
    1317:	ba 00 00 00 00       	mov    $0x0,%edx
    131c:	48 f7 f6             	div    %rsi
    131f:	48 6b c0 10          	imul   $0x10,%rax,%rax
    1323:	48 89 c2             	mov    %rax,%rdx
    1326:	48 81 e2 00 f0 ff ff 	and    $0xfffffffffffff000,%rdx
    132d:	48 89 e7             	mov    %rsp,%rdi
    1330:	48 29 d7             	sub    %rdx,%rdi
    1333:	48 89 fa             	mov    %rdi,%rdx
    1336:	48 39 d4             	cmp    %rdx,%rsp
    1339:	74 12                	je     134d <main+0x143>
    133b:	48 81 ec 00 10 00 00 	sub    $0x1000,%rsp
    1342:	48 83 8c 24 f8 0f 00 	orq    $0x0,0xff8(%rsp)
    1349:	00 00
    134b:	eb e9                	jmp    1336 <main+0x12c>
    134d:	48 89 c2             	mov    %rax,%rdx
    1350:	81 e2 ff 0f 00 00    	and    $0xfff,%edx
    1356:	48 29 d4             	sub    %rdx,%rsp
    1359:	48 89 c2             	mov    %rax,%rdx
    135c:	81 e2 ff 0f 00 00    	and    $0xfff,%edx
    1362:	48 85 d2             	test   %rdx,%rdx
    1365:	74 10                	je     1377 <main+0x16d>
    1367:	25 ff 0f 00 00       	and    $0xfff,%eax
    136c:	48 83 e8 08          	sub    $0x8,%rax
    1370:	48 01 e0             	add    %rsp,%rax
    1373:	48 83 08 00          	orq    $0x0,(%rax)
    1377:	48 89 e0             	mov    %rsp,%rax
    137a:	48 83 c0 03          	add    $0x3,%rax
    137e:	48 c1 e8 02          	shr    $0x2,%rax
    1382:	48 c1 e0 02          	shl    $0x2,%rax
    1386:	48 89 45 a8          	mov    %rax,-0x58(%rbp)
    138a:	8b 75 88             	mov    -0x78(%rbp),%esi
    138d:	8b 7d 8c             	mov    -0x74(%rbp),%edi
    1390:	48 63 c6             	movslq %esi,%rax
    1393:	48 83 e8 01          	sub    $0x1,%rax
    1397:	48 89 45 b0          	mov    %rax,-0x50(%rbp)
    139b:	48 63 c6             	movslq %esi,%rax
    139e:	48 89 85 20 ff ff ff 	mov    %rax,-0xe0(%rbp)
    13a5:	48 c7 85 28 ff ff ff 	movq   $0x0,-0xd8(%rbp)
    13ac:	00 00 00 00
    13b0:	48 63 c7             	movslq %edi,%rax
    13b3:	48 83 e8 01          	sub    $0x1,%rax
    13b7:	48 89 45 b8          	mov    %rax,-0x48(%rbp)
    13bb:	48 63 c6             	movslq %esi,%rax
    13be:	48 89 85 60 ff ff ff 	mov    %rax,-0xa0(%rbp)
    13c5:	48 c7 85 68 ff ff ff 	movq   $0x0,-0x98(%rbp)
    13cc:	00 00 00 00
    13d0:	48 63 c7             	movslq %edi,%rax
    13d3:	48 89 85 50 ff ff ff 	mov    %rax,-0xb0(%rbp)
    13da:	48 c7 85 58 ff ff ff 	movq   $0x0,-0xa8(%rbp)
    13e1:	00 00 00 00
    13e5:	4c 8b 85 60 ff ff ff 	mov    -0xa0(%rbp),%r8
    13ec:	4c 8b 8d 68 ff ff ff 	mov    -0x98(%rbp),%r9
    13f3:	4c 89 ca             	mov    %r9,%rdx
    13f6:	4c 8b b5 50 ff ff ff 	mov    -0xb0(%rbp),%r14
    13fd:	4c 8b bd 58 ff ff ff 	mov    -0xa8(%rbp),%r15
    1404:	49 0f af d6          	imul   %r14,%rdx
    1408:	4c 89 f8             	mov    %r15,%rax
    140b:	49 0f af c0          	imul   %r8,%rax
    140f:	48 8d 0c 02          	lea    (%rdx,%rax,1),%rcx
    1413:	4c 89 c0             	mov    %r8,%rax
    1416:	49 f7 e6             	mul    %r14
    1419:	48 01 d1             	add    %rdx,%rcx
    141c:	48 89 ca             	mov    %rcx,%rdx
    141f:	48 63 c6             	movslq %esi,%rax
    1422:	48 89 85 40 ff ff ff 	mov    %rax,-0xc0(%rbp)
    1429:	48 c7 85 48 ff ff ff 	movq   $0x0,-0xb8(%rbp)
    1430:	00 00 00 00
    1434:	48 63 c7             	movslq %edi,%rax
    1437:	48 89 85 30 ff ff ff 	mov    %rax,-0xd0(%rbp)
    143e:	48 c7 85 38 ff ff ff 	movq   $0x0,-0xc8(%rbp)
    1445:	00 00 00 00
    1449:	4c 8b 8d 40 ff ff ff 	mov    -0xc0(%rbp),%r9
    1450:	4c 8b 95 48 ff ff ff 	mov    -0xb8(%rbp),%r10
    1457:	4c 89 d2             	mov    %r10,%rdx
    145a:	4c 8b 9d 30 ff ff ff 	mov    -0xd0(%rbp),%r11
    1461:	4c 8b a5 38 ff ff ff 	mov    -0xc8(%rbp),%r12
    1468:	49 0f af d3          	imul   %r11,%rdx
    146c:	4c 89 e0             	mov    %r12,%rax
    146f:	49 0f af c1          	imul   %r9,%rax
    1473:	48 8d 0c 02          	lea    (%rdx,%rax,1),%rcx
    1477:	4c 89 c8             	mov    %r9,%rax
    147a:	49 f7 e3             	mul    %r11
    147d:	48 01 d1             	add    %rdx,%rcx
    1480:	48 89 ca             	mov    %rcx,%rdx
    1483:	48 63 d6             	movslq %esi,%rdx
    1486:	48 63 c7             	movslq %edi,%rax
    1489:	48 0f af c2          	imul   %rdx,%rax
    148d:	48 8d 14 85 00 00 00 	lea    0x0(,%rax,4),%rdx
    1494:	00
    1495:	b8 10 00 00 00       	mov    $0x10,%eax
    149a:	48 83 e8 01          	sub    $0x1,%rax
    149e:	48 01 d0             	add    %rdx,%rax
    14a1:	be 10 00 00 00       	mov    $0x10,%esi
    14a6:	ba 00 00 00 00       	mov    $0x0,%edx
    14ab:	48 f7 f6             	div    %rsi
    14ae:	48 6b c0 10          	imul   $0x10,%rax,%rax
    14b2:	48 89 c2             	mov    %rax,%rdx
    14b5:	48 81 e2 00 f0 ff ff 	and    $0xfffffffffffff000,%rdx
    14bc:	48 89 e7             	mov    %rsp,%rdi
    14bf:	48 29 d7             	sub    %rdx,%rdi
    14c2:	48 89 fa             	mov    %rdi,%rdx
    14c5:	48 39 d4             	cmp    %rdx,%rsp
    14c8:	74 12                	je     14dc <main+0x2d2>
    14ca:	48 81 ec 00 10 00 00 	sub    $0x1000,%rsp
    14d1:	48 83 8c 24 f8 0f 00 	orq    $0x0,0xff8(%rsp)
    14d8:	00 00
    14da:	eb e9                	jmp    14c5 <main+0x2bb>
    14dc:	48 89 c2             	mov    %rax,%rdx
    14df:	81 e2 ff 0f 00 00    	and    $0xfff,%edx
    14e5:	48 29 d4             	sub    %rdx,%rsp
    14e8:	48 89 c2             	mov    %rax,%rdx
    14eb:	81 e2 ff 0f 00 00    	and    $0xfff,%edx
    14f1:	48 85 d2             	test   %rdx,%rdx
    14f4:	74 10                	je     1506 <main+0x2fc>
    14f6:	25 ff 0f 00 00       	and    $0xfff,%eax
    14fb:	48 83 e8 08          	sub    $0x8,%rax
    14ff:	48 01 e0             	add    %rsp,%rax
    1502:	48 83 08 00          	orq    $0x0,(%rax)
    1506:	48 89 e0             	mov    %rsp,%rax
    1509:	48 83 c0 03          	add    $0x3,%rax
    150d:	48 c1 e8 02          	shr    $0x2,%rax
    1511:	48 c1 e0 02          	shl    $0x2,%rax
    1515:	48 89 45 c0          	mov    %rax,-0x40(%rbp)
    1519:	c7 45 94 00 00 00 00 	movl   $0x0,-0x6c(%rbp)
    1520:	eb 49                	jmp    156b <main+0x361>
    1522:	c7 45 90 00 00 00 00 	movl   $0x0,-0x70(%rbp)
    1529:	eb 34                	jmp    155f <main+0x355>
    152b:	8b 45 94             	mov    -0x6c(%rbp),%eax
    152e:	0f af 45 88          	imul   -0x78(%rbp),%eax
    1532:	89 c2                	mov    %eax,%edx
    1534:	48 89 df             	mov    %rbx,%rdi
    1537:	48 c1 ef 02          	shr    $0x2,%rdi
    153b:	8b 45 90             	mov    -0x70(%rbp),%eax
    153e:	8d 0c 02             	lea    (%rdx,%rax,1),%ecx
    1541:	48 8b 45 a8          	mov    -0x58(%rbp),%rax
    1545:	8b 55 90             	mov    -0x70(%rbp),%edx
    1548:	48 63 f2             	movslq %edx,%rsi
    154b:	8b 55 94             	mov    -0x6c(%rbp),%edx
    154e:	48 63 d2             	movslq %edx,%rdx
    1551:	48 0f af d7          	imul   %rdi,%rdx
    1555:	48 01 f2             	add    %rsi,%rdx
    1558:	89 0c 90             	mov    %ecx,(%rax,%rdx,4)
    155b:	83 45 90 01          	addl   $0x1,-0x70(%rbp)
    155f:	8b 45 90             	mov    -0x70(%rbp),%eax
    1562:	3b 45 8c             	cmp    -0x74(%rbp),%eax
    1565:	7c c4                	jl     152b <main+0x321>
    1567:	83 45 94 01          	addl   $0x1,-0x6c(%rbp)
    156b:	8b 45 94             	mov    -0x6c(%rbp),%eax
    156e:	3b 45 88             	cmp    -0x78(%rbp),%eax
    1571:	7c af                	jl     1522 <main+0x318>
    1573:	48 8b 4d c0          	mov    -0x40(%rbp),%rcx
    1577:	48 8b 55 a8          	mov    -0x58(%rbp),%rdx
    157b:	8b 75 88             	mov    -0x78(%rbp),%esi
    157e:	8b 45 8c             	mov    -0x74(%rbp),%eax
    1581:	89 c7                	mov    %eax,%edi
    1583:	e8 c1 fb ff ff       	callq  1149 <trans>
    1588:	48 8b a5 18 ff ff ff 	mov    -0xe8(%rbp),%rsp
    158f:	b8 00 00 00 00       	mov    $0x0,%eax
    1594:	48 8b 5d c8          	mov    -0x38(%rbp),%rbx
    1598:	64 48 33 1c 25 28 00 	xor    %fs:0x28,%rbx
    159f:	00 00
    15a1:	74 05                	je     15a8 <main+0x39e>
    15a3:	e8 a8 fa ff ff       	callq  1050 <__stack_chk_fail@plt>
    15a8:	48 8d 65 d8          	lea    -0x28(%rbp),%rsp
    15ac:	5b                   	pop    %rbx
    15ad:	41 5c                	pop    %r12
    15af:	41 5d                	pop    %r13
    15b1:	41 5e                	pop    %r14
    15b3:	41 5f                	pop    %r15
    15b5:	5d                   	pop    %rbp
    15b6:	c3                   	retq
    15b7:	66 0f 1f 84 00 00 00 	nopw   0x0(%rax,%rax,1)
    15be:	00 00

00000000000015c0 <__libc_csu_init>:
    15c0:	f3 0f 1e fa          	endbr64
    15c4:	41 57                	push   %r15
    15c6:	4c 8d 3d eb 27 00 00 	lea    0x27eb(%rip),%r15        # 3db8 <__frame_dummy_init_array_entry>
    15cd:	41 56                	push   %r14
    15cf:	49 89 d6             	mov    %rdx,%r14
    15d2:	41 55                	push   %r13
    15d4:	49 89 f5             	mov    %rsi,%r13
    15d7:	41 54                	push   %r12
    15d9:	41 89 fc             	mov    %edi,%r12d
    15dc:	55                   	push   %rbp
    15dd:	48 8d 2d dc 27 00 00 	lea    0x27dc(%rip),%rbp        # 3dc0 <__do_global_dtors_aux_fini_array_entry>
    15e4:	53                   	push   %rbx
    15e5:	4c 29 fd             	sub    %r15,%rbp
    15e8:	48 83 ec 08          	sub    $0x8,%rsp
    15ec:	e8 0f fa ff ff       	callq  1000 <_init>
    15f1:	48 c1 fd 03          	sar    $0x3,%rbp
    15f5:	74 1f                	je     1616 <__libc_csu_init+0x56>
    15f7:	31 db                	xor    %ebx,%ebx
    15f9:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)
    1600:	4c 89 f2             	mov    %r14,%rdx
    1603:	4c 89 ee             	mov    %r13,%rsi
    1606:	44 89 e7             	mov    %r12d,%edi
    1609:	41 ff 14 df          	callq  *(%r15,%rbx,8)
    160d:	48 83 c3 01          	add    $0x1,%rbx
    1611:	48 39 dd             	cmp    %rbx,%rbp
    1614:	75 ea                	jne    1600 <__libc_csu_init+0x40>
    1616:	48 83 c4 08          	add    $0x8,%rsp
    161a:	5b                   	pop    %rbx
    161b:	5d                   	pop    %rbp
    161c:	41 5c                	pop    %r12
    161e:	41 5d                	pop    %r13
    1620:	41 5e                	pop    %r14
    1622:	41 5f                	pop    %r15
    1624:	c3                   	retq
    1625:	66 66 2e 0f 1f 84 00 	data16 nopw %cs:0x0(%rax,%rax,1)
    162c:	00 00 00 00

0000000000001630 <__libc_csu_fini>:
    1630:	f3 0f 1e fa          	endbr64
    1634:	c3                   	retq

Disassembly of section .fini:

0000000000001638 <_fini>:
    1638:	f3 0f 1e fa          	endbr64
    163c:	48 83 ec 08          	sub    $0x8,%rsp
    1640:	48 83 c4 08          	add    $0x8,%rsp
    1644:	c3                   	retq
