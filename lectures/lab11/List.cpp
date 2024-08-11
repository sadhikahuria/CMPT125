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

unsigned int List::getElementCount() const{
    return elementCount;
}

bool List::prepend( int newElement){
    bool result = true;
    Node *newNode = new Node(newElement);
    if (newNode != nullptr){
        if (tail == nullptr) tail = newNode;
        if (head != nullptr) newNode-> next;
        head = newNode;
        elementCount++;
    }
    else result = false;

    return result;
}

bool List::removeAtFront(){
    bool result = true;

    if ( head != nullptr){

        Node * remove = head;
        head = head->next;
        remove -> next = nullptr;
        delete remove;
        remove = nullptr;

        if ( head == nullptr ) tail = nullptr;

        elementCount--;
    }
    else result = false;

    return result;
}

bool List::getFrontElement(int *frontElement) const {
    bool result = true;
    if ( head != nullptr){
        *frontElement = head -> data;
    }
    else result = false;
    return result;
}

void List::printList() const{
    cout << endl << "This List had " << elementCount << " elements: { ";
    Node *current = head;
    while ( current -> next != nullptr ){
        cout << current->data << ", ";
        current = current-> next;
    }
    cout << current-> data << " }" << endl;
    return;
}