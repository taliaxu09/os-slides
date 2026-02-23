#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define NUM_PROCESSES 8
static int counter = 0;

int main(void) {
    for (int i = 0; i < NUM_PROCESSES; ++i) {
        pid_t pid = fork();
        if (pid == 0) {
            for (int j = 0; j < 10000; ++j) 
                ++counter;
            exit(0);
        }
    }
    for (int i = 0; i < NUM_PROCESSES; ++i) 
        wait(NULL);

    printf("counter = %d\n", counter);
    return 0;
}
