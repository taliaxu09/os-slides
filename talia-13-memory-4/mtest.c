#include <stdio.h>

struct alnt_st {
    char a;
    int b;
    char c;
};

int main() {
    struct alnt_st test;
    printf("Size of struct: %d bytes\n", sizeof(test));
    return 0;
}
