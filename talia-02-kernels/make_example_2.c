#include <stdio.h>

void hello_world(void) {
    printf("Hello world\n");
}

int *make(void) {
    int z = 11;
    int *p = &z;
    return p;
}

int main(void) {
    int *q = make();
    hello_world();
    printf("%d\n", *q);
    return 0;
}
