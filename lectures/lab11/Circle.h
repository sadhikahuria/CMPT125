/*
* Circle.h
*
* Description: This class models a circle.
* Class Invariant: The circle's radius must be greater than 0.0

* Author:
* Creation date: July 2024
*/

#ifndef CIRCLE_H
#define CIRCLE_H


// Definition of a circle class
class Circle {

  private: // Everything that follows is private and cannot be "seen" i.e., accessed from outside the class.

  /* Data */

	const unsigned int DEFAULT_VALUE = 10;
    int x;          // coordinate (an int), can be negative
    int y;          // coordinate (an int), can be negative
    double radius;  //(a double), must be greater than 0.0
  
  /* Methods - Some classes have private methods, this one doesn't! */

  public: // Everything that follows is public and can be "seen" i.e., accessed from outside the class.

    // Default constructor
    // Description: A default constructor that creates a circle of radius 10 at position (0,0).
    //              The default constructor has no parameters.	
    Circle();
	
    // Parameterized constructor
    // Description: A constructor with parameters for x, y, and radius.
	//              Constructs a new circle with the given values.
    Circle(int x, int y, double radius);
     
	 
    // Getters: Return information about the circle.
	// Note the "const" at the end of the method.
    // This guarantees that the method does not alter the member variables
	
    // Description: Returns the circle's x coordinate.
	// PostCondition: Does not change the circle.
    int getX() const;
	// Description: Returns the circle's y coordinate.
	// PostCondition: Does not change the circle.
    int getY() const;
	// Description: Returns the the circle's radius.
	// PostCondition: Does not change the circle.
    double getRadius() const; 

    
	// Setters: Change the values of the data members.
    // In this lab, the setters 
	// void setX(int x); and 
	// void setY(int y);
	// are not implemented. They have been replaced by the method
	// void move(int horiz, int vert); - see below!
	
    // Description: Changes the circle's radius to aRadius,
	//              or to 10.0 if aRadius is <= 0.0 (invalid).
    void setRadius(double aRadius);


    // Methods - Specific to Problem Statement 
	
    // Description: Moves the circle the given horizontal and 
	//              vertical distances (therefore changing 
	//              its x and y data members (aka attributes).
	// Replace void setX(int x); and void setY(int y);
    void move(int horiz, int vert);

    // Description: Computes and returns the circle's area.
	// PostCondition: Does not change the circle. 	
    double computeArea() const;

    // Description: Prints the circle's data members like this:
    //           	"This circle has a radius of 10.0 and is located at point (12,7)."
	// PostCondition: Does not change the circle. 	
    void printCircle() const; // 

}; // Note the ";" - don't forget it!
#endif