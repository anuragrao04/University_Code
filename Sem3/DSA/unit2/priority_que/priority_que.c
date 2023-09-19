#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

typedef struct element {
  int data;
  int priority;
} element;

void enqueue(element *priority_que, int *count, int data, int priority);
int dequeue(element *priority_que, int *count);
void display(element *priority_que, int count);

int main(int argc, char *argv[]) {
  element priority_que[MAX_SIZE]; // array implementation
  int data;
  int priority;
  int count = -1;
  while (1) {
    int choice;
    printf("1. Enque\n2. Deque\n3. Display\n0. Exit\n");
    scanf("%d", &choice);
    switch (choice) {
    case 1:
      printf("Enter data: ");
      scanf("%d", &data);
      printf("Enter priority: ");
      scanf("%d", &priority);
      enqueue(priority_que, &count, data, priority);
      break;
    case 2:
      printf("dequed: %d", dequeue(priority_que, &count));
      break;
    case 3:
      display(priority_que, count);
    case 0:
      return EXIT_SUCCESS;
    }
  }
  return EXIT_SUCCESS;
}

void enqueue(element *priority_que, int *count, int data, int priority) {
  int i = (*count) - 1;
  element new_element = {data, priority};

  while (i >= 0 && priority_que[i].data > data) {
    priority_que[i + 1] = priority_que[i];
    i--;
  }
  priority_que[i + 1] = new_element;
  (*count)++;

  display(priority_que, *count);
}

int dequeue(element *priority_que, int *count) {
  if (*count == -1) {
    return -1;
  } else {
    (*count)--;
    return priority_que[0].data;
  }
}

void display(element *priority_que, int count) {
  for (int i = 0; i <= count; i++) {
    printf("%5d", priority_que[i].data);
  }
  printf("\n");
  for (int i = 0; i <= count; i++) {
    printf("%5d", priority_que[i].priority);
  }
  printf("\n");
}
