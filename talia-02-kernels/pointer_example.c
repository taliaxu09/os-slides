#include <stdio.h>
#include <stdlib.h>

void testA(int x, int y){
	x = 5;
	y = 10;
}

void testB(int *x, int *y){
	*x = 5;
	*y = 10;
}

void testC(int x, int y){
	*(&x) = 5;
	*(&y) = 10;
}

void testD(int *x, int *y){
	*x = 5;
	*y = 10;
}

int main(void){
	int x1 = 1, y1 = 1;
	testA(x1, y1);
	printf("testA: x = %d, y = %d\n", x1, y1);
	
	int *x2 = malloc(sizeof(int)); *x2 = 1;
	int *y2 = malloc(sizeof(int)); *y2 = 1;
	testB(x2, y2);
	printf("testB: x = %d, y = %d\n", *x2, *y2);
	
	int x3 = 1, y3 = 1;
	testB(&x3, &y3);
	printf("testB: x = %d, y = %d\n", x3, y3);
	
	int x4 = 1, y4 = 1;
	testC(x4, y4);
	printf("testC: x = %d, y = %d\n", x4, y4);
	
	int x5 = 1, y5 = 1;
	testD(&x5, &y5);
	printf("testC: x = %d, y = %d\n", x5, y5);
	
	return 0;
}