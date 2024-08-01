/*
 * testDriver.cpp
 * 
 * Class Description: Tests the List data collection class.
 *
 * Modified on: July 2024
 * Author: AL 
 */

#include <cstddef>  // Needed for nullptr
#include <iostream>
#include <cctype>
#include <cstdlib>
#include "List.h"                

using std::cout;
using std::endl;

int main() {

  /* Variables declaration */
  const unsigned int MIN_NUMBER_OF_ELEMENTS = 5;
  List * aList = new List(); 

  /* Populating the list */
  cout << "Populating the List." << endl;  
  srand( time( 0 ) );
  unsigned int limit = MIN_NUMBER_OF_ELEMENTS + rand( ) % 10;
  for ( unsigned int i = 0; i < limit; i++ )
    if ( ! aList->append( rand( ) % 100 ) ) 
      cout << "Could not aList->append( )." << endl; 
  
  /* Printing the List */ 
  cout << "Printing the List with " << aList->getElementCount( ) << " elements." << endl; 
  aList->printList( );   
  
  delete aList;
  aList = NULL;
  
  return 0;
}
