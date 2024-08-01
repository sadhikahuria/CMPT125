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
//              This method returns true if successful. Otherwise,e
//              it sets the parameter to nullptr and returns false. 
// Precondition: List is not empty.
// Postcondition: List unchanged.
// Time Efficicency: ____O(n)________  *** Write your Time Efficicency here! ***

bool List::findMin( unsigned int * minPosition ) const {

  bool result = true; //result
  bool empty = (head == nullptr); //precondition

  if (empty){
    minPosition = nullptr;
    result = false;
  }//fail 

  if(!empty){ // if list not empty 

    Node *current = head; // anchoring 
    int minval = current->data; // minimum value to compare and to store, set to the first element
    unsigned int pos = 1; // to compare elements starting with position 1 
    unsigned int minpos = 1; // to store the minimum position starting with minval position, which is 1

    while (current != nullptr){ // while the next elment is not null/ next list element still exists

      if (current-> data < minval){ //comparing each element to the min val
        minval = current->data; // setting the next min
        minpos = pos; // setting the position of the min element to current position
      }

      current = current-> next; //traversing through the list
      pos++; //incrementing position
    }

    *minPosition = minpos; // setting the pointer to the value 

    //printing min val and its position
    cout << "The element in the list with the minimum value is " << minval << " at position " << minpos << endl;

    return result; //return successful or not
  }
  
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
