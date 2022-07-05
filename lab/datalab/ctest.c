#include <stdio.h>

/*
  V = (-1)^S * 2^E * M
  if normalized:
    2V = 2^(E + 1) * M
  if denormalized:
    2V = 2^E *

*/
unsigned floatScale2(unsigned uf) {
  // NaN or
  if((uf < 0x80000000u && uf >= 0x7f800000u) || uf >= 0xff800000u) // 0111 1111 1000 or 1
    return uf;

  unsigned s = uf & 0x80000000;
  unsigned e = uf & 0x7f800000;
  unsigned f = uf & 0x007fffff;

  printf("[debug] e: 0x%x\n", e);
  printf("[debug] s: 0x%x\n", s);
  printf("[debug] f: 0x%x\n", f);

  // denormalized
  if(e == 0)
    return s + (f << 1);

  // normalized
  return s + (e + 0x800000) + f;
}

int floatFloat2Int(unsigned uf) {
  unsigned s, e, bias, eBias;
  int ret;

  // NaN or Infinity
  if((uf < 0x80000000u && uf >= 0x7f800000u) || uf >= 0xff800000u)
    return 0x80000000u;

  s = uf & 0x80000000;
  e = uf & 0x7f800000;
  bias =   0x3f800000;

  if(e == 0 || e < bias)
    return 0;

  eBias = (e - bias) >> 23;

  if(eBias > 30)
    return 0x80000000u;

  ret = 1 << eBias;

  if(s > 0)
    return ret * -1;
  return ret;
}

unsigned floatPower2(int x) {
  if(x == 0)
    return 0x3f800000; // 1.0
  else if(x > 0) {
    printf("[debug] x > 0: 0x%x\n", x);
    if(x > 0x7f)  // If too large, return +INF.
      return 0x7f800000u;
    printf("[debug] x + 0x7f: 0x%x\n", x + 0x7f);
    return (x + 0x7f) & 0x7f800000;
  }

  if(x == 0x80000000)
    return 0;
  return 0x40000000 >> (-x);
}

int main() {
  /* isTmax */
  // int tmin = 0x80000000;
  // int tmax = 0x7fffffff;
  // printf("0x%x\n", !((tmax + 1) ^ tmin));
  // printf("0x%x\n", tmax >> 31);
  // printf("0x%x\n", (tmax >> 31 ^ 1) & !(tmin ^ tmin));
  // printf("0x%x\n", (tmin + 1) ^ tmin);

  /* allOddBits */
  // int y = 0xaa << 24 | 0xaa << 16 | 0xaa << 8 | 0xaa;
  // int y = ~0x7fffffff ^ 0;
  // printf("0x%x\n", !!y + 0x7fffffff);

  /* negate */
  // printf("%d\n", ~(5) + 1);
  // printf("%d\n", ~(-7) + 1);
  // printf("%d\n", ~(0) + 1);

  /* isAsciiDigit */
  // int x = 0;
  // printf("%d\n", !6 & !!0x38 & !!0x39);
  // x = 0x38;
  // printf("%d\n", !((x >> 3 ^ 6) & (x ^ 0x38) & (x ^ 0x39)));
  // x = 0x39;
  // printf("%d\n", !((x >> 3 ^ 6) & (x ^ 0x38) & (x ^ 0x39)));
  // x = 0x40;
  // printf("%d\n", !((x >> 3 ^ 6) & (x ^ 0x38) & (x ^ 0x39)));
  // x = -0x31;
  // printf("%d\n", !((x >> 3 ^ 6) & (x ^ 0x38) & (x ^ 0x39)));
  // return !((x & y) ^ y);

  /* isLessOrEqual */
  // int x = 0x80000000;
  // int y = 0x8dae3457;
  // int x = 1;
  // int y = 0;
  // int signx = x >> 31;
  // int signy = y >> 31;
  // int isSameSign = !(signx ^ signy);

  // !(x ^ y) | (!isSameSign & signx & !signy) | (isSameSign & (signx ^ ((~y + x) >> 31)));
  // printf("%d\n", signx ^ ((~y + 1 + x) >> 31));
  // printf("0x%x\n", ~0x1);

  /* logicalNeg */
  // int x = 0x7ffffffc;
  // int y = ~(x ^ (x + x));
  // int z = (x >> 31 ^ 1) & (y ^ 0) & (y >> 1 ^ 0) & y & 1;
  // printf("%d\n", z);
  // printf("0x%x\n", ~0);

  /* howManyBits */
  // printf("%d\n", 0xd);
  // printf("%d\n", 0x9);
  // printf("%d\n", 0x8);
  // int c = 0;
  // (x ^ 0) ? 0 : 1;
  // (x >> 1 ^ 0) ? 0 : 2;
  // (x >> 2 ^ 0) ? 0 : 3;
  // (x >> cnt++)
  // count >> !!((x >> 1) ^ 0)
  // int x23 = x >> 23;
  // int x15 = x >> 15;
  // int x7 = x >> 7;
  // (x15 ^ 0) ? (x7 ^ 0) ? (x3 ^ 0) ? (x1 ^ 0) ? (x ^ 0) ? 2 : 1 : 3 : 4 : 5 : 6
  // : (x23)
  // ((x >> 15) ^ 0) ?
  // int b30 = (x >> 30 & 1) ^ 0xe0
  //
  // 30 | 29 | 28 | 1

  /* floatScale2 */
  // printf("expect: 0x1000000 ? 0x%x\n", floatScale2(0x800000));
  // printf("expect: 0x0 ? 0x%x\n", floatScale2(0x0));
  // printf("expect: 0x2 ? 0x%x\n", floatScale2(0x1));
  // printf("expect: 0x1000001 ? 0x%x\n", floatScale2(0x800001));
  // printf("expect: 0x80000000 ? 0x%x\n", floatScale2(0x80000000));
  // printf("expect: 0x7f800000 ? 0x%x\n", floatScale2(0x7f800000));

  /* floatFloat2Int */
  printf("expect: 0x1 ? 0x%x\n", floatFloat2Int(0x3f800000));
  printf("expect: 0xffffffff ? 0x%x\n", floatFloat2Int(0xbf800000));
  printf("expect: 0x80000000 ? 0x%x\n", floatFloat2Int(0x7effffff));

  printf("expect: 0x7f800000 ? 0x%x\n", floatPower2(0x800000));
  printf("0x%x\n", -0x80800000);
  printf("expect: 0x0 ? 0x%x\n", floatPower2(0x80800000));
  /*
    0x7effffff:
    0 11111101 111111111
    0 01111111
      0111 1110
      7e
  */
}
