#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void check(int ret, const char* message) {
    if (ret != -1) {
        return;
    }
    int error = errno;
    perror(message);
    exit(error);
}

int main(void) {
    int fds[2];
    check(pipe(fds), "pipe");

    pid_t pid = fork();
    check(pid, "fork");
    if (pid > 0) {
        const char* str = "Howdy child";
        int len = strlen(str);
        int bytes_written = write(fds[1], str, len);
        check(bytes_written, "write");
    }
    else {
        char buffer[4096];
        int bytes_read = read(fds[0], buffer, sizeof(buffer));
        check(bytes_read, "read");
        printf("Child read: %.*s\n", bytes_read, buffer);
    }

    close(fds[0]);
    close(fds[1]);

    return 0;
}
