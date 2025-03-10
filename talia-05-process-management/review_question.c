#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    if (fork() == 0) {  
        if (fork() == 0)
			sleep(2);
		exit(0);
    } else {  
        sleep(3);
        exit(0);
    }
}
