#include <stdio.h>
#include <unistd.h>

int main(){

    if (1 && fork());

    printf("1\n");

    return 0;
}
