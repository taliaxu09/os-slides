#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

void* run(__attribute__((unused)) void* arg) {
  usleep(10);
  printf("%s\n", (char *) arg);
  return NULL;
}

int main(void) {
  pthread_t p1, p2;
  pthread_create(&p1, NULL, &run, "A");
  pthread_create(&p2, NULL, &run, "B");
  printf("In main\n");
  return 0;
}
