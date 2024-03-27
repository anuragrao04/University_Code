#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
  int fd[2]; // Array to store file descriptors for read and write ends of the pipe

  // Create a pipe
  if (pipe(fd) == -1) {
    perror("pipe");
    return 1;
  }

  // Fork a child process
  pid_t child_pid = fork();

  if (child_pid < 0) {
    perror("fork");
    return 1;
  }

  // Parent process
  if (child_pid > 0) {
    printf("Parent process writing to pipe...\n");
    write(fd[1], "Hello from parent!", 17); // Write to the write end of the pipe
    close(fd[0]); // Close the read end of the pipe (not needed in parent)
  }

  // Child process
  else {
    char buffer[100];
    printf("Child process reading from pipe...\n");
    read(fd[0], buffer, sizeof(buffer)); // Read from the read end of the pipe
    printf("Received from parent: %s\n", buffer);
    close(fd[1]); // Close the write end of the pipe (not needed in child)
  }

  return 0;
}
