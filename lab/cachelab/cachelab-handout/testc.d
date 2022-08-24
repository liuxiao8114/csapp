
testc:     file format elf64-x86-64


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
    1020:	ff 35 8a 2f 00 00    	pushq  0x2f8a(%rip)        # 3fb0 <_GLOBAL_OFFSET_TABLE_+0x8>
    1026:	f2 ff 25 8b 2f 00 00 	bnd jmpq *0x2f8b(%rip)        # 3fb8 <_GLOBAL_OFFSET_TABLE_+0x10>
    102d:	0f 1f 00             	nopl   (%rax)
    1030:	f3 0f 1e fa          	endbr64 
    1034:	68 00 00 00 00       	pushq  $0x0
    1039:	f2 e9 e1 ff ff ff    	bnd jmpq 1020 <.plt>
    103f:	90                   	nop
    1040:	f3 0f 1e fa          	endbr64 
    1044:	68 01 00 00 00       	pushq  $0x1
    1049:	f2 e9 d1 ff ff ff    	bnd jmpq 1020 <.plt>
    104f:	90                   	nop
    1050:	f3 0f 1e fa          	endbr64 
    1054:	68 02 00 00 00       	pushq  $0x2
    1059:	f2 e9 c1 ff ff ff    	bnd jmpq 1020 <.plt>
    105f:	90                   	nop

Disassembly of section .plt.got:

0000000000001060 <__cxa_finalize@plt>:
    1060:	f3 0f 1e fa          	endbr64 
    1064:	f2 ff 25 8d 2f 00 00 	bnd jmpq *0x2f8d(%rip)        # 3ff8 <__cxa_finalize@GLIBC_2.2.5>
    106b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

Disassembly of section .plt.sec:

0000000000001070 <puts@plt>:
    1070:	f3 0f 1e fa          	endbr64 
    1074:	f2 ff 25 45 2f 00 00 	bnd jmpq *0x2f45(%rip)        # 3fc0 <puts@GLIBC_2.2.5>
    107b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

0000000000001080 <printf@plt>:
    1080:	f3 0f 1e fa          	endbr64 
    1084:	f2 ff 25 3d 2f 00 00 	bnd jmpq *0x2f3d(%rip)        # 3fc8 <printf@GLIBC_2.2.5>
    108b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

0000000000001090 <malloc@plt>:
    1090:	f3 0f 1e fa          	endbr64 
    1094:	f2 ff 25 35 2f 00 00 	bnd jmpq *0x2f35(%rip)        # 3fd0 <malloc@GLIBC_2.2.5>
    109b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

Disassembly of section .text:

00000000000010a0 <_start>:
    10a0:	f3 0f 1e fa          	endbr64 
    10a4:	31 ed                	xor    %ebp,%ebp
    10a6:	49 89 d1             	mov    %rdx,%r9
    10a9:	5e                   	pop    %rsi
    10aa:	48 89 e2             	mov    %rsp,%rdx
    10ad:	48 83 e4 f0          	and    $0xfffffffffffffff0,%rsp
    10b1:	50                   	push   %rax
    10b2:	54                   	push   %rsp
    10b3:	4c 8d 05 06 03 00 00 	lea    0x306(%rip),%r8        # 13c0 <__libc_csu_fini>
    10ba:	48 8d 0d 8f 02 00 00 	lea    0x28f(%rip),%rcx        # 1350 <__libc_csu_init>
    10c1:	48 8d 3d 0e 02 00 00 	lea    0x20e(%rip),%rdi        # 12d6 <main>
    10c8:	ff 15 12 2f 00 00    	callq  *0x2f12(%rip)        # 3fe0 <__libc_start_main@GLIBC_2.2.5>
    10ce:	f4                   	hlt    
    10cf:	90                   	nop

00000000000010d0 <deregister_tm_clones>:
    10d0:	48 8d 3d 39 2f 00 00 	lea    0x2f39(%rip),%rdi        # 4010 <__TMC_END__>
    10d7:	48 8d 05 32 2f 00 00 	lea    0x2f32(%rip),%rax        # 4010 <__TMC_END__>
    10de:	48 39 f8             	cmp    %rdi,%rax
    10e1:	74 15                	je     10f8 <deregister_tm_clones+0x28>
    10e3:	48 8b 05 ee 2e 00 00 	mov    0x2eee(%rip),%rax        # 3fd8 <_ITM_deregisterTMCloneTable>
    10ea:	48 85 c0             	test   %rax,%rax
    10ed:	74 09                	je     10f8 <deregister_tm_clones+0x28>
    10ef:	ff e0                	jmpq   *%rax
    10f1:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)
    10f8:	c3                   	retq   
    10f9:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

0000000000001100 <register_tm_clones>:
    1100:	48 8d 3d 09 2f 00 00 	lea    0x2f09(%rip),%rdi        # 4010 <__TMC_END__>
    1107:	48 8d 35 02 2f 00 00 	lea    0x2f02(%rip),%rsi        # 4010 <__TMC_END__>
    110e:	48 29 fe             	sub    %rdi,%rsi
    1111:	48 89 f0             	mov    %rsi,%rax
    1114:	48 c1 ee 3f          	shr    $0x3f,%rsi
    1118:	48 c1 f8 03          	sar    $0x3,%rax
    111c:	48 01 c6             	add    %rax,%rsi
    111f:	48 d1 fe             	sar    %rsi
    1122:	74 14                	je     1138 <register_tm_clones+0x38>
    1124:	48 8b 05 c5 2e 00 00 	mov    0x2ec5(%rip),%rax        # 3ff0 <_ITM_registerTMCloneTable>
    112b:	48 85 c0             	test   %rax,%rax
    112e:	74 08                	je     1138 <register_tm_clones+0x38>
    1130:	ff e0                	jmpq   *%rax
    1132:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)
    1138:	c3                   	retq   
    1139:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

0000000000001140 <__do_global_dtors_aux>:
    1140:	f3 0f 1e fa          	endbr64 
    1144:	80 3d c5 2e 00 00 00 	cmpb   $0x0,0x2ec5(%rip)        # 4010 <__TMC_END__>
    114b:	75 2b                	jne    1178 <__do_global_dtors_aux+0x38>
    114d:	55                   	push   %rbp
    114e:	48 83 3d a2 2e 00 00 	cmpq   $0x0,0x2ea2(%rip)        # 3ff8 <__cxa_finalize@GLIBC_2.2.5>
    1155:	00 
    1156:	48 89 e5             	mov    %rsp,%rbp
    1159:	74 0c                	je     1167 <__do_global_dtors_aux+0x27>
    115b:	48 8b 3d a6 2e 00 00 	mov    0x2ea6(%rip),%rdi        # 4008 <__dso_handle>
    1162:	e8 f9 fe ff ff       	callq  1060 <__cxa_finalize@plt>
    1167:	e8 64 ff ff ff       	callq  10d0 <deregister_tm_clones>
    116c:	c6 05 9d 2e 00 00 01 	movb   $0x1,0x2e9d(%rip)        # 4010 <__TMC_END__>
    1173:	5d                   	pop    %rbp
    1174:	c3                   	retq   
    1175:	0f 1f 00             	nopl   (%rax)
    1178:	c3                   	retq   
    1179:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

0000000000001180 <frame_dummy>:
    1180:	f3 0f 1e fa          	endbr64 
    1184:	e9 77 ff ff ff       	jmpq   1100 <register_tm_clones>

0000000000001189 <atoh>:
    1189:	f3 0f 1e fa          	endbr64 
    118d:	55                   	push   %rbp
    118e:	48 89 e5             	mov    %rsp,%rbp
    1191:	48 83 ec 20          	sub    $0x20,%rsp
    1195:	48 89 7d e8          	mov    %rdi,-0x18(%rbp)
    1199:	c7 45 fc 00 00 00 00 	movl   $0x0,-0x4(%rbp)
    11a0:	e9 bd 00 00 00       	jmpq   1262 <atoh+0xd9>
    11a5:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
    11a9:	0f b6 00             	movzbl (%rax),%eax
    11ac:	3c 2f                	cmp    $0x2f,%al
    11ae:	7e 2a                	jle    11da <atoh+0x51>
    11b0:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
    11b4:	0f b6 00             	movzbl (%rax),%eax
    11b7:	3c 39                	cmp    $0x39,%al
    11b9:	7f 1f                	jg     11da <atoh+0x51>
    11bb:	8b 45 fc             	mov    -0x4(%rbp),%eax
    11be:	c1 e0 04             	shl    $0x4,%eax
    11c1:	89 c2                	mov    %eax,%edx
    11c3:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
    11c7:	0f b6 00             	movzbl (%rax),%eax
    11ca:	0f be c0             	movsbl %al,%eax
    11cd:	01 d0                	add    %edx,%eax
    11cf:	83 e8 30             	sub    $0x30,%eax
    11d2:	89 45 fc             	mov    %eax,-0x4(%rbp)
    11d5:	e9 83 00 00 00       	jmpq   125d <atoh+0xd4>
    11da:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
    11de:	0f b6 00             	movzbl (%rax),%eax
    11e1:	3c 60                	cmp    $0x60,%al
    11e3:	7e 27                	jle    120c <atoh+0x83>
    11e5:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
    11e9:	0f b6 00             	movzbl (%rax),%eax
    11ec:	3c 66                	cmp    $0x66,%al
    11ee:	7f 1c                	jg     120c <atoh+0x83>
    11f0:	8b 45 fc             	mov    -0x4(%rbp),%eax
    11f3:	c1 e0 04             	shl    $0x4,%eax
    11f6:	89 c2                	mov    %eax,%edx
    11f8:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
    11fc:	0f b6 00             	movzbl (%rax),%eax
    11ff:	0f be c0             	movsbl %al,%eax
    1202:	01 d0                	add    %edx,%eax
    1204:	83 e8 57             	sub    $0x57,%eax
    1207:	89 45 fc             	mov    %eax,-0x4(%rbp)
    120a:	eb 51                	jmp    125d <atoh+0xd4>
    120c:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
    1210:	0f b6 00             	movzbl (%rax),%eax
    1213:	3c 40                	cmp    $0x40,%al
    1215:	7e 27                	jle    123e <atoh+0xb5>
    1217:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
    121b:	0f b6 00             	movzbl (%rax),%eax
    121e:	3c 46                	cmp    $0x46,%al
    1220:	7f 1c                	jg     123e <atoh+0xb5>
    1222:	8b 45 fc             	mov    -0x4(%rbp),%eax
    1225:	c1 e0 04             	shl    $0x4,%eax
    1228:	89 c2                	mov    %eax,%edx
    122a:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
    122e:	0f b6 00             	movzbl (%rax),%eax
    1231:	0f be c0             	movsbl %al,%eax
    1234:	01 d0                	add    %edx,%eax
    1236:	83 e8 37             	sub    $0x37,%eax
    1239:	89 45 fc             	mov    %eax,-0x4(%rbp)
    123c:	eb 1f                	jmp    125d <atoh+0xd4>
    123e:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
    1242:	48 89 c6             	mov    %rax,%rsi
    1245:	48 8d 3d b8 0d 00 00 	lea    0xdb8(%rip),%rdi        # 2004 <_IO_stdin_used+0x4>
    124c:	b8 00 00 00 00       	mov    $0x0,%eax
    1251:	e8 2a fe ff ff       	callq  1080 <printf@plt>
    1256:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
    125b:	eb 17                	jmp    1274 <atoh+0xeb>
    125d:	48 83 45 e8 01       	addq   $0x1,-0x18(%rbp)
    1262:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
    1266:	0f b6 00             	movzbl (%rax),%eax
    1269:	84 c0                	test   %al,%al
    126b:	0f 85 34 ff ff ff    	jne    11a5 <atoh+0x1c>
    1271:	8b 45 fc             	mov    -0x4(%rbp),%eax
    1274:	c9                   	leaveq 
    1275:	c3                   	retq   

0000000000001276 <testMalloc>:
    1276:	f3 0f 1e fa          	endbr64 
    127a:	55                   	push   %rbp
    127b:	48 89 e5             	mov    %rsp,%rbp
    127e:	48 83 ec 10          	sub    $0x10,%rsp
    1282:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
    1286:	48 83 7d f8 00       	cmpq   $0x0,-0x8(%rbp)
    128b:	74 0e                	je     129b <testMalloc+0x25>
    128d:	48 8d 3d 7d 0d 00 00 	lea    0xd7d(%rip),%rdi        # 2011 <_IO_stdin_used+0x11>
    1294:	e8 d7 fd ff ff       	callq  1070 <puts@plt>
    1299:	eb 38                	jmp    12d3 <testMalloc+0x5d>
    129b:	bf 14 00 00 00       	mov    $0x14,%edi
    12a0:	e8 eb fd ff ff       	callq  1090 <malloc@plt>
    12a5:	48 89 45 f8          	mov    %rax,-0x8(%rbp)
    12a9:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    12ad:	48 ba 30 31 32 33 34 	movabs $0x3736353433323130,%rdx
    12b4:	35 36 37 
    12b7:	48 b9 38 39 30 31 32 	movabs $0x3534333231303938,%rcx
    12be:	33 34 35 
    12c1:	48 89 10             	mov    %rdx,(%rax)
    12c4:	48 89 48 08          	mov    %rcx,0x8(%rax)
    12c8:	c7 40 10 36 37 38 39 	movl   $0x39383736,0x10(%rax)
    12cf:	c6 40 14 00          	movb   $0x0,0x14(%rax)
    12d3:	90                   	nop
    12d4:	c9                   	leaveq 
    12d5:	c3                   	retq   

00000000000012d6 <main>:
    12d6:	f3 0f 1e fa          	endbr64 
    12da:	55                   	push   %rbp
    12db:	48 89 e5             	mov    %rsp,%rbp
    12de:	48 83 ec 10          	sub    $0x10,%rsp
    12e2:	bf 20 00 00 00       	mov    $0x20,%edi
    12e7:	e8 a4 fd ff ff       	callq  1090 <malloc@plt>
    12ec:	48 89 45 f8          	mov    %rax,-0x8(%rbp)
    12f0:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    12f4:	48 8d 50 08          	lea    0x8(%rax),%rdx
    12f8:	48 89 55 f8          	mov    %rdx,-0x8(%rbp)
    12fc:	48 8b 00             	mov    (%rax),%rax
    12ff:	48 89 c7             	mov    %rax,%rdi
    1302:	e8 6f ff ff ff       	callq  1276 <testMalloc>
    1307:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    130b:	48 8b 00             	mov    (%rax),%rax
    130e:	48 89 c7             	mov    %rax,%rdi
    1311:	e8 60 ff ff ff       	callq  1276 <testMalloc>
    1316:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    131a:	48 83 c0 08          	add    $0x8,%rax
    131e:	48 8b 10             	mov    (%rax),%rdx
    1321:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    1325:	48 8b 00             	mov    (%rax),%rax
    1328:	48 89 c6             	mov    %rax,%rsi
    132b:	48 8d 3d ed 0c 00 00 	lea    0xced(%rip),%rdi        # 201f <_IO_stdin_used+0x1f>
    1332:	b8 00 00 00 00       	mov    $0x0,%eax
    1337:	e8 44 fd ff ff       	callq  1080 <printf@plt>
    133c:	b8 01 00 00 00       	mov    $0x1,%eax
    1341:	c9                   	leaveq 
    1342:	c3                   	retq   
    1343:	66 2e 0f 1f 84 00 00 	nopw   %cs:0x0(%rax,%rax,1)
    134a:	00 00 00 
    134d:	0f 1f 00             	nopl   (%rax)

0000000000001350 <__libc_csu_init>:
    1350:	f3 0f 1e fa          	endbr64 
    1354:	41 57                	push   %r15
    1356:	4c 8d 3d 4b 2a 00 00 	lea    0x2a4b(%rip),%r15        # 3da8 <__frame_dummy_init_array_entry>
    135d:	41 56                	push   %r14
    135f:	49 89 d6             	mov    %rdx,%r14
    1362:	41 55                	push   %r13
    1364:	49 89 f5             	mov    %rsi,%r13
    1367:	41 54                	push   %r12
    1369:	41 89 fc             	mov    %edi,%r12d
    136c:	55                   	push   %rbp
    136d:	48 8d 2d 3c 2a 00 00 	lea    0x2a3c(%rip),%rbp        # 3db0 <__do_global_dtors_aux_fini_array_entry>
    1374:	53                   	push   %rbx
    1375:	4c 29 fd             	sub    %r15,%rbp
    1378:	48 83 ec 08          	sub    $0x8,%rsp
    137c:	e8 7f fc ff ff       	callq  1000 <_init>
    1381:	48 c1 fd 03          	sar    $0x3,%rbp
    1385:	74 1f                	je     13a6 <__libc_csu_init+0x56>
    1387:	31 db                	xor    %ebx,%ebx
    1389:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)
    1390:	4c 89 f2             	mov    %r14,%rdx
    1393:	4c 89 ee             	mov    %r13,%rsi
    1396:	44 89 e7             	mov    %r12d,%edi
    1399:	41 ff 14 df          	callq  *(%r15,%rbx,8)
    139d:	48 83 c3 01          	add    $0x1,%rbx
    13a1:	48 39 dd             	cmp    %rbx,%rbp
    13a4:	75 ea                	jne    1390 <__libc_csu_init+0x40>
    13a6:	48 83 c4 08          	add    $0x8,%rsp
    13aa:	5b                   	pop    %rbx
    13ab:	5d                   	pop    %rbp
    13ac:	41 5c                	pop    %r12
    13ae:	41 5d                	pop    %r13
    13b0:	41 5e                	pop    %r14
    13b2:	41 5f                	pop    %r15
    13b4:	c3                   	retq   
    13b5:	66 66 2e 0f 1f 84 00 	data16 nopw %cs:0x0(%rax,%rax,1)
    13bc:	00 00 00 00 

00000000000013c0 <__libc_csu_fini>:
    13c0:	f3 0f 1e fa          	endbr64 
    13c4:	c3                   	retq   

Disassembly of section .fini:

00000000000013c8 <_fini>:
    13c8:	f3 0f 1e fa          	endbr64 
    13cc:	48 83 ec 08          	sub    $0x8,%rsp
    13d0:	48 83 c4 08          	add    $0x8,%rsp
    13d4:	c3                   	retq   
