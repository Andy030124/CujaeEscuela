#include "utils.h"

// input a float value (NULL if you won't print any)
float inputf(const char* str){
    float ret=0.0f;
    if( str )
        puts(str);
    scanf("%f", &ret);
    printf("Scanned Value: %f\n", ret);
    return ret;
}

// do a pow to any float number
float mpow(float n, int exp){
    printf("Cicles: %i\n", exp);
    printf("Number %f\n", n);
    for(int i=1; i < exp; i++){
        printf("%i/%i\n",i,exp);
        n*=n;
        printf("Number %f\n", n);
    }
    printf("Return: %f\n", n);
    return n;
}

// calculate the volume of a cylinder
float volumen(float rext, float rint, float longitud){
    printf("Inputs: \n rext - %f \n rint - %f \n len - %f",
        rext, rint, longitud
    );
    return (
        (M_PI * longitud) * ( mpow(rext, 2) - mpow(rint, 2) )
    );
}


