#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdint.h>


//factorial
unsigned int fact( unsigned int num){

    if (num == 0){
        return 1;
    }
    else {
        return num* fact(num -1);
    }
}

//binary serach
int binary(int *arr, int low, int high, int target){
    if (high - low == 0){
        if (arr[high] == target){
            return high;
        } else {
            return '\0';
        }
    } else {
        int mid = (low + high)/2;
        if ( target == arr[mid]){
            return mid;
        }
        else if (target < arr[mid]){
            return binary ( arr, low, mid-1, target);
        } 
        else if (target > arr[mid]){
            return binary (arr, mid+1, high, target);
        }
        
    }
    return '\0';
    
}
int Binary(int *arr, int low, int high, int target){
    
    while ( low <= high ){
        int mid = (high + low) / 2;
        if ( arr[mid] == target) {
            return mid;
        }
        else if ( arr[mid] < target) {
            return Binary(arr, mid+1, high, target);
        } 
        else if ( arr[mid] > target){
            return Binary( arr, low, mid-1, target);
        }
        else{
            return '\0';
        }
    }
    return '\0';
}
int main(){

    //fact() check
    unsigned int num = 5 ;
    printf("fact of %d is %d\n", num, fact(num));
    

    //binary
    int arr[7] = {1, 2, 4, 5, 6, 8, 9};
    int target = 6;
    int ser1 = binary(arr, 0, 6, target);
    int ser2 = Binary(arr, 0, 6, target);
    printf("ser 1: %d, and ser 2: %d, write answer is 4", ser1, ser2);
}

