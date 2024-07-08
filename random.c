#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int array[6];
    array[0] = 5;
    array[3] = 4;
    array[5] = 3;
    for (int i = 0; i < 6; i++){
        if (array[i] != '\0'){
            printf("yes ");
        }
        else{
            printf("no ");
        }
    }
}