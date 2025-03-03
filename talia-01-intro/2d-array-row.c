#include <stdio.h>
#include <time.h>


// Get nanosecond difference correctly
int  get_nanoseconds(struct timespec start, struct timespec end) {
    return (end.tv_sec - start.tv_sec) * 1000000000ULL + (end.tv_nsec - start.tv_nsec);
 }

#define ROWS 5000
#define COLS 5000

int array[ROWS][COLS];

int main(void){
    struct timespec start, end;
    int time_taken, result;
    int i, j;

    clock_gettime(CLOCK_MONOTONIC, &start);
    for (i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
	        array[i][j] = i * COLS + j;
	    }
    }
    clock_gettime(CLOCK_MONOTONIC, &end);

    time_taken = get_nanoseconds(start, end);
    printf("Time taken row first: %d nanoseconds\n", time_taken);

    clock_gettime(CLOCK_MONOTONIC, &start);
    for (j = 0; j < COLS; j++) {
            for (int i = 0; i < ROWS; i++) {
	        array[i][j] = i * COLS + j;
	    }
    }

    clock_gettime(CLOCK_MONOTONIC, &end);
    time_taken = get_nanoseconds(start, end);
    printf("Time taken col first: %d nanoseconds\n", time_taken);

    return 0;
}
