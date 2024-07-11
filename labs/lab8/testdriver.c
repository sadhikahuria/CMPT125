#include <stdio.h>
#include <stdlib.h>
#include "dataStructure.h"

int main(){

    intArray_t *arr = intArray_create(10);
    if (arr == NULL){
        return 0;

    }

    for ( int i = 0; i < 10; i++){
        if (intArray_append( arr, rand() ) != INTARR_OK){
            printf("ERRORRRRR append");
            return 0;
        } 
    }

    if (intArray_print(arr) != INTARR_OK){
        printf("ERRORRRRR print");
        return 0;
    } 


    int random = arr -> data[8];
    unsigned int *index;
    if ( intArray_find( arr, random, index) != INTARR_OK){
        printf("ERRORRR finding");
        return 0;
    }
    if (index != 8){
        prinf("ERROR wrong index found");
        return 0;
    }
    


    if ( intArray_modify( arr, 1234, 6) != INTARR_OK){
        printf("EROOR failed moditfy");
        return 0;

    }
    if ( arr-> data[6] != 1234){
        printf("ERROR wrong modify");
        return 0;
    }
    


    if ( intArray_remove( arr, 3) != INTARR_OK){
        printf("ERROR removing");
        return 0;
    }
    if ( arr-> elementCount != 9){
        printf("Error didn't remove properly");
        return 0;
    }

    if( intArray_sort(arr) != INTARR_OK){
        printf("ERROR sorting");
        return 0;
    }

    for (unsigned int i = 0; i < arr-> elementCount -1; i++){
        if ( arr-> data[i] > arr-> data[i+1]){
            printf("ERROR wrong sorting");
            return 0;
        }
    } 

    intArray_t *copy = intArray_copy(arr);
    if (copy == NULL){
        printf("ERROR copying");
        return 0;
    }
    if (copy-> elementCount != arr -> elementCount){
        printf("ERROR copied wrong");
        return 0;
    }


    if ( intArray_write_to_json( arr, "test.json") != INTARR_OK){
        prinf("ERRORRRRR write to json:");
        return 0;
    }

    intArray_t *json = intArray_load_from_json("test.json");
    if (json == NULL){
        prinf("failed reading");
        return 0;
    }
    if ( json-> elementCount != arr-> elementCount){
        printf("wrong reading");
        return 0;
    }

    if (intArray_destroy(arr) != INTARR_OK){
        printf("ERROR destroy");
        return 0;
    }
    if (intArray_destroy(json) != INTARR_OK){
        prinf("Error destory json");
        return 0;
    }

    return 1;



}