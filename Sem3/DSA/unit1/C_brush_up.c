#include <stdio.h>
#include <stdlib.h>
#define EMPLOYEE_SIZE 3
typedef struct employee {
  int ID;
  int salary;
} employee_t;

void read(employee_t *employee) {
  printf("Enter ID: ");
  scanf("%d", &employee->ID);
  printf("Enter Salary: ");
  scanf("%d", &employee->salary);
}

void print(employee_t *employee) {
  printf("ID: %d\nsalary: %d\n", employee->ID, employee->salary);
}

int main(int argc, char *argv[]) {

  employee_t *pEmployees =
      (employee_t *)malloc(EMPLOYEE_SIZE * sizeof(employee_t));

  for (int i = 0; i < EMPLOYEE_SIZE; i++) {
    printf("Employee %d:\n", i + 1);
    read(pEmployees++);
  }
  pEmployees -= EMPLOYEE_SIZE;

  printf("\nDetails: \n");
  for (int i = 0; i < EMPLOYEE_SIZE; i++) {
    printf("Employee %d:\n", i + 1);
    print(pEmployees++);
  }

  return EXIT_SUCCESS;
}
