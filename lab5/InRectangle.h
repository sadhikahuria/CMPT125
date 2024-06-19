#define POINTS 2
#define CORNERS 4

int InRectangle(float pt[POINTS], float rect[CORNERS] );

// pt[POINTS] -point on the plane [x,y]
// rect[CORNERS] [x, y,opposite x, opposite y]

// InRectangle return 0 - point outside the plane
// return 1 - point inside the plane or on the boundary