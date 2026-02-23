#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

#define N 100000000  // Size of the array (100 million)

// Global array
int *array;

// Thread function
void* fill_array(void* arg) {
    int thread_id = ((int*)arg)[0];
    int num_threads = ((int*)arg)[1];
    free(arg);

    long chunk_size = N / num_threads;
    long start = thread_id * chunk_size;
    long end = (thread_id == num_threads - 1) ? N : start + chunk_size;

    for (long i = start; i < end; ++i) {
        array[i] = thread_id;
    }

    return NULL;
}

// Helper: get current time in seconds
double get_time_sec() {
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return ts.tv_sec + ts.tv_nsec / 1e9;
}

int main(int argc, char *argv[]) {
    int num_threads = (argc >= 2) ? atoi(argv[1]) : 2;
    array = malloc(sizeof(int) * N);

    printf("Filling array of size %d with %d thread(s)...\n", N, num_threads);

    // Single-threaded
    double start = get_time_sec();
    for (long i = 0; i < N; ++i) {
        array[i] = 1;
    }
    double single_time = get_time_sec() - start;
    printf("Single-threaded time: %.4f seconds\n", single_time);

    // Multi-threaded
    pthread_t *threads = malloc(sizeof(pthread_t) * num_threads);
    start = get_time_sec();
    for (int i = 0; i < num_threads; ++i) {
        int *args = malloc(sizeof(int) * 2);
        args[0] = i;            // thread ID
        args[1] = num_threads;  // total threads
        pthread_create(&threads[i], NULL, fill_array, args);
    }

    for (int i = 0; i < num_threads; ++i) {
        pthread_join(threads[i], NULL);
    }
    double multi_time = get_time_sec() - start;
    printf("Multi-threaded time (%d thread%s): %.4f seconds\n", num_threads,
           num_threads > 1 ? "s" : "", multi_time);

    // Cleanup
    free(array);
    free(threads);
    return 0;
}
