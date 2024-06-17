#include <stdio.h>
#include <stdio.h>
#include <stdint.h>

uint8_t getpixel( const uint8_t array[], unsigned int cols, unsigned int rows, unsigned int x, unsigned int y){
    
    assert( x < cols);
    assert ( y < rows);
    return array[x + y * cols];
}

void set_pixel( uint8_t array[], unsigned int cols, unsigned int rows, unsigned int x, unsigned int y, uint8_t colour){
    assert( x < cols);
    assert ( y < rows);
    array[x + y * cols] = colour;
    return;
}