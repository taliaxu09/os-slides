#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int pid = getpid();
    fork();
    if (getpid() == pid){
	// wait(NULL);
	printf("Hello A\n");
    }
    else{
	printf("Hello B\n");
    }
    return 0;
}
