#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void) {
  int i = 4;
  while (i != 0) {
    int pid = fork();
    if (pid == 0) {
      i--;
    }
    else {
      printf("%d\n", i);
      exit(0);
    }
  }
  return 0;
}
