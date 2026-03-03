#include <stdio.h>

void swap2(int a, int b) {
    int t = a;
    a = b;
    b = t;
}

int main(){
    int a = 2, b = 3;
    printf("Before swapping: %d %d\n", a, b);
    swap2(a, b);
    printf("After swapping: %d %d\n", a, b);   
    return 0;
}
