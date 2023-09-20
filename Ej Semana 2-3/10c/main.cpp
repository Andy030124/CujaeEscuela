/*
Dadas las coordenadas de un punto, 
diga el cuadrante en el que se encuentra
*/

#include <iostream>

int resolve_cuadrante(int px, int py){
    int ret = 0;
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

    return 0;
}

