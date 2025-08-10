#include "matrix.h"
#include "common.h"
#include <stdbool.h>

Matrix make_matrix(uint nrows, uint ncols) {
  Matrix m = {.nrows = nrows, .ncols = ncols, .data = NULL};
  m.data = (value *)calloc(nrows * ncols, sizeof(value));
  return m;
}

void delete_matrix(Matrix *m) { free(m->data); }

inline value *matrix_get(Matrix *m, uint rdx, uint cdx) {
  return &m->data[rdx * m->ncols + cdx];
}

static bool check_mdims(Matrix *lhs, Matrix *rhs) {
  uint lncols = lhs->ncols;
  uint rnrows = rhs->nrows;
  return (lncols == rnrows);
}

// NOTE: mabye implement Strassen Matrix multipliation
Matrix matrix_mult(Matrix *lhs, Matrix *rhs) {
  if (!check_mdims(lhs, rhs)) {
    eprintf("Could not multiply matrix!\n");
  }
  assert(lhs->ncols == rhs->nrows && "Middle dimensions not equal!\n");
  uint lnrows = lhs->nrows;
  uint rncols = rhs->ncols;
  uint mdim = lhs->ncols;
  Matrix res = make_matrix(lnrows, rncols);
  // preform row-column dot product version of mult
  // NOTE: maybe figure out a mult method with better preformance
  for (uint r = 0; r < lnrows; r++) {
    for (uint c = 0; c < rncols; c++) {
      *matrix_get(&res, r, c) = 0;
      for (uint m = 0; m < mdim; m++) {
        value rval = *matrix_get(lhs, r, m);
        value cval = *matrix_get(rhs, m, c);
        *matrix_get(&res, r, c) += rval * cval;
      }
    }
  }
  return res;
}

void matrix_for_each(Matrix *m, void (*routine)(value *val)) {
  uint ncols = m->ncols;
  uint nrows = m->nrows;
  for (uint r = 0; r < nrows; r++) {
    for (uint c = 0; c < ncols; c++) {
      value *v = &m->data[r * ncols + c];
      (*routine)(v);
    }
  }
}

void matrix_display(Matrix *m) {
  const uint FLOAT_SIZE = 5;
  StringBuilder sb = {0};
  alist_make(&sb);
  // build sb
  char *vstr = (char *)malloc(FLOAT_SIZE * sizeof(char));
  for (uint r = 0; r < m->nrows; r++) {
    alist_append(&sb, '['); // opening brackets
    for (uint c = 0; c < m->ncols; c++) {
      value v = *matrix_get(m, r, c);
      snprintf(vstr, FLOAT_SIZE, "%.2f", v);
      alist_append_many(&sb, vstr, FLOAT_SIZE);
      if (c < m->ncols - 1)
        alist_append_many(&sb, ", ", 2);
    }
    alist_append(&sb, ']'); // closing brackets
    alist_append(&sb, '\n');
  }
  free(vstr);
  // print sb
  for (size_t i = 0; i < sb.size; i++) {
    printf("%c", sb.items[i]);
  }
  // free sb
  alist_free(&sb);
}
