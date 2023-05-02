// 9. Generalizar la solución anterior
// Autor: Andy Ortiz - 7090
#include <iostream>
#include <cmath>
using namespace std;

int main(){
    system("color A0");
    double inicio, fin, incremento;

    // Prototipos
    double calcularRaizCuadrada(double x);
    void imprimirTabla(double inicio, double fin, double incremento);

    // Llamados
    cout << "Ingrese el valor de inicio: ";
    cin >> inicio;
    cout << "Ingrese el valor de fin: ";
    cin >> fin;
    cout << "Ingrese el valor de incremento: ";
    cin >> incremento;

    cout << "Valor\tRaiz cuadrada" << endl;
    imprimirTabla(inicio, fin, incremento);

    system("pause");
    return 0;
}

double calcularRaizCuadrada(double x){
    return sqrt(x);
}

void imprimirTabla(double inicio, double fin, double incremento){
    if(inicio <= fin + incremento/10000){
        cout << inicio << "\t" << calcularRaizCuadrada(inicio) << endl;
        imprimirTabla(inicio + incremento, fin, incremento);
    }
}