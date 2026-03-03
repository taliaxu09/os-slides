#include <stdio.h>

struct Data {
    int count;
    int values[2];
};

void updateAndSwap(struct Data d) {
    d.count += 1;

    int temp = d.values[0];
    d.values[0] = d.values[1];
    d.values[1] = temp;
}

int main(void) {
    struct Data myData = {10, {100, 200}};
    
    printf("Before: count = %d, values = {%d, %d}\n",
           myData.count, myData.values[0], myData.values[1]);
           
    updateAndSwap(myData);
    
    printf("After: count = %d, values = {%d, %d}\n",
           myData.count, myData.values[0], myData.values[1]);
           
    return 0;
}
