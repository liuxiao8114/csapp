#include <math.h>
#include "combine.h"

#define DATA_START 100
#define DATA_STEP 10
#define DATA_END 199

extern void combine1(vec_ptr, data_t *);
extern void combine2(vec_ptr, data_t *);
extern void combine3(vec_ptr, data_t *);
extern void combine4(vec_ptr, data_t *);

void (*combine)(vec_ptr, data_t *);
int set_vec_element(vec_ptr, long, data_t);

int main() {
  int len = ceil((double)(DATA_END - DATA_START) / DATA_STEP);
  vec_ptr p = new_vec(len);
  data_t data;

  for(int i = 0, j = DATA_START; j < DATA_END; i++, j += DATA_STEP)
    set_vec_element(p, i, j);

  combine4(p, &data);

  printf("Acc Result: %ld\n", data);
}

long vec_length(vec_ptr v) {
  return v->len;
}

data_t *get_vec_start(vec_ptr v) {
  return v->data;
}

vec_ptr new_vec(long len) {
  vec_ptr result = (vec_ptr)malloc(sizeof(vec_rec));
  data_t *data = NULL;

  if(!result)
    return NULL;

  result->len = len;
  if(len > 0) {
    data = (data_t *)calloc(len, sizeof(data_t));

    if(!data) {
      free(result);
      return NULL;
    }
  }

  result->data = data;
  return result;
}

int get_vec_element(vec_ptr v, long index, data_t *dest) {
  if(index < 0 || index >= vec_length(v))
    return 0;
  *dest = v->data[index];
  return 1;
}

int set_vec_element(vec_ptr v, long index, data_t value) {
  if(index < 0 || index >= vec_length(v))
    return 0;

  printf("Set %ld = %ld\n", index, value);
  v->data[index] = value;
  return 1;
}
