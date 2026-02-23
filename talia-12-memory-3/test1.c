#include <stdio.h>
#include <unistd.h>

int main() {
	if (fork() || fork())
		fork();

	printf("1");  // Using printf instead of 
	return 0;
}

