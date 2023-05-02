/*
    Pedir al usuario el valor de N, A, B
    N: cantidad de valores a procesarse
    A: será la base
    B: será el exponente
    
    Elaborar un programa recursivo en C++ que permita calcular en repetidas ocasiones un exponente
    (A ^ B) por medio de sumas exclusivamente, siendo A y B valores enteros ingresados por el usuario.

    Autor: Andy Ortiz - 7090
*/ 

//Autor: Andy Ortiz
#include <iostream>
using namespace std;

int main() {
    system("color A0");
    int n, A, B;
    float exponente;

    // Prototipos
    int leerN(int n);
    float calcularExponente(int A, int B);
    void calcularExponenteRepetidasVeces(int n);
    void datosEstudiante();
    

    // Llamados
    n = leerN(n);
    calcularExponenteRepetidasVeces(n);
    datosEstudiante();

    system("pause");
    return 0;
}

int leerN(int n){
    // Ingresa el valor de N
    do{
        cout << "Ingrese la cantidad de calculos a realizar (N): ";
        cin >> n;
    }while(n <= 0);

    return n;
}

float calcularExponente(int A, int B) {
    // Caso base
    if (B == 0) {
        return 1;
    }
    // Caso exponente negativo
    if (B < 0) {
        return 1 / calcularExponente(A, -B);
    }
    // Llamado recursivo
    return A * calcularExponente(A, B-1);
}

void calcularExponenteRepetidasVeces(int n) {
    int A, B;
    float exponente;
    if (n == 0) {
        return;
    }
    cout << "Ingrese el valor de A: ";
    cin >> A;
    cout << "Ingrese el valor de B: ";
    cin >> B;
    exponente = calcularExponente(A, B);
    // Validamos que A y B sean enteros
    if (cin.fail()) {
        cout << "Error: A y B deben ser enteros." << endl;
        cin.clear();
    } else {
        cout << "La expresion " << A  << "^" << B << " es: " << exponente << endl;
    }
    calcularExponenteRepetidasVeces(n-1);
}


void datosEstudiante(){
    cout << endl << "-----------------------------" << endl;
    cout << "Nombre: Andy Ortiz. V" << endl;
    cout << "Codigo: 7090" << endl;
    cout << "-----------------------------" << endl;
}