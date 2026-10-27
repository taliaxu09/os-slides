#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    int fd[2];  // File descriptors for the pipe
    pipe(fd);

    pid_t pid = fork();

    if (pid == 0) {
        char buf[32];
	close(fd[1]);
	ssize_t n = read(fd[0], buf, sizeof(buf) - 1);
	if (n > 0){
	    buf[n] = '\0';
	    printf("child: %s\n", buf);
        }
	close(fd[0]);
	return 0;
    }
    
    close(fd[0]);
    write(fd[1], "hello", 5);
    close(fd[1]);
    waitpid(pid, NULL, 0);
    return 0;
}
