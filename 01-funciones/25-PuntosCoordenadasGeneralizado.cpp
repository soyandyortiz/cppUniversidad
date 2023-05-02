// 6. Generalice la solución al problema anterior
// Autor: Andy Ortiz - 7090
#include <iostream>
#include <cmath>
using namespace std;

int main(){
    system("color A0");
    int r;

    // Prototipos
    bool esEntero(double num);
    void buscarPuntos(int r, int x, int y);

    // Llamados
    cout << "Ingrese el radio de la circunferencia: ";
    cin >> r;
    buscarPuntos(r, -r, -r);

    system("pause");
    return 0;
}

bool esEntero(double num){
    return floor(num) == num;
}

void buscarPuntos(int r, int x, int y){
    if(x > r || y > r){
        return;
    }
    if(x < -r || y < -r){
        buscarPuntos(r, x+1, -r);
        return;
    }
    if(esEntero(sqrt(r*r - x*x)) && esEntero(sqrt(r*r - y*y))){
        cout << "(" << x << ", " << sqrt(r*r - x*x) << ")" << endl;
        cout << "(" << y << ", " << sqrt(r*r - y*y) << ")" << endl;
    }
    buscarPuntos(r, x, y+1);
}