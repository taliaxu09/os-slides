#include <stdio.h>
#include <unistd.h>

int main() {
    int value = 2;
    pid_t result =  fork();
    
    if (result == 0)
        value = 3;

    printf("%s: %d\n", result == 0? "child" : "parent", value);
    return 0;
}
