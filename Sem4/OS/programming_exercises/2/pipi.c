#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  int pipe_fd[2];
  pid_t child_pid;
  // we create a pipe now
  if (pipe(pipe_fd) == -1) {
    printf("Pipe failed\n");
    exit(1);
  }

  child_pid = fork();
  if (child_pid == -1) {
    printf("Fork failed\n");
    exit(1);
  }

  // parent
  if (child_pid > 0) {
    close(pipe_fd[0]);
    char buffer[256];
    printf("Enter a string: ");
    fgets(buffer, 256, stdin);
    write(pipe_fd[1], buffer, strlen(buffer));
    wait(NULL);
    close(pipe_fd[1]);
  }

  // child
  if (child_pid == 0) {
    close(pipe_fd[1]);
    char buffer[256];
    read(pipe_fd[0], buffer, 256);
    char reversed_buffer[256];
    int counter = 0;
    for (int i = strlen(buffer) - 1; i >= 0; i--) {
      reversed_buffer[counter++] = buffer[i];
    }
    reversed_buffer[counter] = '\0';
    printf("Hi! I'm child. Here's the reversed string: %s\n", reversed_buffer);
    close(pipe_fd[0]);
    exit(0);
  }
  return EXIT_SUCCESS;
}
