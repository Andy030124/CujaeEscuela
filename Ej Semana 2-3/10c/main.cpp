/*
Dadas las coordenadas de un punto, 
diga el cuadrante en el que se encuentra
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

int resolve_cuadrante(int px, int py){
    int ret = 0; // si devuelvo 0, se asume que estoy sobre los ejes
    if( px > 0 && py > 0 ) ret=1;
    else if( px < 0 && py > 0 ) ret=2;
    else if( px < 0 && py < 0 ) ret=3;
    else if( px > 0 && py < 0 ) ret=4;
    return ret;
}

int main(){
    int px=0, py=0;
    std::cout << "Introduzca las coordenadas en el formato x y:\n";
    std::cin >> px >> py;

    int cuadrante = resolve_cuadrante(px, py);
    if( cuadrante == 0 )
        std::cout << "Está sobre ambos ejes.\n";
    else
        std::cout << "Está en el cuadrante " << cuadrante << "\n";

    pause();
    return 0;
}

