// faltaba iostream
#include <iostream>

// cout, cin y endl requieren std:: o using namespace std
// using namespace std;

int main(){
    // no estaban declaradas X e Y
    int X=0, Y=0;
    std::cout << "Entre la abcisa" << std::endl;
    std::cin >> X;

    std::cout << "Entre la ordenada" << std::endl;
    std::cin >> Y;
    int c=5; // cuadrante 5 = sobre los ejes

    // Abcisa y ordenada positivas = cuadrante 1
    if( X > 0 && Y > 0 ) c=1;
    if( X < 0 && Y > 0 ) c=2;
    if( X < 0 && Y < 0 ) c=3;
    if( X > 0 && Y < 0 ) c=4;
    // no es necesario, ya que c por defecto vale 5
    // else c=5;
    std::cout << c; // faltaba el ;
    std::system("pause");
    return 0;
}
