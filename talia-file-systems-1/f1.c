#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    FILE *file = fopen("f1.txt", "w");
    
    // Fork the process
    pid_t pid = fork();
    
    fputs("hello\n", file);

    return 0;
}

