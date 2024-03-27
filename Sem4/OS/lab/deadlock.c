#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

pthread_t tid1, tid2;
pthread_mutex_t first_mutex, second_mutex;

void *do_work_one(void *arg) {
  pthread_mutex_lock(&first_mutex);
  printf("Thread 1 acquired first mutex\n");
  sleep(5);
  printf("Thread 1 going to acquire second mutex\n");
  pthread_mutex_lock(&second_mutex);
  sleep(5);
  pthread_mutex_unlock(&second_mutex);
  sleep(5);
  pthread_mutex_unlock(&first_mutex);
  pthread_exit(0);
}
void *do_work_two(void *arg) {
  pthread_mutex_lock(&second_mutex);
  printf("Thread 2 acquired second mutex\n");
  sleep(5);
  printf("Thread 2 going to acquire first mutex\n");
  pthread_mutex_lock(&first_mutex);
  sleep(5);
  pthread_mutex_unlock(&first_mutex);
  sleep(5);
  pthread_mutex_unlock(&second_mutex);
  pthread_exit(0);
}

int main(int argc, char *argv[]) {
  if (pthread_mutex_init(&first_mutex, NULL) != 0) {
    fprintf(stderr, "mutex init failed\n");
  }
  if (pthread_mutex_init(&second_mutex, NULL) != 0) {
    fprintf(stderr, "mutex init failed\n");
  }
  if (pthread_create(&tid1, NULL, do_work_one, NULL) != 0) {
    fprintf(stderr, "thread 1 create failed\n");
  }
  if (pthread_create(&tid2, NULL, do_work_two, NULL) != 0) {
    fprintf(stderr, "thread 2 create failed\n");
  }
  if (pthread_join(tid1, NULL) != 0) {
    fprintf(stderr, "thread 1 join failed\n");
  }
  if (pthread_join(tid2, NULL) != 0) {
    fprintf(stderr, "thread 2 join failed\n");
  }
  pthread_mutex_destroy(&first_mutex);
  pthread_mutex_destroy(&second_mutex);
  return EXIT_SUCCESS;
}
