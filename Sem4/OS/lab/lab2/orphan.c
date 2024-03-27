#include <stdio.h>
#include <stdlib.h>
#include <sys/_types/_pid_t.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  pid_t pid;
  pid = fork();
  // this if statement will only be executed in the parent process
  if (pid > 0) {
    printf("This is the parent process. Gonna die\n");
    exit(0);
  }
  // this below block is run only in the child process
  else if (pid == 0) {
    printf("Child going to sleep for 60 seconds\n");
    printf("This makes parent die and child stay alive\n");
    sleep(60);
    exit(0); // child exits here only
  } else {
    printf("Fork Creation Failed\n");
  }
  return EXIT_SUCCESS;
}
