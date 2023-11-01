/* 5.7 */
void combine5(vec_ptr v, data_t *dest) {
  long i;
  long length = vec_length(v);
  data_t *data = get_vec_start(v);
  data_t acc = IDENT;

  for(i = 0; i < length; i += 2) {
    acc = acc OP data[i];
    acc = acc OP data[i + 1];
  }

  *dest = acc;
}

void combine6(vec_ptr v, data_t *dest) {
  long i;
  long length = vec_length(v);
  data_t *data = get_vec_start(v);
  data_t acc = IDENT;

  for(i = 0; i < length; i += 2) {
    acc = acc OP data[i];
    acc = acc OP data[i + 1];
  }

  *dest = acc;
}

void combine7(vec_ptr v, data_t *dest) {
  long i;
  long length = vec_length(v);
  data_t *data = get_vec_start(v);
  data_t acc = IDENT;

  for(i = 0; i < length; i += 2) {
    acc = acc OP data[i];
    acc = acc OP data[i + 1];
  }

  *dest = acc;
}
