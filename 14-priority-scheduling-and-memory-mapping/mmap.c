#include <assert.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>

int main(void) {
    int fd = open("mmap.c", O_RDONLY);
    assert(fd == 3);
    struct stat stat;
    assert(fstat(fd, &stat) == 0);
    char* data = mmap(NULL, stat.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
    assert(data != MAP_FAILED);
    assert(close(fd) == 0);

    for (int i = 0; i < stat.st_size; ++i) {
        printf("%c", data[i]);
    }

    assert(munmap(data, stat.st_size) == 0);
    return 0;
}
