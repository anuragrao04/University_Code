#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 10

void initGraph(int matrix[][MAXSIZE], int size) {
  for (int i = 0; i < MAXSIZE; i++) {
    for (int j = 0; j < MAXSIZE; j++) {
      matrix[i][j] = 0;
    }
  }
}

void addEdge(int matrix[][MAXSIZE], int v1, int v2) { matrix[v1][v2] = 1; }

int elementExists(int matrix[][MAXSIZE], int element) {
  for (int i = 0; i < MAXSIZE; i++) {
    if (matrix[element][i] == 1 || matrix[i][element] == 1) {
      return 1;
    }
  }
  return 0;
}

void dfs(int matrix[][MAXSIZE], int source, int visited[]) {
  printf("%d ", source);
  visited[source] = 1;
  for (int i = 0; i < MAXSIZE; i++) {
    if (matrix[source][i] == 1 && visited[i] == 0) {
      visited[i] = 1;
      dfs(matrix, i, visited);
    }
  }
}

void clearVisited(int visited[]) {
  for (int i = 0; i < MAXSIZE; i++) {
    visited[i] = 0;
  }
}

int isStronglyConnected(int matrix[][MAXSIZE]) {
  int visited[MAXSIZE];
  clearVisited(visited);

  for (int j = 0; j < MAXSIZE; j++) {
    if (!elementExists(matrix, j)) {
      continue;
    }
    dfs(matrix, j, visited);
    for (int i = 0; i < MAXSIZE; i++) {
      if (visited[i] == 0 && elementExists(matrix, i)) {
        return 0;
      }
    }
    clearVisited(visited);
  }
  return 1;
}

int isWeaklyConnected(int matrix[][MAXSIZE]) {
  int visited[MAXSIZE];
  clearVisited(visited);
  int connected = 1;

  for (int i = 0; i < MAXSIZE; i++) {
    connected = 1;

    if (!elementExists(matrix, i)) {
      continue;
    }

    clearVisited(visited);
    dfs(matrix, i, visited);

    for (int j = 0; j < MAXSIZE; j++) {
      if (visited[j] == 0 && elementExists(matrix, j)) {
        connected = 0;
        break;
      }
    }

    if (connected == 1) {
      return 1;
    }
  }
  return 0;
}

void bfs(int matrix[MAXSIZE][MAXSIZE], int source, int visited[]) {
  int queue[MAXSIZE];
  int front = 0, rear = -1;

  queue[++rear] = source;
  visited[source] = 1;

  while (front <= rear) {
    int current = queue[front++];
    printf("%d ", current);
    for (int i = 0; i < MAXSIZE; i++) {
      if (!visited[i] && matrix[current][i]) {
        queue[++rear] = i;
        visited[i] = 1;
      }
    }
  }
}

void getConnectionStatus(int matrix[][MAXSIZE]) {
  if (isStronglyConnected(matrix)) {
    printf("\nGraph is strongly connected\n");
  } else if (isWeaklyConnected(matrix)) {
    printf("\nGraph is weakly connected\n");
  } else {
    printf("\nGraph is not connected\n");
  }
}

int main(int argc, char *argv[]) {
  int matrix[MAXSIZE][MAXSIZE];

  initGraph(matrix, MAXSIZE);

  while (1) {
    printf("1. Enter Graph\n2. Print DFS\n3. Print BFS\n4. "
           "Print Connection Status\n0. Exit\n");
    int choice;
    scanf("%d", &choice);
    int source;
    int num_edges;
    int v1, v2;
    switch (choice) {

    case 1:
      printf("Enter number of edges: ");
      scanf("%d", &num_edges);
      for (int i = 0; i < num_edges; i++) {
        printf("vertex1 -> vertex2. Enter vertex1 and vertex2: ");
        scanf("%d %d", &v1, &v2);
        addEdge(matrix, v1, v2);
      }

      printf("\nAdjacency Matrix:\n");
      for (int i = 0; i < MAXSIZE; i++) {
        for (int j = 0; j < MAXSIZE; j++) {
          printf("%d ", matrix[i][j]);
        }
        printf("\n");
      }
      break;

    case 2:
      printf("\nEnter source: ");
      scanf("%d", &source);

      int visited[MAXSIZE];
      clearVisited(visited);
      printf("\nDFS: ");
      dfs(matrix, source, visited);
      for (int i = 0; i < MAXSIZE; i++) {
        if (visited[i] == 0 && elementExists(matrix, i)) {
          dfs(matrix, i, visited);
        }
      }
      printf("\n");
      clearVisited(visited);
      break;

    case 3:
      printf("\nEnter source: ");
      scanf("%d", &source);

      clearVisited(visited);
      printf("\nBFS: ");
      bfs(matrix, source, visited);
      for (int i = 0; i < MAXSIZE; i++) {
        if (!visited[i] && elementExists(matrix, i)) {
          bfs(matrix, i, visited);
        }
      }
      printf("\n");
      clearVisited(visited);
      break;

    case 4:
      getConnectionStatus(matrix);
      break;

    case 0:
      return EXIT_SUCCESS;
    }
  }
  return EXIT_SUCCESS;
}
