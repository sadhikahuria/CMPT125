#include <iostream>
#include <cmath>
#include "Circle.h"

using std::cout;
using std::endl;

Circle::Circle() {
    x = 0;
    y = 0;
    radius = DEFAULT_VALUE;
}

Circle::Circle(int xCoord, int yCoord, double aRadius){
    x = xCoord;
    y = yCoord; 
    radius = aRadius;
}

int Circle::getX() const{
    return x;
}

int Circle::getY() const{
    return y;
}

double Circle::getRadius() const{
    return radius;
}

void Circle::move(int horiz, int vert){
    if ( horiz >= 0) x = horiz;
    else x = 0;

    if (vert >= 0) y = vert;
    else y = 0;

    return;
}

void Circle::setRadius(double aRadius){
    if (aRadius > 0.0 ) radius = aRadius;
    else radius = DEFAULT_VALUE;
    return;
}

double Circle::computeArea() const{
    return (radius * radius * M_PI);
}

void Circle::printCircle() const{
    cout << endl << "This circle has a radius of " << radius << " and is located at point";
    cout << " (" << x << "," << y << ")" << endl;
}







