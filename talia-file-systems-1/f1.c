#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    FILE *file;
    file = fopen("test.txt", "w");
    
    // Fork the process
    pid_t pid = fork();
    
    fputs("hello\n", file);
    fputs("hello again\n", file);

    return 0;
}

