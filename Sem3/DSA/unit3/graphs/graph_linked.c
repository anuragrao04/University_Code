#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

typedef struct vertex {
    int data;
    struct vertex *link;
    int visited;
} vertex_t;



typedef struct graph {
  int count;
  vertex_t *vertices[MAX_SIZE];
} graph_t;



void clearVisited(graph_t* graph){
  for(int i = 0; i < MAX_SIZE; i++){
    if(graph->vertices[i] != NULL)
      graph->vertices[i]->visited = 0;
  }
}


void initGraph(graph_t *graph){
  for(int i = 0; i < MAX_SIZE; i++){
    graph->vertices[i] = NULL;
  }
  graph->count = 0;
}

void addVertex(graph_t *graph, int data){
  vertex_t *newVertex = (vertex_t*)malloc(sizeof(vertex_t));
  newVertex->data = data;
  newVertex->link = NULL;
  graph->vertices[data] = newVertex;
}

void addEdge(graph_t *graph, int vertex, int newVertex){
  vertex_t *new = (vertex_t*)malloc(sizeof(vertex_t));
  new->data = newVertex;
  new->link = NULL;
  vertex_t *temp = graph->vertices[vertex];
  while(temp->link != NULL){
    temp = temp->link;
  }
  temp->link = new;
}



void dfs(graph_t* graph, int source){
  vertex_t *temp = graph->vertices[source];
  printf("%d ", temp->data);
  temp->visited = 1;
  temp = temp->link;
  while(temp != NULL){
    if(temp->visited == 0){
      dfs(graph, temp->data);
    }
    temp = temp->link;
  }
}


int main(int argc, char *argv[])
{
  graph_t graph;
  initGraph(&graph);

  while(1){
    printf("1. Enter Graph\n2. Print DFS\n0. Exit\n");
    int choice;
    scanf("%d", &choice);
    int source;
    switch(choice){

    case 1:
      while(1){
        printf("\nEnter vertices and a list of vertices they are connected to. -1 to stop and go to the next vertice. -2 to stop: ");
        int v1, v2;
        scanf("%d", &v1);
        addVertex(&graph, v1);
        if(v1 == -2){
          break;
        }
        while(1){
          scanf("%d", &v2);
          if(v2 != -1){
            addEdge(&graph, v1, v2);
          } else{
            break;
          }
        }
      }

      printf("\nGraph: \n");
      for(int i = 0; i < MAX_SIZE ;i++){
        if(graph.vertices[i] != NULL){
          printf("%d: ", graph.vertices[i]->data);
          vertex_t *temp = graph.vertices[i]->link;
          while(temp != NULL){
            printf("%d ", temp->data);
            temp = temp->link;
          }
          printf("\n");
        }
      }
      break;

    case 2:
      printf("\nEnter source: ");
      scanf("%d", &source);

      clearVisited(&graph);
      dfs(&graph, source);
      clearVisited(&graph);
      break;

    case 0:
      return EXIT_SUCCESS;

    }
  }

  return EXIT_SUCCESS;
}




