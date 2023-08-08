#include <stdio.h>
#include <stdlib.h>

void multiply_matrix(int r1, int c1, int r2, int c2, int matrix1[r1][c1],
                     int matrix2[r2][c2]);
int main(int argc, char *argv[]) {
  int r1, r2, c1, c2;
  printf("Enter rowsxcolumns for matrix 1: ");
  scanf("%dx%d", &r1, &c1);

  printf("Enter rowsxcolumns for matrix 2: ");
  scanf("%dx%d", &r2, &c2);

  int matrix1[r1][c1];
  int matrix2[r2][c2];

  printf("Now taking input for matrix 1\n");
  for (int i = 0; i < r1; i++) {
    for (int j = 0; j < c1; j++) {
      printf("Enter element at position (%d, %d): ", i, j);
      scanf("%d", &matrix1[i][j]);
    }
  }

  printf("Now taking input for matrix 2\n");
  for (int i = 0; i < r2; i++) {
    for (int j = 0; j < c2; j++) {
      printf("Enter element at position (%d, %d): ", i, j);
      scanf("%d", &matrix2[i][j]);
    }
  }

  multiply_matrix(r1, c1, r2, c2, matrix1, matrix2);

  return EXIT_SUCCESS;
}

void multiply_matrix(int r1, int c1, int r2, int c2, int matrix1[r1][c1],
                     int matrix2[r2][c2]) {

  if (c1 != r2) {
    printf("can't multiply. The dimensions are not compatible\n");
    return;
  }

  else {

    int matrix_result[r1][c2];

    for (int i = 0; i < r1; i++) {
      for (int j = 0; j < c2; j++) {
        matrix_result[i][j] = 0;
      }
    }

    for (int i = 0; i < r1; i++) {
      for (int j = 0; j < c2; j++) {
        for (int k = 0; k < r2; k++) {
          matrix_result[i][j] += matrix1[i][k] * matrix2[k][j];
        }
      }
    }

    for (int i = 0; i < r1; i++) {
      for (int j = 0; j < c2; j++) {
        printf("%d ", matrix_result[i][j]);
      }
      printf("\n");
    }
  }
}
