#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main(void) {
  int i = 4;
  while (i != 0) {
    int pid = fork();
    if (pid == 0) {
      i--;
    }
    else {
      waitpid(pid, NULL, 0);
      printf("%d\n", i);
      exit(0);
    }
  }
  return 0;
}
