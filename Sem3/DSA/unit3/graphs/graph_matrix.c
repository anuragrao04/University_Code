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
    if (matrix[element][i] == 1) {
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

  for (int i = 0; i < MAXSIZE; i++) {
    if (visited[i] == 0 && elementExists(matrix, i)) {
      dfs(matrix, i, visited);
    }
  }
}

void dumb_dfs(int matrix[][MAXSIZE], int source, int visited[]) {
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
    dumb_dfs(matrix, j, visited);
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

    dumb_dfs(matrix, i, visited);

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
    printf("1. Enter Graph\n2. Print DFS\3. Print BFS (Not implemented)\n4. "
           "Print Connection Status\n0. Exit\n");
    int choice;
    scanf("%d", &choice);
    int source;
    switch (choice) {

    case 1:
      while (1) {
        printf("\nEnter vertices and a list of vertices they are connected to. "
               "-1 to stop and go to the next vertice. -2 to stop: ");
        int v1, v2;
        scanf("%d", &v1);
        if (v1 == -2) {
          break;
        }
        while (1) {
          scanf("%d", &v2);
          if (v2 != -1) {
            addEdge(matrix, v1, v2);
          } else {
            break;
          }
        }
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
