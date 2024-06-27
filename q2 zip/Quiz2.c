/*
 * D101-D102
 * Filename: Quiz2.c
 *
 * Description: Simple operations on raster images
 *
 * Completed by: <Put your name here>
 * Completion Date: June 27
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
	// Validate the parameters
	assert( array != NULL );
    assert( x < cols );
    assert( y < rows ); 
    return array[ y*cols + x ];
}

/* Set the pixel at coordinate (x,y) to the specified colour. */
void set_pixel( uint8_t array[], 
                unsigned int cols, 
                unsigned int rows,
                unsigned int x,
                unsigned int y,
                uint8_t colour )
{
	// Validate the parameters
	assert( array != NULL ); 
	assert( x < cols );
    assert( y < rows );
    array[ y * cols + x ] = colour;
    return;
} 

/* ---------------------- Quiz 2 ---------------------- */
/* Given a pixel located at coordinates (x,y) in the raster image array[], 
   print the colour of the pixel located directly below this given pixel,
   in the raster image, on stdout. Your function must print this pixel colour
   as part of the following output statement:
   "The colour of the pixel below the pixel located at coordinates (__,__) is __." 
   Make sure you fill in the three blanks when printing the above output statement.
   This output statement must be printed on its own line.
*/
void print_pixel_below( const uint8_t array[],
                        unsigned int cols, 
                        unsigned int rows,
                        unsigned int x,
                        unsigned int y )
{
    // Put your code here
    return;
} 

/*-------------------------------------------------
  OPERATIONS ON THE WHOLE IMAGE 
*/

/*
  Returns a pointer to a freshly allocated array that contains the
  same values as the original array, or a null pointer if the
  allocation fails. The caller is responsible for freeing the array
  later.
*/
uint8_t * copy( const uint8_t array[], 
                unsigned int cols, 
                unsigned int rows )
{
  // Validate the parameter
  assert( array != NULL );

  uint8_t * copyPtr = malloc(cols*rows*sizeof(uint8_t));
  if (!copyPtr) {
    perror("Call to malloc failed\n");
    exit(1);
  }
  memcpy( copyPtr, array, cols * rows * sizeof(uint8_t) );
	
  return copyPtr;
}


/* ---------------------- Quiz 2 ---------------------- */
/* Flip the raster image vertically, top-to-bottom. */
void flip_vertical( uint8_t array[], 
                    unsigned int cols, 
                    unsigned int rows )
{
  // Put your code here
  return;
}
