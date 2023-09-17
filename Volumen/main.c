#include "utils.h"

int main(){
    #ifdef RELEASE
        printf("El volumen es: %f\n", (
            volumen(
                inputf("Introduzca el radio externo: "),
                inputf("Introduzca el radio interno: "),
                inputf("Introduzca la longitud: ")
            )
        ));
    #else
        float 
            rext = inputf("Introduzca el radio externo: "),
            rint = inputf("Introduzca el radio interno: "),
            longitud = inputf("Introduzca la longitud: "),
            pow_rext = mpow(rext, 2),
            pow_rint = mpow(rint, 2),
            rest_rad = (pow_rext - pow_rint),
            mul_long = (M_PI * longitud),
            final = mul_long * rest_rad;

        printf("Pow %f = %f\n", rext, pow_rext );
        printf("Pow %f = %f\n", rint, pow_rint );
        printf("%f - %f = %f\n", pow_rext, pow_rint, rest_rad);
        printf("%f * %f = %f\n", M_PI, longitud, mul_long);
        printf("%f * %f = %f \n", mul_long, rest_rad, final );
    #endif

    return 0;
}


