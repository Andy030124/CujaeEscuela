#include "utils.h"

// input a float value (NULL if you won't print any)
float inputf(const char* str){
    float ret=0.0f;
    if( str ) puts(str);
    scanf("%f", &ret);
    return ret;
}

// do a pow to any float number
float mpow(float n, int exp){
    for(int i=1; i < exp; i++)n*=n;
    return n;
}

// calculate the volume of a cylinder
float volumen(float rext, float rint, float longitud)
{ return ( (M_PI * longitud) * ( mpow(rext, 2) - mpow(rint, 2) ) ); }
