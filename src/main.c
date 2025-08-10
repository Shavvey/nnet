#include "matrix.h"
#include <stdio.h>

static void set(value *elem) {
  *elem = 2.00;
}

int main() {
  Matrix m1 = make_matrix(2,2);
  Matrix m2 = make_matrix(2,2);
  *matrix_get(&m1, 0, 0) = 1;
  *matrix_get(&m1, 1, 1) = 1;
  matrix_for_each(&m2, &set);
  *matrix_get(&m2, 0, 0) = 3;
  matrix_display(&m1);
  printf("\n");
  matrix_display(&m2);
  Matrix m3 = matrix_mult(&m1, &m2);
  printf("\n");
  matrix_display(&m3);
  return EXIT_SUCCESS;
}
