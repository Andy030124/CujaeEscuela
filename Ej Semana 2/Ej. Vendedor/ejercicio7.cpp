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
#include <iostream>
#include <sstream>
#include <cstdlib> // para system

// para que funcione el system pause en Linux y windows
#if defined(__linux__) && !defined(__MINGW32__)
    #define PAUSE "foo=0; read foo"
#elif defined(__MINGW32__) || defined(_WIN32)
    #define PAUSE "pause > null"
#endif

void pause(){
    std::cout << "\nPulse una tecla para salir...";
    std::system(PAUSE);
    std::cout << "\n";
}

template<typename T>
void input(std::string str, T& var){
    std::cout << str;
    std::cin >> var;
}

int main() {
    float ventaDiaria=0, // almacenar mis ventas diarias por semana
        salarioFijo=0,  // mi salario semanal
        comision=0,     // la comision semanal que se le suma a mi salario
        totalVentas=0,  // mi total de ventas semanal
        promedioVentas=0,   // el promedio de ganancia semanal
        salarioTotal=0,     // el resultado total
        valorDado=0; // el valor final para decidir true o false

    // Ingresar los datos de ventas y salario fijo
    input("Ingrese el salario fijo del vendedor: ", salarioFijo);

    std::cout 
    << "Ingrese el valor de cada una de las 5 ventas realizadas en la semana: " 
    << std::endl;

    for (int i = 0; i < 5; i++) {
        std::stringstream str{};
        str << "Venta dia " << i << ": ";
        input(str.str().c_str(), ventaDiaria);
        totalVentas += ventaDiaria; // calcular el total de ventas
    }
    // Calcular el promedio del total de ventas
    promedioVentas = totalVentas / 5;

    // Calcular la comisión y el salario total
    comision = promedioVentas * 0.09;
    salarioTotal = salarioFijo + comision;

    // Verificar si está por encima del valor dado
    input("Ingrese el valor dado para comparar: ", valorDado);

    // Mostrar el salario total y si está por encima del valor dado
    std::cout 
    << "El vendedor debe ganar " << salarioTotal << " en la semana.\n"
    << "¿Está por encima del valor dado?" << std::boolalpha << (salarioTotal > valorDado) 
    << std::endl;

    pause(); // pausear la consola
    return 0;
}
