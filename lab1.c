#include <stdio.h>
#include <math.h>

int main(){
    float num = 2.32;
    printf("Please, enter a floating point value:");
    //scanf("%f", &num);

    int floored = floor(num);
    int rounded = round(num);
    int ceiled = ceil(num);

    printf("The smallest interger larger than or equal to %f is %d", num, floored);
    printf("The nearest interger  to %f is %d", num, rounded);
    printf("The largest interger smaller than or equal to %f is %d", num, ceiled);

}