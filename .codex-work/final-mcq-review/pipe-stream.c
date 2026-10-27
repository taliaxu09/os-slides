#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
int main(void) {
    int fd[2];
    char buf[3];
    pipe(fd);
    write(fd[1], "AB", 2);
    write(fd[1], "CD", 2);
    close(fd[1]);
    for (int i=0;i<3;i++) {
        ssize_t n=read(fd[0],buf,3);
        printf("%zd:%.*s\n",n,(int)n,buf);
    }
    close(fd[0]);
    return 0;
}