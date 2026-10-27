#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
int main(void) {
    int fd[2];
    pipe(fd);
    pid_t pid = fork();

    if (pid == 0) {
        char c;
        read(fd[0], &c, 1);
        read(fd[0], &c, 1);
        _exit(0);
    }

    close(fd[0]);
    write(fd[1], "X", 1);
    close(fd[1]);
    waitpid(pid, NULL, 0);
    return 0;
}
