#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    int fd[2];
    pid_t pid;
    char buffer[20];

	pid = fork();
	pipe(fd);

    if (pid == 0) { 
        write(fd[1], "Hello", 6);
        printf("Child wrote to pipe\n");
    } else { 
        read(fd[0], buffer, sizeof(buffer));
        printf("Parent received: %s\n", buffer);
    }
    
    return 0;
}