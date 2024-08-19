#include <stdio.h>

int* foo() {
    int x = 1;
    printf("&x = %p\n", (void*) &x);
    return &x;
}

int main(void) {
    int *p = foo();
    //printf("*p = %d\n", *p);
    printf("p = %p\n", (void*) p);
    return 0;
}
