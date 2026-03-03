#include <stdio.h>

void swap2(int a[2]){
    int t = a[0];
    a[0] = a[1];
    a[1] = t;
}

int main(){
    int a[2] = {2, 3};
    swap2(a);
    printf("%d %d\n", a[0], a[1]);
    return 0;
}

