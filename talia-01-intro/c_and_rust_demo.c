#include <stddef.h>
#include <stdio.h>

void bump_all(int *items, size_t len) {
    for (size_t i = 0; i < len; i++) {
        items[i] += 1;
    }
}

int read_at_unchecked(const int *items, size_t len, size_t index) {
    (void)len;
    return items[index];
}

int main(void) {
    int numbers[] = {1, 2, 3};
    size_t len = sizeof(numbers) / sizeof(numbers[0]);

    bump_all(numbers, len);
    printf("after bump_all: [%d, %d, %d]\n", numbers[0], numbers[1], numbers[2]);

    int *first = &numbers[0];
    int *also_first = &numbers[0];
    *first += 10;
    *also_first += 20;
    printf("two mutable aliases changed numbers[0] to %d\n", numbers[0]);

    printf("read_at_unchecked(numbers, len, 1) = %d\n",
           read_at_unchecked(numbers, len, 1));

    /*
     * Try changing the final index above from 1 to len.
     * C will still compile it, but reading past the array is undefined behavior.
     */

    return 0;
}
