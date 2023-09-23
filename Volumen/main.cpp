#include <iostream>
#include <cmath>
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

void input(std::string str, float& var){
    std::cout << str;
    std::cin >> var;
}

int main(){
    float 
        rext,
        rint,
        longitud;
    input("Introduzca el radio externo: ",rext);
    input("Introduzca el radio interno: ",rint);
    input("Introduzca la longitud: ",longitud);
    
    float
        pow_rext = std::pow(rext, 2),
        pow_rint = std::pow(rint, 2),
        rest_rad = (pow_rext - pow_rint),
        mul_long = (M_PI * longitud),
        result = mul_long * rest_rad;

    std::cout 
    << "Pow "<< rext << " = "<< pow_rext << "\n"
    << "Pow "<< rint << " = "<< pow_rint << "\n" 
    << pow_rext << "-" << pow_rint << "=" << rest_rad << "\n"
    <<  M_PI << "*" << longitud << "=" << mul_long << "\n"
    << mul_long << "*" << rest_rad << "=" << result << "\n";

    pause();
    return 0;
}


