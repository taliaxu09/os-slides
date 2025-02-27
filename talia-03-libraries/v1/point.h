#ifndef POINT_H
#define POINT_H

struct point {
  int y;
  int x;
};

struct point *point_create(int x, int y);
int point_get_x(struct point *p);
int point_get_y(struct point *p);
void point_destroy(struct point *p);

#endif
