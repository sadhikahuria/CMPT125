#include <stdio.h>
#include "dataStructure.h"

int main(){
    intArray_t *list = intArray_create(6);
    intArray_append( list, 1);
    intArray_append( list, 2);
    intArray_append( list, 3);
    unsigned int *index = NULL;
    intArray_find(list, 2, index);
    printf("number is %d, and index is 2", *index );

}