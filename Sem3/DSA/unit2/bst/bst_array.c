#include <stdio.h>
#include <stdlib.h>
#define MAX 100


void insert(int bst[], int data);
void inorder(int bst[], int i);
void preorder(int bst[], int i);
void postorder(int bst[], int i);
int min(int bst[]);
int max(int bst[]);
void display(int bst[], int i, int space);

int main(int argc, char *argv[])
{
  int bst[MAX];
  int ch;
  int data;


  int i = 0;
  while(i < MAX){
    bst[i] = -1;
    i++;
  }


  while(1){
    printf("1. Insert\n");
    printf("2. Inorder\n");
    printf("3. Preorder\n");
    printf("4. Postorder\n");
    printf("5. Min\n");
    printf("6. Max\n"); 
    printf("7. Display\n"); 
    printf("0. Exit\n");

    printf("Enter your choice: ");
    scanf("%d", &ch);

    switch(ch){
      case 1:
        printf("Enter the value to be inserted: ");
        scanf("%d", &data);
        insert(bst, data);
        break;
      case 2:
        inorder(bst, 0);
        break;
      case 3:
        preorder(bst, 0);
        break;
      case 4:
        postorder(bst, 0);
        break;
      case 5:
        printf("Min: %d\n", min(bst));
        break;
      case 6:
        printf("Max: %d\n", max(bst));
        break;
      case 7:
        display(bst, 0, 5);
        break;

      case 0:
        exit(0);
      default:
        printf("Invalid choice\n");
    }

  }

  return EXIT_SUCCESS;
}

void insert(int bst[], int data){
  int i = 0; 
  while(bst[i] != -1){
    if(bst[i] < data){
      i = 2*i + 2;
    } else{
      i = 2*i + 1;
    }
  }
  bst[i] = data;
}


void inorder(int bst[], int i){
  if(bst[i] != -1){
    inorder(bst, 2*i + 1);
    printf("%d ", bst[i]);
    inorder(bst, 2*i + 2);
  }
}


void postorder(int bst[], int i){
  if(bst[i] != -1){
    postorder(bst, 2*i + 1);
    postorder(bst, 2*i + 2);
    printf("%d ", bst[i]);
  }
}

void preorder(int bst[], int i){
  if(bst[i] != -1){
    printf("%d ", bst[i]);
    preorder(bst, 2*i + 1);
    preorder(bst, 2*i + 2);
  }
}

int min(int bst[]){
  int i = 0;
  while(bst[2*i + 1] != -1){
    i = 2*i + 1;
  }
  return bst[i];
}


int max(int bst[]){
  int i = 0;
  while(bst[2*i + 2] != -1){
    i = 2*i + 2;
  }
  return bst[i];
}


void display(int bst[], int i, int space){
  if(bst[i] == -1){
    return;
  }
  space += 5;

  display(bst, 2*i + 2, space);

  for(int i = 5; i < space; i++){
    printf(" ");
  }
  printf("%d\n", bst[i]);

  display(bst, 2*i + 1, space);
}

