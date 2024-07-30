#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>
#include <math.h>
#include <string.h>

// B2U binary to unsigned char 
// positional notation
    // eg: 246,10 = 2*10^2 + 4*10^1 + 6*10^0
            // 200 + 40 + 6
    // eg: 1010,2 = 1*2^3 +1*2^1
        // = 8 + 2 = 10

// 0b00011011 0b means binary number

int main(){
    char x = 0b00011011;
    unsigned char y = 0b10000000;
    char z = 246;
    printf("x = %c\ny = %c\nzz = %c\n", x, y, z);
    
}