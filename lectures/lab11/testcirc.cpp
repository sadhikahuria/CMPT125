#include <iostream>
#include <iomanip>
#include "Circle.h"

using std::cout;
using std::endl;

int main(){

    Circle c1 = Circle(0,0,3);
    Circle c2 = Circle(5, 20, 10);
    Circle *c3 = new Circle (0,0,5);
    Circle c4 = Circle();

    cout << "printing c1";
    c1.printCircle();

    cout << "printing c2";
    c2.printCircle();
    cout << "Changing c2";
    c2.setRadius(4);
    c2.move(4,5);
    cout << "printing c2";
    c2.printCircle();

    cout << "printing c3";
    c3->printCircle();
    delete c3;
    c3 = nullptr;

    cout << "printing c4";
    c4.printCircle();

    return 0;


}