#include <stdio.h>
#include <stdlib.h>
#include <sys/_types/_pid_t.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  pid_t pid;
  pid = fork();
  // this if statement will only be executed in the parent process
  if (pid > 0) {
    printf("This is the parent process\n");
    printf("Parent going to sleep for 60 seconds\n");
    printf("This makes parent not able to acknowledge child's death\n");
    sleep(60);
  }
  // this below block is run only in the child process
  else if (pid == 0) {
    printf("Child is gonna exit\n");
    exit(0); // child exits here only
  } else {
    printf("Fork Creation Failed\n");
  }
  return EXIT_SUCCESS;
}
