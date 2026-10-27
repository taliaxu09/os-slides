#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(void)
{
    pid_t pid = fork();

    if (pid < 0) {
        perror("fork");
        return 1;
    }

    if (pid == 0) {
        printf("parent: %d\n", getppid());
        sleep(5);
        printf("parent after sleep: %d\n", getppid());
    } else {
        sleep(3);
    }

    return 0;
}
