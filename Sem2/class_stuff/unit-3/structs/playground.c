#include <stdio.h>
#include <stdlib.h>

struct person {
  char name[50];
  int age;
};

void func(struct person *p) { p->age = 19; }

int main(int argc, char *argv[]) {
  struct person persons[] = {"Anurag", 18, "Someone", 17};
  printf("%d\n", persons[1].age);
  func(persons + 1);
  printf("%d\n", persons[1].age);

  return EXIT_SUCCESS;
}
