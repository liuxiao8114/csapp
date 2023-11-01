/*
size_t *ptr;

for(i = 0; i < n - k + 1; i += k) {
  ptr[i]
  ptr[i + 1]
  ptr[i + 2]
  //...
  ptr[i + k - 1]
}

for(; i < n; i++) {
  ptr[i];
}
*/


/* 5 x 1 loop unrolling */
void combine5(vec_ptr v, data_t *dest) {
  long i;
  long length = vec_length(v);
  long UNROLLING = 5;
  data_t *data = get_vec_start(v);
  data_t acc = IDENT;

 /* Combine 5 elements at a time */
 for (i = 0; i < length - UNROLLING + 1; i += UNROLLING) {
   acc =
   (
     (
       (
         (
           acc OP data[i]
         ) OP data[i + 1]
       ) OP data[i + 2]
     ) OP data[i + 3]
   ) OP data[i + 4];
 }

 /* Finish any remaining elements */
 for (; i < length; i++)
   acc = acc OP data[i];

 *dest = acc;
}
