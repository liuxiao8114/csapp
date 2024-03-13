
test-trans:     file format elf64-x86-64


Disassembly of section .init:

0000000000001000 <_init>:
    1000:	f3 0f 1e fa          	endbr64 
    1004:	48 83 ec 08          	sub    $0x8,%rsp
    1008:	48 8b 05 d9 3f 00 00 	mov    0x3fd9(%rip),%rax        # 4fe8 <__gmon_start__>
    100f:	48 85 c0             	test   %rax,%rax
    1012:	74 02                	je     1016 <_init+0x16>
    1014:	ff d0                	callq  *%rax
    1016:	48 83 c4 08          	add    $0x8,%rsp
    101a:	c3                   	retq   

Disassembly of section .plt:

0000000000001020 <.plt>:
    1020:	ff 35 e2 3e 00 00    	pushq  0x3ee2(%rip)        # 4f08 <_GLOBAL_OFFSET_TABLE_+0x8>
    1026:	f2 ff 25 e3 3e 00 00 	bnd jmpq *0x3ee3(%rip)        # 4f10 <_GLOBAL_OFFSET_TABLE_+0x10>
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
    1060:	f3 0f 1e fa          	endbr64 
    1064:	68 03 00 00 00       	pushq  $0x3
    1069:	f2 e9 b1 ff ff ff    	bnd jmpq 1020 <.plt>
    106f:	90                   	nop
    1070:	f3 0f 1e fa          	endbr64 
    1074:	68 04 00 00 00       	pushq  $0x4
    1079:	f2 e9 a1 ff ff ff    	bnd jmpq 1020 <.plt>
    107f:	90                   	nop
    1080:	f3 0f 1e fa          	endbr64 
    1084:	68 05 00 00 00       	pushq  $0x5
    1089:	f2 e9 91 ff ff ff    	bnd jmpq 1020 <.plt>
    108f:	90                   	nop
    1090:	f3 0f 1e fa          	endbr64 
    1094:	68 06 00 00 00       	pushq  $0x6
    1099:	f2 e9 81 ff ff ff    	bnd jmpq 1020 <.plt>
    109f:	90                   	nop
    10a0:	f3 0f 1e fa          	endbr64 
    10a4:	68 07 00 00 00       	pushq  $0x7
    10a9:	f2 e9 71 ff ff ff    	bnd jmpq 1020 <.plt>
    10af:	90                   	nop
    10b0:	f3 0f 1e fa          	endbr64 
    10b4:	68 08 00 00 00       	pushq  $0x8
    10b9:	f2 e9 61 ff ff ff    	bnd jmpq 1020 <.plt>
    10bf:	90                   	nop
    10c0:	f3 0f 1e fa          	endbr64 
    10c4:	68 09 00 00 00       	pushq  $0x9
    10c9:	f2 e9 51 ff ff ff    	bnd jmpq 1020 <.plt>
    10cf:	90                   	nop
    10d0:	f3 0f 1e fa          	endbr64 
    10d4:	68 0a 00 00 00       	pushq  $0xa
    10d9:	f2 e9 41 ff ff ff    	bnd jmpq 1020 <.plt>
    10df:	90                   	nop
    10e0:	f3 0f 1e fa          	endbr64 
    10e4:	68 0b 00 00 00       	pushq  $0xb
    10e9:	f2 e9 31 ff ff ff    	bnd jmpq 1020 <.plt>
    10ef:	90                   	nop
    10f0:	f3 0f 1e fa          	endbr64 
    10f4:	68 0c 00 00 00       	pushq  $0xc
    10f9:	f2 e9 21 ff ff ff    	bnd jmpq 1020 <.plt>
    10ff:	90                   	nop
    1100:	f3 0f 1e fa          	endbr64 
    1104:	68 0d 00 00 00       	pushq  $0xd
    1109:	f2 e9 11 ff ff ff    	bnd jmpq 1020 <.plt>
    110f:	90                   	nop
    1110:	f3 0f 1e fa          	endbr64 
    1114:	68 0e 00 00 00       	pushq  $0xe
    1119:	f2 e9 01 ff ff ff    	bnd jmpq 1020 <.plt>
    111f:	90                   	nop
    1120:	f3 0f 1e fa          	endbr64 
    1124:	68 0f 00 00 00       	pushq  $0xf
    1129:	f2 e9 f1 fe ff ff    	bnd jmpq 1020 <.plt>
    112f:	90                   	nop
    1130:	f3 0f 1e fa          	endbr64 
    1134:	68 10 00 00 00       	pushq  $0x10
    1139:	f2 e9 e1 fe ff ff    	bnd jmpq 1020 <.plt>
    113f:	90                   	nop
    1140:	f3 0f 1e fa          	endbr64 
    1144:	68 11 00 00 00       	pushq  $0x11
    1149:	f2 e9 d1 fe ff ff    	bnd jmpq 1020 <.plt>
    114f:	90                   	nop
    1150:	f3 0f 1e fa          	endbr64 
    1154:	68 12 00 00 00       	pushq  $0x12
    1159:	f2 e9 c1 fe ff ff    	bnd jmpq 1020 <.plt>
    115f:	90                   	nop
    1160:	f3 0f 1e fa          	endbr64 
    1164:	68 13 00 00 00       	pushq  $0x13
    1169:	f2 e9 b1 fe ff ff    	bnd jmpq 1020 <.plt>
    116f:	90                   	nop
    1170:	f3 0f 1e fa          	endbr64 
    1174:	68 14 00 00 00       	pushq  $0x14
    1179:	f2 e9 a1 fe ff ff    	bnd jmpq 1020 <.plt>
    117f:	90                   	nop
    1180:	f3 0f 1e fa          	endbr64 
    1184:	68 15 00 00 00       	pushq  $0x15
    1189:	f2 e9 91 fe ff ff    	bnd jmpq 1020 <.plt>
    118f:	90                   	nop
    1190:	f3 0f 1e fa          	endbr64 
    1194:	68 16 00 00 00       	pushq  $0x16
    1199:	f2 e9 81 fe ff ff    	bnd jmpq 1020 <.plt>
    119f:	90                   	nop
    11a0:	f3 0f 1e fa          	endbr64 
    11a4:	68 17 00 00 00       	pushq  $0x17
    11a9:	f2 e9 71 fe ff ff    	bnd jmpq 1020 <.plt>
    11af:	90                   	nop

Disassembly of section .plt.got:

00000000000011b0 <__cxa_finalize@plt>:
    11b0:	f3 0f 1e fa          	endbr64 
    11b4:	f2 ff 25 3d 3e 00 00 	bnd jmpq *0x3e3d(%rip)        # 4ff8 <__cxa_finalize@GLIBC_2.2.5>
    11bb:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

Disassembly of section .plt.sec:

00000000000011c0 <__isoc99_fscanf@plt>:
    11c0:	f3 0f 1e fa          	endbr64 
    11c4:	f2 ff 25 4d 3d 00 00 	bnd jmpq *0x3d4d(%rip)        # 4f18 <__isoc99_fscanf@GLIBC_2.7>
    11cb:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

00000000000011d0 <puts@plt>:
    11d0:	f3 0f 1e fa          	endbr64 
    11d4:	f2 ff 25 45 3d 00 00 	bnd jmpq *0x3d45(%rip)        # 4f20 <puts@GLIBC_2.2.5>
    11db:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

00000000000011e0 <fclose@plt>:
    11e0:	f3 0f 1e fa          	endbr64 
    11e4:	f2 ff 25 3d 3d 00 00 	bnd jmpq *0x3d3d(%rip)        # 4f28 <fclose@GLIBC_2.2.5>
    11eb:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

00000000000011f0 <__stack_chk_fail@plt>:
    11f0:	f3 0f 1e fa          	endbr64 
    11f4:	f2 ff 25 35 3d 00 00 	bnd jmpq *0x3d35(%rip)        # 4f30 <__stack_chk_fail@GLIBC_2.4>
    11fb:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

0000000000001200 <system@plt>:
    1200:	f3 0f 1e fa          	endbr64 
    1204:	f2 ff 25 2d 3d 00 00 	bnd jmpq *0x3d2d(%rip)        # 4f38 <system@GLIBC_2.2.5>
    120b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

0000000000001210 <printf@plt>:
    1210:	f3 0f 1e fa          	endbr64 
    1214:	f2 ff 25 25 3d 00 00 	bnd jmpq *0x3d25(%rip)        # 4f40 <printf@GLIBC_2.2.5>
    121b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

0000000000001220 <__assert_fail@plt>:
    1220:	f3 0f 1e fa          	endbr64 
    1224:	f2 ff 25 1d 3d 00 00 	bnd jmpq *0x3d1d(%rip)        # 4f48 <__assert_fail@GLIBC_2.2.5>
    122b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

0000000000001230 <fputs@plt>:
    1230:	f3 0f 1e fa          	endbr64 
    1234:	f2 ff 25 15 3d 00 00 	bnd jmpq *0x3d15(%rip)        # 4f50 <fputs@GLIBC_2.2.5>
    123b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

0000000000001240 <alarm@plt>:
    1240:	f3 0f 1e fa          	endbr64 
    1244:	f2 ff 25 0d 3d 00 00 	bnd jmpq *0x3d0d(%rip)        # 4f58 <alarm@GLIBC_2.2.5>
    124b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

0000000000001250 <srand@plt>:
    1250:	f3 0f 1e fa          	endbr64 
    1254:	f2 ff 25 05 3d 00 00 	bnd jmpq *0x3d05(%rip)        # 4f60 <srand@GLIBC_2.2.5>
    125b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

0000000000001260 <fgets@plt>:
    1260:	f3 0f 1e fa          	endbr64 
    1264:	f2 ff 25 fd 3c 00 00 	bnd jmpq *0x3cfd(%rip)        # 4f68 <fgets@GLIBC_2.2.5>
    126b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

0000000000001270 <strcmp@plt>:
    1270:	f3 0f 1e fa          	endbr64 
    1274:	f2 ff 25 f5 3c 00 00 	bnd jmpq *0x3cf5(%rip)        # 4f70 <strcmp@GLIBC_2.2.5>
    127b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

0000000000001280 <fprintf@plt>:
    1280:	f3 0f 1e fa          	endbr64 
    1284:	f2 ff 25 ed 3c 00 00 	bnd jmpq *0x3ced(%rip)        # 4f78 <fprintf@GLIBC_2.2.5>
    128b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

0000000000001290 <__sysv_signal@plt>:
    1290:	f3 0f 1e fa          	endbr64 
    1294:	f2 ff 25 e5 3c 00 00 	bnd jmpq *0x3ce5(%rip)        # 4f80 <__sysv_signal@GLIBC_2.2.5>
    129b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

00000000000012a0 <time@plt>:
    12a0:	f3 0f 1e fa          	endbr64 
    12a4:	f2 ff 25 dd 3c 00 00 	bnd jmpq *0x3cdd(%rip)        # 4f88 <time@GLIBC_2.2.5>
    12ab:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

00000000000012b0 <fflush@plt>:
    12b0:	f3 0f 1e fa          	endbr64 
    12b4:	f2 ff 25 d5 3c 00 00 	bnd jmpq *0x3cd5(%rip)        # 4f90 <fflush@GLIBC_2.2.5>
    12bb:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

00000000000012c0 <__isoc99_sscanf@plt>:
    12c0:	f3 0f 1e fa          	endbr64 
    12c4:	f2 ff 25 cd 3c 00 00 	bnd jmpq *0x3ccd(%rip)        # 4f98 <__isoc99_sscanf@GLIBC_2.7>
    12cb:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

00000000000012d0 <fopen@plt>:
    12d0:	f3 0f 1e fa          	endbr64 
    12d4:	f2 ff 25 c5 3c 00 00 	bnd jmpq *0x3cc5(%rip)        # 4fa0 <fopen@GLIBC_2.2.5>
    12db:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

00000000000012e0 <getopt@plt>:
    12e0:	f3 0f 1e fa          	endbr64 
    12e4:	f2 ff 25 bd 3c 00 00 	bnd jmpq *0x3cbd(%rip)        # 4fa8 <getopt@GLIBC_2.2.5>
    12eb:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

00000000000012f0 <atoi@plt>:
    12f0:	f3 0f 1e fa          	endbr64 
    12f4:	f2 ff 25 b5 3c 00 00 	bnd jmpq *0x3cb5(%rip)        # 4fb0 <atoi@GLIBC_2.2.5>
    12fb:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

0000000000001300 <sprintf@plt>:
    1300:	f3 0f 1e fa          	endbr64 
    1304:	f2 ff 25 ad 3c 00 00 	bnd jmpq *0x3cad(%rip)        # 4fb8 <sprintf@GLIBC_2.2.5>
    130b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

0000000000001310 <exit@plt>:
    1310:	f3 0f 1e fa          	endbr64 
    1314:	f2 ff 25 a5 3c 00 00 	bnd jmpq *0x3ca5(%rip)        # 4fc0 <exit@GLIBC_2.2.5>
    131b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

0000000000001320 <fwrite@plt>:
    1320:	f3 0f 1e fa          	endbr64 
    1324:	f2 ff 25 9d 3c 00 00 	bnd jmpq *0x3c9d(%rip)        # 4fc8 <fwrite@GLIBC_2.2.5>
    132b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

0000000000001330 <rand@plt>:
    1330:	f3 0f 1e fa          	endbr64 
    1334:	f2 ff 25 95 3c 00 00 	bnd jmpq *0x3c95(%rip)        # 4fd0 <rand@GLIBC_2.2.5>
    133b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

Disassembly of section .text:

0000000000001340 <_start>:
    1340:	f3 0f 1e fa          	endbr64 
    1344:	31 ed                	xor    %ebp,%ebp
    1346:	49 89 d1             	mov    %rdx,%r9
    1349:	5e                   	pop    %rsi
    134a:	48 89 e2             	mov    %rsp,%rdx
    134d:	48 83 e4 f0          	and    $0xfffffffffffffff0,%rsp
    1351:	50                   	push   %rax
    1352:	54                   	push   %rsp
    1353:	4c 8d 05 d6 11 00 00 	lea    0x11d6(%rip),%r8        # 2530 <__libc_csu_fini>
    135a:	48 8d 0d 5f 11 00 00 	lea    0x115f(%rip),%rcx        # 24c0 <__libc_csu_init>
    1361:	48 8d 3d 6b 07 00 00 	lea    0x76b(%rip),%rdi        # 1ad3 <main>
    1368:	ff 15 72 3c 00 00    	callq  *0x3c72(%rip)        # 4fe0 <__libc_start_main@GLIBC_2.2.5>
    136e:	f4                   	hlt    
    136f:	90                   	nop

0000000000001370 <deregister_tm_clones>:
    1370:	48 8d 3d 01 3d 00 00 	lea    0x3d01(%rip),%rdi        # 5078 <__TMC_END__>
    1377:	48 8d 05 fa 3c 00 00 	lea    0x3cfa(%rip),%rax        # 5078 <__TMC_END__>
    137e:	48 39 f8             	cmp    %rdi,%rax
    1381:	74 15                	je     1398 <deregister_tm_clones+0x28>
    1383:	48 8b 05 4e 3c 00 00 	mov    0x3c4e(%rip),%rax        # 4fd8 <_ITM_deregisterTMCloneTable>
    138a:	48 85 c0             	test   %rax,%rax
    138d:	74 09                	je     1398 <deregister_tm_clones+0x28>
    138f:	ff e0                	jmpq   *%rax
    1391:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)
    1398:	c3                   	retq   
    1399:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

00000000000013a0 <register_tm_clones>:
    13a0:	48 8d 3d d1 3c 00 00 	lea    0x3cd1(%rip),%rdi        # 5078 <__TMC_END__>
    13a7:	48 8d 35 ca 3c 00 00 	lea    0x3cca(%rip),%rsi        # 5078 <__TMC_END__>
    13ae:	48 29 fe             	sub    %rdi,%rsi
    13b1:	48 89 f0             	mov    %rsi,%rax
    13b4:	48 c1 ee 3f          	shr    $0x3f,%rsi
    13b8:	48 c1 f8 03          	sar    $0x3,%rax
    13bc:	48 01 c6             	add    %rax,%rsi
    13bf:	48 d1 fe             	sar    %rsi
    13c2:	74 14                	je     13d8 <register_tm_clones+0x38>
    13c4:	48 8b 05 25 3c 00 00 	mov    0x3c25(%rip),%rax        # 4ff0 <_ITM_registerTMCloneTable>
    13cb:	48 85 c0             	test   %rax,%rax
    13ce:	74 08                	je     13d8 <register_tm_clones+0x38>
    13d0:	ff e0                	jmpq   *%rax
    13d2:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)
    13d8:	c3                   	retq   
    13d9:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

00000000000013e0 <__do_global_dtors_aux>:
    13e0:	f3 0f 1e fa          	endbr64 
    13e4:	80 3d bd 3c 00 00 00 	cmpb   $0x0,0x3cbd(%rip)        # 50a8 <completed.8061>
    13eb:	75 2b                	jne    1418 <__do_global_dtors_aux+0x38>
    13ed:	55                   	push   %rbp
    13ee:	48 83 3d 02 3c 00 00 	cmpq   $0x0,0x3c02(%rip)        # 4ff8 <__cxa_finalize@GLIBC_2.2.5>
    13f5:	00 
    13f6:	48 89 e5             	mov    %rsp,%rbp
    13f9:	74 0c                	je     1407 <__do_global_dtors_aux+0x27>
    13fb:	48 8b 3d 06 3c 00 00 	mov    0x3c06(%rip),%rdi        # 5008 <__dso_handle>
    1402:	e8 a9 fd ff ff       	callq  11b0 <__cxa_finalize@plt>
    1407:	e8 64 ff ff ff       	callq  1370 <deregister_tm_clones>
    140c:	c6 05 95 3c 00 00 01 	movb   $0x1,0x3c95(%rip)        # 50a8 <completed.8061>
    1413:	5d                   	pop    %rbp
    1414:	c3                   	retq   
    1415:	0f 1f 00             	nopl   (%rax)
    1418:	c3                   	retq   
    1419:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

0000000000001420 <frame_dummy>:
    1420:	f3 0f 1e fa          	endbr64 
    1424:	e9 77 ff ff ff       	jmpq   13a0 <register_tm_clones>

0000000000001429 <eval_perf>:
    1429:	f3 0f 1e fa          	endbr64 
    142d:	55                   	push   %rbp
    142e:	48 89 e5             	mov    %rsp,%rbp
    1431:	48 81 ec d0 06 00 00 	sub    $0x6d0,%rsp
    1438:	89 bd 3c f9 ff ff    	mov    %edi,-0x6c4(%rbp)
    143e:	89 b5 38 f9 ff ff    	mov    %esi,-0x6c8(%rbp)
    1444:	89 95 34 f9 ff ff    	mov    %edx,-0x6cc(%rbp)
    144a:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
    1451:	00 00 
    1453:	48 89 45 f8          	mov    %rax,-0x8(%rbp)
    1457:	31 c0                	xor    %eax,%eax
    1459:	b8 00 00 00 00       	mov    $0x0,%eax
    145e:	e8 61 0f 00 00       	callq  23c4 <registerFunctions>
    1463:	c7 85 50 f9 ff ff 00 	movl   $0x0,-0x6b0(%rbp)
    146a:	00 00 00 
    146d:	e9 2b 05 00 00       	jmpq   199d <eval_perf+0x574>
    1472:	8b 85 50 f9 ff ff    	mov    -0x6b0(%rbp),%eax
    1478:	48 98                	cltq   
    147a:	48 c1 e0 05          	shl    $0x5,%rax
    147e:	48 89 c2             	mov    %rax,%rdx
    1481:	48 8d 05 40 3c 00 00 	lea    0x3c40(%rip),%rax        # 50c8 <func_list+0x8>
    1488:	48 8b 04 02          	mov    (%rdx,%rax,1),%rax
    148c:	48 8d 35 75 1b 00 00 	lea    0x1b75(%rip),%rsi        # 3008 <_IO_stdin_used+0x8>
    1493:	48 89 c7             	mov    %rax,%rdi
    1496:	e8 d5 fd ff ff       	callq  1270 <strcmp@plt>
    149b:	85 c0                	test   %eax,%eax
    149d:	75 0c                	jne    14ab <eval_perf+0x82>
    149f:	8b 85 50 f9 ff ff    	mov    -0x6b0(%rbp),%eax
    14a5:	89 05 65 3b 00 00    	mov    %eax,0x3b65(%rip)        # 5010 <results>
    14ab:	8b 15 03 3c 00 00    	mov    0x3c03(%rip),%edx        # 50b4 <func_counter>
    14b1:	8b 85 50 f9 ff ff    	mov    -0x6b0(%rbp),%eax
    14b7:	89 c6                	mov    %eax,%esi
    14b9:	48 8d 3d 60 1b 00 00 	lea    0x1b60(%rip),%rdi        # 3020 <_IO_stdin_used+0x20>
    14c0:	b8 00 00 00 00       	mov    $0x0,%eax
    14c5:	e8 46 fd ff ff       	callq  1210 <printf@plt>
    14ca:	8b 0d e0 3b 00 00    	mov    0x3be0(%rip),%ecx        # 50b0 <N>
    14d0:	8b 15 d6 3b 00 00    	mov    0x3bd6(%rip),%edx        # 50ac <M>
    14d6:	8b b5 50 f9 ff ff    	mov    -0x6b0(%rbp),%esi
    14dc:	48 8d 85 10 fa ff ff 	lea    -0x5f0(%rbp),%rax
    14e3:	41 89 f0             	mov    %esi,%r8d
    14e6:	48 8d 35 83 1b 00 00 	lea    0x1b83(%rip),%rsi        # 3070 <_IO_stdin_used+0x70>
    14ed:	48 89 c7             	mov    %rax,%rdi
    14f0:	b8 00 00 00 00       	mov    $0x0,%eax
    14f5:	e8 06 fe ff ff       	callq  1300 <sprintf@plt>
    14fa:	48 8d 85 10 fa ff ff 	lea    -0x5f0(%rbp),%rax
    1501:	48 89 c7             	mov    %rax,%rdi
    1504:	e8 f7 fc ff ff       	callq  1200 <system@plt>
    1509:	c1 f8 08             	sar    $0x8,%eax
    150c:	25 ff 00 00 00       	and    $0xff,%eax
    1511:	89 85 54 f9 ff ff    	mov    %eax,-0x6ac(%rbp)
    1517:	83 bd 54 f9 ff ff 00 	cmpl   $0x0,-0x6ac(%rbp)
    151e:	74 38                	je     1558 <eval_perf+0x12f>
    1520:	8b 15 8a 3b 00 00    	mov    0x3b8a(%rip),%edx        # 50b0 <N>
    1526:	8b 05 80 3b 00 00    	mov    0x3b80(%rip),%eax        # 50ac <M>
    152c:	8b 8d 54 f9 ff ff    	mov    -0x6ac(%rbp),%ecx
    1532:	8d 71 ff             	lea    -0x1(%rcx),%esi
    1535:	8b 8d 50 f9 ff ff    	mov    -0x6b0(%rbp),%ecx
    153b:	41 89 c8             	mov    %ecx,%r8d
    153e:	89 d1                	mov    %edx,%ecx
    1540:	89 c2                	mov    %eax,%edx
    1542:	48 8d 3d 87 1b 00 00 	lea    0x1b87(%rip),%rdi        # 30d0 <_IO_stdin_used+0xd0>
    1549:	b8 00 00 00 00       	mov    $0x0,%eax
    154e:	e8 bd fc ff ff       	callq  1210 <printf@plt>
    1553:	e9 3e 04 00 00       	jmpq   1996 <eval_perf+0x56d>
    1558:	48 8d 35 f4 1b 00 00 	lea    0x1bf4(%rip),%rsi        # 3153 <_IO_stdin_used+0x153>
    155f:	48 8d 3d ef 1b 00 00 	lea    0x1bef(%rip),%rdi        # 3155 <_IO_stdin_used+0x155>
    1566:	e8 65 fd ff ff       	callq  12d0 <fopen@plt>
    156b:	48 89 85 70 f9 ff ff 	mov    %rax,-0x690(%rbp)
    1572:	48 83 bd 70 f9 ff ff 	cmpq   $0x0,-0x690(%rbp)
    1579:	00 
    157a:	75 1f                	jne    159b <eval_perf+0x172>
    157c:	48 8d 0d 85 1f 00 00 	lea    0x1f85(%rip),%rcx        # 3508 <__PRETTY_FUNCTION__.2780>
    1583:	ba 50 00 00 00       	mov    $0x50,%edx
    1588:	48 8d 35 ce 1b 00 00 	lea    0x1bce(%rip),%rsi        # 315d <_IO_stdin_used+0x15d>
    158f:	48 8d 3d d4 1b 00 00 	lea    0x1bd4(%rip),%rdi        # 316a <_IO_stdin_used+0x16a>
    1596:	e8 85 fc ff ff       	callq  1220 <__assert_fail@plt>
    159b:	48 8d 8d 60 f9 ff ff 	lea    -0x6a0(%rbp),%rcx
    15a2:	48 8d 95 58 f9 ff ff 	lea    -0x6a8(%rbp),%rdx
    15a9:	48 8b 85 70 f9 ff ff 	mov    -0x690(%rbp),%rax
    15b0:	48 8d 35 bd 1b 00 00 	lea    0x1bbd(%rip),%rsi        # 3174 <_IO_stdin_used+0x174>
    15b7:	48 89 c7             	mov    %rax,%rdi
    15ba:	b8 00 00 00 00       	mov    $0x0,%eax
    15bf:	e8 fc fb ff ff       	callq  11c0 <__isoc99_fscanf@plt>
    15c4:	48 8b 85 70 f9 ff ff 	mov    -0x690(%rbp),%rax
    15cb:	48 89 c7             	mov    %rax,%rdi
    15ce:	e8 0d fc ff ff       	callq  11e0 <fclose@plt>
    15d3:	8b 85 50 f9 ff ff    	mov    -0x6b0(%rbp),%eax
    15d9:	48 98                	cltq   
    15db:	48 c1 e0 05          	shl    $0x5,%rax
    15df:	48 89 c2             	mov    %rax,%rdx
    15e2:	48 8d 05 e7 3a 00 00 	lea    0x3ae7(%rip),%rax        # 50d0 <func_list+0x10>
    15e9:	c6 04 02 01          	movb   $0x1,(%rdx,%rax,1)
    15ed:	8b 05 1d 3a 00 00    	mov    0x3a1d(%rip),%eax        # 5010 <results>
    15f3:	39 85 50 f9 ff ff    	cmp    %eax,-0x6b0(%rbp)
    15f9:	75 0a                	jne    1605 <eval_perf+0x1dc>
    15fb:	c7 05 0f 3a 00 00 01 	movl   $0x1,0x3a0f(%rip)        # 5014 <results+0x4>
    1602:	00 00 00 
    1605:	48 8d 35 47 1b 00 00 	lea    0x1b47(%rip),%rsi        # 3153 <_IO_stdin_used+0x153>
    160c:	48 8d 3d 6b 1b 00 00 	lea    0x1b6b(%rip),%rdi        # 317e <_IO_stdin_used+0x17e>
    1613:	e8 b8 fc ff ff       	callq  12d0 <fopen@plt>
    1618:	48 89 85 78 f9 ff ff 	mov    %rax,-0x688(%rbp)
    161f:	48 83 bd 78 f9 ff ff 	cmpq   $0x0,-0x688(%rbp)
    1626:	00 
    1627:	75 1f                	jne    1648 <eval_perf+0x21f>
    1629:	48 8d 0d d8 1e 00 00 	lea    0x1ed8(%rip),%rcx        # 3508 <__PRETTY_FUNCTION__.2780>
    1630:	ba 5d 00 00 00       	mov    $0x5d,%edx
    1635:	48 8d 35 21 1b 00 00 	lea    0x1b21(%rip),%rsi        # 315d <_IO_stdin_used+0x15d>
    163c:	48 8d 3d 45 1b 00 00 	lea    0x1b45(%rip),%rdi        # 3188 <_IO_stdin_used+0x188>
    1643:	e8 d8 fb ff ff       	callq  1220 <__assert_fail@plt>
    1648:	8b 95 50 f9 ff ff    	mov    -0x6b0(%rbp),%edx
    164e:	48 8d 85 90 f9 ff ff 	lea    -0x670(%rbp),%rax
    1655:	48 8d 35 3a 1b 00 00 	lea    0x1b3a(%rip),%rsi        # 3196 <_IO_stdin_used+0x196>
    165c:	48 89 c7             	mov    %rax,%rdi
    165f:	b8 00 00 00 00       	mov    $0x0,%eax
    1664:	e8 97 fc ff ff       	callq  1300 <sprintf@plt>
    1669:	48 8d 85 90 f9 ff ff 	lea    -0x670(%rbp),%rax
    1670:	48 8d 35 29 1b 00 00 	lea    0x1b29(%rip),%rsi        # 31a0 <_IO_stdin_used+0x1a0>
    1677:	48 89 c7             	mov    %rax,%rdi
    167a:	e8 51 fc ff ff       	callq  12d0 <fopen@plt>
    167f:	48 89 85 80 f9 ff ff 	mov    %rax,-0x680(%rbp)
    1686:	48 83 bd 80 f9 ff ff 	cmpq   $0x0,-0x680(%rbp)
    168d:	00 
    168e:	75 1f                	jne    16af <eval_perf+0x286>
    1690:	48 8d 0d 71 1e 00 00 	lea    0x1e71(%rip),%rcx        # 3508 <__PRETTY_FUNCTION__.2780>
    1697:	ba 63 00 00 00       	mov    $0x63,%edx
    169c:	48 8d 35 ba 1a 00 00 	lea    0x1aba(%rip),%rsi        # 315d <_IO_stdin_used+0x15d>
    16a3:	48 8d 3d f8 1a 00 00 	lea    0x1af8(%rip),%rdi        # 31a2 <_IO_stdin_used+0x1a2>
    16aa:	e8 71 fb ff ff       	callq  1220 <__assert_fail@plt>
    16af:	c7 85 54 f9 ff ff 00 	movl   $0x0,-0x6ac(%rbp)
    16b6:	00 00 00 
    16b9:	e9 ee 00 00 00       	jmpq   17ac <eval_perf+0x383>
    16be:	0f b6 85 10 fc ff ff 	movzbl -0x3f0(%rbp),%eax
    16c5:	3c 20                	cmp    $0x20,%al
    16c7:	0f 85 df 00 00 00    	jne    17ac <eval_perf+0x383>
    16cd:	0f b6 85 12 fc ff ff 	movzbl -0x3ee(%rbp),%eax
    16d4:	3c 20                	cmp    $0x20,%al
    16d6:	0f 85 d0 00 00 00    	jne    17ac <eval_perf+0x383>
    16dc:	0f b6 85 11 fc ff ff 	movzbl -0x3ef(%rbp),%eax
    16e3:	3c 53                	cmp    $0x53,%al
    16e5:	74 1a                	je     1701 <eval_perf+0x2d8>
    16e7:	0f b6 85 11 fc ff ff 	movzbl -0x3ef(%rbp),%eax
    16ee:	3c 4d                	cmp    $0x4d,%al
    16f0:	74 0f                	je     1701 <eval_perf+0x2d8>
    16f2:	0f b6 85 11 fc ff ff 	movzbl -0x3ef(%rbp),%eax
    16f9:	3c 4c                	cmp    $0x4c,%al
    16fb:	0f 85 ab 00 00 00    	jne    17ac <eval_perf+0x383>
    1701:	48 8d 85 10 fc ff ff 	lea    -0x3f0(%rbp),%rax
    1708:	48 83 c0 03          	add    $0x3,%rax
    170c:	48 8d 8d 40 f9 ff ff 	lea    -0x6c0(%rbp),%rcx
    1713:	48 8d 95 68 f9 ff ff 	lea    -0x698(%rbp),%rdx
    171a:	48 8d 35 8f 1a 00 00 	lea    0x1a8f(%rip),%rsi        # 31b0 <_IO_stdin_used+0x1b0>
    1721:	48 89 c7             	mov    %rax,%rdi
    1724:	b8 00 00 00 00       	mov    $0x0,%eax
    1729:	e8 92 fb ff ff       	callq  12c0 <__isoc99_sscanf@plt>
    172e:	48 8b 95 68 f9 ff ff 	mov    -0x698(%rbp),%rdx
    1735:	48 8b 85 58 f9 ff ff 	mov    -0x6a8(%rbp),%rax
    173c:	48 39 c2             	cmp    %rax,%rdx
    173f:	75 0a                	jne    174b <eval_perf+0x322>
    1741:	c7 85 54 f9 ff ff 01 	movl   $0x1,-0x6ac(%rbp)
    1748:	00 00 00 
    174b:	83 bd 54 f9 ff ff 00 	cmpl   $0x0,-0x6ac(%rbp)
    1752:	74 2a                	je     177e <eval_perf+0x355>
    1754:	48 8b 85 68 f9 ff ff 	mov    -0x698(%rbp),%rax
    175b:	ba fe ff ff ff       	mov    $0xfffffffe,%edx
    1760:	48 39 d0             	cmp    %rdx,%rax
    1763:	77 19                	ja     177e <eval_perf+0x355>
    1765:	48 8b 95 80 f9 ff ff 	mov    -0x680(%rbp),%rdx
    176c:	48 8d 85 10 fc ff ff 	lea    -0x3f0(%rbp),%rax
    1773:	48 89 d6             	mov    %rdx,%rsi
    1776:	48 89 c7             	mov    %rax,%rdi
    1779:	e8 b2 fa ff ff       	callq  1230 <fputs@plt>
    177e:	48 8b 95 68 f9 ff ff 	mov    -0x698(%rbp),%rdx
    1785:	48 8b 85 60 f9 ff ff 	mov    -0x6a0(%rbp),%rax
    178c:	48 39 c2             	cmp    %rax,%rdx
    178f:	75 1b                	jne    17ac <eval_perf+0x383>
    1791:	c7 85 54 f9 ff ff 00 	movl   $0x0,-0x6ac(%rbp)
    1798:	00 00 00 
    179b:	48 8b 85 80 f9 ff ff 	mov    -0x680(%rbp),%rax
    17a2:	48 89 c7             	mov    %rax,%rdi
    17a5:	e8 36 fa ff ff       	callq  11e0 <fclose@plt>
    17aa:	eb 24                	jmp    17d0 <eval_perf+0x3a7>
    17ac:	48 8b 95 78 f9 ff ff 	mov    -0x688(%rbp),%rdx
    17b3:	48 8d 85 10 fc ff ff 	lea    -0x3f0(%rbp),%rax
    17ba:	be e8 03 00 00       	mov    $0x3e8,%esi
    17bf:	48 89 c7             	mov    %rax,%rdi
    17c2:	e8 99 fa ff ff       	callq  1260 <fgets@plt>
    17c7:	48 85 c0             	test   %rax,%rax
    17ca:	0f 85 ee fe ff ff    	jne    16be <eval_perf+0x295>
    17d0:	48 8b 85 78 f9 ff ff 	mov    -0x688(%rbp),%rax
    17d7:	48 89 c7             	mov    %rax,%rdi
    17da:	e8 01 fa ff ff       	callq  11e0 <fclose@plt>
    17df:	8b 8d 34 f9 ff ff    	mov    -0x6cc(%rbp),%ecx
    17e5:	8b 95 38 f9 ff ff    	mov    -0x6c8(%rbp),%edx
    17eb:	8b 85 3c f9 ff ff    	mov    -0x6c4(%rbp),%eax
    17f1:	89 c6                	mov    %eax,%esi
    17f3:	48 8d 3d be 19 00 00 	lea    0x19be(%rip),%rdi        # 31b8 <_IO_stdin_used+0x1b8>
    17fa:	b8 00 00 00 00       	mov    $0x0,%eax
    17ff:	e8 0c fa ff ff       	callq  1210 <printf@plt>
    1804:	8b bd 50 f9 ff ff    	mov    -0x6b0(%rbp),%edi
    180a:	8b b5 34 f9 ff ff    	mov    -0x6cc(%rbp),%esi
    1810:	8b 8d 38 f9 ff ff    	mov    -0x6c8(%rbp),%ecx
    1816:	8b 95 3c f9 ff ff    	mov    -0x6c4(%rbp),%edx
    181c:	48 8d 85 10 fb ff ff 	lea    -0x4f0(%rbp),%rax
    1823:	41 89 f9             	mov    %edi,%r9d
    1826:	41 89 f0             	mov    %esi,%r8d
    1829:	48 8d 35 c0 19 00 00 	lea    0x19c0(%rip),%rsi        # 31f0 <_IO_stdin_used+0x1f0>
    1830:	48 89 c7             	mov    %rax,%rdi
    1833:	b8 00 00 00 00       	mov    $0x0,%eax
    1838:	e8 c3 fa ff ff       	callq  1300 <sprintf@plt>
    183d:	48 8d 85 10 fb ff ff 	lea    -0x4f0(%rbp),%rax
    1844:	48 89 c7             	mov    %rax,%rdi
    1847:	e8 b4 f9 ff ff       	callq  1200 <system@plt>
    184c:	48 8d 35 00 19 00 00 	lea    0x1900(%rip),%rsi        # 3153 <_IO_stdin_used+0x153>
    1853:	48 8d 3d cc 19 00 00 	lea    0x19cc(%rip),%rdi        # 3226 <_IO_stdin_used+0x226>
    185a:	e8 71 fa ff ff       	callq  12d0 <fopen@plt>
    185f:	48 89 85 88 f9 ff ff 	mov    %rax,-0x678(%rbp)
    1866:	48 83 bd 88 f9 ff ff 	cmpq   $0x0,-0x678(%rbp)
    186d:	00 
    186e:	75 1f                	jne    188f <eval_perf+0x466>
    1870:	48 8d 0d 91 1c 00 00 	lea    0x1c91(%rip),%rcx        # 3508 <__PRETTY_FUNCTION__.2780>
    1877:	ba 92 00 00 00       	mov    $0x92,%edx
    187c:	48 8d 35 da 18 00 00 	lea    0x18da(%rip),%rsi        # 315d <_IO_stdin_used+0x15d>
    1883:	48 8d 3d aa 19 00 00 	lea    0x19aa(%rip),%rdi        # 3234 <_IO_stdin_used+0x234>
    188a:	e8 91 f9 ff ff       	callq  1220 <__assert_fail@plt>
    188f:	48 8d b5 4c f9 ff ff 	lea    -0x6b4(%rbp),%rsi
    1896:	48 8d 8d 48 f9 ff ff 	lea    -0x6b8(%rbp),%rcx
    189d:	48 8d 95 44 f9 ff ff 	lea    -0x6bc(%rbp),%rdx
    18a4:	48 8b 85 88 f9 ff ff 	mov    -0x678(%rbp),%rax
    18ab:	49 89 f0             	mov    %rsi,%r8
    18ae:	48 8d 35 85 19 00 00 	lea    0x1985(%rip),%rsi        # 323a <_IO_stdin_used+0x23a>
    18b5:	48 89 c7             	mov    %rax,%rdi
    18b8:	b8 00 00 00 00       	mov    $0x0,%eax
    18bd:	e8 fe f8 ff ff       	callq  11c0 <__isoc99_fscanf@plt>
    18c2:	48 8b 85 88 f9 ff ff 	mov    -0x678(%rbp),%rax
    18c9:	48 89 c7             	mov    %rax,%rdi
    18cc:	e8 0f f9 ff ff       	callq  11e0 <fclose@plt>
    18d1:	8b 85 44 f9 ff ff    	mov    -0x6bc(%rbp),%eax
    18d7:	8b 95 50 f9 ff ff    	mov    -0x6b0(%rbp),%edx
    18dd:	48 63 d2             	movslq %edx,%rdx
    18e0:	48 89 d1             	mov    %rdx,%rcx
    18e3:	48 c1 e1 05          	shl    $0x5,%rcx
    18e7:	48 8d 15 e6 37 00 00 	lea    0x37e6(%rip),%rdx        # 50d4 <func_list+0x14>
    18ee:	89 04 11             	mov    %eax,(%rcx,%rdx,1)
    18f1:	8b 85 48 f9 ff ff    	mov    -0x6b8(%rbp),%eax
    18f7:	8b 95 50 f9 ff ff    	mov    -0x6b0(%rbp),%edx
    18fd:	48 63 d2             	movslq %edx,%rdx
    1900:	48 89 d1             	mov    %rdx,%rcx
    1903:	48 c1 e1 05          	shl    $0x5,%rcx
    1907:	48 8d 15 ca 37 00 00 	lea    0x37ca(%rip),%rdx        # 50d8 <func_list+0x18>
    190e:	89 04 11             	mov    %eax,(%rcx,%rdx,1)
    1911:	8b 85 4c f9 ff ff    	mov    -0x6b4(%rbp),%eax
    1917:	8b 95 50 f9 ff ff    	mov    -0x6b0(%rbp),%edx
    191d:	48 63 d2             	movslq %edx,%rdx
    1920:	48 89 d1             	mov    %rdx,%rcx
    1923:	48 c1 e1 05          	shl    $0x5,%rcx
    1927:	48 8d 15 ae 37 00 00 	lea    0x37ae(%rip),%rdx        # 50dc <func_list+0x1c>
    192e:	89 04 11             	mov    %eax,(%rcx,%rdx,1)
    1931:	8b bd 4c f9 ff ff    	mov    -0x6b4(%rbp),%edi
    1937:	8b b5 48 f9 ff ff    	mov    -0x6b8(%rbp),%esi
    193d:	8b 8d 44 f9 ff ff    	mov    -0x6bc(%rbp),%ecx
    1943:	8b 85 50 f9 ff ff    	mov    -0x6b0(%rbp),%eax
    1949:	48 98                	cltq   
    194b:	48 c1 e0 05          	shl    $0x5,%rax
    194f:	48 89 c2             	mov    %rax,%rdx
    1952:	48 8d 05 6f 37 00 00 	lea    0x376f(%rip),%rax        # 50c8 <func_list+0x8>
    1959:	48 8b 14 02          	mov    (%rdx,%rax,1),%rdx
    195d:	8b 85 50 f9 ff ff    	mov    -0x6b0(%rbp),%eax
    1963:	41 89 f9             	mov    %edi,%r9d
    1966:	41 89 f0             	mov    %esi,%r8d
    1969:	89 c6                	mov    %eax,%esi
    196b:	48 8d 3d d6 18 00 00 	lea    0x18d6(%rip),%rdi        # 3248 <_IO_stdin_used+0x248>
    1972:	b8 00 00 00 00       	mov    $0x0,%eax
    1977:	e8 94 f8 ff ff       	callq  1210 <printf@plt>
    197c:	8b 05 8e 36 00 00    	mov    0x368e(%rip),%eax        # 5010 <results>
    1982:	39 85 50 f9 ff ff    	cmp    %eax,-0x6b0(%rbp)
    1988:	75 0c                	jne    1996 <eval_perf+0x56d>
    198a:	8b 85 48 f9 ff ff    	mov    -0x6b8(%rbp),%eax
    1990:	89 05 82 36 00 00    	mov    %eax,0x3682(%rip)        # 5018 <results+0x8>
    1996:	83 85 50 f9 ff ff 01 	addl   $0x1,-0x6b0(%rbp)
    199d:	8b 05 11 37 00 00    	mov    0x3711(%rip),%eax        # 50b4 <func_counter>
    19a3:	39 85 50 f9 ff ff    	cmp    %eax,-0x6b0(%rbp)
    19a9:	0f 8c c3 fa ff ff    	jl     1472 <eval_perf+0x49>
    19af:	90                   	nop
    19b0:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    19b4:	64 48 33 04 25 28 00 	xor    %fs:0x28,%rax
    19bb:	00 00 
    19bd:	74 05                	je     19c4 <eval_perf+0x59b>
    19bf:	e8 2c f8 ff ff       	callq  11f0 <__stack_chk_fail@plt>
    19c4:	c9                   	leaveq 
    19c5:	c3                   	retq   

00000000000019c6 <usage>:
    19c6:	f3 0f 1e fa          	endbr64 
    19ca:	55                   	push   %rbp
    19cb:	48 89 e5             	mov    %rsp,%rbp
    19ce:	48 83 ec 10          	sub    $0x10,%rsp
    19d2:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
    19d6:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    19da:	48 8b 00             	mov    (%rax),%rax
    19dd:	48 89 c6             	mov    %rax,%rsi
    19e0:	48 8d 3d 91 18 00 00 	lea    0x1891(%rip),%rdi        # 3278 <_IO_stdin_used+0x278>
    19e7:	b8 00 00 00 00       	mov    $0x0,%eax
    19ec:	e8 1f f8 ff ff       	callq  1210 <printf@plt>
    19f1:	48 8d 3d a4 18 00 00 	lea    0x18a4(%rip),%rdi        # 329c <_IO_stdin_used+0x29c>
    19f8:	e8 d3 f7 ff ff       	callq  11d0 <puts@plt>
    19fd:	48 8d 3d a4 18 00 00 	lea    0x18a4(%rip),%rdi        # 32a8 <_IO_stdin_used+0x2a8>
    1a04:	e8 c7 f7 ff ff       	callq  11d0 <puts@plt>
    1a09:	be 00 01 00 00       	mov    $0x100,%esi
    1a0e:	48 8d 3d bb 18 00 00 	lea    0x18bb(%rip),%rdi        # 32d0 <_IO_stdin_used+0x2d0>
    1a15:	b8 00 00 00 00       	mov    $0x0,%eax
    1a1a:	e8 f1 f7 ff ff       	callq  1210 <printf@plt>
    1a1f:	be 00 01 00 00       	mov    $0x100,%esi
    1a24:	48 8d 3d d5 18 00 00 	lea    0x18d5(%rip),%rdi        # 3300 <_IO_stdin_used+0x300>
    1a2b:	b8 00 00 00 00       	mov    $0x0,%eax
    1a30:	e8 db f7 ff ff       	callq  1210 <printf@plt>
    1a35:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    1a39:	48 8b 00             	mov    (%rax),%rax
    1a3c:	48 89 c6             	mov    %rax,%rsi
    1a3f:	48 8d 3d ec 18 00 00 	lea    0x18ec(%rip),%rdi        # 3332 <_IO_stdin_used+0x332>
    1a46:	b8 00 00 00 00       	mov    $0x0,%eax
    1a4b:	e8 c0 f7 ff ff       	callq  1210 <printf@plt>
    1a50:	90                   	nop
    1a51:	c9                   	leaveq 
    1a52:	c3                   	retq   

0000000000001a53 <sigsegv_handler>:
    1a53:	f3 0f 1e fa          	endbr64 
    1a57:	55                   	push   %rbp
    1a58:	48 89 e5             	mov    %rsp,%rbp
    1a5b:	48 83 ec 10          	sub    $0x10,%rsp
    1a5f:	89 7d fc             	mov    %edi,-0x4(%rbp)
    1a62:	48 8d 3d e0 18 00 00 	lea    0x18e0(%rip),%rdi        # 3349 <_IO_stdin_used+0x349>
    1a69:	e8 62 f7 ff ff       	callq  11d0 <puts@plt>
    1a6e:	48 8d 3d ef 18 00 00 	lea    0x18ef(%rip),%rdi        # 3364 <_IO_stdin_used+0x364>
    1a75:	e8 56 f7 ff ff       	callq  11d0 <puts@plt>
    1a7a:	48 8b 05 ff 35 00 00 	mov    0x35ff(%rip),%rax        # 5080 <stdout@@GLIBC_2.2.5>
    1a81:	48 89 c7             	mov    %rax,%rdi
    1a84:	e8 27 f8 ff ff       	callq  12b0 <fflush@plt>
    1a89:	bf 01 00 00 00       	mov    $0x1,%edi
    1a8e:	e8 7d f8 ff ff       	callq  1310 <exit@plt>

0000000000001a93 <sigalrm_handler>:
    1a93:	f3 0f 1e fa          	endbr64 
    1a97:	55                   	push   %rbp
    1a98:	48 89 e5             	mov    %rsp,%rbp
    1a9b:	48 83 ec 10          	sub    $0x10,%rsp
    1a9f:	89 7d fc             	mov    %edi,-0x4(%rbp)
    1aa2:	48 8d 3d d2 18 00 00 	lea    0x18d2(%rip),%rdi        # 337b <_IO_stdin_used+0x37b>
    1aa9:	e8 22 f7 ff ff       	callq  11d0 <puts@plt>
    1aae:	48 8d 3d af 18 00 00 	lea    0x18af(%rip),%rdi        # 3364 <_IO_stdin_used+0x364>
    1ab5:	e8 16 f7 ff ff       	callq  11d0 <puts@plt>
    1aba:	48 8b 05 bf 35 00 00 	mov    0x35bf(%rip),%rax        # 5080 <stdout@@GLIBC_2.2.5>
    1ac1:	48 89 c7             	mov    %rax,%rdi
    1ac4:	e8 e7 f7 ff ff       	callq  12b0 <fflush@plt>
    1ac9:	bf 01 00 00 00       	mov    $0x1,%edi
    1ace:	e8 3d f8 ff ff       	callq  1310 <exit@plt>

0000000000001ad3 <main>:
    1ad3:	f3 0f 1e fa          	endbr64 
    1ad7:	55                   	push   %rbp
    1ad8:	48 89 e5             	mov    %rsp,%rbp
    1adb:	48 83 ec 20          	sub    $0x20,%rsp
    1adf:	89 7d ec             	mov    %edi,-0x14(%rbp)
    1ae2:	48 89 75 e0          	mov    %rsi,-0x20(%rbp)
    1ae6:	eb 74                	jmp    1b5c <main+0x89>
    1ae8:	0f be 45 ff          	movsbl -0x1(%rbp),%eax
    1aec:	83 f8 68             	cmp    $0x68,%eax
    1aef:	74 3f                	je     1b30 <main+0x5d>
    1af1:	83 f8 68             	cmp    $0x68,%eax
    1af4:	7f 50                	jg     1b46 <main+0x73>
    1af6:	83 f8 4d             	cmp    $0x4d,%eax
    1af9:	74 07                	je     1b02 <main+0x2f>
    1afb:	83 f8 4e             	cmp    $0x4e,%eax
    1afe:	74 19                	je     1b19 <main+0x46>
    1b00:	eb 44                	jmp    1b46 <main+0x73>
    1b02:	48 8b 05 7f 35 00 00 	mov    0x357f(%rip),%rax        # 5088 <optarg@@GLIBC_2.2.5>
    1b09:	48 89 c7             	mov    %rax,%rdi
    1b0c:	e8 df f7 ff ff       	callq  12f0 <atoi@plt>
    1b11:	89 05 95 35 00 00    	mov    %eax,0x3595(%rip)        # 50ac <M>
    1b17:	eb 43                	jmp    1b5c <main+0x89>
    1b19:	48 8b 05 68 35 00 00 	mov    0x3568(%rip),%rax        # 5088 <optarg@@GLIBC_2.2.5>
    1b20:	48 89 c7             	mov    %rax,%rdi
    1b23:	e8 c8 f7 ff ff       	callq  12f0 <atoi@plt>
    1b28:	89 05 82 35 00 00    	mov    %eax,0x3582(%rip)        # 50b0 <N>
    1b2e:	eb 2c                	jmp    1b5c <main+0x89>
    1b30:	48 8b 45 e0          	mov    -0x20(%rbp),%rax
    1b34:	48 89 c7             	mov    %rax,%rdi
    1b37:	e8 8a fe ff ff       	callq  19c6 <usage>
    1b3c:	bf 00 00 00 00       	mov    $0x0,%edi
    1b41:	e8 ca f7 ff ff       	callq  1310 <exit@plt>
    1b46:	48 8b 45 e0          	mov    -0x20(%rbp),%rax
    1b4a:	48 89 c7             	mov    %rax,%rdi
    1b4d:	e8 74 fe ff ff       	callq  19c6 <usage>
    1b52:	bf 01 00 00 00       	mov    $0x1,%edi
    1b57:	e8 b4 f7 ff ff       	callq  1310 <exit@plt>
    1b5c:	48 8b 4d e0          	mov    -0x20(%rbp),%rcx
    1b60:	8b 45 ec             	mov    -0x14(%rbp),%eax
    1b63:	48 8d 15 2b 18 00 00 	lea    0x182b(%rip),%rdx        # 3395 <_IO_stdin_used+0x395>
    1b6a:	48 89 ce             	mov    %rcx,%rsi
    1b6d:	89 c7                	mov    %eax,%edi
    1b6f:	e8 6c f7 ff ff       	callq  12e0 <getopt@plt>
    1b74:	88 45 ff             	mov    %al,-0x1(%rbp)
    1b77:	80 7d ff ff          	cmpb   $0xff,-0x1(%rbp)
    1b7b:	0f 85 67 ff ff ff    	jne    1ae8 <main+0x15>
    1b81:	8b 05 25 35 00 00    	mov    0x3525(%rip),%eax        # 50ac <M>
    1b87:	85 c0                	test   %eax,%eax
    1b89:	74 0a                	je     1b95 <main+0xc2>
    1b8b:	8b 05 1f 35 00 00    	mov    0x351f(%rip),%eax        # 50b0 <N>
    1b91:	85 c0                	test   %eax,%eax
    1b93:	75 22                	jne    1bb7 <main+0xe4>
    1b95:	48 8d 3d 04 18 00 00 	lea    0x1804(%rip),%rdi        # 33a0 <_IO_stdin_used+0x3a0>
    1b9c:	e8 2f f6 ff ff       	callq  11d0 <puts@plt>
    1ba1:	48 8b 45 e0          	mov    -0x20(%rbp),%rax
    1ba5:	48 89 c7             	mov    %rax,%rdi
    1ba8:	e8 19 fe ff ff       	callq  19c6 <usage>
    1bad:	bf 01 00 00 00       	mov    $0x1,%edi
    1bb2:	e8 59 f7 ff ff       	callq  1310 <exit@plt>
    1bb7:	8b 05 ef 34 00 00    	mov    0x34ef(%rip),%eax        # 50ac <M>
    1bbd:	3d 00 01 00 00       	cmp    $0x100,%eax
    1bc2:	7f 0d                	jg     1bd1 <main+0xfe>
    1bc4:	8b 05 e6 34 00 00    	mov    0x34e6(%rip),%eax        # 50b0 <N>
    1bca:	3d 00 01 00 00       	cmp    $0x100,%eax
    1bcf:	7e 2c                	jle    1bfd <main+0x12a>
    1bd1:	be 00 01 00 00       	mov    $0x100,%esi
    1bd6:	48 8d 3d e4 17 00 00 	lea    0x17e4(%rip),%rdi        # 33c1 <_IO_stdin_used+0x3c1>
    1bdd:	b8 00 00 00 00       	mov    $0x0,%eax
    1be2:	e8 29 f6 ff ff       	callq  1210 <printf@plt>
    1be7:	48 8b 45 e0          	mov    -0x20(%rbp),%rax
    1beb:	48 89 c7             	mov    %rax,%rdi
    1bee:	e8 d3 fd ff ff       	callq  19c6 <usage>
    1bf3:	bf 01 00 00 00       	mov    $0x1,%edi
    1bf8:	e8 13 f7 ff ff       	callq  1310 <exit@plt>
    1bfd:	48 8d 35 4f fe ff ff 	lea    -0x1b1(%rip),%rsi        # 1a53 <sigsegv_handler>
    1c04:	bf 0b 00 00 00       	mov    $0xb,%edi
    1c09:	e8 82 f6 ff ff       	callq  1290 <__sysv_signal@plt>
    1c0e:	48 83 f8 ff          	cmp    $0xffffffffffffffff,%rax
    1c12:	75 2a                	jne    1c3e <main+0x16b>
    1c14:	48 8b 05 85 34 00 00 	mov    0x3485(%rip),%rax        # 50a0 <stderr@@GLIBC_2.2.5>
    1c1b:	48 89 c1             	mov    %rax,%rcx
    1c1e:	ba 22 00 00 00       	mov    $0x22,%edx
    1c23:	be 01 00 00 00       	mov    $0x1,%esi
    1c28:	48 8d 3d b1 17 00 00 	lea    0x17b1(%rip),%rdi        # 33e0 <_IO_stdin_used+0x3e0>
    1c2f:	e8 ec f6 ff ff       	callq  1320 <fwrite@plt>
    1c34:	bf 01 00 00 00       	mov    $0x1,%edi
    1c39:	e8 d2 f6 ff ff       	callq  1310 <exit@plt>
    1c3e:	48 8d 35 4e fe ff ff 	lea    -0x1b2(%rip),%rsi        # 1a93 <sigalrm_handler>
    1c45:	bf 0e 00 00 00       	mov    $0xe,%edi
    1c4a:	e8 41 f6 ff ff       	callq  1290 <__sysv_signal@plt>
    1c4f:	48 83 f8 ff          	cmp    $0xffffffffffffffff,%rax
    1c53:	75 2a                	jne    1c7f <main+0x1ac>
    1c55:	48 8b 05 44 34 00 00 	mov    0x3444(%rip),%rax        # 50a0 <stderr@@GLIBC_2.2.5>
    1c5c:	48 89 c1             	mov    %rax,%rcx
    1c5f:	ba 22 00 00 00       	mov    $0x22,%edx
    1c64:	be 01 00 00 00       	mov    $0x1,%esi
    1c69:	48 8d 3d 70 17 00 00 	lea    0x1770(%rip),%rdi        # 33e0 <_IO_stdin_used+0x3e0>
    1c70:	e8 ab f6 ff ff       	callq  1320 <fwrite@plt>
    1c75:	bf 01 00 00 00       	mov    $0x1,%edi
    1c7a:	e8 91 f6 ff ff       	callq  1310 <exit@plt>
    1c7f:	bf 58 02 00 00       	mov    $0x258,%edi
    1c84:	e8 b7 f5 ff ff       	callq  1240 <alarm@plt>
    1c89:	ba 05 00 00 00       	mov    $0x5,%edx
    1c8e:	be 01 00 00 00       	mov    $0x1,%esi
    1c93:	bf 05 00 00 00       	mov    $0x5,%edi
    1c98:	e8 8c f7 ff ff       	callq  1429 <eval_perf>
    1c9d:	8b 05 6d 33 00 00    	mov    0x336d(%rip),%eax        # 5010 <results>
    1ca3:	83 f8 ff             	cmp    $0xffffffff,%eax
    1ca6:	75 32                	jne    1cda <main+0x207>
    1ca8:	48 8d 3d 59 17 00 00 	lea    0x1759(%rip),%rdi        # 3408 <_IO_stdin_used+0x408>
    1caf:	e8 1c f5 ff ff       	callq  11d0 <puts@plt>
    1cb4:	48 8d 35 4d 13 00 00 	lea    0x134d(%rip),%rsi        # 3008 <_IO_stdin_used+0x8>
    1cbb:	48 8d 3d 86 17 00 00 	lea    0x1786(%rip),%rdi        # 3448 <_IO_stdin_used+0x448>
    1cc2:	b8 00 00 00 00       	mov    $0x0,%eax
    1cc7:	e8 44 f5 ff ff       	callq  1210 <printf@plt>
    1ccc:	48 8d 3d b2 17 00 00 	lea    0x17b2(%rip),%rdi        # 3485 <_IO_stdin_used+0x485>
    1cd3:	e8 f8 f4 ff ff       	callq  11d0 <puts@plt>
    1cd8:	eb 44                	jmp    1d1e <main+0x24b>
    1cda:	8b 0d 38 33 00 00    	mov    0x3338(%rip),%ecx        # 5018 <results+0x8>
    1ce0:	8b 15 2e 33 00 00    	mov    0x332e(%rip),%edx        # 5014 <results+0x4>
    1ce6:	8b 05 24 33 00 00    	mov    0x3324(%rip),%eax        # 5010 <results>
    1cec:	89 c6                	mov    %eax,%esi
    1cee:	48 8d 3d ab 17 00 00 	lea    0x17ab(%rip),%rdi        # 34a0 <_IO_stdin_used+0x4a0>
    1cf5:	b8 00 00 00 00       	mov    $0x0,%eax
    1cfa:	e8 11 f5 ff ff       	callq  1210 <printf@plt>
    1cff:	8b 15 13 33 00 00    	mov    0x3313(%rip),%edx        # 5018 <results+0x8>
    1d05:	8b 05 09 33 00 00    	mov    0x3309(%rip),%eax        # 5014 <results+0x4>
    1d0b:	89 c6                	mov    %eax,%esi
    1d0d:	48 8d 3d d2 17 00 00 	lea    0x17d2(%rip),%rdi        # 34e6 <_IO_stdin_used+0x4e6>
    1d14:	b8 00 00 00 00       	mov    $0x0,%eax
    1d19:	e8 f2 f4 ff ff       	callq  1210 <printf@plt>
    1d1e:	b8 00 00 00 00       	mov    $0x0,%eax
    1d23:	c9                   	leaveq 
    1d24:	c3                   	retq   

0000000000001d25 <printSummary>:
    1d25:	f3 0f 1e fa          	endbr64 
    1d29:	55                   	push   %rbp
    1d2a:	48 89 e5             	mov    %rsp,%rbp
    1d2d:	48 83 ec 20          	sub    $0x20,%rsp
    1d31:	89 7d ec             	mov    %edi,-0x14(%rbp)
    1d34:	89 75 e8             	mov    %esi,-0x18(%rbp)
    1d37:	89 55 e4             	mov    %edx,-0x1c(%rbp)
    1d3a:	8b 4d e4             	mov    -0x1c(%rbp),%ecx
    1d3d:	8b 55 e8             	mov    -0x18(%rbp),%edx
    1d40:	8b 45 ec             	mov    -0x14(%rbp),%eax
    1d43:	89 c6                	mov    %eax,%esi
    1d45:	48 8d 3d cc 17 00 00 	lea    0x17cc(%rip),%rdi        # 3518 <__PRETTY_FUNCTION__.2780+0x10>
    1d4c:	b8 00 00 00 00       	mov    $0x0,%eax
    1d51:	e8 ba f4 ff ff       	callq  1210 <printf@plt>
    1d56:	48 8d 35 db 17 00 00 	lea    0x17db(%rip),%rsi        # 3538 <__PRETTY_FUNCTION__.2780+0x30>
    1d5d:	48 8d 3d d6 17 00 00 	lea    0x17d6(%rip),%rdi        # 353a <__PRETTY_FUNCTION__.2780+0x32>
    1d64:	e8 67 f5 ff ff       	callq  12d0 <fopen@plt>
    1d69:	48 89 45 f8          	mov    %rax,-0x8(%rbp)
    1d6d:	48 83 7d f8 00       	cmpq   $0x0,-0x8(%rbp)
    1d72:	75 1f                	jne    1d93 <printSummary+0x6e>
    1d74:	48 8d 0d ed 17 00 00 	lea    0x17ed(%rip),%rcx        # 3568 <__PRETTY_FUNCTION__.2223>
    1d7b:	ba 15 00 00 00       	mov    $0x15,%edx
    1d80:	48 8d 35 c1 17 00 00 	lea    0x17c1(%rip),%rsi        # 3548 <__PRETTY_FUNCTION__.2780+0x40>
    1d87:	48 8d 3d c5 17 00 00 	lea    0x17c5(%rip),%rdi        # 3553 <__PRETTY_FUNCTION__.2780+0x4b>
    1d8e:	e8 8d f4 ff ff       	callq  1220 <__assert_fail@plt>
    1d93:	8b 75 e4             	mov    -0x1c(%rbp),%esi
    1d96:	8b 4d e8             	mov    -0x18(%rbp),%ecx
    1d99:	8b 55 ec             	mov    -0x14(%rbp),%edx
    1d9c:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    1da0:	41 89 f0             	mov    %esi,%r8d
    1da3:	48 8d 35 b3 17 00 00 	lea    0x17b3(%rip),%rsi        # 355d <__PRETTY_FUNCTION__.2780+0x55>
    1daa:	48 89 c7             	mov    %rax,%rdi
    1dad:	b8 00 00 00 00       	mov    $0x0,%eax
    1db2:	e8 c9 f4 ff ff       	callq  1280 <fprintf@plt>
    1db7:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    1dbb:	48 89 c7             	mov    %rax,%rdi
    1dbe:	e8 1d f4 ff ff       	callq  11e0 <fclose@plt>
    1dc3:	90                   	nop
    1dc4:	c9                   	leaveq 
    1dc5:	c3                   	retq   

0000000000001dc6 <initMatrix>:
    1dc6:	f3 0f 1e fa          	endbr64 
    1dca:	55                   	push   %rbp
    1dcb:	48 89 e5             	mov    %rsp,%rbp
    1dce:	41 55                	push   %r13
    1dd0:	41 54                	push   %r12
    1dd2:	53                   	push   %rbx
    1dd3:	48 83 ec 48          	sub    $0x48,%rsp
    1dd7:	89 7d bc             	mov    %edi,-0x44(%rbp)
    1dda:	89 75 b8             	mov    %esi,-0x48(%rbp)
    1ddd:	48 89 55 b0          	mov    %rdx,-0x50(%rbp)
    1de1:	48 89 4d a8          	mov    %rcx,-0x58(%rbp)
    1de5:	8b 5d bc             	mov    -0x44(%rbp),%ebx
    1de8:	48 63 c3             	movslq %ebx,%rax
    1deb:	48 83 e8 01          	sub    $0x1,%rax
    1def:	48 89 45 d0          	mov    %rax,-0x30(%rbp)
    1df3:	48 63 c3             	movslq %ebx,%rax
    1df6:	49 89 c2             	mov    %rax,%r10
    1df9:	41 bb 00 00 00 00    	mov    $0x0,%r11d
    1dff:	44 8b 65 b8          	mov    -0x48(%rbp),%r12d
    1e03:	49 63 c4             	movslq %r12d,%rax
    1e06:	48 83 e8 01          	sub    $0x1,%rax
    1e0a:	48 89 45 d8          	mov    %rax,-0x28(%rbp)
    1e0e:	49 63 c4             	movslq %r12d,%rax
    1e11:	49 89 c0             	mov    %rax,%r8
    1e14:	41 b9 00 00 00 00    	mov    $0x0,%r9d
    1e1a:	bf 00 00 00 00       	mov    $0x0,%edi
    1e1f:	e8 7c f4 ff ff       	callq  12a0 <time@plt>
    1e24:	89 c7                	mov    %eax,%edi
    1e26:	e8 25 f4 ff ff       	callq  1250 <srand@plt>
    1e2b:	c7 45 cc 00 00 00 00 	movl   $0x0,-0x34(%rbp)
    1e32:	eb 73                	jmp    1ea7 <initMatrix+0xe1>
    1e34:	c7 45 c8 00 00 00 00 	movl   $0x0,-0x38(%rbp)
    1e3b:	eb 5e                	jmp    1e9b <initMatrix+0xd5>
    1e3d:	8b 45 cc             	mov    -0x34(%rbp),%eax
    1e40:	48 63 d0             	movslq %eax,%rdx
    1e43:	48 63 c3             	movslq %ebx,%rax
    1e46:	48 0f af c2          	imul   %rdx,%rax
    1e4a:	48 8d 14 85 00 00 00 	lea    0x0(,%rax,4),%rdx
    1e51:	00 
    1e52:	48 8b 45 b0          	mov    -0x50(%rbp),%rax
    1e56:	4c 8d 2c 02          	lea    (%rdx,%rax,1),%r13
    1e5a:	e8 d1 f4 ff ff       	callq  1330 <rand@plt>
    1e5f:	8b 55 c8             	mov    -0x38(%rbp),%edx
    1e62:	48 63 d2             	movslq %edx,%rdx
    1e65:	41 89 44 95 00       	mov    %eax,0x0(%r13,%rdx,4)
    1e6a:	8b 45 c8             	mov    -0x38(%rbp),%eax
    1e6d:	48 63 d0             	movslq %eax,%rdx
    1e70:	49 63 c4             	movslq %r12d,%rax
    1e73:	48 0f af c2          	imul   %rdx,%rax
    1e77:	48 8d 14 85 00 00 00 	lea    0x0(,%rax,4),%rdx
    1e7e:	00 
    1e7f:	48 8b 45 a8          	mov    -0x58(%rbp),%rax
    1e83:	4c 8d 2c 02          	lea    (%rdx,%rax,1),%r13
    1e87:	e8 a4 f4 ff ff       	callq  1330 <rand@plt>
    1e8c:	8b 55 cc             	mov    -0x34(%rbp),%edx
    1e8f:	48 63 d2             	movslq %edx,%rdx
    1e92:	41 89 44 95 00       	mov    %eax,0x0(%r13,%rdx,4)
    1e97:	83 45 c8 01          	addl   $0x1,-0x38(%rbp)
    1e9b:	8b 45 c8             	mov    -0x38(%rbp),%eax
    1e9e:	3b 45 bc             	cmp    -0x44(%rbp),%eax
    1ea1:	7c 9a                	jl     1e3d <initMatrix+0x77>
    1ea3:	83 45 cc 01          	addl   $0x1,-0x34(%rbp)
    1ea7:	8b 45 cc             	mov    -0x34(%rbp),%eax
    1eaa:	3b 45 b8             	cmp    -0x48(%rbp),%eax
    1ead:	7c 85                	jl     1e34 <initMatrix+0x6e>
    1eaf:	90                   	nop
    1eb0:	90                   	nop
    1eb1:	48 83 c4 48          	add    $0x48,%rsp
    1eb5:	5b                   	pop    %rbx
    1eb6:	41 5c                	pop    %r12
    1eb8:	41 5d                	pop    %r13
    1eba:	5d                   	pop    %rbp
    1ebb:	c3                   	retq   

0000000000001ebc <randMatrix>:
    1ebc:	f3 0f 1e fa          	endbr64 
    1ec0:	55                   	push   %rbp
    1ec1:	48 89 e5             	mov    %rsp,%rbp
    1ec4:	41 54                	push   %r12
    1ec6:	53                   	push   %rbx
    1ec7:	48 83 ec 20          	sub    $0x20,%rsp
    1ecb:	89 7d dc             	mov    %edi,-0x24(%rbp)
    1ece:	89 75 d8             	mov    %esi,-0x28(%rbp)
    1ed1:	48 89 55 d0          	mov    %rdx,-0x30(%rbp)
    1ed5:	8b 5d dc             	mov    -0x24(%rbp),%ebx
    1ed8:	48 63 c3             	movslq %ebx,%rax
    1edb:	48 83 e8 01          	sub    $0x1,%rax
    1edf:	48 89 45 e8          	mov    %rax,-0x18(%rbp)
    1ee3:	48 63 c3             	movslq %ebx,%rax
    1ee6:	49 89 c0             	mov    %rax,%r8
    1ee9:	41 b9 00 00 00 00    	mov    $0x0,%r9d
    1eef:	bf 00 00 00 00       	mov    $0x0,%edi
    1ef4:	e8 a7 f3 ff ff       	callq  12a0 <time@plt>
    1ef9:	89 c7                	mov    %eax,%edi
    1efb:	e8 50 f3 ff ff       	callq  1250 <srand@plt>
    1f00:	c7 45 e4 00 00 00 00 	movl   $0x0,-0x1c(%rbp)
    1f07:	eb 45                	jmp    1f4e <randMatrix+0x92>
    1f09:	c7 45 e0 00 00 00 00 	movl   $0x0,-0x20(%rbp)
    1f10:	eb 30                	jmp    1f42 <randMatrix+0x86>
    1f12:	8b 45 e4             	mov    -0x1c(%rbp),%eax
    1f15:	48 63 d0             	movslq %eax,%rdx
    1f18:	48 63 c3             	movslq %ebx,%rax
    1f1b:	48 0f af c2          	imul   %rdx,%rax
    1f1f:	48 8d 14 85 00 00 00 	lea    0x0(,%rax,4),%rdx
    1f26:	00 
    1f27:	48 8b 45 d0          	mov    -0x30(%rbp),%rax
    1f2b:	4c 8d 24 02          	lea    (%rdx,%rax,1),%r12
    1f2f:	e8 fc f3 ff ff       	callq  1330 <rand@plt>
    1f34:	8b 55 e0             	mov    -0x20(%rbp),%edx
    1f37:	48 63 d2             	movslq %edx,%rdx
    1f3a:	41 89 04 94          	mov    %eax,(%r12,%rdx,4)
    1f3e:	83 45 e0 01          	addl   $0x1,-0x20(%rbp)
    1f42:	8b 45 e0             	mov    -0x20(%rbp),%eax
    1f45:	3b 45 dc             	cmp    -0x24(%rbp),%eax
    1f48:	7c c8                	jl     1f12 <randMatrix+0x56>
    1f4a:	83 45 e4 01          	addl   $0x1,-0x1c(%rbp)
    1f4e:	8b 45 e4             	mov    -0x1c(%rbp),%eax
    1f51:	3b 45 d8             	cmp    -0x28(%rbp),%eax
    1f54:	7c b3                	jl     1f09 <randMatrix+0x4d>
    1f56:	90                   	nop
    1f57:	90                   	nop
    1f58:	48 83 c4 20          	add    $0x20,%rsp
    1f5c:	5b                   	pop    %rbx
    1f5d:	41 5c                	pop    %r12
    1f5f:	5d                   	pop    %rbp
    1f60:	c3                   	retq   

0000000000001f61 <correctTrans>:
    1f61:	f3 0f 1e fa          	endbr64 
    1f65:	55                   	push   %rbp
    1f66:	48 89 e5             	mov    %rsp,%rbp
    1f69:	89 7d dc             	mov    %edi,-0x24(%rbp)
    1f6c:	89 75 d8             	mov    %esi,-0x28(%rbp)
    1f6f:	48 89 55 d0          	mov    %rdx,-0x30(%rbp)
    1f73:	48 89 4d c8          	mov    %rcx,-0x38(%rbp)
    1f77:	8b 45 dc             	mov    -0x24(%rbp),%eax
    1f7a:	48 63 d0             	movslq %eax,%rdx
    1f7d:	48 83 ea 01          	sub    $0x1,%rdx
    1f81:	48 89 55 f0          	mov    %rdx,-0x10(%rbp)
    1f85:	48 63 d0             	movslq %eax,%rdx
    1f88:	49 89 d2             	mov    %rdx,%r10
    1f8b:	41 bb 00 00 00 00    	mov    $0x0,%r11d
    1f91:	8b 55 d8             	mov    -0x28(%rbp),%edx
    1f94:	48 63 ca             	movslq %edx,%rcx
    1f97:	48 83 e9 01          	sub    $0x1,%rcx
    1f9b:	48 89 4d f8          	mov    %rcx,-0x8(%rbp)
    1f9f:	48 63 ca             	movslq %edx,%rcx
    1fa2:	49 89 c8             	mov    %rcx,%r8
    1fa5:	41 b9 00 00 00 00    	mov    $0x0,%r9d
    1fab:	c7 45 e8 00 00 00 00 	movl   $0x0,-0x18(%rbp)
    1fb2:	eb 6a                	jmp    201e <correctTrans+0xbd>
    1fb4:	c7 45 e4 00 00 00 00 	movl   $0x0,-0x1c(%rbp)
    1fbb:	eb 55                	jmp    2012 <correctTrans+0xb1>
    1fbd:	8b 4d e8             	mov    -0x18(%rbp),%ecx
    1fc0:	48 63 f1             	movslq %ecx,%rsi
    1fc3:	48 63 c8             	movslq %eax,%rcx
    1fc6:	48 0f af ce          	imul   %rsi,%rcx
    1fca:	48 8d 34 8d 00 00 00 	lea    0x0(,%rcx,4),%rsi
    1fd1:	00 
    1fd2:	48 8b 4d d0          	mov    -0x30(%rbp),%rcx
    1fd6:	48 01 ce             	add    %rcx,%rsi
    1fd9:	8b 4d e4             	mov    -0x1c(%rbp),%ecx
    1fdc:	48 63 c9             	movslq %ecx,%rcx
    1fdf:	8b 0c 8e             	mov    (%rsi,%rcx,4),%ecx
    1fe2:	89 4d ec             	mov    %ecx,-0x14(%rbp)
    1fe5:	8b 4d e4             	mov    -0x1c(%rbp),%ecx
    1fe8:	48 63 f1             	movslq %ecx,%rsi
    1feb:	48 63 ca             	movslq %edx,%rcx
    1fee:	48 0f af ce          	imul   %rsi,%rcx
    1ff2:	48 8d 34 8d 00 00 00 	lea    0x0(,%rcx,4),%rsi
    1ff9:	00 
    1ffa:	48 8b 4d c8          	mov    -0x38(%rbp),%rcx
    1ffe:	48 8d 3c 0e          	lea    (%rsi,%rcx,1),%rdi
    2002:	8b 4d e8             	mov    -0x18(%rbp),%ecx
    2005:	48 63 c9             	movslq %ecx,%rcx
    2008:	8b 75 ec             	mov    -0x14(%rbp),%esi
    200b:	89 34 8f             	mov    %esi,(%rdi,%rcx,4)
    200e:	83 45 e4 01          	addl   $0x1,-0x1c(%rbp)
    2012:	8b 4d e4             	mov    -0x1c(%rbp),%ecx
    2015:	3b 4d dc             	cmp    -0x24(%rbp),%ecx
    2018:	7c a3                	jl     1fbd <correctTrans+0x5c>
    201a:	83 45 e8 01          	addl   $0x1,-0x18(%rbp)
    201e:	8b 4d e8             	mov    -0x18(%rbp),%ecx
    2021:	3b 4d d8             	cmp    -0x28(%rbp),%ecx
    2024:	7c 8e                	jl     1fb4 <correctTrans+0x53>
    2026:	90                   	nop
    2027:	90                   	nop
    2028:	5d                   	pop    %rbp
    2029:	c3                   	retq   

000000000000202a <registerTransFunction>:
    202a:	f3 0f 1e fa          	endbr64 
    202e:	55                   	push   %rbp
    202f:	48 89 e5             	mov    %rsp,%rbp
    2032:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
    2036:	48 89 75 f0          	mov    %rsi,-0x10(%rbp)
    203a:	8b 05 74 30 00 00    	mov    0x3074(%rip),%eax        # 50b4 <func_counter>
    2040:	48 98                	cltq   
    2042:	48 c1 e0 05          	shl    $0x5,%rax
    2046:	48 89 c1             	mov    %rax,%rcx
    2049:	48 8d 15 70 30 00 00 	lea    0x3070(%rip),%rdx        # 50c0 <func_list>
    2050:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    2054:	48 89 04 11          	mov    %rax,(%rcx,%rdx,1)
    2058:	8b 05 56 30 00 00    	mov    0x3056(%rip),%eax        # 50b4 <func_counter>
    205e:	48 98                	cltq   
    2060:	48 c1 e0 05          	shl    $0x5,%rax
    2064:	48 89 c1             	mov    %rax,%rcx
    2067:	48 8d 15 5a 30 00 00 	lea    0x305a(%rip),%rdx        # 50c8 <func_list+0x8>
    206e:	48 8b 45 f0          	mov    -0x10(%rbp),%rax
    2072:	48 89 04 11          	mov    %rax,(%rcx,%rdx,1)
    2076:	8b 05 38 30 00 00    	mov    0x3038(%rip),%eax        # 50b4 <func_counter>
    207c:	48 98                	cltq   
    207e:	48 c1 e0 05          	shl    $0x5,%rax
    2082:	48 89 c2             	mov    %rax,%rdx
    2085:	48 8d 05 44 30 00 00 	lea    0x3044(%rip),%rax        # 50d0 <func_list+0x10>
    208c:	c6 04 02 00          	movb   $0x0,(%rdx,%rax,1)
    2090:	8b 05 1e 30 00 00    	mov    0x301e(%rip),%eax        # 50b4 <func_counter>
    2096:	48 98                	cltq   
    2098:	48 c1 e0 05          	shl    $0x5,%rax
    209c:	48 89 c2             	mov    %rax,%rdx
    209f:	48 8d 05 2e 30 00 00 	lea    0x302e(%rip),%rax        # 50d4 <func_list+0x14>
    20a6:	c7 04 02 00 00 00 00 	movl   $0x0,(%rdx,%rax,1)
    20ad:	8b 05 01 30 00 00    	mov    0x3001(%rip),%eax        # 50b4 <func_counter>
    20b3:	48 98                	cltq   
    20b5:	48 c1 e0 05          	shl    $0x5,%rax
    20b9:	48 89 c2             	mov    %rax,%rdx
    20bc:	48 8d 05 15 30 00 00 	lea    0x3015(%rip),%rax        # 50d8 <func_list+0x18>
    20c3:	c7 04 02 00 00 00 00 	movl   $0x0,(%rdx,%rax,1)
    20ca:	8b 05 e4 2f 00 00    	mov    0x2fe4(%rip),%eax        # 50b4 <func_counter>
    20d0:	48 98                	cltq   
    20d2:	48 c1 e0 05          	shl    $0x5,%rax
    20d6:	48 89 c2             	mov    %rax,%rdx
    20d9:	48 8d 05 fc 2f 00 00 	lea    0x2ffc(%rip),%rax        # 50dc <func_list+0x1c>
    20e0:	c7 04 02 00 00 00 00 	movl   $0x0,(%rdx,%rax,1)
    20e7:	8b 05 c7 2f 00 00    	mov    0x2fc7(%rip),%eax        # 50b4 <func_counter>
    20ed:	83 c0 01             	add    $0x1,%eax
    20f0:	89 05 be 2f 00 00    	mov    %eax,0x2fbe(%rip)        # 50b4 <func_counter>
    20f6:	90                   	nop
    20f7:	5d                   	pop    %rbp
    20f8:	c3                   	retq   

00000000000020f9 <trans>:
    20f9:	f3 0f 1e fa          	endbr64 
    20fd:	55                   	push   %rbp
    20fe:	48 89 e5             	mov    %rsp,%rbp
    2101:	89 7d dc             	mov    %edi,-0x24(%rbp)
    2104:	89 75 d8             	mov    %esi,-0x28(%rbp)
    2107:	48 89 55 d0          	mov    %rdx,-0x30(%rbp)
    210b:	48 89 4d c8          	mov    %rcx,-0x38(%rbp)
    210f:	8b 45 dc             	mov    -0x24(%rbp),%eax
    2112:	48 63 d0             	movslq %eax,%rdx
    2115:	48 83 ea 01          	sub    $0x1,%rdx
    2119:	48 89 55 f0          	mov    %rdx,-0x10(%rbp)
    211d:	48 63 d0             	movslq %eax,%rdx
    2120:	49 89 d2             	mov    %rdx,%r10
    2123:	41 bb 00 00 00 00    	mov    $0x0,%r11d
    2129:	8b 55 d8             	mov    -0x28(%rbp),%edx
    212c:	48 63 ca             	movslq %edx,%rcx
    212f:	48 83 e9 01          	sub    $0x1,%rcx
    2133:	48 89 4d f8          	mov    %rcx,-0x8(%rbp)
    2137:	48 63 ca             	movslq %edx,%rcx
    213a:	49 89 c8             	mov    %rcx,%r8
    213d:	41 b9 00 00 00 00    	mov    $0x0,%r9d
    2143:	c7 45 e8 00 00 00 00 	movl   $0x0,-0x18(%rbp)
    214a:	eb 6a                	jmp    21b6 <trans+0xbd>
    214c:	c7 45 e4 00 00 00 00 	movl   $0x0,-0x1c(%rbp)
    2153:	eb 55                	jmp    21aa <trans+0xb1>
    2155:	8b 4d e8             	mov    -0x18(%rbp),%ecx
    2158:	48 63 f1             	movslq %ecx,%rsi
    215b:	48 63 c8             	movslq %eax,%rcx
    215e:	48 0f af ce          	imul   %rsi,%rcx
    2162:	48 8d 34 8d 00 00 00 	lea    0x0(,%rcx,4),%rsi
    2169:	00 
    216a:	48 8b 4d d0          	mov    -0x30(%rbp),%rcx
    216e:	48 01 ce             	add    %rcx,%rsi
    2171:	8b 4d e4             	mov    -0x1c(%rbp),%ecx
    2174:	48 63 c9             	movslq %ecx,%rcx
    2177:	8b 0c 8e             	mov    (%rsi,%rcx,4),%ecx
    217a:	89 4d ec             	mov    %ecx,-0x14(%rbp)
    217d:	8b 4d e4             	mov    -0x1c(%rbp),%ecx
    2180:	48 63 f1             	movslq %ecx,%rsi
    2183:	48 63 ca             	movslq %edx,%rcx
    2186:	48 0f af ce          	imul   %rsi,%rcx
    218a:	48 8d 34 8d 00 00 00 	lea    0x0(,%rcx,4),%rsi
    2191:	00 
    2192:	48 8b 4d c8          	mov    -0x38(%rbp),%rcx
    2196:	48 8d 3c 0e          	lea    (%rsi,%rcx,1),%rdi
    219a:	8b 4d e8             	mov    -0x18(%rbp),%ecx
    219d:	48 63 c9             	movslq %ecx,%rcx
    21a0:	8b 75 ec             	mov    -0x14(%rbp),%esi
    21a3:	89 34 8f             	mov    %esi,(%rdi,%rcx,4)
    21a6:	83 45 e4 01          	addl   $0x1,-0x1c(%rbp)
    21aa:	8b 4d e4             	mov    -0x1c(%rbp),%ecx
    21ad:	3b 4d dc             	cmp    -0x24(%rbp),%ecx
    21b0:	7c a3                	jl     2155 <trans+0x5c>
    21b2:	83 45 e8 01          	addl   $0x1,-0x18(%rbp)
    21b6:	8b 4d e8             	mov    -0x18(%rbp),%ecx
    21b9:	3b 4d d8             	cmp    -0x28(%rbp),%ecx
    21bc:	7c 8e                	jl     214c <trans+0x53>
    21be:	90                   	nop
    21bf:	90                   	nop
    21c0:	5d                   	pop    %rbp
    21c1:	c3                   	retq   

00000000000021c2 <transpose_32_64>:
    21c2:	f3 0f 1e fa          	endbr64 
    21c6:	55                   	push   %rbp
    21c7:	48 89 e5             	mov    %rsp,%rbp
    21ca:	89 7d cc             	mov    %edi,-0x34(%rbp)
    21cd:	89 75 c8             	mov    %esi,-0x38(%rbp)
    21d0:	48 89 55 c0          	mov    %rdx,-0x40(%rbp)
    21d4:	48 89 4d b8          	mov    %rcx,-0x48(%rbp)
    21d8:	8b 4d cc             	mov    -0x34(%rbp),%ecx
    21db:	48 63 c1             	movslq %ecx,%rax
    21de:	48 83 e8 01          	sub    $0x1,%rax
    21e2:	48 89 45 f0          	mov    %rax,-0x10(%rbp)
    21e6:	48 63 c1             	movslq %ecx,%rax
    21e9:	49 89 c2             	mov    %rax,%r10
    21ec:	41 bb 00 00 00 00    	mov    $0x0,%r11d
    21f2:	8b 75 c8             	mov    -0x38(%rbp),%esi
    21f5:	48 63 c6             	movslq %esi,%rax
    21f8:	48 83 e8 01          	sub    $0x1,%rax
    21fc:	48 89 45 f8          	mov    %rax,-0x8(%rbp)
    2200:	48 63 c6             	movslq %esi,%rax
    2203:	49 89 c0             	mov    %rax,%r8
    2206:	41 b9 00 00 00 00    	mov    $0x0,%r9d
    220c:	c7 45 e8 08 00 00 00 	movl   $0x8,-0x18(%rbp)
    2213:	8b 45 cc             	mov    -0x34(%rbp),%eax
    2216:	3b 45 c8             	cmp    -0x38(%rbp),%eax
    2219:	7f 0d                	jg     2228 <transpose_32_64+0x66>
    221b:	8b 45 cc             	mov    -0x34(%rbp),%eax
    221e:	99                   	cltd   
    221f:	f7 7d e8             	idivl  -0x18(%rbp)
    2222:	0f af 45 e8          	imul   -0x18(%rbp),%eax
    2226:	eb 0b                	jmp    2233 <transpose_32_64+0x71>
    2228:	8b 45 c8             	mov    -0x38(%rbp),%eax
    222b:	99                   	cltd   
    222c:	f7 7d e8             	idivl  -0x18(%rbp)
    222f:	0f af 45 e8          	imul   -0x18(%rbp),%eax
    2233:	89 45 ec             	mov    %eax,-0x14(%rbp)
    2236:	c7 45 dc 00 00 00 00 	movl   $0x0,-0x24(%rbp)
    223d:	e9 9e 00 00 00       	jmpq   22e0 <transpose_32_64+0x11e>
    2242:	c7 45 d8 00 00 00 00 	movl   $0x0,-0x28(%rbp)
    2249:	e9 80 00 00 00       	jmpq   22ce <transpose_32_64+0x10c>
    224e:	8b 45 dc             	mov    -0x24(%rbp),%eax
    2251:	89 45 e4             	mov    %eax,-0x1c(%rbp)
    2254:	eb 65                	jmp    22bb <transpose_32_64+0xf9>
    2256:	8b 45 d8             	mov    -0x28(%rbp),%eax
    2259:	89 45 e0             	mov    %eax,-0x20(%rbp)
    225c:	eb 4c                	jmp    22aa <transpose_32_64+0xe8>
    225e:	8b 45 e4             	mov    -0x1c(%rbp),%eax
    2261:	48 63 d0             	movslq %eax,%rdx
    2264:	48 63 c1             	movslq %ecx,%rax
    2267:	48 0f af c2          	imul   %rdx,%rax
    226b:	48 8d 14 85 00 00 00 	lea    0x0(,%rax,4),%rdx
    2272:	00 
    2273:	48 8b 45 c0          	mov    -0x40(%rbp),%rax
    2277:	48 01 c2             	add    %rax,%rdx
    227a:	8b 45 e0             	mov    -0x20(%rbp),%eax
    227d:	48 63 f8             	movslq %eax,%rdi
    2280:	48 63 c6             	movslq %esi,%rax
    2283:	48 0f af c7          	imul   %rdi,%rax
    2287:	48 8d 3c 85 00 00 00 	lea    0x0(,%rax,4),%rdi
    228e:	00 
    228f:	48 8b 45 b8          	mov    -0x48(%rbp),%rax
    2293:	48 01 c7             	add    %rax,%rdi
    2296:	8b 45 e0             	mov    -0x20(%rbp),%eax
    2299:	48 98                	cltq   
    229b:	8b 14 82             	mov    (%rdx,%rax,4),%edx
    229e:	8b 45 e4             	mov    -0x1c(%rbp),%eax
    22a1:	48 98                	cltq   
    22a3:	89 14 87             	mov    %edx,(%rdi,%rax,4)
    22a6:	83 45 e0 01          	addl   $0x1,-0x20(%rbp)
    22aa:	8b 55 d8             	mov    -0x28(%rbp),%edx
    22ad:	8b 45 e8             	mov    -0x18(%rbp),%eax
    22b0:	01 d0                	add    %edx,%eax
    22b2:	39 45 e0             	cmp    %eax,-0x20(%rbp)
    22b5:	7c a7                	jl     225e <transpose_32_64+0x9c>
    22b7:	83 45 e4 01          	addl   $0x1,-0x1c(%rbp)
    22bb:	8b 55 dc             	mov    -0x24(%rbp),%edx
    22be:	8b 45 e8             	mov    -0x18(%rbp),%eax
    22c1:	01 d0                	add    %edx,%eax
    22c3:	39 45 e4             	cmp    %eax,-0x1c(%rbp)
    22c6:	7c 8e                	jl     2256 <transpose_32_64+0x94>
    22c8:	8b 45 e8             	mov    -0x18(%rbp),%eax
    22cb:	01 45 d8             	add    %eax,-0x28(%rbp)
    22ce:	8b 45 d8             	mov    -0x28(%rbp),%eax
    22d1:	3b 45 ec             	cmp    -0x14(%rbp),%eax
    22d4:	0f 8c 74 ff ff ff    	jl     224e <transpose_32_64+0x8c>
    22da:	8b 45 e8             	mov    -0x18(%rbp),%eax
    22dd:	01 45 dc             	add    %eax,-0x24(%rbp)
    22e0:	8b 45 dc             	mov    -0x24(%rbp),%eax
    22e3:	3b 45 ec             	cmp    -0x14(%rbp),%eax
    22e6:	0f 8c 56 ff ff ff    	jl     2242 <transpose_32_64+0x80>
    22ec:	8b 45 dc             	mov    -0x24(%rbp),%eax
    22ef:	89 45 e4             	mov    %eax,-0x1c(%rbp)
    22f2:	eb 60                	jmp    2354 <transpose_32_64+0x192>
    22f4:	8b 45 d8             	mov    -0x28(%rbp),%eax
    22f7:	89 45 e0             	mov    %eax,-0x20(%rbp)
    22fa:	eb 4c                	jmp    2348 <transpose_32_64+0x186>
    22fc:	8b 45 e4             	mov    -0x1c(%rbp),%eax
    22ff:	48 63 d0             	movslq %eax,%rdx
    2302:	48 63 c1             	movslq %ecx,%rax
    2305:	48 0f af c2          	imul   %rdx,%rax
    2309:	48 8d 14 85 00 00 00 	lea    0x0(,%rax,4),%rdx
    2310:	00 
    2311:	48 8b 45 c0          	mov    -0x40(%rbp),%rax
    2315:	48 01 c2             	add    %rax,%rdx
    2318:	8b 45 e0             	mov    -0x20(%rbp),%eax
    231b:	48 63 f8             	movslq %eax,%rdi
    231e:	48 63 c6             	movslq %esi,%rax
    2321:	48 0f af c7          	imul   %rdi,%rax
    2325:	48 8d 3c 85 00 00 00 	lea    0x0(,%rax,4),%rdi
    232c:	00 
    232d:	48 8b 45 b8          	mov    -0x48(%rbp),%rax
    2331:	48 01 c7             	add    %rax,%rdi
    2334:	8b 45 e0             	mov    -0x20(%rbp),%eax
    2337:	48 98                	cltq   
    2339:	8b 14 82             	mov    (%rdx,%rax,4),%edx
    233c:	8b 45 e4             	mov    -0x1c(%rbp),%eax
    233f:	48 98                	cltq   
    2341:	89 14 87             	mov    %edx,(%rdi,%rax,4)
    2344:	83 45 e0 01          	addl   $0x1,-0x20(%rbp)
    2348:	8b 45 e0             	mov    -0x20(%rbp),%eax
    234b:	3b 45 c8             	cmp    -0x38(%rbp),%eax
    234e:	7c ac                	jl     22fc <transpose_32_64+0x13a>
    2350:	83 45 e4 01          	addl   $0x1,-0x1c(%rbp)
    2354:	8b 45 e4             	mov    -0x1c(%rbp),%eax
    2357:	3b 45 cc             	cmp    -0x34(%rbp),%eax
    235a:	7c 98                	jl     22f4 <transpose_32_64+0x132>
    235c:	90                   	nop
    235d:	90                   	nop
    235e:	5d                   	pop    %rbp
    235f:	c3                   	retq   

0000000000002360 <transpose_submit>:
    2360:	f3 0f 1e fa          	endbr64 
    2364:	55                   	push   %rbp
    2365:	48 89 e5             	mov    %rsp,%rbp
    2368:	48 83 ec 30          	sub    $0x30,%rsp
    236c:	89 7d ec             	mov    %edi,-0x14(%rbp)
    236f:	89 75 e8             	mov    %esi,-0x18(%rbp)
    2372:	48 89 55 e0          	mov    %rdx,-0x20(%rbp)
    2376:	48 89 4d d8          	mov    %rcx,-0x28(%rbp)
    237a:	8b 45 ec             	mov    -0x14(%rbp),%eax
    237d:	48 63 d0             	movslq %eax,%rdx
    2380:	48 83 ea 01          	sub    $0x1,%rdx
    2384:	48 89 55 f0          	mov    %rdx,-0x10(%rbp)
    2388:	48 98                	cltq   
    238a:	49 89 c2             	mov    %rax,%r10
    238d:	41 bb 00 00 00 00    	mov    $0x0,%r11d
    2393:	8b 45 e8             	mov    -0x18(%rbp),%eax
    2396:	48 63 d0             	movslq %eax,%rdx
    2399:	48 83 ea 01          	sub    $0x1,%rdx
    239d:	48 89 55 f8          	mov    %rdx,-0x8(%rbp)
    23a1:	48 98                	cltq   
    23a3:	49 89 c0             	mov    %rax,%r8
    23a6:	41 b9 00 00 00 00    	mov    $0x0,%r9d
    23ac:	48 8b 4d d8          	mov    -0x28(%rbp),%rcx
    23b0:	48 8b 55 e0          	mov    -0x20(%rbp),%rdx
    23b4:	8b 75 e8             	mov    -0x18(%rbp),%esi
    23b7:	8b 45 ec             	mov    -0x14(%rbp),%eax
    23ba:	89 c7                	mov    %eax,%edi
    23bc:	e8 01 fe ff ff       	callq  21c2 <transpose_32_64>
    23c1:	90                   	nop
    23c2:	c9                   	leaveq 
    23c3:	c3                   	retq   

00000000000023c4 <registerFunctions>:
    23c4:	f3 0f 1e fa          	endbr64 
    23c8:	55                   	push   %rbp
    23c9:	48 89 e5             	mov    %rsp,%rbp
    23cc:	48 8d 35 8d 2c 00 00 	lea    0x2c8d(%rip),%rsi        # 5060 <transpose_submit_desc>
    23d3:	48 8d 3d 86 ff ff ff 	lea    -0x7a(%rip),%rdi        # 2360 <transpose_submit>
    23da:	e8 4b fc ff ff       	callq  202a <registerTransFunction>
    23df:	90                   	nop
    23e0:	5d                   	pop    %rbp
    23e1:	c3                   	retq   

00000000000023e2 <is_transpose>:
    23e2:	f3 0f 1e fa          	endbr64 
    23e6:	55                   	push   %rbp
    23e7:	48 89 e5             	mov    %rsp,%rbp
    23ea:	89 7d dc             	mov    %edi,-0x24(%rbp)
    23ed:	89 75 d8             	mov    %esi,-0x28(%rbp)
    23f0:	48 89 55 d0          	mov    %rdx,-0x30(%rbp)
    23f4:	48 89 4d c8          	mov    %rcx,-0x38(%rbp)
    23f8:	8b 45 dc             	mov    -0x24(%rbp),%eax
    23fb:	48 63 d0             	movslq %eax,%rdx
    23fe:	48 83 ea 01          	sub    $0x1,%rdx
    2402:	48 89 55 f0          	mov    %rdx,-0x10(%rbp)
    2406:	48 63 d0             	movslq %eax,%rdx
    2409:	49 89 d2             	mov    %rdx,%r10
    240c:	41 bb 00 00 00 00    	mov    $0x0,%r11d
    2412:	8b 55 d8             	mov    -0x28(%rbp),%edx
    2415:	48 63 ca             	movslq %edx,%rcx
    2418:	48 83 e9 01          	sub    $0x1,%rcx
    241c:	48 89 4d f8          	mov    %rcx,-0x8(%rbp)
    2420:	48 63 ca             	movslq %edx,%rcx
    2423:	49 89 c8             	mov    %rcx,%r8
    2426:	41 b9 00 00 00 00    	mov    $0x0,%r9d
    242c:	c7 45 ec 00 00 00 00 	movl   $0x0,-0x14(%rbp)
    2433:	eb 6e                	jmp    24a3 <is_transpose+0xc1>
    2435:	c7 45 e8 00 00 00 00 	movl   $0x0,-0x18(%rbp)
    243c:	eb 59                	jmp    2497 <is_transpose+0xb5>
    243e:	8b 4d ec             	mov    -0x14(%rbp),%ecx
    2441:	48 63 f1             	movslq %ecx,%rsi
    2444:	48 63 c8             	movslq %eax,%rcx
    2447:	48 0f af ce          	imul   %rsi,%rcx
    244b:	48 8d 34 8d 00 00 00 	lea    0x0(,%rcx,4),%rsi
    2452:	00 
    2453:	48 8b 4d d0          	mov    -0x30(%rbp),%rcx
    2457:	48 01 ce             	add    %rcx,%rsi
    245a:	8b 4d e8             	mov    -0x18(%rbp),%ecx
    245d:	48 63 c9             	movslq %ecx,%rcx
    2460:	8b 34 8e             	mov    (%rsi,%rcx,4),%esi
    2463:	8b 4d e8             	mov    -0x18(%rbp),%ecx
    2466:	48 63 f9             	movslq %ecx,%rdi
    2469:	48 63 ca             	movslq %edx,%rcx
    246c:	48 0f af cf          	imul   %rdi,%rcx
    2470:	48 8d 3c 8d 00 00 00 	lea    0x0(,%rcx,4),%rdi
    2477:	00 
    2478:	48 8b 4d c8          	mov    -0x38(%rbp),%rcx
    247c:	48 01 cf             	add    %rcx,%rdi
    247f:	8b 4d ec             	mov    -0x14(%rbp),%ecx
    2482:	48 63 c9             	movslq %ecx,%rcx
    2485:	8b 0c 8f             	mov    (%rdi,%rcx,4),%ecx
    2488:	39 ce                	cmp    %ecx,%esi
    248a:	74 07                	je     2493 <is_transpose+0xb1>
    248c:	b8 00 00 00 00       	mov    $0x0,%eax
    2491:	eb 1d                	jmp    24b0 <is_transpose+0xce>
    2493:	83 45 e8 01          	addl   $0x1,-0x18(%rbp)
    2497:	8b 4d e8             	mov    -0x18(%rbp),%ecx
    249a:	3b 4d dc             	cmp    -0x24(%rbp),%ecx
    249d:	7c 9f                	jl     243e <is_transpose+0x5c>
    249f:	83 45 ec 01          	addl   $0x1,-0x14(%rbp)
    24a3:	8b 4d ec             	mov    -0x14(%rbp),%ecx
    24a6:	3b 4d d8             	cmp    -0x28(%rbp),%ecx
    24a9:	7c 8a                	jl     2435 <is_transpose+0x53>
    24ab:	b8 01 00 00 00       	mov    $0x1,%eax
    24b0:	5d                   	pop    %rbp
    24b1:	c3                   	retq   
    24b2:	66 2e 0f 1f 84 00 00 	nopw   %cs:0x0(%rax,%rax,1)
    24b9:	00 00 00 
    24bc:	0f 1f 40 00          	nopl   0x0(%rax)

00000000000024c0 <__libc_csu_init>:
    24c0:	f3 0f 1e fa          	endbr64 
    24c4:	41 57                	push   %r15
    24c6:	4c 8d 3d 33 28 00 00 	lea    0x2833(%rip),%r15        # 4d00 <__frame_dummy_init_array_entry>
    24cd:	41 56                	push   %r14
    24cf:	49 89 d6             	mov    %rdx,%r14
    24d2:	41 55                	push   %r13
    24d4:	49 89 f5             	mov    %rsi,%r13
    24d7:	41 54                	push   %r12
    24d9:	41 89 fc             	mov    %edi,%r12d
    24dc:	55                   	push   %rbp
    24dd:	48 8d 2d 24 28 00 00 	lea    0x2824(%rip),%rbp        # 4d08 <__do_global_dtors_aux_fini_array_entry>
    24e4:	53                   	push   %rbx
    24e5:	4c 29 fd             	sub    %r15,%rbp
    24e8:	48 83 ec 08          	sub    $0x8,%rsp
    24ec:	e8 0f eb ff ff       	callq  1000 <_init>
    24f1:	48 c1 fd 03          	sar    $0x3,%rbp
    24f5:	74 1f                	je     2516 <__libc_csu_init+0x56>
    24f7:	31 db                	xor    %ebx,%ebx
    24f9:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)
    2500:	4c 89 f2             	mov    %r14,%rdx
    2503:	4c 89 ee             	mov    %r13,%rsi
    2506:	44 89 e7             	mov    %r12d,%edi
    2509:	41 ff 14 df          	callq  *(%r15,%rbx,8)
    250d:	48 83 c3 01          	add    $0x1,%rbx
    2511:	48 39 dd             	cmp    %rbx,%rbp
    2514:	75 ea                	jne    2500 <__libc_csu_init+0x40>
    2516:	48 83 c4 08          	add    $0x8,%rsp
    251a:	5b                   	pop    %rbx
    251b:	5d                   	pop    %rbp
    251c:	41 5c                	pop    %r12
    251e:	41 5d                	pop    %r13
    2520:	41 5e                	pop    %r14
    2522:	41 5f                	pop    %r15
    2524:	c3                   	retq   
    2525:	66 66 2e 0f 1f 84 00 	data16 nopw %cs:0x0(%rax,%rax,1)
    252c:	00 00 00 00 

0000000000002530 <__libc_csu_fini>:
    2530:	f3 0f 1e fa          	endbr64 
    2534:	c3                   	retq   

Disassembly of section .fini:

0000000000002538 <_fini>:
    2538:	f3 0f 1e fa          	endbr64 
    253c:	48 83 ec 08          	sub    $0x8,%rsp
    2540:	48 83 c4 08          	add    $0x8,%rsp
    2544:	c3                   	retq   
