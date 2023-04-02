#include <stdio.h>

int main(int argc, char const *argv[]) {
  int a, b, c, count;

  scanf("%d %d %d", &a, &b, &c);
  if (a == b) {
    count += 1;
  }
  if (b == c) {
    count += 1;
  }
  if (c == a) {
    count += 1;
  }

  if (count == 0) {
    printf("scalar triangle\n");
  } else if (count == 1) {
    printf("isoceles triangle\n");
  } else {
    printf("equilateral triangle\n");
  }

  return 0;
}
