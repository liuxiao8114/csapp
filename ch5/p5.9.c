void merge(long src1[], long src2[], long dest[], long n) {
  long i1;
  long i2;
  long id;

  while(i1 < n && i2 < n) {
    if(src1[i1] < src2[i2])
      dest[id++] = src1[i1++];
    else
      dest[id++] = src2[i2++];
  }
  /*
  while(i1 < n && i2 < n)
    dest[id++] = (src1[i1] < src2[i2]) ? src1[i1++] : src2[i2++];
  */
}
