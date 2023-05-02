// 10. Determinar las letras más repetidas encontradas en una cadena ingresada (evitar repeticiones)
// Autor: Andy Ortiz - 7090
#include <iostream>
#include <cstring>
using namespace std;

int main() {
    system("color A0");
    string cadena;

    // Prototipos
    int contarCaracter(char c, string s);
    bool estaEnArreglo(char c, char arr[], int tam);
    void encontrarMasRepetidos(string s, char masRepetidos[], int& tam);
    void imprimirMasRepetidos(char masRepetidos[], int tam, int i = 0);

    // Llamados
    cout << "Ingrese una cadena: ";
    getline(cin, cadena);

    char masRepetidos[50];
    int tam = 0;
    encontrarMasRepetidos(cadena, masRepetidos, tam);

    cout << "Letras mas repetidas: ";
    imprimirMasRepetidos(masRepetidos, tam);

    system("pause");
    return 0;
}

int contarCaracter(char c, string s) {
    if (s == "") {
        return 0;
    } else {
        int cont = contarCaracter(c, s.substr(1));
        if (s[0] == c) {
            return cont + 1;
        } else {
            return cont;
        }
    }
}

bool estaEnArreglo(char c, char arr[], int tam) {
    if (tam == 0) {
        return false;
    } else {
        return arr[tam - 1] == c || estaEnArreglo(c, arr, tam - 1);
    }
}

void encontrarMasRepetidos(string s, char masRepetidos[], int& tam) {
    if (s == "") {
        return;
    } else {
        char c = s[0];
        int cont = contarCaracter(c, s);
        if (cont > 1 && !estaEnArreglo(c, masRepetidos, tam)) {
            masRepetidos[tam] = c;
            tam++;
        }
        encontrarMasRepetidos(s.substr(1), masRepetidos, tam);
    }
}

void imprimirMasRepetidos(char masRepetidos[], int tam, int i = 0) {
    if (i < tam) {
        cout << masRepetidos[i] << " ";
        imprimirMasRepetidos(masRepetidos, tam, i + 1);
    } else {
        cout << endl;
    }
}
