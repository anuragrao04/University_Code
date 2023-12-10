#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 2

typedef struct queue {
  int arr[MAX_SIZE];
  int f;
  int b;
} Q;

int is_empty(Q *queue) { return queue->f == queue->b && queue->f == -1; }

int is_full(Q *queue) { return (queue->b + 1) % MAX_SIZE == queue->f; }

void enqueue(Q *queue, int element) {
  // Check if the queue is empty
  if (is_empty(queue)) {
    queue->f = 0;
    queue->b = 0;
  } else {
    // Check if the queue is full
    if (is_full(queue)) {
      printf("Not enough space\n");
      return;
    }

    // Check if the back is at the end of the array
    if (queue->b == MAX_SIZE - 1) {
      queue->b = 0;
    } else {
      queue->b++;
    }
  }

  // Add the element to the queue
  queue->arr[queue->b] = element;
}

int dequeue(Q *queue) {
  // Check if the queue is empty
  if (is_empty(queue)) {
    printf("Nothing to dequeue\n");
    return -1;
  }
  // Get the element to return
  int element = queue->arr[queue->f];
  // Update the front of the queue
  if (queue->f == queue->b) {
    // Only element remaining, reset queue
    queue->f = -1;
    queue->b = -1;
  } else if (queue->f == MAX_SIZE - 1) {
    // Wrap around the array
    queue->f = 0;
  } else {
    // Normal increment
    queue->f++;
  }
  // Return the element
  return element;
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
