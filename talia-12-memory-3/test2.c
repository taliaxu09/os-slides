#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int x = 5;
    if (fork() == 0) {       // Child process
        x += 5;              // x = 10 in child
        printf("%d ", x);    // prints "10 "
    } else {                 // Parent process
        x -= 2;              // x = 3 in parent
        wait(NULL);          // wait for child to finish
        printf("%d ", x);    // prints "3 "
    }
    printf("%d ", x);        // Both processes execute this line separately
    return 0;
}