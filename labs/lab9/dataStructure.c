/* 
 * dataStructure.c
 *
 * Provides a data structure made of a doubly-headed singly-linked list (DHSL) 
 * of unsorted elements (integers) in which duplicated elements are allowed.
 * 
 * A DHSL list is comprised of a single variable of data type list_t
 * and zero or more elements (each element stored in a node variable of data
 * type element_t). The struct list_t contains a pointer (called "head") to 
 * the first element in the list and a pointer (called "tail") to the last 
 * element of the list. If the list is empty, both pointers are set to NULL. 
 * The first element (node in the list) contains a pointer to the "next" element,
 * and so on. The last element in the list has its "next" pointer set to NULL.
 *
 * The interface of this data structure includes several utility 
 * functions that operate on this data structure.
 *
 * Precondition: Functions that operate on such data structure
 *               require a valid pointer to it as their first argument.
 *
 * Do not change the dataStructure.h file.
 *
 * Your name: Sadhika Huria
 * Modified Date: July 17, 2024
*/ 

#include <stdio.h>
#include <stdlib.h>
#include "dataStructure.h"


/* 
 * Description: Creates a new empty data structure of list_t type and 
 *              if successful, returns a pointer to it. 
 *              If unsuccessful, returns NULL.
 * Time Efficiency: O(1)
 */
list_t * list_create( void ) {

  list_t * aList = malloc( sizeof(list_t) );
  if (aList == NULL){
    return NULL;
  }
  else {
    aList->head = NULL;
    aList -> tail = NULL;
    aList-> elementCount = 0;
  }
  return aList;
}

/*
 * Description: Frees all memory used by the data structure pointed to by "list". 
 *              Returns LIST_OK on success.
 * Time Efficiency: O(n)
 */ 
listResult_t list_destroy( list_t * list ) {

  listResult_t result = LIST_OK;

  if (list == NULL){
    result = LIST_NULL_PARAM;
  }
  else{
    if (list-> head != NULL && list-> elementCount != 0){
      element_t *removenode = list->head;
      while(removenode != NULL){
        element_t *nextnode = removenode-> next;
        free(removenode);
        removenode = nextElement;
      }
      
    }
  }
  
  return result;
}

/* 
 * Description: Returns a pointer to a new element i.e., a node  
 *              containing "newElement" and its "next" pointer set to NULL, 
 *              or NULL if memory allocation fails.
 * Time Efficiency: O(1)
 */
element_t * element_create( int newElement ) {

  element_t * anElement = malloc( sizeof(element_t) );

  if(anElement == NULL){
    return NULL;
  }
  else {
    anElement->val = newElement;
    anElement-> next = NULL;
  }

  return anElement;
}

/* Description: Appends a new element, i.e., a node containing "newElement", 
 *              to this data structure pointed to by "list" and returns LIST_OK. 
 *              If "newElement" cannot be appended, leaves the 
 *              data structure unmodified and returns LIST_ERROR.
 *              Returns LIST_NULL_PARAM if "list" is NULL.
 * Time efficiency: O(1)
 */
listResult_t list_append( list_t * list, int newElement ) {
	listResult_t result = LIST_OK;
  if(list == NULL){
    result = LIST_NULL_PARAM;
  }

  else{
    element_t * newNode = element_create(newElement);
    if (newNode == NULL){
      result = LIST_ERROR;
    }
    if ( (list-> elementCount == 0) || (list-> head == NULL)){
      list-> head = newNode;
    }
    else{
      list-> tail -> next = newNode;
    }
    list -> tail = newNode;
    list-> elementCount ++;
  }
  
  return result;
}

/* Description: Prepends a new element, i.e., a node containing "newElement", 
 *              to this data structure pointed to by "list" and returns LIST_OK. 
 *              If "newElement" cannot be prepended, leaves the 
 *              data structure unmodified and returns LIST_ERROR.
 *              Returns LIST_NULL_PARAM if "list" is NULL.
 * Time efficiency: O(1)
 */
listResult_t list_prepend( list_t * list, int newElement ) {
  
  listResult_t result = LIST_OK;

  // Returns LIST_NULL_PARAM if "list" is NULL.
  if ( list == NULL ) result = LIST_NULL_PARAM; 
  else {
	// Creates a new element (node) containing "newElement" 
    element_t * anElement = element_create( newElement );    
    if ( anElement == NULL ) result = LIST_ERROR;
    else {
      if ( list->tail == NULL ) // Empty list
        list->tail = anElement;
  
      if ( list->head ) // Non-empty list
        anElement->next = list->head;

      list->head = anElement;

      // Record the fact that there is one more element in the list
      list->elementCount++; 
    }
  }  
  return result;
}

/* Description: Removes the front (first) element (node) from the data 
 *              structure pointed to by "list" and returns LIST_OK. 
 *              If no elements (no nodes) can be removed, leaves the 
 *              data structure unmodified and returns LIST_ERROR.
 *              Returns LIST_NULL_PARAM if "list" is NULL.
 * Time efficiency: O(1)
 */
listResult_t list_removeFront( list_t * list ) {
	
  listResult_t result = LIST_OK;

  if(list == NULL){
    result = LIST_NULL_PARAM;
  }
  else{
    if(list-> head != NULL){
      element_t *remove = list-> head;
      list-> head = list -> head -> next;
      free(remove);
      remove = NULL;
      list-> elementCount --;

    }
    else{result = LIST_ERROR;}
  }
  return result;
}
							
/* Description: Returns a pointer to the element (i.e., to the node) at 
 *              "position" in the data structure pointed to by "list". 
 *              To determine the proper "position" in the data structure,
 *              know that the first element (node) in the list is at "position" 1, 
 *              the second element (node) is at "position" 2, etc. 
 *              Returns NULL if "position" is out of range. 
 *              Returns NULL if "list" is NULL.
 *              This function does not modify the data structure.
 * Time efficiency: O(n)
 */ 
element_t * list_get( list_t * list, unsigned int position ){

  if((list == NULL) || (list-> elementCount < position) || (position < 1)){
    return NULL;
  }
  element_t *anElement = list-> head;
  for(unsigned int i = 1; i < position; i++){
    if (anElement -> next != NULL){
      anElement = anElement -> next;
    }
  }    
  return anElement;
}

/* Description: Returns a pointer to the element (i.e., to the node) that 
 *              contains the first occurrence of "targetElement" in the data 
 *              structure pointed to by "list". Returns NULL if "targetElement"
 *              is not found. Returns NULL if "list" is NULL.
 *              This function does not modify the data structure.
 * Time efficiency: O(n)
 */ 
element_t * list_find( list_t * list, int targetElement ) {

  element_t * anElement = NULL; 

  // Function Stub
  // This stub is to be removed when you have successfully implemented this function, i.e., 
  // ***Remove this call to printf!***  
  printf( "Calling list_find(...): find the first occurrence of targetElement %d in the list.\n", targetElement );
  
  return anElement;
}

/* Description: Prints the content of the data structure pointed to by "list",
 *              printing the list in human-readable form from the first element
 *              to the last element, between curly braces, then returns LIST_OK.
 *              Returns LIST_NULL_PARAM if "list" is NULL.
 *              This function does not modify the data structure.
 * Time Efficiency: O(n)
 */
listResult_t list_print( list_t * list ) {

  listResult_t result = LIST_OK;

  // Returns LIST_NULL_PARAM if "list" is NULL.
  if ( list == NULL ) result = LIST_NULL_PARAM;
  else {  
    printf( "This data structure has %d element%c:\n", list->elementCount,
             list->elementCount > 0 ? 's': ' ' );
    printf( "{" );
  
    // Prints each element
    for ( element_t * eachElement = list->head; eachElement; eachElement = eachElement->next )
      printf( " %d", eachElement->val );

    printf( " }\n" );
  }
  
  return result;
}