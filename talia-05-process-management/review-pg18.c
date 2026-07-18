#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

int main() {
    char *command = "/bin/ls";
    char *args[] = {"ls", NULL};
    int rc = fork();

    if (rc == 0) {
        close(STDOUT_FILENO);
        int fd = open("foo.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
        execve(command, args, NULL);
        exit(0);
    } else {
        wait(NULL);
    }

    return 0;
}