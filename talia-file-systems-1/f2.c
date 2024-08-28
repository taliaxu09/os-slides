#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    FILE *file = fopen("f2.txt", "w");
	
    fputs("hello\n", file);
	
    // Fork the process
    pid_t pid = fork();

    return 0;
}

