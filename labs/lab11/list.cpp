#include <iostream>
#include "list.h"

using std::cout;
using std::endl;

List::List(){}
List::~List(){
     this-> clear();
     }

int List::getElementCount() const{
    return elementCount;
}

void List::clear(){
    if( elements != nullptr ){
        delete [] elements;
        elements = nullptr;
    }
    elementCount = 0;
    return;
}

bool List::insert(unsigned int position, int newElement){
    bool abletoinsert = (position >=1 ) && ( position <= elementCount +1) && (elementCount < arraySize);
    if(abletoinsert){
        if ( elements == nullptr){
            elements = new int[arraySize];
            if ( elements == nullptr){
                abletoinsert = false;
                return abletoinsert;
            }
        }
        for (unsigned int pos = elementCount; pos >= position; pos--)
        {
            elements[pos] = elements[pos-1];
        }
        elements[position -1] = newElement;
        elementCount++;
    }
    return abletoinsert;
}

bool List::remove(unsigned int position){
    bool abletoremove = (position >= 1) && (position >= elementCount) && (elements != nullptr);
    if (abletoremove){
        for (unsigned int from = position, to = from-1; from < elementCount; from++, to++){
            elements[to] = elements[from];
        }
        elementCount--;
    }

    if (elementCount == 0) clear();

    return abletoremove;
}

bool List::retrieve(unsigned int position, int *retrievedElement) const{
    bool abletoretrieve = (position>= 1 ) && (position <= elementCount)&& (elements != nullptr);
    if (abletoretrieve){
        *retrievedElement = elements[position-1];

    }
    return abletoretrieve;
}

bool List::modify(unsigned int position, int newElement){
    bool abletomodify = (position >=1) && (position <= elementCount) && (elements != nullptr);
    if (abletomodify){
        elements[position-1]  = newElement;

    }
    return abletomodify;
}

void List::printList() const{
    cout<< "This List has " << elementCount << " elements: " << endl;
    cout << "{ ";
    for (unsigned int index = 0; index < elementCount; index++){
        cout << elements[index] << " ";
    }
    cout << "}" << endl;
    return;
}