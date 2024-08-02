#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define NTHREADS 50000

void *run(__attribute__((unused)) void* arg) {
  return 0;
}

int main() {
  pthread_attr_t attr;
  pthread_attr_init(&attr);
  pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

  for (int i=0; i < NTHREADS; ++i) {
    pthread_t tid;
    int rc = pthread_create(&tid, &attr, run, NULL);
    if (rc != 0) {              
      printf("ERROR: return code from pthread_create() is %d\n", rc);
      exit(rc);
    }

    /* Wait for the thread */
    rc = pthread_join(tid, NULL);
    if (rc != 0) {
      printf("ERROR: return code from pthread_join() is %d\n", rc);
      exit(rc);
    }
  }
  
  pthread_attr_destroy(&attr);
  return 0;
}
