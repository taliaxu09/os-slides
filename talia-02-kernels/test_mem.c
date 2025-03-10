#include <stdio.h>
#include <stdlib.h>

int x;
int y = 15;

int main(int argc, char *argv[])
{
    int v[5];
    int i;

    int *values = malloc(sizeof(int) * 5);
    for (i = 0; i < 5; i++){
	values[i] = i;
	printf("%d\n", values[i]);
    }
    return 0;
}
