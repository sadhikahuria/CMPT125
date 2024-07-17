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
            return NULL;
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
    return NULL;
    
}

int main(){

    //fact() check
    unsigned int num = 5 ;
    printf("fact of %d is %d\n", num, fact(num));
    return 0;
}