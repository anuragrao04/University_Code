#include <stdio.h>
#include <stdlib.h>

void add(int matrix1[][10], int matrix2[][10], int r1, int c1, int r2, int c2);
void sub(int matrix1[][10], int matrix2[][10], int r1, int c1, int r2, int c2);
void mul(int matrix1[][10], int matrix2[][10], int r1, int c1, int r2, int c2);

int main(int argc, char *argv[]) {

  int r1, c1, r2, c2;
  printf("\n\nNote that the max number of columns are 10\n\n");
  printf("Enter the dimensions of matrix1 in the form of rowsxcolumns: ");
  scanf("%dx%d", &r1, &c1);

  printf("\nEnter the dimensions of matrix2 in the form of rowsxcolumns: ");
  scanf("%dx%d", &r2, &c2);

  int matrix1[r1][10];
  int matrix2[r2][10];

  printf("\n\nPlease input values for Matrix1: ");
  for (int i = 0; i < r1; i++) {
    for (int j = 0; j < c1; j++) {
      printf("\nEnter integer at position row = %d and column = %d: ", i, j);
      scanf("%d", &matrix1[i][j]);
    }
  }

  printf("\n\nPlease input values for Matrix2: ");
  for (int i = 0; i < r2; i++) {
    for (int j = 0; j < c2; j++) {
      printf("\nEnter integer at position row = %d and column = %d: ", i, j);
      scanf("%d", &matrix2[i][j]);
    }
  }

  char operator;
  printf("\nEnter operator (+, -, *): ");
  scanf(" %c", &operator);
  switch (operator) {
  case '+':
    add(matrix1, matrix2, r1, c1, r2, c2);
    break;
  case '-':
    sub(matrix1, matrix2, r1, c1, r2, c2);
    break;
  case '*':
    mul(matrix1, matrix2, r1, c1, r2, c2);
    break;
  default:
    printf("\nInvalid Operator, exiting!");
  }

  return EXIT_SUCCESS;
}

void add(int matrix1[][10], int matrix2[][10], int r1, int c1, int r2, int c2) {
  if (r1 != r2 || c1 != c2) {
    printf("\nThe dimensions are not equal, exiting!\n");
    return;
  }

  for (int i = 0; i < r1; i++) {
    for (int j = 0; j < c1; j++) {
      printf("%5d ", matrix1[i][j]);
    }
    printf("\n");
  }

  printf("\n + \n\n");

  for (int i = 0; i < r2; i++) {
    for (int j = 0; j < c2; j++) {
      printf("%5d ", matrix2[i][j]);
    }
    printf("\n");
  }

  printf("\n = \n\n");

  int matrix_result[r1][c1];
  for (int i = 0; i < r1; i++) {
    for (int j = 0; j < c1; j++) {
      matrix_result[i][j] = matrix1[i][j] + matrix2[i][j];
    }
  }

  for (int i = 0; i < r1; i++) {
    for (int j = 0; j < c1; j++) {
      printf("%5d ", matrix_result[i][j]);
    }
    printf("\n");
  }
}

void sub(int matrix1[][10], int matrix2[][10], int r1, int c1, int r2, int c2) {

  if (r1 != r2 || c1 != c2) {
    printf("\nThe dimensions are not equal, exiting!\n");
    return;
  }

  for (int i = 0; i < r1; i++) {
    for (int j = 0; j < c1; j++) {
      printf("%5d ", matrix1[i][j]);
    }
    printf("\n");
  }

  printf("\n - \n\n");

  for (int i = 0; i < r2; i++) {
    for (int j = 0; j < c2; j++) {
      printf("%5d ", matrix2[i][j]);
    }
    printf("\n");
  }

  printf("\n = \n\n");

  int matrix_result[r1][c1];
  for (int i = 0; i < r1; i++) {
    for (int j = 0; j < c1; j++) {
      matrix_result[i][j] = matrix1[i][j] - matrix2[i][j];
    }
  }

  for (int i = 0; i < r1; i++) {
    for (int j = 0; j < c1; j++) {
      printf("%5d ", matrix_result[i][j]);
    }
    printf("\n");
  }
}
void mul(int matrix1[][10], int matrix2[][10], int r1, int c1, int r2, int c2) {
  if (c1 != r2) {
    printf("Wrong dimensions, exiting!");
  }

  int matrix_result[r1][c2];
  // init all elements to 0
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
    for (int j = 0; j < c1; j++) {
      printf("%5d ", matrix1[i][j]);
    }
    printf("\n");
  }

  printf("\n * \n\n");

  for (int i = 0; i < r2; i++) {
    for (int j = 0; j < c2; j++) {
      printf("%5d ", matrix2[i][j]);
    }
    printf("\n");
  }

  printf("\n = \n\n");

  for (int i = 0; i < r1; i++) {
    for (int j = 0; j < c2; j++) {
      printf("%5d ", matrix_result[i][j]);
    }
    printf("\n");
  }
}
