/*
Dadas las longitudes de los 3 lados de un triangulo
Calcular si es triangulo rectangulo
*/

#include <iostream>
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

void input(const char* str, int& var){
    std::cout << str << " ";
    std::cin >> var;
    std::cout << "\n";
}

int main()
{
    int CatetoA, CatetoB, Hipo;
    // asumo que mi usuario sabe que es un cateto y una hipotenusa
    input("Ingrese el valor de un Cateto: ", CatetoA);
    input("Ingrese el valor del otro Cateto: ", CatetoB);
    input("Ingrese el valor de la Hipotenusa ", Hipo);

    // por si acaso puedo comprobarlo
    if( CatetoA > Hipo || CatetoB > Hipo ){
        std::cout << "Introdujo mal los datos... (Reorganizando)\n";
        // Utilizamos una ternaria
        // ya se que uno de los dos catetos es mayor que la hipotenusa
        std::swap(Hipo, 
            // verifico que sea el Cateto A
            ((CatetoA > Hipo)&&(CatetoA > CatetoB)) 
            ? CatetoA : CatetoB // si es A, entonces lo devuelvo, sino es B
        ); // intercambio 2 valores
        std::cout 
        << "Valores reorganizados:\n" 
        << "Hipotenusa: "   << Hipo << '\n'
        << "CatetoA: "      << CatetoA << '\n'
        << "CatetoB: "      << CatetoB << '\n';
    }

    // CatetoA^2 + CatetoB^2
    int SumaCatetos = (
        (CatetoA * CatetoA) +
        (CatetoB * CatetoB)
    ),
    // Hipo^2
    HipoMul = Hipo * Hipo;

    // muestro resultados parciales (para mayor transparencia con el usuario)
    std::cout 
    << "Hipotenusa: "<< HipoMul     << '\n'
    << "Catetos: " << SumaCatetos   << '\n';
    
    if( HipoMul == SumaCatetos ){
        std::cout << "Es un triángulo rectangulo\n";
    }else{
        std::cout << "No es un triángulo rectangulo\n";
    }
    pause();
    return 0;
}

