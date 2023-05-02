// 7. Imprimir solamente el N-ésimo dígito fraccionario de cada numero real (posee parte entera 
// y parte fraccionaria) ingresado.
// Autor: Andy Ortiz - 7090
#include <iostream>
#include <cmath>
using namespace std;

int main(){
    system("color A0");
    double num;
    int n;

    // Prototipos
    int digitoFraccionario(double num, int n);

    // Llamados
    cout << "Ingrese un numero real: ";
    cin >> num;
    cout << "Ingrese el valor de N: ";
    cin >> n;
    cout << digitoFraccionario(num, n) << endl;

    system("pause");
    return 0;
}

int digitoFraccionario(double num, int n){
    int entero = (int) num;
    double fraccion = num - entero;
    if(n == 1){
        fraccion *= 10;
        return (int) fraccion;
    }
    else{
        fraccion *= 10;
        return digitoFraccionario(fraccion, n-1);
    }
}