#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main() {
    int fd1 = open("f2_new.txt", O_WRONLY | O_CREAT);
    
    write(fd1, "hello\n", strlen("hello\n"));
	
    // Fork the process
    pid_t pid = fork();

    return 0;
}

