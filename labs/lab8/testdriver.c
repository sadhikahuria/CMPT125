#include <stdio.h>
#include "dataStructure.c"

int main(){
    intArray_t *list = intArray_create(6);
    intArray_append( list, 1);
    intArray_append( list, 2);
    intArray_append( list, 3);

}