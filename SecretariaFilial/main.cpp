#include <iostream>
#include <string>
#include <unordered_map>
#include <cstring>
#include <algorithm>

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
    category_t BaseDatos{};
    cant_t totalEstudiantes{0};

    input("Ingrese el total de estudiantes: ", totalEstudiantes);
    
    std::cout << "Ingrese las notas de cada estudiante: \n";
    std::string mensaje{"Nota del estudiante #"};
    for(cant_t i=0; i < totalEstudiantes; i++){
        cant_t nota{0};
        input(mensaje + std::to_string(i+1), nota);
        nota = std::clamp(nota, MIN_NOTA, MAX_NOTA);

        std::string nota_key{ std::to_string(nota) };
        if( BaseDatos.count(nota_key) == 0){
            BaseDatos.emplace(
                nota_key, 1
            );
        }else{
            BaseDatos[ nota_key ] += 1;
        }
    }


    // IMPRIMIR ESTADISTICAS
    cant_t mejoresAlumnos = BaseDatos[ "4" ] + BaseDatos[ "5" ];
    /*
    obtener el porcentaje es:
    X = cantidad
    T = total
    P = ?
    P = X/T * 100
    Necesitamos double para que funcione el calculo (se utiliza static cast para evitar un warning)
    */
    double percentage = (static_cast<double>(mejoresAlumnos) / totalEstudiantes) * 100;

    std::cout 
    << "Cantidad de estudiantes con las notas de 4 y 5: " 
    << mejoresAlumnos << "\n"
    << "Cantidad de estudiantes con la nota de 3: "
    << BaseDatos[ "3" ] << "\n"
    << "Desaprobaron: " << BaseDatos[ "2" ] << "\n"
    << "El " << percentage << "\% obtuvieron buenas notas\n";

    return 0;
}




