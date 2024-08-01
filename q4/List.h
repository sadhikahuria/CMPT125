/*
 * List.h
 * 
 * Class Description: An DHSL list-based implementation of a List data collection class. 
 *
 * Modified on: July 2024
 * Author: AL
 */              


#ifndef LIST_H
#define LIST_H

#include "Node.h"

class List {

private:
    Node * head = nullptr;           // Pointer to the first node (element) in the List.
    Node * tail = nullptr;           // Pointer to the last node (element) in the List.
    unsigned int elementCount = 0;   // Current number of elements in List.

public:
    // Default constructor
    // Not to be modified!
    List();

    // Destructor
    // Not to be modified!
    ~List();

    // Description: Returns the current number of elements in the List.
    // Postcondition: List unchanged.
    // Time Efficicency: O(1)
    // Not to be modified!
    unsigned int getElementCount() const;


	// Description: Inserts "newElement" at the back of the List 
    //              and returns true if successful, false otherwise.
    // Time Efficicency: O(1) 
    // Not to be modified!	
    bool append( int newElement );
    
	
	// Description: Removes the element from the front of the List 
    //              and returns true if successful, false otherwise. 
    // Precondition: List is not empty.
    // Time Efficicency: O(1)
	// Not to be modified!	
    bool removeAtFront( );
	
    // D101-D102
    // Description: This method finds the element with the minimum value in
    //              the List and returns its position number via the parameter. 
    //              Careful: The position numbers range from 1 to "elementCount".
    //             	This method also prints this element, with the minimum value
    //              in the List, using the following format:
    //              "The element in the List with the minimum value is _____." 
    //              filling in the blank with this minimum value.
    //              This method returns true if successful. Otherwise,
    //              it sets the parameter to nullptr and returns false.
	// Precondition: List is not empty.
	// Postcondition: List unchanged.
	// Time Efficicency: _______________  <- to be completed in List.cpp
	bool findMin( unsigned int * minPosition ) const;
	
    // Description: Prints all elements in the List.
    // Format: "This List has <elementCount> elements: { <element 1> ... <element n-1> }"	
    // Postcondition: List unchanged.
    // Time Efficicency: O(n)
    // Not to be modified!
    void printList() const;	

};
#endif
