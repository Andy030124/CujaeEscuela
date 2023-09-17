// ANDY GARCIA FONTICOBA
// GRUPO 11, CUJAE

/*
Un vendedor recibe cada semana un salario fijo, 
mas una comision del 9% del total del promedio
de las ventas realizadas en cada dia de la semana.
Conociendo el importe de cada una de las 5 ventas
realizadas en la semana calcular lo que debe ganar
en la semana y si esta por encima de un valor dado,
almacenar true en una variable.
*/

#include <stdio.h> // para printf y scanf
#include <stdbool.h> // para bool

#ifdef __linux__
    static char __pause_str__[2]; // in linux is necesary 2 scan chars
    #define PAUSE scanf("%c%c",&__pause_str__[0],&__pause_str__[1])
#elif defined(__MINGW32__) || defined(_WIN32)
    #include <stdlib.h> // para system (solo en windows)
    #define PAUSE system("pause > null")
#endif

void pause(){
    printf("\nPulse una tecla para salir...");
    PAUSE;
}

int main() {
    float ventaDiaria=0, // array con ventas por cada semana
        salarioFijo=0,
        comision=0,
        totalVentas=0,
        promedioVentas=0,
        salarioTotal=0,
        valorDado=0; // el valor final para decidir true o false

    // Ingresar los datos de ventas y salario fijo
    printf("Ingrese el salario fijo del vendedor: ");
    scanf("%f", &salarioFijo);

    printf("Ingrese el valor de cada una de las 5 ventas realizadas en la semana:\n");
    for (int i = 0; i < 5; i++) {
        printf("Venta dia %d: ", i + 1);
        scanf("%f", &ventaDiaria);
        totalVentas += ventaDiaria; // calcular el total de ventas
    }
    // Calcular el promedio del total de ventas
    promedioVentas = totalVentas / 5;

    // Calcular la comisión y el salario total
    comision = promedioVentas * 0.09;
    salarioTotal = salarioFijo + comision;

    // Verificar si está por encima del valor dado
    printf("Ingrese el valor dado para comparar: ");
    scanf("%f", &valorDado);

    // Mostrar el salario total y si está por encima del valor dado
    printf("El vendedor debe ganar %.2f en la semana.\n", salarioTotal);
    printf("¿Está por encima del valor dado? %s\n", (salarioTotal > valorDado) ? "true" : "false");

    pause(); // pausear la consola
    return 0;
}
