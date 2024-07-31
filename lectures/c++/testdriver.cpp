#include <iostream>
#include <stdio.h>
#include "Rectangle.h"


using namespace std;

int main(){
    
    rectangle r1 = rectangle(5,7);
    rectangle r2 = rectangle(5,5);
    rectangle r3 = rectangle(0,6);

    r1.printRectangle();
    r2.printRectangle();
    r3.printRectangle();

    return 0;
}