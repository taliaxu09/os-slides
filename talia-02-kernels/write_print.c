#include <stdio.h>
#include <unistd.h>

int main(void) {
    printf("1");
    sleep(1);
    write(1, "2", 1);
    return 0;
}
