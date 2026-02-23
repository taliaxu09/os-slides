#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>  // for malloc and free

void* run(void *arg) {
  printf("%s\n", (char *) arg);

  int* retval = malloc(sizeof(int));  // allocate memory for the result
  if (retval == NULL) {
      perror("malloc failed");
      pthread_exit(NULL);  // safely exit thread if malloc fails
  }

  *retval = 42;  // set the return value
  return retval; // return pointer to allocated int
}

int main() {
  pthread_t p1;
  void* ret_val;

  pthread_create(&p1, NULL, &run, "A");
  pthread_join(p1, &ret_val);  // capture returned pointer

  int result = *(int*)ret_val;  // dereference to get the actual int
  printf("Thread returned: %d\n", result);

  free(ret_val);  // free the allocated memory to avoid memory leak

  return 0;
}
