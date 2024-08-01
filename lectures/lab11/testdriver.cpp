/*
 * testDriver.cpp
 * 
 * Class Description: Tests the List data collection ADT class.
 *
 * Modified on: July 2024
 * Author: AL 
 */

#include <iostream>
#include "List.h"                

using std::cout;
using std::endl;

int main() {

  /* Variables declaration */
  List * aList = new List(); 

  /* Test Case 1 - remove from an empty List (no allocated memory yet) */
  cout << endl 
       << "Test Case 1 - Removing element at position 1 from an empty List (no allocated memory yet)."
       << endl; 
  cout << "Test Case 1 - Expected result: Could not aList->remove( )." << endl;
  if ( ! aList->remove( 1 ) ) 
      cout << "Test Case 1 - Actual Result: Could not aList->remove( )." << endl; 
  else
      cout << "Test Case 1 - Actual Result: aList->remove( ) successfully." << endl; 

  /* Test Case 2 - Populating the List of 5 random numbers */
  cout << endl 
       << "Test Case 2 - Populating the List of 5 random numbers." << endl; 
  cout << "Test Case 2 - Expected result: List has 5 elements." << endl; 
  srand( time( 0 ) );
  for ( unsigned int i = 0; i < List::defal; i++ )
    if ( ! aList->insert( i + 1, rand( ) % 100 ) ) 
      cout << "Test Case 2 - Actual Result: Could not aList->insert( )." << endl; 
  else
      cout << "Test Case 2 - Actual Result: aList->insert( ) successfully." << endl;

  /*Printing the List */ 
  cout << "Printing the List with " << aList->getElementCount( ) << " elements." << endl; 
  aList->printList( );

  /* Test Case 3 - Modifying the List */
  cout << endl << "Test Case 3 - Modifying the List at position " 
       << List::defal - 2 << " with 99." << endl;  
  cout << "Test Case 3 - Expected result: Element at position " 
       << List::defal - 2 << " replaced with 99." << endl; 
  if ( ! aList->modify( List::defal - 2 , 99 ) ) 
    cout << "Test Case 3 - Actual Result: Could not aList->modify( )." << endl; 
  else
    cout << "Test Case 3 - Actual Result: aList->modify( ) successfully." << endl;

  /* Printing the List */ 
  cout << "Printing the List with " << aList->getElementCount( ) << " elements." << endl; 
  aList->printList( );

  /* Test Case 4 - Retrieving from the List */
  int retrievedElement = 0;
  cout << endl << "Test Case 4 - Retrieving element from the List at position "
       << List::defal - 3 << endl; 
  cout << "Test Case 4 - Expected result: aList->retrieve( ) successfully." << endl; 
  if ( ! aList->retrieve( List::defal - 3 , &retrievedElement ) ) 
    cout << "Test Case 4 - Actual Result: Could not aList->retrieve( )." << endl;
  else 
    cout << "Test Case 4 - Actual Result: The retrieved element from the List at position " 
         << List::defal - 3 << " is " << retrievedElement << endl; 	

  /* Printing the List */ 
  cout << "Printing the List with " << aList->getElementCount( ) << " elements." << endl; 
  aList->printList( );

  /* Test Case 5 - Insert an element into a full List */
  cout << endl 
       << "Test Case 5 - Insert an element into a full List." << endl; 
  cout << "Test Case 5 - Expected result: Unable to insert into a full List." << endl; 
  if ( ! aList->insert( 1, rand( ) % 100 ) ) 
    cout << "Test Case 5 - Actual Result: Could not aList->insert( )." << endl; 
  else
    cout << "Test Case 5 - Actual Result: aList->insert( ) successfully." << endl;

  /*Printing the List */ 
  cout << "Printing the List with " << aList->getElementCount( ) << " elements." << endl; 
  aList->printList( );

  /* Test Case 6 - Removing from the List */
  cout << endl << "Test Case 6 - Removing element at position 1 from the List." << endl; 
  cout << "Test Case 6 - Expected Result: Element at position 1 has been removed from the List." 
       << endl; 
  if ( ! aList->remove( 1 ) ) 
    cout << "Test Case 6 - Actual Result: Could not aList->remove( )." << endl; 
  else
    cout << "Test Case 6 - Actual Result: aList->remove( ) successfully." << endl; 

  /* Printing the List */ 
  cout << "Printing the List with " << aList->getElementCount( ) << " elements." << endl; 
  aList->printList( );
  
  // Destructor called implicitely
  delete aList;
  aList = nullptr;
  
  return 0;
}