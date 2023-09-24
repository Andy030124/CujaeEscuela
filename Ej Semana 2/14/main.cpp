// ANDY GARCIA FONTICOBA
// GRUPO 11, CUJAE

/*
Elabore un programa que permita evaluar f(x)
1               si x=0;
x^3 + 4x        si x>0;
x^2 - 1         si x<0;
*/
#include <iostream>
#include <cmath> // std::pow
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

double f(double x);

int main(){
    double x=0;

    std::cout << "Ingrese el valor de x -> ";
    std::cin >> x;

    // f(x) :) 
    std::cout << "f(x) donde x="<< x << " es: " << f(x);
    pause();
    return 0;
}

double f(double x){
if(x>0)         return std::pow(x,3) + (4*x); // x^3 + 4x
else if(x<0)    return std::pow(x,2) - 1;     // x^2 - 1

// else x == 0
return 1;
}