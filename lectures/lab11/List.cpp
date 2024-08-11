#include <cstddef>
#include <iostream>
#include "Node.h"
#include "List.h"


using std::cout;
using std::endl;

List::List(){}
List::~List(){
    while( getElementCount() > 0 ){
        removeAtFront();
    }
}

