//list.h
//list is a linear data collection


/* Methods
    insert
    remove(position)
    
*/


#ifndef LIST_H
#define LIST_H

#include "Node.h"

class List {

    private:

    Node * head = nullptr;
    Node * tail = nullptr;
    unsigned int elementCount = 0;


    public:

    List();
    ~List();

    unsigned int getElementCount() const;
    bool append(int newElement);
    bool prepend(int newElement);
    bool removeAtFront();
    bool getFrontElement( int * frontElement ) const;
    void printList() const;

};
#endif