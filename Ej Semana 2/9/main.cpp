// ANDY GARCIA FONTICOBA
// GRUPO 11, CUJAE

/*
Interpretar el codigo:
Es un programa simple que obtiene una de 3 opciones
en caso de que la opcion introducida este correcta, hace un calculo
en dependencia de la opcion:
.1 salida 2
.2 salida 1
3. salida 0
y en caso de que no sea la entrada correcta, imprime un mensaje.
*/
#include <iostream>

int main(){
    int Opcion;
    int Res=1;

    std::cout << "Entre la opcion deseada (un valor entre 1 y 3):";
    std::cin >> Opcion;

    switch (Opcion){
    case 1: Res = Res+1; break;
    case 2: Res = Res * Res; break;
    case 3: Res = Res * Res * Res - 1; break; 
    default: std::cout << "No es un valor posible: " << Res << std::endl; 
    }

    if( Opcion==1 || Opcion==2 || Opcion==3 )
        std::cout << "El resultado es: " << Res << std::endl;
    std::system("pause");
    return 0;
}


