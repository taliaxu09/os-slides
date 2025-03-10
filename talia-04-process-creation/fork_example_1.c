#include <stdio.h>
#include <unistd.h>

int main() {
    int value = 2;
    fork();
    printf("Hello world, %d\n", value);
    return 0;
}
