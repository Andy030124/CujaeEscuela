#include <iostream>
#include <cmath>

#ifdef __linux__
    namespace unistd{
        #include <unistd.h>
    }
    #define PAUSE unistd::pause()
#elif defined(__MINGW32__) || defined(_WIN32)
    #include <cstdlib> // para system (solo en windows)
    #define PAUSE std::system("pause > null")
#endif

void pause(){
    std::cout << "\nPulse una tecla para salir...";
    PAUSE;
}

template<typename T>
void input(std::string str, T& var){
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

    return 0;
}


