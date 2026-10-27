#include <errno.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(void) {
    pid_t pid = fork();
  
    if (pid == 0){
        printf("child\n");
        return 0;
    }

    wait(NULL);
    printf("parent\n");
    return 0;
}
