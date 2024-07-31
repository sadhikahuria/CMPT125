// rectangle.h

// methods: functions for a class
//public: methods
// private: data


/* 
Methods vs functions

Functions: 
    prepending name of the function with data structure
        eg intArray_print: print is the function, and intArray was the structure
    we pass a pointer to an object of the data type
        eg intArray *ia: ia was a pointer to the list
    created and destroyed list
        eg intArray_create and intArray_destroy

Methods:
    dont prepend, methods are in the class
    you must indicate scope, 
        eg <classnasme>:: in the implementation
    there is a constructor and a destructor

*/
#ifndef RECTANGLE.H
#define RECTANGLE.H

class rectangle {
    
    private: //private, can't be seen through client code, like test driver
    
    const unsigned int default = 10;
    unsigned int width;
    unsigned int height;


    public: //anyone can access it
    
    //methods - specific to class

    //tocreate use class name
    rectangle(); //default, no arguments
    rectangle(unsigned int width, unsigned int height); //with parameters

    //getters
    unsigned int getwidth() const;
    unsigned int getheight() const;
    
    // setters
    void setwidth (unsigned int awidth);
    void setheight (unsigned int aheight);

    //methods - specific to problem statement
    
    unsigned int computearea() const;
    bool isSquare() const;
    void printRectangle() const;

};

#endif

