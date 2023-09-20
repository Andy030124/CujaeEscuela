/*
Elabore un programa que permita evaluar f(x)
1               si x=0;
x^3 + 4x        si x>0;
x^2 - 1         si x<0;
*/
#include <iostream>
#include <cmath>

int f(int x);

int main(){
    int x=0;

    std::cout << "Ingrese el valor de x -> ";
    std::cin >> x;

    // f(x) :) 
    std::cout << "f(x) donde x="<< x << " es: " << f(x);
    return 0;
}

int f(int x){
if(x>0)         return std::pow(x,3) + (4*x); // x^3 + 4x
else if(x<0)    return std::pow(x,2) - 1;     // x^2 - 1

// else x == 0
return 1;
}