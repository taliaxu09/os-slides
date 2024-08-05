#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    FILE *file;
    file = fopen("test.txt", "w");
    
    fputs("hello\n", file);
    fputs("hello again\n", file);

    // Fork the process
    pid_t pid = fork();

    return 0;
}

