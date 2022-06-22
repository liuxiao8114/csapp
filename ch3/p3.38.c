#define M 4
#define N 6

long P[M][N];
long Q[N][M];

long sum_element(long i, long j) {
  return P[i][j] + Q[j][i];
}

void main() {
  sum_element(2, 3);
}

/*
leaq 0(,%rdi,8), %rdx
subq %rdi, %rdx
addq %rsi, %rdx
leaq (%rsi,%rsi,4), %rax
addq %rax, %rdi
movq Q(,%rdi,8), %rax
addq P(,%rdx,8), %rax
ret

%rdx: 8i
%rdx: 7i
%rdx: j + 7i  #P, M = 7
%rax: 5j
%rdi: 5j + i  #Q, N = 5
*/
