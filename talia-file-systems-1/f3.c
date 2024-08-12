#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    FILE *file;
    file = fopen("test.txt", "w");
    fputs("hello\n", file);
    fputs("hello again\n", file);
    fclose(file);

    file = fopen("test.txt", "r");
    // Fork the process
    pid_t pid = fork();
     
    if (pid == 0) {
        // Child process
        char line[256];
        if (fgets(line, sizeof(line), file) != NULL) {
            printf("Child read: %s", line);
        }
    } else {
        // Parent process
        //sleep(1);
        char line[256];
        if (fgets(line, sizeof(line), file) != NULL) {
            printf("Parent read: %s", line);
        }
    }

    return 0;
}

