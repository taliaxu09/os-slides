#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

// Function to read and print the process state from /proc
int print_state(pid_t pid) {
    char path[40];
    char line[100];
    FILE *status_file;

    // Construct the path to the process status file
    sprintf(path, "/proc/%d/status", pid);
    status_file = fopen(path, "r");

    if (status_file == NULL) {
        printf("Process %d not found or already reaped.\n", pid);
        return -1;
    }

    // Read file line by line to find the "State:" field
    while (fgets(line, sizeof(line), status_file)) {
        if (strncmp(line, "State:", 6) == 0) {
            printf("%s", line); // This will print "State: S (sleeping)" etc.
            break;
        }
    }

    fclose(status_file);
    return 0;
}

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        perror("fork failed");
        return 1;
    }

    if (pid == 0) {
        // CHILD PROCESS: Sleeps for 2 seconds then exits
        sleep(2);
        exit(0); 
    } 
    else {
        // PARENT PROCESS
        int ret;
        
        // 1. Check while child is still sleeping
        sleep(1);
        printf("Child process state (at 1s): ");
        ret = print_state(pid);
        
        // 2. Check after child has exited (becomes a zombie)
        sleep(2);
        printf("Child process state (at 3s): ");
        ret = print_state(pid);
        
        // 3. Clean up the zombie process
        wait(NULL);
        printf("Parent reaped the child. Checking again...\n");
        print_state(pid);
    }

    return 0;
}