#include "matrix.h"
#include <stdio.h>

void print(value *val) {
  value v = *val;
  printf("Value is: %f\n", v);
}

int main() {
  Matrix m = make_matrix(3, 3);
  Matrix m1 = make_matrix(3, 3);
  matrix_mult(&m, &m1);
  *matrix_get(&m, 0, 1) = 3;
  matrix_for_each(&m, &print);
  matrix_display(&m);
  return EXIT_SUCCESS;
}
