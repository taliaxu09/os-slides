#include <stdio.h>   
#include <stdlib.h>  
#include <unistd.h>  
#include <sys/wait.h>

int x = 3; 
void main() 
{ 
    while(x > 0) { 
        int ret = fork(); 
        if(ret == 0) { 
            printf("x = %d\n", x); 
        } else 
            wait(NULL); 
        x--; 
    } 
}