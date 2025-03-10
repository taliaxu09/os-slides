#include <stdio.h>
#include <string.h> 
#include <stdlib.h>

struct testStructure{
	int A;
	char B;
	int *C;
};

int main(){
	struct testStructure s1;
	s1.A = 8;
	s1.B = 'A';
	s1.C = malloc(sizeof(int)*2);
	s1.C[0] = 2;
	s1.C[1] = 3;

	struct testStructure s2;
	s2 = s1;
	s2.C[0] = 20;
	printf("s1 -> A: %d, B: %c, C: [%d, %d]\n", s1.A, s1.B, s1.C[0], s1.C[1]);
	printf("s2 -> A: %d, B: %c, C: [%d, %d]\n", s2.A, s2.B, s2.C[0], s2.C[1]);
	return 0;
}
