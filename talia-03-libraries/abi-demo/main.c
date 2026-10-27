#include <stdio.h>
#include <stdlib.h>

#include "point.h"

int main(void) {
  struct point *p = point_create(1, 2);

  printf("library: %d, %d\n", point_get_x(p), point_get_y(p));
  printf("struct:  %d, %d\n", p->x, p->y);

  point_destroy(p);
  return EXIT_SUCCESS;
}
