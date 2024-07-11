/* 
 * dataStructure.c
 *
 * Provides a bound-checked data structure made of an array of integers
 * in which duplicated elements are allowed.
 *
 * The interface of this data structure includes several utility 
 * functions that operate on this array of integers as well as 
 * file i/o functions: saving into and loading from json files. 
 * 
 * Do not change the dataStructure.h file.
 *
 * Author: RV + AL 
 * Modified Date: July 2024 
*/

#include <stdlib.h> // for malloc() and for rand()
#include <stdio.h>  // for file i/o calls
#include <time.h>   // for time()
#include <string.h> // for strlen()
 
#include "dataStructure.h"


/* 
 * Description: Creates a new intArray_t data structure 
 *              with initial array size "size".
 *              If successful (i.e. memory allocation succeeds), 
 *              returns a pointer to a newly-allocated intArray_t. 
 *              If unsuccessful, returns a NULL pointer.
 * Time Efficiency: O(1)
 */
intArray_t * intArray_create( unsigned int size ) {

  // Allocate memory on the heap for intArray_t struct 
  intArray_t * ia = malloc( sizeof( intArray_t ) );
  if ( ia != NULL ) {

    // Set its field "size"
    ia->size = size;

    // Allocate memory on the heap for array
    ia->data = malloc( size * sizeof(int) );
    if ( ia->data == NULL ) {
      free( ia );
      ia = NULL;
    }
	else
	  // Set its field "elementCount" to zero -> empty array
	  ia->elementCount = 0;
  }
  return ia;
}

/* 
 * Description: Frees all memory allocated for "ia".
 *              If the pointer "ia" is NULL, it does nothing. 
 *              If the pointer "ia->data" is NULL, it does not 
 *              attempt to free it. Returns INTARR_OK.
 * Time Efficiency: O(1)
 */ 
intArrayResult_t intArray_destroy( intArray_t * ia ) {

  // If heap memory has been allocated for intArray_t struct ...
  if ( ia != NULL ) {
  
    // If heap memory has been allocated for array ...
    if ( ia->data != NULL ) {
      // ... then free it
      free( ia->data );
      ia->data = NULL;
    }
  
    // ... then free it.
    free( ia );
    ia = NULL;
  }

  return INTARR_OK;
}

/* Description: Appends "newElement" and returns INTARR_OK. 
 *              If "newElement" cannot be appended, leaves the 
 *              data structure unmodified and returns INTARR_ERROR.
 *              If "ia" is NULL, returns INTARR_BADPARAM.
 * Time efficiency: O(1)
 */
intArrayResult_t intArray_append( intArray_t * ia, int newElement ) {
  //check if ia is null
  if (ia == NULL){
    return INTARR_BADPARAM;
  }

  // check if array is full
  if (ia-> elementCount == ia-> size){
    return INTARR_ERROR;
  }

  //append and update struct parameters
  if (ia-> elementCount < ia-> size){
    ia -> data[ia-> elementCount] = newElement;
    ia-> elementCount ++;
  return INTARR_OK;
  }
  else{
    return INTARR_ERROR;
  }
}
				
/* Description: Removes the element at "indexToBeRemoved" in the data structure
 *              and returns INTARR_OK. If the data structure was initially sorted,
 *              it does not remain sorted after removing the element at "indexToBeRemoved".
 *              If "ia" is NULL or "indexToBeRemoved" is out of bounds, returns INTARR_BADPARAM.
 * Time efficiency: O(1)
 */
intArrayResult_t intArray_remove( intArray_t * ia, unsigned int indexToBeRemoved ) {
	//check if ia is null
  if( ia == NULL){
    return INTARR_BADPARAM;
  }

  //check bounds through count
    if ( ( indexToBeRemoved >= ia-> elementCount ) ){
    return INTARR_BADPARAM;
  }


  //remove and adjust index
  unsigned int adjustindex = indexToBeRemoved;
  while((adjustindex < ia-> elementCount)){
    ia-> data[adjustindex] = ia-> data[adjustindex+1];
    adjustindex++;
  }

  ia-> elementCount--;

  return INTARR_OK;
}

/* Description: Modifies (overwrites) the element at "index" with "newElement"
 *              and returns INTARR_OK. If "ia" is NULL or "index" is out of bounds,
 *              returns INTARR_BADPARAM.
 * Time Efficiency: O(1)
 */
intArrayResult_t intArray_modify( intArray_t * ia, int newElement, unsigned int index ) {
	//checking if ia is null
  if (ia == NULL){
    return INTARR_BADPARAM;

  }
  //checking bounds
  if ( (index >= ia-> elementCount)){
    return INTARR_BADPARAM;
  }

  //overwriting
  ia -> data[index] = newElement;
  return INTARR_OK;
  
}

/* Description: Finds the first occurrence of "targetElement" in the data structure,
 *              sets "*index" to its index and returns INTARR_OK. If "targetElement" 
 *              does not occur in the data structure, leaves "*index" unmodified 
 *              and returns INTARR_NOTFOUND. If "ia" is NULL, returns INTARR_BADPARAM.
 * Time efficiency: O(n)
 */
intArrayResult_t intArray_find( intArray_t * ia, int targetElement, unsigned int * index ) {
  //check is ia is null
  if ((ia == NULL) || (index == NULL)){
    return INTARR_BADPARAM;
  }  

  //looking for element
  for( unsigned int i = 0; i < ia-> elementCount; i++){
    if( ( ia-> data[i] ) == targetElement ){
      *index = i;
      return INTARR_OK;
    }
  }

  //if element not found
  return INTARR_NOTFOUND;
  
}

/* Description: Sorts the data structure by value in ascending sort order 
 *              (by smallest-to-largest), such that data[i] < data[i+1] for all valid i, 
 *              then returns INTARR_OK. If "ia" is NULL, returns INTARR_BADPARAM.
 *              Works in-place: content of "ia" is sorted on return. 
 *              Sorts the array using the Bubble Sort algorithm.
 * Time efficiency: O(n^2)
 * Space efficiency: O(1) - Bubble Sort is an "in-place" algorithm.
 */
intArrayResult_t intArray_sort( intArray_t * ia ) {
  if ( ia == NULL){
    return INTARR_BADPARAM;
  }

  for (unsigned int i = 0; i < ia->elementCount - 1; i++) {
    for (unsigned int j = 0; j < ia->elementCount - i - 1; j++) {
      if (ia->data[j] > ia->data[j + 1]) {
        // Swap elements
        int filler = ia->data[j];
        ia->data[j] = ia->data[j + 1];
        ia->data[j + 1] = filler;
      }
    }
  }
  return INTARR_OK;
}
							
/* Description: Returns a duplicate copy of "ia", allocating new storage 
 *              for this duplicate data (we call this a "deep copy"). 
 *              If unsuccessful (i.e. memory allocation for the copy fails, 
 *              or "ia" is NULL), returns a NULL pointer. 
 */
intArray_t * intArray_copy( const intArray_t * ia ) {
  //check if ia is NULL
  if (ia == NULL){
    return NULL;
  }

  //allocating
  intArray_t *copy = intArray_create(ia-> size);
  if (copy == NULL){
    return NULL;
  }

  //copy
  for(unsigned int i = 0; i < ia-> elementCount; i++){
    copy-> data[i] = ia->data[i];
  }
  copy -> elementCount = ia -> elementCount;

  return copy;
}

/* Description: Prints each field (member) of the data structure "ia" and
 *              prints each element of its array field then returns INTARR_OK.
 * Time Efficiency: O(n)
 */
intArrayResult_t intArray_print( intArray_t * ia ) {
	// check if ia is null
  if( ia == NULL){
    return INTARR_BADPARAM;
  }

  printf("Size: %u\n", ia-> size);
  printf("Element Count: %u\n", ia-> elementCount);
  printf("Data: ");
  for(unsigned int i = 0; i < ia -> elementCount-1; i++){ //printing all elements
    printf("%d, ", ia -> data[i]);
  }

  printf("%d\n", ia-> data[ia->elementCount]);
  
  return INTARR_OK;  // You are free to modify this return statement.
}

/* Description: Writes (saves) the entire array "ia" into a file 
 *              called "filename" in a JSON text file format (explained below)
 *              that can be loaded by the function intArray_load_from_json(...).
 *              Returns INTARR_OK on success, or INTARR_ERROR on failure. 
 *              Empty arrays (elementCount == 0) should produce an 
 *              output file containing an empty array.
 *              If "ia" is NULL or "filename" is NULL, returns INTARR_BADPARAM.
 *
 *              The JSON output should be human-readable.
 *
 * Example: The following lines are a valid JSON file content 
 *          produced by first saving "elemenCount" (3), then
 *          each of the 3 elements contained in the array
 *          (100, 200, 300) into a file:
 * [
 *  3,
 *  100, 
 *  200, 
 *  300 
 * ]
 */


intArrayResult_t intArray_write_to_json( intArray_t * ia, const char * filename ) {

  //checking is array or the file is null
  if ( (ia == NULL) || ( filename == NULL)){
    return INTARR_ERROR;
  }

  FILE * myfile = fopen( filename, "w");
  //checking to see if fopen is succesful
  if (myfile == NULL){
    return INTARR_ERROR;
  }

  // printing in the given format above

  fprintf(myfile, "[\n\t%d,\n", ia-> elementCount);
  for ( unsigned int i = 0; i < ia -> elementCount; i++){
    fprintf( myfile, "\t%d", ia-> data[i]);
    if ( i < ia-> elementCount - 1){
      fprintf(myfile, ",");
    }
    fprintf(myfile, "\n");

  }
  fprintf(myfile, "]\n");


  //close the file
  fclose(myfile);

  return INTARR_OK; 
}


/* Description: Loads a new array from the file called "filename", that was
 *              previously saved using intArray_write_to_json(...). The file may 
 *              contain an empty array. Returns a pointer to a newly-allocated 
 *              data structure on success (even if the array is empty), 
 *              or NULL on failure.
 *              If "filename" is NULL, returns NULL.
 */
intArray_t * intArray_load_from_json( const char * filename ) {

  //check if filename is null
  if (filename == NULL){
    return NULL;
  }

  //open file
  FILE *myfile = fopen(filename, "r");
  //check fopen
  if (myfile == NULL){
    return NULL;
  }

  
  //check size
  unsigned int size;
  fscanf(myfile, "[\n\t%d,\n", &size);
  
  //create array
  intArray_t *newarr = intArray_create(size);

  //check for create
  if (newarr == NULL){
    return NULL;
  }


  // reading my elements
  for(unsigned int i = 0; i < size-1; i++){
    fscanf( myfile, "\t%d,\n", &(newarr-> data[i]));
    newarr-> elementCount ++;
  }
  fscanf(myfile, "\t%d\n", &(newarr-> data[size-1]));
  newarr-> elementCount ++;

  //close the file and return
  fclose(myfile);
  return newarr;

}

