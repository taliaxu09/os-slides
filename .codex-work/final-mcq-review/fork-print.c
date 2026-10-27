#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
int main(void) {
    fork();
    if (fork() && fork()) {
        execl("/bin/sleep", "sleep", "10", (char *)NULL);
    }
    printf("1");
    return 0;
}
