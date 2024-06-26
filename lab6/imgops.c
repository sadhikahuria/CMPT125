/*
 * Filename: imgops.c
 *
 * Description: 10 simple operations on raster images
 *
 * Author: RV - 2014
 * Modified by: AL - 2024
 *
 * Completed by: <Put your name here>
 * Completion Date: 
 */

#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/*-------------------------------------------------
  OPERATIONS ON A PIXEL 
*/

/* Get the pixel in the array at coordinate (x,y). */
uint8_t get_pixel( const uint8_t array[], 
                   unsigned int cols, 
                   unsigned int rows,
                   unsigned int x,
                   unsigned int y ) 
{	   
  // Parameter validation
  assert( x < cols );
  assert( y < rows );
	
  // Converting (x,y) -> index
  return array[x + y * cols];
}
	

/* Set the pixel at coordinate (x,y) to the specified colour. */
void set_pixel( uint8_t array[], 
                unsigned int cols, 
                unsigned int rows,
                unsigned int x,
                unsigned int y,
                uint8_t colour ) 
{
  // Parameter validation
  assert( x < cols );
  assert( y < rows );
	
  // Converting (x,y) -> index
  array[x + y * cols] = colour; 
  return;
} 

/*-------------------------------------------------
  OPERATIONS ON THE WHOLE IMAGE 
*/

/* Set every pixel to zero 0 (black). */
void zero( uint8_t array[], unsigned int cols, unsigned int rows ){
  for( unsigned int i = 0; i < (rows * cols); i++){
    array[i] = 0;
  }

  return;
}

/*
  Returns a pointer to a freshly allocated array that contains the
  same values as the original array, or a null pointer if the
  allocation fails. The caller is responsible for freeing the array
  later.
*/
uint8_t* copy( const uint8_t array[], 
               unsigned int cols, 
               unsigned int rows )
{
  // Put your code here
  uint8_t *arr_copy = malloc(cols * rows * sizeof(unsigned int));
  if( arr_copy == NULL){
    perror("allocation for arr_copy failed");
    exit(1);
  }
  for ( unsigned int i = 0; i < (rows*cols); i++){
    arr_copy[i] = array[i];
  }


  return arr_copy; // You will need to change NULL to something more appropriate.
}

/* Return the darkest colour that appears in the image. */
uint8_t darkest( const uint8_t array[], 
                 unsigned int cols, 
                 unsigned int rows )
{
  uint8_t dark = array[0];
  for( unsigned int i = 0; i < (rows*cols); i++){
    if( array[i] < dark){
      dark = array[i];
    }
  }
  return dark; // You will need to change 0 to something more appropriate.
}

/* Return the lightest colour that appears in the image. */
uint8_t lightest( const uint8_t array[], 
	              unsigned int cols, 
	              unsigned int rows )
{
  // Put your code here
  uint8_t light = array[0];
  for( unsigned int i = 0; i < (rows*cols); i++){
    if( array[i] > light){
      light = array[i];
    }
  }
  return light; // You will need to change 0 to something more appropriate.
}

/* Replace every instance of pre_colour with post_colour. */
void replace_colour( uint8_t array[], 
                    unsigned int cols, 
                    unsigned int rows,
                    uint8_t pre_colour,
                    uint8_t post_colour )
{
  // Put your code here
  for ( unsigned int i = 0; i < (rows*cols); i++){
    if ( array[i] == pre_colour){
      array[i] = post_colour;
    }
  }
  return;
}

/* Flip the image horizontally, left-to-right, like in a mirror. */
void flip_horizontal( uint8_t array[], 
                      unsigned int cols, 
                      unsigned int rows )
{
  // Put your code here
  unsigned int arr_end = (rows*cols)-1;
  unsigned int middle = ((rows*cols)/2);
  for (unsigned int i = 0; i < (middle); i++){
    uint8_t filler = array[i];
    array[i] = array[arr_end - i];
    array[arr_end - i] = filler;
  }
  return;
}


/* Find the coordinates (x,y) of the first pixel with a value that
   equals colour. Search from left-to-right, top-to-bottom. If it is
   found, store the coordinates in *x and *y and return 1. If it is
   not found, return 0.
*/
int locate_colour( const uint8_t array[],              
                  unsigned int cols, 
                  unsigned int rows,
                  uint8_t colour,
                  unsigned int *x,
                  unsigned int *y )
{
  int returnval = 0;
  for ( unsigned int i = 0; i < rows; i++)
  {
    for (unsigned int j = 0; j < cols; j++)
    {
      if ( array[i + ( j*cols)] == colour)
      {
        x = i;
        y = j; 
        returnval = 1;
      
      }
    }
  }
  return returnval;  // You will need to change 0 to something more appropriate.
}

/* Invert the image such that black becomes white and vice
   versa and light shades of grey become the corresponding dark
   shade.
*/
void invert( uint8_t array[], 
             unsigned int cols, 
             unsigned int rows )
{
  uint8_t maxval = 255;
  for ( unsigned int i = 0; i < ( rows * cols); i++){
    array[i] = maxval - array[i];
  }
  return;
}
