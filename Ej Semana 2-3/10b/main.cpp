/*
Dadas las longitudes de los 3 lados de un triangulo
Calcular si es triangulo rectangulo
*/

#include <iostream>

void input(const char* str, int& var){
    std::cout << str << "\n";
    std::cin >> var;
}

int main()
{
    int CatetoA, CatetoB, Hipo;
    input("Ingrese el valor de un Cateto: ", CatetoA);
    input("Ingrese el valor del otro Cateto: ", CatetoB);
    input("Ingrese el valor de la Hipotenusa ", Hipo);

    int SumaCatetos = (
        (CatetoA * CatetoA) +
        (CatetoB * CatetoB)
    ),
    HipoMul = Hipo * Hipo;

    std::cout 
    << "Hipotenusa: "<< HipoMul     << '\n'
    << "Catetos: " << SumaCatetos   << '\n';
    
    if( HipoMul == SumaCatetos ){
        std::cout << "Es un triángulo rectangulo\n";
    }else{
        std::cout << "No es un triángulo rectangulo\n";
    }

    return 0;
}

