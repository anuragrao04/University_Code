#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  pid_t child_pid = fork();
  if (child_pid == 0) {
    // only run in child
    system("ps -u $USER");
    exit(0); // exits after printing user processes
  } else {
    // parent
    wait(NULL); // makes sure that children die before parent dies
  }
  return EXIT_SUCCESS;
}
