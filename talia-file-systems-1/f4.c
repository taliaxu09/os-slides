#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

int main() {
    int fd1 = open("f4.txt", O_RDWR | O_CREAT | O_TRUNC);

    write(fd1, "hello\n", strlen("hello\n"));
	
    // Fork the process
    pid_t pid = fork();

    if (pid == 0){
		write(fd1, "hello again\n", strlen("hello again\n"));
    } else {
		sleep(0.1);
		char line[256];
		read(fd1, line, 256);
		printf("%s", line);
    }
    return 0;
}

