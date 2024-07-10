/* 
 * Filename: Demo_Shallow_Copy.c
 *
 * Description: Demo a shallow copy.
 *
 * Modified: AL 
 *
 * Modification Date: June 2024
 */

#include <stdint.h> // for uint8_t
#include <stdlib.h> // for malloc() and for rand()
#include <time.h>   // for time()
#include <string.h> 
#include <stdio.h> 
#include <assert.h>

#include "dataStructure.h"


int main( int argc, char * argv[] ) {

  const unsigned int ALL_IS_GOOD = 0;  
  const unsigned int ERROR = 1;
  const unsigned int SIZE = 10;  
  
  printf("Creating data structure of intArray_t data type.\n"); 
  intArray_t * original = intArray_create( SIZE );
  if ( original == NULL ) {
    printf("test_ia == NULL\n");
    return ERROR;
  } 
 
  printf("Populating original with random data\n");
  // Intialize the random number generator with the current time in seconds
  srand( time(NULL) );
  // Fill "original" with random numbers
  for ( unsigned int i = 0; i < original->size; i++ ) {
    intArray_append( original, ( rand() % original->size ) ); 
  }

  printf("Printing original\n"); 
  intArray_print( original );

  // Shallow copy:
  printf("Let's copy original to shallow_copy_of_original\n");
  //intArray * shallow_copy_of_original = original;



  
  // Ascertain that shallow_copy_of_original is indeed a copy of original
  assert( shallow_copy_of_original == original );
  assert( shallow_copy_of_original->size == original->size );  
  assert( shallow_copy_of_original->elementCount == original->elementCount );  
  assert( shallow_copy_of_original->data == original->data );  

  printf("Printing shallow_copy_of_original\n"); 
  intArray_print( shallow_copy_of_original );

  // Even the pointer shallow_copy_of_original->data is a copy of the 
  // pointer original->data
  printf( "shallow_copy_of_original->data => %p AND original->data => %p\n", 
           shallow_copy_of_original->data, original->data );

  // Let's observe the effect of this shallow copy:
  // if the original->data is changed (here we sort it)  
  printf("Sort original\n"); 
  intArray_sort( original );
  
  printf("Printing original\n"); 
  intArray_print( original );

  // so will shallow_copy_of_original->data 
  // because both pointers are pointing to the same memory location 
  printf("Printing shallow_copy_of_original\n"); 
  intArray_print( shallow_copy_of_original );
 
  // Let's observe the effect of this shallow copy once again:
  // if the first element of original->data is changed to 99
  printf("Modify first element of original to 99\n"); 
  intArray_modify( original, 99, 0 );
  
  printf("Printing original\n"); 
  intArray_print( original );

  // so will the first element of shallow_copy_of_original->data 
  // because both pointers are pointing to the same memory location 
  printf("Printing shallow_copy_of_original\n"); 
  intArray_print( shallow_copy_of_original );

  // Let's observe the effect of this shallow copy one more time:
  // if we destroy original and release original->data    
  printf("Destroy original\n");  
  intArray_destroy( original );
  
  // what happens when we print shallow_copy_of_original?
  printf("Printing shallow_copy_of_original\n"); 
  intArray_print( shallow_copy_of_original ); 
 
  return ALL_IS_GOOD;
}