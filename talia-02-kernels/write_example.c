#include <unistd.h>
#include <string.h>

// printf("%s, Decimal: %d, Binary: %b, %s, Hex: 0x%lX\n", "First String", 42, 13, "Second String", 0xDEADBEEF);

void to_binary(unsigned int num, char *buf) {
    for (int i = 31; i >= 0; i--) buf[31 - i] = (num & (1 << i)) ? '1' : '0';
    buf[32] = '\0';
}

void write_number(int num) {
    char buf[12]; // Enough for max 32-bit int (-2147483648)
    int len = 0;
    int temp = num < 0 ? -num : num;
    do { buf[len++] = '0' + (temp % 10); temp /= 10; } while (temp);
    if (num < 0) buf[len++] = '-';
    for (int i = len - 1; i >= 0; i--) write(STDOUT_FILENO, &buf[i], 1);
}

void write_hex(long num) {
    char buf[20];
    int len = 0;
    do { 
        int digit = num % 16;
        buf[len++] = (digit < 10) ? ('0' + digit) : ('A' + digit - 10);
        num /= 16;
    } while (num);
    write(STDOUT_FILENO, "0x", 2);
    for (int i = len - 1; i >= 0; i--) write(STDOUT_FILENO, &buf[i], 1);
}

int main() {
    char bin[33];
    to_binary(13, bin);

    write(STDOUT_FILENO, "First String, Decimal: ", 24);
    write_number(42);
    
    write(STDOUT_FILENO, ", Binary: ", 10);
    write(STDOUT_FILENO, bin, 32);
    
    write(STDOUT_FILENO, ", Second String, Hex: ", 23);
    write_hex(0xDEADBEEF);

    write(STDOUT_FILENO, "\n", 1);
    return 0;
}