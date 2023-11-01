#define A 9
#define B 5

typedef struct {
  int x[A][B]; /* Unknown constants A and B */
  long y;
} str1;

typedef struct {
  char array[B];
  int t;
  short s[A];
  long u;
} str2;

void setVal(str1 *p, str2 *q) {
  long v1 = q->t;
  long v2 = q->u;
  p->y = v1 + v2;
}

/*
3.68 ◆◆◆
void setVal(str1 *p, str2 *q)
p in %rdi, q in %rsi
setVal:
movslq 8(%rsi), %rax  # 4 < B <= 8
addq  32(%rsi), %rax  # 6 < A <= 10
movq  %rax, 184(%rdi) # 176 < 4 * A * B <= 184
ret
*/
