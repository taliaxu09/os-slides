#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>

int main() {
    int fd[2];  // File descriptors for the pipe
    pid_t pid;
    char buffer[20];

    //pipe(fd);
    pid = fork();
    pipe(fd);

    if (pid == 0) {
	write(fd[1], "Hello", 6);
	printf("Child wrote to pipe\n");
    } else {
	read(fd[0], buffer, sizeof(buffer));
        printf("Child received: %s\n", buffer);
    }

    return 0;
}
