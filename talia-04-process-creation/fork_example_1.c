#include <stdio.h>
#include <unistd.h>

int main() {
    int value = 2;
    fork();
    printf("Hello, world!\n");
    return 0;
}
