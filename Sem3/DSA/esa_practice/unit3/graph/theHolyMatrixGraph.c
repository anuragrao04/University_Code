#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 10

void initMatrix(int matrix[MAXSIZE][MAXSIZE]) {
  for (int i = 0; i < MAXSIZE; i++) {
    for (int j = 0; j < MAXSIZE; j++) {
      matrix[i][j] = 0;
    }
  }
}

void addEdge(int matrix[][MAXSIZE], int v1, int v2) {
  if (v1 >= MAXSIZE || v2 >= MAXSIZE) {
    printf("Vertice index is out of bounds\n");
  } else {
    matrix[v1][v2] = 1;
  }
}

void clearVisited(int visited[MAXSIZE]) {
  for (int i = 0; i < MAXSIZE; i++) {
    visited[i] = 0;
  }
}

void dfs(int matrix[MAXSIZE][MAXSIZE], int source, int visited[MAXSIZE]) {
  printf("%d ", source);
  visited[source] = 1;
  for (int i = 0; i < MAXSIZE; i++) {
    if (!visited[i] && matrix[source][i]) {
      dfs(matrix, i, visited);
    }
  }
}

void dfs_path(int matrix[MAXSIZE][MAXSIZE], int source, int destination,
              int *count, int path[MAXSIZE], int visited[MAXSIZE]) {
  path[*(count)++] = source;
  printf("%d %d %d\n", source, destination, *count);
  if (source == destination) {
    visited[source] = 1;
    // we found a path
    for (int i = 0; i < *count; i++) {
      printf("->%d", path[i]);
    }
    printf("\n");
  } else { // because count is -1 and -2 for some reason
    visited[source] = 1;
    for (int i = 0; i < MAXSIZE; i++) {
      if (!visited[i] && matrix[source][i]) {
        dfs_path(matrix, i, destination, count, path, visited);
      }
    }
    visited[source] = 0;
    (*count)--;
  }
}

void bfs(int matrix[MAXSIZE][MAXSIZE], int source, int visited[MAXSIZE]) {
  int queue[MAXSIZE * MAXSIZE];
  int f = 0;
  int b = 0;
  queue[b] = source;
  visited[source] = 1;

  while (f <= b) {
    int current = queue[f++];
    printf("%d ", current);
    for (int i = 0; i < MAXSIZE; i++) {
      if (!visited[i] && matrix[current][i]) {
        queue[++b] = i;
        visited[i] = 1;
      }
    }
  }
}

int elementExists(int matrix[][MAXSIZE], int element) {
  for (int i = 0; i < MAXSIZE; i++) {
    if (matrix[element][i] == 1 || matrix[i][element] == 1) {
      return 1;
    }
  }
  return 0;
}

int isStronglyConnected(int matrix[][MAXSIZE]) {
  int visited[MAXSIZE];
  for (int i = 0; i < MAXSIZE; i++) {
    if (elementExists(matrix, i)) {
      clearVisited(visited);
      dfs(matrix, i, visited);
      for (int i = 0; i < MAXSIZE; i++) {
        if (elementExists(matrix, i) && !visited[i]) {
          return 0;
        }
      }
    }
  }
  return 1;
}

int isWeaklyConnected(int matrix[MAXSIZE][MAXSIZE]) {
  int flag = 1;
  int visited[MAXSIZE];
  clearVisited(visited);
  for (int i = 0; i < MAXSIZE; i++) {
    flag = 1;
    if (elementExists(matrix, i)) {
      clearVisited(visited);
      dfs(matrix, i, visited);
      for (int i = 0; i < MAXSIZE; i++) {
        if (elementExists(matrix, i) && !visited[i]) {
          flag = 0;
        }
      }
      if (flag) {
        return 1;
      }
    }
  }
  return 0;
}

int main(int argc, char *argv[]) {
  int matrix[MAXSIZE][MAXSIZE];
  initMatrix(matrix);

  int choice;
  while (1) {
    printf("\n\n1. Enter Edges\n2. DFS\n3. BFS\n4. Check connection status\n5. "
           "DFS Path\n0. "
           "Exit\n");
    printf("Enter choice: ");
    scanf("%d", &choice);
    int v1, v2, source, destination, count, path[MAXSIZE], visited[MAXSIZE];
    switch (choice) {
    case 1:
      while (1) {
        printf("Enter v1 -> v2. -1 -1 to stop: ");
        scanf("%d %d", &v1, &v2);
        if (v1 == -1 && v2 == -1)
          break;
        addEdge(matrix, v1, v2);
      }
      printf("\n");
      for (int i = 0; i < MAXSIZE; i++) {
        for (int j = 0; j < MAXSIZE; j++) {
          printf("%d ", matrix[i][j]);
        }
        printf("\n");
      }
      break;
    case 2:
      printf("Enter source: ");
      scanf("%d", &source);
      clearVisited(visited);
      dfs(matrix, source, visited);

      for (int i = 0; i < MAXSIZE; i++) {
        if (!visited[i] && elementExists(matrix, i))
          dfs(matrix, i, visited);
      }
      clearVisited(visited);
      break;
    case 3:
      printf("Enter source: ");
      scanf("%d", &source);
      clearVisited(visited);
      bfs(matrix, source, visited);
      for (int i = 0; i < MAXSIZE; i++) {
        if (!visited[i] && elementExists(matrix, i))
          bfs(matrix, i, visited);
      }
      clearVisited(visited);
      break;
    case 4:
      if (isStronglyConnected(matrix)) {
        printf("Strongly Connected\n");
      } else if (isWeaklyConnected(matrix)) {
        printf("Weakly Connected\n");
      } else {
        printf("Not Connected\n");
      }
      break;
    case 5:
      printf("Enter source: ");
      scanf("%d", &source);
      printf("Enter destination: ");
      scanf("%d", &destination);
      count = 0;
      clearVisited(visited);
      dfs_path(matrix, source, destination, &count, path, visited);
      break;

    case 0:
      return EXIT_SUCCESS;
    }
  }
  return EXIT_SUCCESS;
}
