#include <stdio.h>


unsigned int scrambled( int arr1[], int arr2[], unsigned int size );

int main(){

    unsigned int size = 3;
    unsigned int result = 0;
    printf("\nTesting the function scrambled(...)\n\n");

    int arr1[] = {10, 15, 20};
    int arr2[] = {10, 20, 15};

    if ( (result = scrambled(arr1, arr2, size)) == 1) {
        printf("%d means that both are scrambled version of each other.\n", result);
    }
    else {
        printf("%d means that both are NOT scrambled version of each other.\n", result);
    }

    return 0;

}



