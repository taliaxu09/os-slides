#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int fd[2];
    char buffer[20];

    if (pipe(fd) == -1) {
        perror("pipe");
        exit(1);
    }
    
    pid_t pid = fork();
    if (pid < 0) {
        perror("fork");
        exit(1);
    }
    
    if (pid == 0) { 
        // Child process: write a message to the pipe without including a null terminator.
        char message[] = "Hello";
        write(fd[1], message, strlen(message));  // Writes 5 byte
        exit(0);
    } else { 
        // Parent process: read data from the pipe.
        read(fd[0], buffer, sizeof(buffer));
        printf("Parent received: %s\n", buffer);
    }
    
    return 0;
}
