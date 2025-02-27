#include <errno.h> /* errno, EINVAL */
#include <fcntl.h> /* open, O_RDONLY */
#include <stdio.h> /* perror, printf */
#include <stdlib.h> /* exit */
#include <unistd.h> /* close, read */

void check_error(int value, const char* message) {
    if (value != -1) {
        return;
    }
    int error = errno;
    perror(message);
    exit(error);
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        return EINVAL;
    }

    int fd = open(argv[1], O_RDONLY);
    check_error(fd, "open");

    char buffer[4];
    ssize_t bytes_read = read(fd, buffer, sizeof(buffer));
    check_error(bytes_read, "read");

    for (int i = 0; i < bytes_read; ++i) {
        char byte = buffer[i];
        if (byte > 31 && byte < 127) {
            printf("Byte %d: %c\n", i, byte);
        }
        else {
            printf("Byte %d: 0x%02hhX\n", i, byte);
        }
    }

    check_error(close(fd), "close");

    return 0;
}
