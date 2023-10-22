#include <stdio.h>
#include <math.h>

int main(){
    unsigned int nim = 2602225201;
    int x = ceil ((float) ((nim+1) % nim)/2) * 10;
    printf("x value = %d\n\n", x);
    return 0;
}