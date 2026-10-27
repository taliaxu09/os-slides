#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void)
{
    int i = 4;

    while (i != 0) {
        pid_t pid = fork();

        if (pid < 0) {
            perror("fork");
            return 1;
        }

        if (pid == 0) {
            i--;
        } else {
	    waitpid(pid, NULL, 0);
            printf("%d ", i);
            exit(0);
        }
    }
    printf("\n");
    return 0;
}
