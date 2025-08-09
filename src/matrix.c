#include "matrix.h"
#include "common.h"
#include <stdbool.h>

Matrix make_matrix(uint nrows, uint ncols) {
  Matrix m = {.nrows = nrows, .ncols = ncols, .data = NULL};
  m.data = (value *)calloc(nrows * ncols, sizeof(value));
  return m;
}

void delete_matrix(Matrix *m) { free(m->data); }

// nice get function to turn 1D array into proper 2D matrix
// i is the row index and j is the col index
value *matrix_get(Matrix *m, uint i, uint j) {
  return &m->data[i * m->ncols + j];
}

static bool check_mdims(Matrix *lhs, Matrix *rhs) {
  uint lncols = lhs->ncols;
  uint rnrows = rhs->nrows;
  return (lncols == rnrows);
}

Matrix matrix_mult(Matrix *lhs, Matrix *rhs) {
  if (!check_mdims(lhs, rhs)) {
    eprintf("Could not multiply matrix!");
  }
  assert(lhs->ncols == rhs->nrows && "Middle dimensions not equal!");
  uint lnrows = lhs->nrows;
  uint rncols = rhs->ncols;
  uint mdim = lhs->ncols;
  Matrix res = make_matrix(lnrows, rncols);
  // preform row-column dot product version of mult
  // NOTE: maybe figure out a mult method with better preformance
  for (uint m = 0; m < mdim; m++) {
    for (uint r = 0; r < lnrows; r++) {
      value mval = 0;
      for (uint c = 0; c < rncols; c++) {
        value rval = *matrix_get(lhs, r, m);
        value cval = *matrix_get(rhs, m, c);
        // row-col dot product
        mval += cval * rval;
      }
      *matrix_get(&res, r, m) = mval;
    }
  }
  return res;
}

void matrix_for_each(Matrix *m, void (*routine)(value *val)) {
  uint ncols = m->ncols;
  uint nrows = m->nrows;
  for (uint r = 0; r < nrows; r++) {
    for (uint c = 0; c < ncols; c++) {
      value v = m->data[r * ncols + c];
      (*routine)(&v);
    }
  }
}

void matrix_display(Matrix *m) {
  StringBuilder sb = {0};
  alist_make(&sb);
  alist_append(&sb, '[');
  // build sb
  for (uint r = 0; r < m->nrows; r++) {
    for (uint c = 0; r < m->ncols; c++) {
      value v = *matrix_get(m, r, c); 
    }
  }
  // print sb
  for (size_t i = 0; i < sb.size; i++) {
    printf("%c", sb.items[i]);
  }
  // free sb
  alist_free(&sb);
}
