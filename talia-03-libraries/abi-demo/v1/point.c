#include <stdlib.h>

#include "point.h"

struct point *point_create(int x, int y) {
  struct point *p = malloc(sizeof(*p));
  if (p == NULL) {
    return NULL;
  }
  p->x = x;
  p->y = y;
  return p;
}

int point_get_x(const struct point *p) {
  return p->x;
}

int point_get_y(const struct point *p) {
  return p->y;
}

void point_destroy(struct point *p) {
  free(p);
}
