#include <stdio.h>
#include <string.h> 
#include <stdlib.h>

struct testStructure{
	int A;
	char B;
	int C[2];
};

int main(){
	struct testStructure s1;
	s1.A = 8;
	s1.B = 'A';
	// s1.C = {1, 2}; // Not OK

	//int temp[] = {1, 2};
	//memcpy(s1.C, temp, sizeof(s1.C)); 

	printf("s1 -> A: %d, B: %c, C: [%d, %d]\n", s1.A, s1.B, s1.C[0], s1.C[1]);
	return 0;
}
