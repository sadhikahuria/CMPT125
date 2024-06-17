// picture manipulation
// grey image
// Raster images
// june 14

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


const unsigned int width = 5;
const unsigned int height = 4;
int main(){
    unsigned char* img = malloc(width * height * sizeof(unsigned char));
    //index = x + y * width;

    for ( unsigned int i = 0; i < width*height; i++){
        img[i] = 0;

    }
    memset(img, 0, width* height *(sizeof(img[0])));
}