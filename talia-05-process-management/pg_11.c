#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

void print_state(pid_t pid)
{
    char path[64];
    snprintf(path, sizeof(path), "/proc/%d/stat", pid);

    FILE *fp = fopen(path, "r");
    if (fp == NULL) {
        perror("Failed to open stat file");
        return;
    }

    int stat_pid;
    char comm[256];
    char state;

    if (fscanf(fp, "%d %255s %c", &stat_pid, comm, &state) == 3) {
        printf("Process PID: %d\n", stat_pid);
        printf("Process State: %c\n", state);
    } else {
        fprintf(stderr, "Failed to parse process state\n");
    }

    fclose(fp);
}

int main(void)
{
    pid_t child = fork();

    if (child == 0) {
        sleep(2);
        return 0;
    }

    sleep(1);
    print_state(child);  

    sleep(5);
    print_state(child);  

    waitpid(child, NULL, 0); 
    sleep(10);

    return 0;
}
