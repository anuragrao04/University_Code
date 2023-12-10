#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 64

typedef struct queue {
  int arr[MAX_SIZE];
  int f;
  int b;
} Q;

void enqueue(Q *queue, int element) {
  if (queue->b == MAX_SIZE - 1) {
    printf("No more space pa\n");
    return;
  } else {
    queue->b++;
    if (queue->f == -1) {
      queue->f++;
    }
    queue->arr[queue->b] = element;
  }
}

int dequeue(Q *queue) {
  if (queue->f == queue->b) {
    if (queue->f == -1) {
      printf("Nothing to dequeue\n");
      return -1;
    } else {
      int toRet = queue->arr[queue->f];
      queue->f = -1;
      queue->b = -1;
      return toRet;
    }
  }

  return queue->arr[queue->f++];
}

int main(int argc, char *argv[]) {
  int choice;
  int element;
  Q queue;
  queue.f = -1;
  queue.b = -1;
  while (1) {
    printf("1. Enqueue\n2. Dequeue\n0. Exit\n");
    scanf("%d", &choice);
    switch (choice) {
    case 1:
      printf("Enter element to enqueue: ");
      scanf("%d", &element);
      enqueue(&queue, element);
      break;
    case 2:
      printf("Dequeued element: %d\n", dequeue(&queue));
      break;
    case 0:
      exit(0);
    default:
      printf("Invalid choice\n");
    }
  }
  return EXIT_SUCCESS;
}
