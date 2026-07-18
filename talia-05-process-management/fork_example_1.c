#include <stdio.h>
#include <unistd.h>

int main() {
    int value = 2;
    if (fork() == 0)
	printf("Child\n");
    else
	printf("Parent\n");
    //printf("Hello world, %d\n", value);
    return 0;
}
