#include <stdio.h>
#include <unistd.h>

static int global = 0;

int main(void) {
  int local = 0;
  while (1) {
    ++local;
    ++global;
    printf("local = %d, global = %d\n", local, global);
    printf("0x%lx, 0x%lx\n", (long int)&local, (long int)&global);
    sleep(1);
  }
  return 0;
}
