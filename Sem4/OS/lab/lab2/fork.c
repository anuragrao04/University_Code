#include <stdio.h>
#include <stdlib.h>
#include <sys/_types/_pid_t.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  pid_t pid;
  int y = 0;
  pid = fork();
  // this if statement will only be executed in the parent process
  if (pid > 0) {
    wait(NULL);
    y = y - 1;
    printf("This is the parent process\n");
    printf("Parent PID: %d\n", getpid());
    printf("The value of Y in parent is: %d\n", y);
  }
  // this below block is run only in the child process
  else if (pid == 0) {
    y = y + 1;
    printf("This is the child process\n");
    printf("Child PID: %d\n", getpid());
    printf("The value of Y in child is: %d\n", y);
    exit(0); // child exits here only
  } else {
    printf("Fork Creation Failed\n");
  }
  printf("Only executed in parent since child exited earlier\n");
  return EXIT_SUCCESS;
}
