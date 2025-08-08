#include "matrix.h"

Matrix make_matrix(uint nrows, uint ncols) {
  Matrix m = {.nrows = nrows, .ncols = ncols, .data = NULL};
  // do all of our allocation here
  m.data = (value *)calloc(nrows * ncols, sizeof(value));
  return m;
}

void delete_matrix(Matrix *m) { free(m->data); }

value get(Matrix *m, uint i, uint j) { 
  return 0;
}

