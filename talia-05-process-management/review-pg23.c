#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int x = 3;

int main() {
    while (x > 0) {
        int ret = fork();

        if (ret == 0) {
            printf("x = %d\n", x);
        } else {
            wait(NULL);
        }

        x--;
    }

    return 0;
}
