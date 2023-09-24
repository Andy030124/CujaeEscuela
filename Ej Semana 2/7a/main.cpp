// ANDY GARCIA FONTICOBA
// GRUPO 11, CUJAE

// iostream y using namespace std; para cout y cin
#include <iostream>
using namespace std;

int main(){
    // no estaban declaradas X e Y
    int X=0, Y=0;
    cout << "Entre la abcisa" << endl;
    cin >> X;

    cout << "Entre la ordenada" << endl;
    cin >> Y;
    int c=5; // cuadrante 5 = sobre los ejes

    // Abcisa y ordenada positivas = cuadrante 1
    if( X > 0 && Y > 0 ) c=1;
    else if( X < 0 && Y > 0 ) c=2;
    else if( X < 0 && Y < 0 ) c=3;
    else if( X > 0 && Y < 0 ) c=4;
    // no es necesario, ya que c por defecto vale 5
    // else c=5;
    cout << c; // faltaba el ;
    system("pause");
    return 0;
}
