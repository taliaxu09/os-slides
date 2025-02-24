#include <stdio.h>
#include <time.h>

// Iterative addition
int  iterative_addition(int  n) {
    int  sum = 0;
    for (int  i = 0; i < n; i++) {
        sum += i;
    }
    return sum;
}

// Recursive addition
int  recursive_addition(int  n) {
    if (n == 0) return 0;
    return (n - 1) + recursive_addition(n - 1);
}

// Get nanosecond difference correctly
int  get_nanoseconds(struct timespec start, struct timespec end) {
    return (end.tv_sec - start.tv_sec) * 1000000000ULL + (end.tv_nsec - start.tv_nsec);
}

int main() {
	
	// 1 + 2 + 3 + 4 + ... + n
	
    struct timespec start, end;
    int  time_taken, result, n = 100;
	
    clock_gettime(CLOCK_MONOTONIC, &start);
    result = iterative_addition(n);
    clock_gettime(CLOCK_MONOTONIC, &end);
    time_taken = get_nanoseconds(start, end);
    printf("Time taken (Iterative): %d nanoseconds\n", time_taken);

    clock_gettime(CLOCK_MONOTONIC, &start);
    result = recursive_addition(n);
    clock_gettime(CLOCK_MONOTONIC, &end);
    time_taken = get_nanoseconds(start, end);
    printf("Time taken (Recursive): %d nanoseconds\n", time_taken);

    return 0;
}
