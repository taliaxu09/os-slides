#include <stdio.h>

struct AlignmentDemo {
    char char_a;
    int int_a;
    char char_b;
    char char_c;
    char char_d;
    int int_b;
    int int_c;
};

int main() {
    struct AlignmentDemo demo;

    // Base address of the struct (address of char_a)
    void *base_address = (void*)&demo.char_a;

    // Printing size of the struct to show alignment padding
    printf("Size of structure: %lu bytes\n", sizeof(demo));

    // Printing memory addresses and offsets from the base
    printf("Address of char_a: %p (offset: %ld)\n", (void*)&demo.char_a, (long)((void*)&demo.char_a - base_address));
    printf("Address of int_a: %p (offset: %ld)\n", (void*)&demo.int_a, (long)((void*)&demo.int_a - base_address));
    printf("Address of char_b: %p (offset: %ld)\n", (void*)&demo.char_b, (long)((void*)&demo.char_b - base_address));
    printf("Address of char_c: %p (offset: %ld)\n", (void*)&demo.char_c, (long)((void*)&demo.char_c - base_address));
    printf("Address of char_d: %p (offset: %ld)\n", (void*)&demo.char_d, (long)((void*)&demo.char_d - base_address));
    printf("Address of int_b: %p (offset: %ld)\n", (void*)&demo.int_b, (long)((void*)&demo.int_b - base_address));
    printf("Address of int_c: %p (offset: %ld)\n", (void*)&demo.int_c, (long)((void*)&demo.int_c - base_address));
	
    return 0;
}
