#include <stdio.h>
#include <unistd.h>

int main() {
    int value = 2;
    int pid = getpid();
    fork();
    value = 3;
    printf("Hello, world, %d, %lx!\n", value, (long int)&value);
    return 0;
}
