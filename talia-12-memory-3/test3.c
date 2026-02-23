#include <stdio.h>
#include <unistd.h>

int main() {
    printf("1");
    execl("/bin/echo", "echo", "2", NULL);
    printf("3");
    return 0;
}