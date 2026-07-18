#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>

int main() {
    int fd[2];  // File descriptors for the pipe
    pipe(fd);

    pid_t pid;
    char write_msg[] = "Hello from parent!";
    char read_msg[100];
    pid = fork();

    if (pid > 0) {
        write(fd[1], write_msg, strlen(write_msg) + 1);
    } else {
        read(fd[0], read_msg, sizeof(read_msg));
        printf("Child received: %s\n", read_msg);
    }

    return 0;
}
