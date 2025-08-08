#ifndef INCLUDE_SRC_MATRIX_H_
#define INCLUDE_SRC_MATRIX_H_
#include <stdlib.h>
#include <stdint.h>
// NOTE: maybe a better name would be number?
typedef float value;
typedef uint32_t uint;
typedef struct _Matrix {
  value *data;
  uint32_t nrows;
  uint32_t ncols;
}Matrix;
// API
Matrix make_matrix(uint nrows, uint ncols);
void delete_matrix(Matrix *m);
value get(Matrix *m, uint i, uint j);
#endif  // INCLUDE_SRC_MATRIX_H_
