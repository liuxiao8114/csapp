/*
A. The value of CNT.
  mov 0x120(%rsi), %ecx # 280 < 8 + 8 * CNT <= 288

  mov 0x120(%rsi),%ecx
  add (%rsi),%ecx
  lea (%rdi,%rdi,4),%rax
  lea (%rsi,%rax,8),%rax
  mov 0x8(%rax),%rdx
  movslq %ecx,%rcx
  mov %rcx,0x10(%rax,%rdx,8)
  retq

  CNT = 35
*/
#define CNT 7

/*
B. A complete declaration of structure a_struct. Assume that the only fields
in this structure are idx and x, and that both of these contain signed values.

lea (%rdi,%rdi,4),%rax      # rax = 5i
lea (%rsi,%rax,8),%rax      # rax = bp + 8 * rax
mov 0x8(%rax),%rdx          # rdx = (bp + 8 * 5i + 8)
movslq %ecx,%rcx            #
mov %rcx,0x10(%rax,%rdx,8)  #
retq
*/
typedef struct {
  int idx;
  long x[4];
} a_struct;

typedef struct {
  int first;
  a_struct a[CNT];
  int last;
} b_struct;

void test(long i, b_struct *bp) {
  int n = bp->first + bp->last;
  a_struct *ap = &bp->a[i];
  ap->x[ap->idx] = n;
}

/*
3.69 ◆◆◆
void test(long i, b_struct *bp)
i in %rdi, bp in %rsi
1  0000000000000000 <test>:
2  0: 8b 8e 20 01 00 00 mov 0x120(%rsi),%ecx
3  6: 03 0e             add (%rsi),%ecx
4  8: 48 8d 04 bf       lea (%rdi,%rdi,4),%rax
5  c: 48 8d 04 c6       lea (%rsi,%rax,8),%rax
6 10: 48 8b 50 08       mov 0x8(%rax),%rdx
7 14: 48 63 c9          movslq %ecx,%rcx
8 17: 48 89 4c d0 10    mov %rcx,0x10(%rax,%rdx,8)
9 1c: c3                retq
*/
