#include <stdlib.h>
#include <stdio.h>

int main(void) {
  int *x = malloc(sizeof(int));
  printf("x = %p\n", (void *)x);
  free(x);
  return 0;
}
