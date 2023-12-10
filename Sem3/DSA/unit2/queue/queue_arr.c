#include <stdio.h>
#include <stdlib.h>
// this is not complete. no main function!
#define MAX 2
typedef struct que {
  int arr[MAX];
  int f;
  int b;
} queue;

void enque(queue *que, int data) {
  if (que->b == MAX) {
    printf("Can't insert anymore. array got over\n");
    return;
  } else {
    que->b++;
    if (que->f == -1) {
      que->f++;
    }
    que->arr[que->b] = data;
  }
}

void deque(queue *que) {
  if (que->f == que->b && que->f == -1) {
    printf("No que pa");
    return;
  } else {
    if (que->f == que->b) {
      que->f = -1;
      que->b = -1;
    } else {
      que->f++;
    }
  }
}

void display(queue *que) {
  for (int i = que->f; i <= que->b; i++) {
    printf("%d ", que->arr[i]);
  }
  printf("\n");
}

int main(int argc, char *argv[]) {
  queue que;
  que.f = -1;
  que.b = -1;

  return EXIT_SUCCESS;
}
