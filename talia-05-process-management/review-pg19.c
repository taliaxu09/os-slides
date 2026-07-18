#include <stdio.h>
#include <unistd.h>

int main() {
    int value = 2;
    if (fork() == 0)
        fork();
    fork();
    printf("Hello, world!\n");
    return 0;
}