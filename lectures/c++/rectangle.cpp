/* 

rectangle:
    width
    height
    area
    (x,y) center
manipulate:
    move
    compute area
    isPointInRectangle

*/

#include <iostream>
#include "rectangle.h"

using std::cin;
using std::cout;
using std::endl;

//implementations

rectangle::rectangle() : width(defaul), height(defaul){
    cout << "Calling default constructor." << endl;
}

rectangle::rectangle(unsigned int awidth, unsigned int aheight) {
    cout << "Calling parameterized constructor with width " << awidth << " and a height " << aheight << endl;
    width = awidth;
    height = aheight;
    if ( awidth <= 0 ) width = defaul;
    if ( aheight <= 0) height = defaul;
}

// use the destructor provided by the system
// rectangle::~rectangle(){}


//getters
unsigned int rectangle::getwidth() const{
    return width;
}
unsigned int rectangle::getheight() const{
    return height;
}


//setters
void rectangle::setwidth(unsigned int awidth) {
    if ( awidth > 0) width = awidth;
    else width = defaul;
    return;
}
void rectangle::setheight(unsigned int aheight){
    if (aheight > 0) height = aheight;
    else height = defaul;
    return;
}

//methods - for problem statements

/*     unsigned int computearea() const;
    bool isSquare() const;
    void printRectangle() const;
    */

unsigned int rectangle::computearea() const{
    return width * height;
}

bool rectangle::isSquare() const{
    return width == height;
}

void rectangle::printRectangle() const{
    cout << "Retangle's width is " << getwidth();
    cout << " and the height is " << getheight();
    cout << "." << endl;
    return;
}