// may 29

#include <stdio.h>

int main(){
    const int array_size = 3;
    char arraychar1[array_size] = "abc";
    char arraychar2[array_size] = "abc";

    int identical = 1;

    //way 1
    for ( int i = 0; i < array_size; i++){
        if (arraychar1[i] != arraychar2[i] ) {
            printf("These two arrays are not identical \n");
            break;
        }
    }

    //way 2

    for ( int i = 0; i < array_size && identical; i++){
        if (arraychar1[i] != arraychar2[i] ) {
            printf("These two arrays are not identical \n");
            identical = 0;
        }
    }

    if (identical){ printf("They are identical\n");}
}