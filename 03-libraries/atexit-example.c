#include <stdio.h>
#include <stdlib.h>

void fini(void) {
  puts("Do fini");
}

int main(void) {
  atexit(fini);
  puts("Do main");
  return 0;
}
