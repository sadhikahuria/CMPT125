// Author: Sadhika Huria
// May 30th, 2024
// CMPT 125 Summer 
// Lab 3

#include <stdio.h>
#define RANGE 100

unsigned int scrambled( int arr1[], int arr2[], unsigned int size ) {

    int checker1[RANGE] = {0};
    int checker2[RANGE] = {0};
    
    for ( int i = 0; i < size; i++ ) {
        int c = arr1[i];
        checker1[c] = 1;
    }

    for ( int i = 0; i < size; i++ ) {
        int c = arr2[i];
        checker2[c] = 1;
    }

    int is_same = 1;

    for (int i = 0; i < RANGE; i++){
        if(checker1[i] != checker2[i]){
            is_same = 0;
        }
    }

    return is_same;

}








