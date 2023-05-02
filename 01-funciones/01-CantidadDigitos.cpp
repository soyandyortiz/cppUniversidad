/* Hacer un programa que permita el ingreso de varios numeros y determinar la cantidad
de dígitos que cada uno de ellos posee */
#include <iostream>
#include <string>
using namespace std;

// Prototipo de función
int leerN();

int main(){
    // Prototipos
    void leerProcesar(int n, int& contador);

    cout << "--------------------------------" << endl;
    cout << "CANTIDAD DE DIGITOS DE NUMEROS" << endl;
    cout << "--------------------------------" << endl;
    int n = leerN();
    int contador = 0;
    leerProcesar(n, contador);

    return 0;
}

int leerN() {
    int n;
    do{
        cout << "Ingrese la cantidad de elementos a procesar: ";
        cin >> n;
    }while(n <= 0);
    return n;
}

void leerProcesar(int n, int& contador) {
    for (int i = 0; i < n; i++) {
        int num;
        cout << "Ingrese un numero: ";
        cin >> num;
        contador++;

        // Convertir el número a una cadena de caracteres
        string num_str = to_string(num);

        // Recorrer la cadena y contar la cantidad de dígitos
        int digitos = 0;
        for(char c : num_str){
            if (isdigit(c)) {
                digitos++;
            }
        }
        cout << "El numero ingresado es: " << num_str << " y tiene: " << digitos << " digitos" << endl;
    }
}
