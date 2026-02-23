#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void) {
    int fd[2];

    // Create a pipe
    if (pipe(fd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    pid_t pid = fork();
    if (pid < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    } 
    else if (pid == 0) { 
        // Child process

        // Close the unused read end
        close(fd[0]);

        // Write the first message including the terminating null
        char *message = "Hello World";
        write(fd[1], message, strlen(message) + 1);

        // Write the second message including the terminating null
        message = "Hello World again";
        write(fd[1], message, strlen(message) + 1);

        // Close the write end and exit
        close(fd[1]);
        exit(EXIT_SUCCESS);
    } 
    else { 
        // Parent process

        // Close the unused write end
        close(fd[1]);

        char buffer[100];
        // Read from the pipe (this call reads all the bytes available)
        int n = read(fd[0], buffer, sizeof(buffer));
        if (n < 0) {
            perror("read");
            exit(EXIT_FAILURE);
        }

        // Print the output using %s (stops printing at the first null terminator)
        printf("Parent process read: %s\n", buffer);

        // Close the read end and wait for the child to exit
        close(fd[0]);
        wait(NULL);
    }
    return 0;
}
