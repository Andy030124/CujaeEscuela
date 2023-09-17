#ifndef _UTILS_H_
#define _UTILS_H_
#include <stdio.h> // for input/output functions
#include <stdlib.h> // for system function
#include <math.h> // for PI

// input a float value (NULL if you won't print any)
float inputf(const char* str);

// do a pow to any float number
float mpow(float n, int exp);

// calculate the volume of a cylinder
float volumen(float rext, float rint, float longitud);

#endif // _UTILS_H_