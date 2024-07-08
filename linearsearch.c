#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct shoe {
    int shoesize;
} shoe_t;

int sizefound(shoe_t array[], int arraysize, int size){
    int elementcount = 0;
    int elementfound = 0;
    if( arraysize == 0){
        return elementfound;
    } 
    else{
        for( int i = 0; i < arraysize; i++){
            if ( (array[i].shoesize) != '\0'){
                elementcount++;
            }
        }
    }
    if(elementcount == 0){
        return elementfound;
    }
    for (int i = 0; i < arraysize; i++){
        if ((array[i].shoesize) == size){
            elementfound = 1;
        }
    }
    return elementfound;
}

int main(){
    int arraysize = 2;
    shoe_t array[2] = {{1}, {5}};
    int answer = sizefound(array, arraysize, 5);
    printf("%d\n", answer);
}