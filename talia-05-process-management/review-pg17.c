#include <unistd.h>

int main(void){
   int ret1 = fork();
   int ret2 = fork();

   printf("ret1 = %d, ret2 = %d\n", ret1, ret2);
   while(1);
}
