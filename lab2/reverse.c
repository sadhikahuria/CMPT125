/*
Filename: reverse.c

Description: Reverses an array of 10 integers and prints it.

Author: Sadhika Huria

Date: 23 May 2024
*/

#include <stdio.h>

int main(){
    
    int arr_size = 10;
    

    printf("Please, Enter 10 integers then press Enter: ");
    int arr[arr_size];

    for(int i = 0; i <arr_size; i++){
        scanf("%d", &arr[i]);
    }

    printf("Contents of array before reversing: ");
    for (int i = 0; i< arr_size; i++){
        printf("%d ", arr[i]);
    }

    int midpoint = (arr_size/2) - 1;

    for(int i = 0, j = arr_size -1; i <= midpoint; i++, j--){
        int hold = arr[i];
        arr[i] = arr[j];
        arr[j] = hold;
    
    }
    printf("\nContents of array after reversing: ");
    for (int i = 0; i< arr_size; i++){
        printf("%d ", arr[i]);
    }


}