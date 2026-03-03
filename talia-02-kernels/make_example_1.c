#include <stdio.h>

int *make(void) {
    int z = 11;
    int *p = &z;
    return p;
}

int main(void) {
    int *q = make();
    printf("%d\n", *q);
    return 0;
}
