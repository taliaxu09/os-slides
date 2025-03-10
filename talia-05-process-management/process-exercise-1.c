#include <stdio.h>   
#include <stdlib.h>  
#include <unistd.h>  
#include <sys/wait.h>

int main() {
    int i = 4;  
	int pid = getpid();
	
    while (i != 0) {
        int pid = fork();  

        if (pid == 0) {  
            i--;  
        } else {  
            printf("%d\n", i);  
            exit(0);  
        }
    }

    return 0;
}
