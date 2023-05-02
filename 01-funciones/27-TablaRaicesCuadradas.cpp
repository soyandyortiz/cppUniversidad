// 8. Imprimir la tabla con las raíces cuadradas de los valores comprendidos entre 6.0 y 7.5 con incrementos de 0.001
// Autor: Andy Ortiz - 7090
#include <iostream>
#include <cmath>
using namespace std;

int main(){
    system("color A0");
    double inicio = 6.0;
    double fin = 7.5;
    double incremento = 0.001;

    // Prototipos
    double calcularRaizCuadrada(double x);
    void imprimirTabla(double inicio, double fin, double incremento);

    // Llamados
    cout << "Valor\tRaiz cuadrada" << endl;
    imprimirTabla(inicio, fin, incremento);

    system("pause");
    return 0;
}

double calcularRaizCuadrada(double x){
    return sqrt(x);
}

void imprimirTabla(double inicio, double fin, double incremento){
    if(inicio <= fin + incremento/2){
        cout << inicio << "\t" << calcularRaizCuadrada(inicio) << endl;
        imprimirTabla(inicio + incremento, fin, incremento);
    }
}