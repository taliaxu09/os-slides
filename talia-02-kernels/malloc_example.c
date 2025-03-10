#include <stdio.h>
#include <stdlib.h>

int* functionA() {
    // stack
	
 //   int num = 42; 
  //  return &num;  
	
	
	// heap
      int* num = (int*) malloc(sizeof(int));
      *num = 42;
      return num;
}

int main() {
    int* ptr = functionA();
    printf("Stack Variable: %d\n", *ptr); 

	free(ptr);
	
    return 0;
}
