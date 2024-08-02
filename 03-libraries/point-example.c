#include <stdio.h>
#include <stdlib.h>

#include "point.h"

int main(void) {
  struct point *p = point_create(1, 2);

  printf("point (x, y) = %d, %d (using library)\n",
         point_get_x(p), point_get_y(p));

  printf("point (x, y) = %d, %d (using struct)\n", p->x, p->y);

  point_destroy(p);
  return 0;
}
