gdb bomb

// explode_bomb
b *0x40143a

// phase1
b *0x400ee0

b *0x400eee   // phase1 check

Border relations with Canada have never been better.

0x402400:       0x64726f42
0x402401:       0x6564726f
0x402402:       0x72656472
0x402403:       0x20726564
0x402404:       0x72207265
0x402405:       0x65722072
0x402406:       0x6c657220
0x402407:       0x616c6572
0x402408:       0x74616c65
0x402409:       0x6974616c


0x40240a:       0x6f697461
0x40240b:       0x6e6f6974
0x40240c:       0x736e6f69
...
                  droB            o oe            taie
0x402400:       0x64726f42      0x72207265      0x74616c65      0x736e6f69
0x402410:       0x74697720      0x61432068      0x6164616e      0x76616820
0x402420:       0x656e2065      0x20726576      0x6e656562      0x74656220
0x402430:       0x2e726574      

// return from the second call of read_line()
b *0x400e53

// phase2
Border relations with Canada have never been better.

b *0x40148f   // before explode in read_six_numbers()








b *0x400f0a   // return from read_six_numbers, check if explode in phase2()
b *0x400f1c   // another check if explode in phase2()

read_six_numbers()
rdi            0x6037d0
rsi            0x7fffffffdf30

0x7fffffffdf30: 0x00000000
0x7fffffffdf32: 0x00000000
0x7fffffffdf34: 0x00000000
0x7fffffffdf38: 0x006037d0
0x7fffffffdf44: 0x00000000

0x7fffffffdf30: 0x00000000      0x00000000      0x006037d0      0x00000000
0x7fffffffdf40: 0x00000000      0x00000000      0x00401431      0x00000000

x/8 0x7fffffffdf30
x/8g 0x4025c3

0x4025c3:       0x25206425

scanf(input, 0x25206425, null, null, 0x006037d0, 0xffffdf40, 0xffffdf44)


scanf(
  input,            %rdi
  0x4025c3,         %rsi
  0x7fffffffdf30,   %rdx
  0x7fffffffdf34,   %rcx
  0x7fffffffdf38,   %r8
  0x7fffffffdf3c,   %r9
  0x7fffffffdf10,   %rsp
  0x7fffffffdf18    %rsp + 8
)

si
ni
i r
disas

0x4025c3:       0x25206425      0x64252064      0x20642520      0x25206425
0x4025d3:       0x72450064      0x3a726f72      0x65725020      0x7574616d
0x4025e3:       0x45206572      0x6f20464f      0x7473206e      0x006e6964
0x4025f3:       0x44415247      0x4f425f45      0x4500424d      0x726f7272
0x402603:       0x6e49203a      0x20747570      0x656e696c      0x6f6f7420
0x402613:       0x6e6f6c20      0x64250067      0x20642520      0x44007325
0x402623:       0x69764572      0x7267006c      0x77746165      0x65746968
0x402633:       0x7363692e      0x2e73632e      0x2e756d63      0x00756465

0x402643:       0x65676e61      0x6168736c      0x692e6b72      0x632e7363
0x402653:       0x6d632e73      0x64652e75      0x616d0075      0x68736f6b
0x402663:       0x2e6b7261      0x2e736369      0x632e7363      0x652e756d
0x402673:       0x00007564      0x6f725000      0x6d617267      0x6d697420
0x402683:       0x6f206465      0x61207475      0x72657466      0x20642520
0x402693:       0x6f636573      0x0a73646e      0x00000000      0x72724500
0x4026a3:       0x203a726f      0x50545448      0x71657220      0x74736575
0x4026b3:       0x69616620      0x2064656c      0x68746977      0x72726520

x $rdx
x/8 0x40240a

// phase3:
Border relations with Canada have never been better.
1 2 4 8 16 32

b *0x400f60 // check(inputLength) if explode
b *0x400fad // before explode after too many checks

%d %d

1st %d: [ 0, 1, 2, 3, 4, 5, 6 ]
2nd %d: [ ?, 311, ]

return from sscanf:
rsp            0x7fffffffdf50

(gdb) x/8 $rsp
0x7fffffffdf50: 0x00402210      0x00000000      0x00000001      0x00000002
0x7fffffffdf60: 0x00000000      0x00000000      0x00400e77      0x00000000

(gdb) x 0x402470
0x402470:       0x00400f7c      0x00000000      0x00400fb9      0x00000000
0x402480:       0x00400f83      0x00000000      0x00400f8a      0x00000000
0x402490:       0x00400f91      0x00000000      0x00400f98      0x00000000
0x4024a0:       0x00400f9f      0x00000000      0x00400fa6      0x00000000

// phase4:
Border relations with Canada have never been better.
1 2 4 8 16 32
1 311

b *0x40101a
b *0x401029
b *0x40102e
b *0x400fce
b *0x400fe2
b *0x40104d

``` c
int start = 0;
int end = 14;
//      %rdi,      %rsi,    %rdx
func4(int p1, int start, int end) {
  int i, j; // i: %rax, j: %rcx
  i = start - end;
  j = i;
  j = j >> 31;
  i += j;
  i = i >> 1;
  j = i + start + 1;

  if(j > p1) {
    end = j - 1;
    return func4(p1, start, end) * 2;
  }
  i = 0;

  if(j >= p1)
    return i;
  start = j - 1;
  return func4(p1, start, end) * 2 + 1;
}
```

// phase5:
Border relations with Canada have never been better.
1 2 4 8 16 32
1 311
1 0

b *0x401062
