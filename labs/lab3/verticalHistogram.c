// Author: Sadhika Huria
// May 30th, 2024
// CMPT 125 SUMMER
// Lab 3

#include <stdio.h>

int main(){

    const int ARRAY_SIZE = 80;
    int histo_values[ARRAY_SIZE];
    int array_length = 0;
    int c;

    printf("Write the values for the histogram: ");
    for( int i = 0; i < ARRAY_SIZE; i++) {
        c = scanf("%d", &histo_values[i]);
        if (c != 1){
            break;
        }
        array_length++;
    }

    int max_value = 0;

    for( int i = 0; i < array_length; i++){
            
        if (max_value < histo_values[i]){
            max_value = histo_values[i];
        }
    }

    for ( int i = max_value; i > 0; i--){ //amount of lines
        for( int j = 0; j < array_length; j++){// length of the row 
            if (histo_values[j] < i){
                printf(" ");
            } else {
                printf("*");
            }
        }
        printf("\n");
    }
}