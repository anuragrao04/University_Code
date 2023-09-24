#include <stdio.h>
#include <stdlib.h>
#define MAX 32
typedef struct que{
  int arr[MAX];
  int f;
  int b;
} queue;


void enque(queue* que, int data){
  if(que->b == MAX-1){
    if(que->f > 0){
      que->b = 0;
      que->arr[que->b] = data;
      return;
    } else{
      printf("No space pa\n");
      return;
    }
  } 

  que->arr[++que->b] = data;
}

void deque(queue* que){
  if(que->f == que->b && que->f == -1){
    printf("No que pa");
    return;
  } else{
    if(que->f == que->b){
      que->f = -1;
      que->b = -1;
    } else{
      if(que->f == MAX-1){
        que->f = 0; 
        return;
      }
      else{
        que->f++;
      }
    }
  }
}

void display(queue* que){
  if(que->f == que->b && que->f == -1){
    printf("No que\n");
  } else{
    if(que->f > que->b){
      for(int i = que->f; i < MAX; i++){
        printf("%d ", que->arr[i]);
      }
      for(int i = 0; i < que->b; i++){
        printf("%d ", que->arr[i]);
      }
      printf("\n");
    } else{
      for(int i = que->f; i <= que->b; i++){
        printf("%d ", que->arr[i]);
      }
      printf("\n");
    }
  }
}


int main(int argc, char *argv[])
{
  int choice;
  queue que;
  que.f = -1;
  que.b = -1;
  while(1){
    printf("1. Enque\n2. Deque\n3. Display\n4. Exit\n");
    scanf("%d", &choice);
    switch(choice){
      case 1:
        printf("Enter data: ");
        int data;
        scanf("%d", &data);
        enque(&que, data);
        break;
      case 2:
        deque(&que);
        break;
      case 3:
        display(&que);
        break;
      case 4:
        exit(0);
        break;
      default:
        printf("Invalid choice\n");
    }
  }


  return EXIT_SUCCESS;
}

