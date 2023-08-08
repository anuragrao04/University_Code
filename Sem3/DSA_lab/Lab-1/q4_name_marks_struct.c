#include <stdio.h>
#include <stdlib.h>

typedef struct student {
  int marks1, marks2, marks3;
  char name[64];
} student_t;

void read(student_t *student) {
  printf("Enter name of the student: ");
  fgets(student->name, 64, stdin);
  printf("Enter marks 1: ");
  scanf("%d", &student->marks1);
  printf("Enter marks 2: ");
  scanf("%d", &student->marks2);
  printf("Enter marks 3: ");
  scanf("%d", &student->marks3);
}

void print(student_t *student) {
  printf("\nDetails: \n");
  printf("Name: %sMarks1: %d\nMarks2: %d\nMarks3: %d\n", student->name,
         student->marks1, student->marks2, student->marks3);
  int avg = student->marks1 + student->marks2 + student->marks3;
  avg = avg / 3;
  printf("Average: %d\n", avg);
}

int main(int argc, char *argv[]) {

  student_t student;

  read(&student);
  print(&student);

  return EXIT_SUCCESS;
}
