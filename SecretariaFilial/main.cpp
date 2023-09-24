// ANDY GARCIA FONTICOBA
// GRUPO 11, CUJAE
/*
Ejercicio 3:
    La secretaria de la filial dispone de las notas (2,3,4,5) de un grupo
de n estudiantes en una asignatura. Elabore una aplicacion de consola que 
permita determinar cuantos estudiantes obtuvieron notas de 4 o 5, cuantos
obtuvieron notas de 3, y cuantos desaprovaron, asi como determinar que 
por ciento representa los que obtuvieron 4 o 5 con respecto al total de
estudiantes.
*/
#include <iostream>
#include <string>
#include <unordered_map>
#include <cstring>
#include <algorithm>
#include <cstdlib> // para system

// para que funcione el system pause en Linux y windows
#if defined(__linux__) && !defined(__MINGW32__)
    #define PAUSE "foo=0; read foo"
#elif defined(__MINGW32__) || defined(_WIN32)
    #define PAUSE "pause > null"
#endif

void pause(){
    std::cout << "\nPulse una tecla para continuar..." << std::endl;
    std::system(PAUSE);
    std::cout << "\n";
}

using nota_t = std::string;
using cant_t = std::size_t;
using category_t = std::unordered_map<std::string, std::size_t>;

template<typename T>
void input(std::string str, T& var){
    std::cout << str << " ";
    std::cin >> var;
    std::cout << std::endl;
}

constexpr std::size_t MIN_NOTA{2};
constexpr std::size_t MAX_NOTA{5};

int main(){
    // inicializo con mis posibles valores para evitar errores futuros
    category_t BaseDatos{
        {"2", 0},
        {"3", 0},
        {"4", 0},
        {"5", 0}
    };
    cant_t totalEstudiantes{0};
    input("Ingrese el total de estudiantes: ", totalEstudiantes);
    
    std::cout << "Ingrese las notas de cada estudiante: \n";
    std::string mensaje{"Nota del estudiante #"}; // mensaje base
    // se usa i=0; porque si el total de estudiantes 
    // es 0 no se recorre el bucle
    for(cant_t i=0; i < totalEstudiantes; i++){
        cant_t nota{0}; // donde va a guardarse la nota
        // Concateno la variable mensaje con i + 1
        input(mensaje + std::to_string(i+1) + ":", nota);
        // nota no puede ser menos que MIN_NOTA ni mayor que MAX_NOTA
        nota = std::clamp(nota, MIN_NOTA, MAX_NOTA);

        // nota_key es llevar la nota a un string
        std::string nota_key{ std::to_string(nota) };
        // como ya cree mis posibles valores arriba
        // puedo hacer esto
        BaseDatos[ nota_key ] += 1;
    }


    // IMPRIMIR ESTADISTICAS
    cant_t mejoresAlumnos = BaseDatos[ "4" ] + BaseDatos[ "5" ];
    /*
    obtener el porcentaje es:
    X = cantidad
    T = total
    P = ?
    P = X/T * 100
    Necesitamos double para que funcione el calculo 
    (se utiliza static cast para evitar un warning)
    */
    double Porcentaje = (
        static_cast<double>(mejoresAlumnos) // mejores alumnos los convierto a double
        / totalEstudiantes
    ) * 100;

    int opcion{0};
    do{
        std::cout
        << "==========================================================\n"
        << "===========================MENÚ===========================\n"
        << "==========================================================\n"
        << "1. Mejores Alumnos (notas de 4 y 5)\n"
        << "2. Estudiantes con la nota 3\n"
        << "3. Desaprobados (nota 2)\n"
        << "4. Porcentaje de buenos alumnos (porcentaje de alumnos con 4 y 5)\n"
        << "Cualquier otra opción para salir: ";
        std::cin >> opcion;

        std::cout << "\n\b";
        switch(opcion){
            case 1:
                std::cout 
                << "Cantidad de estudiantes con las notas de 4 y 5: " 
                << mejoresAlumnos << "\n";
                break;
            case 2:
                std::cout 
                << "Cantidad de estudiantes con la nota de 3: "
                << BaseDatos[ "3" ] << "\n";
                break;
            case 3:
                std::cout 
                << "Cantidada de estudiantes que desaprobaron: " 
                << BaseDatos[ "2" ] << "\n";
                break;
            case 4:
                std::cout 
                // para poder imprimir el % se necesita un \%
                << "El " << Porcentaje << "\% obtuvieron buenas notas\n";
                break;
            default: opcion = 0; break; // para facilitar el condicional
        }
    }while(opcion != 0);

    pause();
    return 0;
}


