#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int x = 3;

int main() {
    while (x > 0) {
        int ret = fork();
        char *args[] = {"a.out", NULL};

        if (ret == 0) {
            printf("x = %d\n", x);
            x--;
            execve("./a.out", args, NULL);
        } else {
            wait(NULL);
        }
    }
}