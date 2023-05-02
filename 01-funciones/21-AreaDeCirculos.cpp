// 2. Generar el área de los círculos cuyo radio está comprendido entre los valores A y B
// Autor: Andy Ortiz - 7090
#include <iostream>
#include <cmath>
#define PI 3.1416
using namespace std;

int main(){
    system("color A0");
    double a, b;
    
    // Prototipos
    void mostrarAreas(double a, double b, double r);

    // Llamados
    cout << "Ingrese el valor de A: ";
    cin >> a;
    cout << "Ingrese el valor de B: ";
    cin >> b;
    mostrarAreas(a, b, a);
    
    system("pause");
    return 0;
}

void mostrarAreas(double a, double b, double r){
    double area = PI * pow(r, 2);
    cout << "El area del circulo de radio " << r << " es: " << area << endl;
    if (r < b) {
        mostrarAreas(a, b, r + 1);
    }
    return;
}
