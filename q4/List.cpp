/*
 * List.cpp
 * 
 * Class Description: An DHSL list-based implementation of a List data collection class.
 *
 * Modified on: July 2024
 * Author: AL
 */                  

#include <cstddef>  // Needed for nullptr
#include <climits>  // Needed for INT_MIN and INT_MAX
#include <iostream>
#include <cmath>
#include "List.h"                

using std::cout;
using std::endl;
	
// Default constructor
// Not to be modified!
List::List() { }

// Destructor
// Not to be modified!
List::~List() {
  while ( getElementCount() > 0 )
    removeAtFront();
} 


// Description: Returns the current number of elements in the List.
// Postcondition: List unchanged.
// Time Efficicency: O(1)
// Not to be modified!
unsigned int List::getElementCount() const {
  return elementCount;
}


// Description: Inserts "newElement" at the back of the List 
//              and returns true if successful, false otherwise.
// Time Efficicency: O(1)
// Not to be modified!    
bool List::append( int newElement ) {

  bool result = true;
  
  Node* newNode = new Node( newElement );  
  if ( newNode ) {  // Same as "if ( newNode != nullptr )" 
    
    if ( head == nullptr ) // Empty List
      head = newNode;
  
    if ( tail ) // Non-empty list - Same as "if ( tail != nullptr )" 
      tail->next = newNode;

    tail = newNode;
      
    elementCount++; // One more element in the list
  }
  else 
    result = false;
  
  return result;
} 


// Description: Removes the element from the front of the List 
//              and returns true if successful, false otherwise. 
// Precondition: List is not empty.
// Time Efficicency: O(1)
// Not to be modified!  
bool List::removeAtFront( ) {

  bool result = true;
  
  if ( head ) {  // Same as "if ( head != nullptr )"
    Node* tobeRemoved = head;
    head = head->next;
    
    tobeRemoved->next = nullptr;
    delete tobeRemoved;
    tobeRemoved = nullptr;
      
    if ( head == nullptr ) tail = nullptr;
    
    elementCount--; 
  }
  else 
    result = false;
  
  return result;
} 
	

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
// Time Efficicency: _______________  *** Write your Time Efficicency here! ***
bool List::findMin( unsigned int * minPosition ) const {
	
  // Put your code here!
  
}

    
// Description: Prints all elements in the List.
// Format: "This List has <elementCount> elements: { <element 1> ... <element n-1> }"
// Postcondition: List unchanged.
// Time Efficicency: O(n)
// Not to be modified!
void List::printList() const {

  cout << "This List has " << elementCount << " elements: {";
  if ( head ) {  // Same as "if ( head != nullptr )"
    Node * current = head;
    for ( unsigned int i = 1; i <= elementCount; i++ ) {
      cout << " " << current->data;
      current = current->next;
    }
  }
  cout << " }" << endl;
  return;
}
