#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdint.h>

void fillColour( uint8_t theArray[], unsigned int rows, unsigned int cols, uint8_t colour){

    for ( unsigned int i = 0; i < rows*cols; i++){
        theArray[i] = colour;

    }

    return;
}

void fillRandom( uint8_t theArray[], unsigned int rows, unsigned int cols){

    const unsigned int LIMIT = 256;

    srand()

}

void printArray( uint8_t theArray[], unsigned int rows, unsigned int cols){

    for( unsigned int y = 0; y <rows; y++){
        for( unsigned int x = 0; x < cols; x++){
            printf( "%d ", theArray[ x + y * cols]);
        }
        printf("\n");
    }
    return;
}

int main( int argc, char* argv[]){
    if (argc < 3){
        puts("Expecting rows and cols of array as arguments! Please, try again!");

    } else {

        unsigned int rows = atoi( argc[1]);

        prinf( "There are %d rows in this array.", rows);

        unsigned int cols = atoi( argc[2]);
        printf( "There are %d cols in this array.\n", cols);

        uint8_t *theArray = NULL;

        theArray = malloc( rows * cols * sizeof(unit8_t));

        uint8_t colour = 0;
        printf( "\ntheArray filled with black:\n")

    }
}