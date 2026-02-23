#include <stdio.h>

int main() {
    int A[100] = {0}; // Initialize all elements to 0

    A[0] = 1;
    A[20] = 2;
    A[64] = 3;
    
    int *p = A;

    int a = *(p);        // Same as A[0]
    int b = *(p + 20);   // Same as A[20]
    int c = *(p + 64);   // Same as A[64]
	
    printf("%x\n", A);
    printf("%x\n", A+1);
    printf("a = %d\n", a);
    printf("b = %d\n", b);
    printf("c = %d\n", c);

    return 0;
}
