#include <iostream>
#include "Node.h"

Node::Node(): next(nullptr) {}

Node::Node(int theData){
    data = theData;
    next = nullptr;

}

Node::Node ( int theData, Node *theNextNode){
    data = theData;
    next = theNextNode;
}