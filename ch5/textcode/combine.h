#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>

#define IDENT 1
#define OP *

typedef long data_t;

typedef struct {
  long len;
  data_t *data;
} vec_rec, *vec_ptr;

long vec_length(vec_ptr v);
data_t *get_vec_start(vec_ptr v);
vec_ptr new_vec(long len);
int get_vec_element(vec_ptr v, long index, data_t *dest);

void combine1(vec_ptr , data_t *);
void combine2(vec_ptr , data_t *);
void combine3(vec_ptr , data_t *);
void combine4(vec_ptr , data_t *);
void combine5(vec_ptr , data_t *);
void combine6(vec_ptr , data_t *);
