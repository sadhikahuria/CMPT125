#include <stdio.h>

int main(){
    float input, small;
    float sum = 0.0;
    int eofcheck;
    float previousinput = 0;
    int count = 0;
    printf("Enter value: ");
    while( ( eofcheck = scanf("%f", &input)) != EOF){
        if (( input >= -100.0) && (input <= 100.0)){
            sum += input;
            if (previousinput > input){
                small = input;
            }
            count++;
            previousinput = input;
        } else {
            printf("\n%.1f is invalid\n", input);
        }
        printf("Enter value: ");
    }

    if(count == 1){
        small = sum;
    }
    printf("\nthe small is %.1f", small);
    printf("\nthe sum is %.1f", sum);
}


