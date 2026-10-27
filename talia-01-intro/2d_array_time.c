#define _POSIX_C_SOURCE 199309L

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

static double seconds(void) {
    struct timespec t;
    clock_gettime(CLOCK_MONOTONIC, &t);
    return (double)t.tv_sec + (double)t.tv_nsec / 1e9;
}

static void bump_row_major(int32_t *matrix, size_t n) {
    for (size_t row = 0; row < n; row++) {
        for (size_t col = 0; col < n; col++) {
            matrix[row * n + col] += 1;
        }
    }
}

static void bump_column_major(int32_t *matrix, size_t n) {
    for (size_t col = 0; col < n; col++) {
        for (size_t row = 0; row < n; row++) {
            matrix[row * n + col] += 1;
        }
    }
}

static uint64_t checksum(const int32_t *matrix, size_t count) {
    uint64_t result = 0;

    for (size_t i = 0; i < count; i++) {
        result += (uint64_t)matrix[i];
    }

    return result;
}

int main(void) {
    const size_t sizes[] = {
        256, 512, 1024, 2048, 4096, 8192
    };

    const size_t size_count = sizeof(sizes) / sizeof(sizes[0]);

    printf("%8s %14s %17s\n",
       "N",
       "Row time [ms]",
       "Column time [ms]");

    for (size_t s = 0; s < size_count; s++) {
        size_t n = sizes[s];

        if (n > SIZE_MAX / n) {
            fprintf(stderr, "Matrix size overflow\n");
            return EXIT_FAILURE;
        }

        size_t count = n * n;

        int32_t *row_matrix = calloc(count, sizeof(*row_matrix));
        int32_t *column_matrix = calloc(count, sizeof(*column_matrix));

        if (row_matrix == NULL || column_matrix == NULL) {
            fprintf(stderr, "Allocation failed for n=%zu\n", n);
            free(row_matrix);
            free(column_matrix);
            return EXIT_FAILURE;
        }

        double start = seconds();
        bump_row_major(row_matrix, n);
        double row_time = seconds() - start;

        start = seconds();
        bump_column_major(column_matrix, n);
        double column_time = seconds() - start;

        uint64_t result =
            checksum(row_matrix, count) +
            checksum(column_matrix, count);

        printf("%8zu %14.6f %17.6f\n",
		   n,
		   row_time*1000,
		   column_time*1000);
	   
        free(row_matrix);
        free(column_matrix);
    }
    while(1);
    return EXIT_SUCCESS;
}
