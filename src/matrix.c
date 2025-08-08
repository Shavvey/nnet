#include "matrix.h"

Matrix make_matrix(uint nrows, uint ncols) {
  Matrix m = {.nrows = nrows, .ncols = ncols, .data = NULL};
  m.data = (value *)calloc(nrows * ncols, sizeof(value));
  return m;
}

void delete_matrix(Matrix *m) { free(m->data); }

// nice get function to turn 1D array into proper 2D matrix
// i is the row index and j is the col index
value get(Matrix *m, uint i, uint j) { 
  return m->data[i*m->ncols+ j];
}

Matrix mult(Matrix *lhs, Matrix *rhs) { 
}

void for_each(Matrix *m) {
}

