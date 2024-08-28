#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

void read_file(int fd) {
    char buffer[4096] = {0};
    ssize_t bytes_read = read(fd, buffer, sizeof(buffer) - 1);
    printf("pid %d read %zd bytes: %s\n", getpid(), bytes_read, buffer);
}

int main(void) {
    int fd1 = open("a.txt", O_RDONLY);
    fork();
    int fd2 = open("b.txt", O_RDONLY);
    read_file(fd1);
    read_file(fd2);
    return 0;
}
