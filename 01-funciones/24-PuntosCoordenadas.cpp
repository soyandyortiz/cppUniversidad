// 5. Determinar los puntos de coordenadas enteras que están sobre la circunferencia X^2 + Y^2 = 25
// Autor: Andy Ortiz - 7090
#include <iostream>
#include <cmath>
using namespace std;

int main(){
    system("color A0");
    
    // Prototipos
    bool esEntero(double num);
    void buscarPuntos(int x, int y);

    // Llamados
    buscarPuntos(-5, -5);

    system("pause");
    return 0;
}

bool esEntero(double num){
    return floor(num) == num;
}

void buscarPuntos(int x, int y){
    if(x > 5 || y > 5){
        return;
    }
    if(x < -5 || y < -5){
        buscarPuntos(x+1, -5);
        return;
    }
    if(esEntero(sqrt(25 - x*x)) && esEntero(sqrt(25 - y*y))){
        cout << "(" << x << ", " << sqrt(25 - x*x) << ")" << endl;
        cout << "(" << y << ", " << sqrt(25 - y*y) << ")" << endl;
    }
    buscarPuntos(x, y+1);
}