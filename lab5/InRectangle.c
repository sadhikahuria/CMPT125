// CMPT125 lab 5
// Author: Sadhika Huria
// Student id: 301599274

#include <stdio.h>
#include <stdlib.h>
#include "InRectangle.h"
#include <math.h>

// pt[POINTS] -point on the plane [x,y]
// rect[CORNERS] [x, y,opposite x, opposite y]

// InRectangle return 0 - point outside the plane
// return 1 - point inside the plane or on the boundary

int InRectangle(float pt[POINTS], float rect[CORNERS] ){
    float x1, y1, x2, y2;
    
    x1 = rect[0];
    y1 = rect[1];
    x2 = rect[2];
    y2 = rect[3];

    float filler;
    int inside = 1;

    //keeping x1 < x2 for top-left & bottom-right corner
    if((y1 >= y2) && (x2 >= x1)){
        filler = x1;
        x1 = x2;
        x2 = filler;
    }

    float ptx, pty;
    ptx = pt[0];
    pty = pt[1];

    if( (ptx < x1) || (ptx > x2) || (pty < y1) || (pty > y2)){
        inside = 0;
    }

    return inside;
}