/*
 * Filename: testDriver.c
 *
 * Description: Test Driver for the function InRectangle().
 *
 * Author: 
 * Modification Date: June 2024
 */

#include <stdio.h>
#include "InRectangle.h"
 
int main( int argc, char* argv[] ) {

  // Define a rectangle from (1,1) to (2,2)
  float rect[CORNERS] = {1.0, 1.0, 2.0, 2.0 };
 
  // Test Case 1
  // Define a point that is inside the rectangle

  float p_in[POINTS] = { 1.5, 1.5 };
  printf( "Test Case 1\n" );
  printf( "\tTest Data: rectangle: (1.0,1.0) and (2.0,2.0), point: (1.5,1.5)\n" );
  printf( "\tExpected Result: point is in the rectangle!\n" );
  if( InRectangle( p_in, rect ) == 0 ) {
    puts( "\nTest Case 1 - error: should return true for p_in." );
    return 1; // indicate error
  }
  else printf( "\tTest Case 1 - Actual Result: point is in the rectangle!\n" );


  // Test Case 2
  // Define a point that is outside the rectangle
  float p_out[POINTS] = {2.5, 0.5};
  printf( "Test Case 2\n" );
  printf( "\tTest Data: rectangle: (1.0,1.0) and (2.0,2.0), point: (2.5,0.5)\n" );
  printf( "\tExpected Result: point is outside the rectangle!\n" );
  if( InRectangle( p_out, rect ) != 0 ) {
  
    puts( "\nTest Case 2 - error: should return false for p_out." );
    return 1; // indicate error
  }
  else printf( "\tTest Case 2 - Actual Result: point is outside the rectangle!\n" );

  // Test Case 3
  // Define a point that is on the edge of the rectangle
  float p_edge[POINTS] = {1.0, 1.0};
  printf( "Test Case 3\n" );
  printf( "\tTest Data: rectangle: (1.0,1.0) and (2.0,2.0), point: (1.0,1.0)\n" );
  printf( "\tExpected Result: point is on the edge of the rectangle!\n" );
  if( InRectangle( p_edge, rect ) == 0 ) {
  
    puts( "\nTest Case 3 - error: should return true for p_edge." );
    return 1; // indicate error
  }
  else printf( "\tTest Case 3 - Actual Result: point is on the edge of the rectangle!\n" );
 
  return 0; // all tests passed
}