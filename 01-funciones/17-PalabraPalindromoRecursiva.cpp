// Programa que determine si una cadena de caracteres es PALÍDROMO de forma recursiva
#include <iostream>
#include <limits>
#include <cstring>
#define LONG 100
using namespace std;

int main() {
    char cadena[LONG];

    //Prototipos
    void LeerCadena(char cadena[]);
    bool esPalindromoRecursivo(char cadena[], int inicio, int fin);
    bool esPalindromo(char cadena[]);

    LeerCadena(cadena);

    // Convertir la cadena a minúsculas
    int longitud = strlen(cadena);
    for(int i=0; i < longitud; i++) {
        cadena[i] = tolower(cadena[i]);
    }

    if(esPalindromo(cadena)) {
        cout << "La cadena es un palindromo." << endl;
    } else {
        cout << "La cadena no es un palindromo." << endl;
    }

    return 0;
}

void LeerCadena(char cadena[]) {
    cout << "Ingrese la cadena: ";
    cin.getline(cadena, LONG, '\n');
    cout << "La cadena es: " << cadena << endl;
}

bool esPalindromoRecursivo(char cadena[], int inicio, int fin) {
    if(inicio >= fin) {
        return true;
    }
    if(cadena[inicio] != cadena[fin]) {
        return false;
    }
    return esPalindromoRecursivo(cadena, inicio + 1, fin - 1);
}

bool esPalindromo(char cadena[]) {
    int longitud = strlen(cadena);
    return esPalindromoRecursivo(cadena, 0, longitud - 1);
}