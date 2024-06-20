/*
 * Filename: testDriver.c
 *
 * Description: Test Driver for the function InRectangle().
 *
 * Author: Sadhika Huria
 * Modification Date: June 18 2024
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


  //My own test cases
  float rect2[CORNERS] = {-2.8, -39.5, 9.87, 2.0 };
 
  // Test Case 4

  float p1[POINTS] = {-1.8, 1.578 };

  printf( "Test Case 4\n" );
  printf( "\tExpected Result: inside!\n" );

  if( InRectangle( p1, rect2 ) == 0 ) {

    puts( "\nTest Case 4 - error" );
    // indicate error
    
  }
  else printf( "\tTest Case 4 - Actual Result: inside!\n" );


  // Test Case 5

  float p2[POINTS] = {-98.5, 1.578 };

  printf( "Test Case 5\n" );
  printf( "\tExpected Result: outside!\n" );

  if( InRectangle( p2, rect2 ) != 0 ) {

    puts( "\nTest Case 5 - error" );
     // indicate error
    
  }
  else printf( "\tTest Case 6 - Actual Result: Outside!\n" );



  // Test Case 6

  float p3[POINTS] = {-2.8, 2.0 };

  printf( "Test Case 6\n" );
  printf( "\tExpected Result: onedge!\n" );

  if( InRectangle( p3, rect2 ) == 0 ) {

    puts( "\nTest Case 6 - error" );
    return 1; // indicate error
    
  }
  else printf( "\tTest Case 6 - Actual Result: onedge!\n" );


  return 0; 
}