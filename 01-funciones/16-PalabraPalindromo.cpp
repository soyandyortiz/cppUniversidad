// Programa que determine si una cadena de caracteres es PALÍDROMO
#include <iostream>
#include <cstring>
#define LONG 100
using namespace std;

int main() {
    char cadena[LONG];

    //Prototipos
    void LeerCadena(char cadena[]);
    bool esPalindromo(char cadena[]);

    //Llamados
    LeerCadena(cadena);

    // Convertir la cadena a minúsculas
    int longitud = strlen(cadena);
    for(int i=0; i < longitud; i++) {
        cadena[i] = tolower(cadena[i]);
    }

    //Determina si es palindromo
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

bool esPalindromo(char cadena[]) {
    int longitud = strlen(cadena);
    for(int i=0; i < longitud/2; i++) {
        if(cadena[i] != cadena[longitud-i-1])
            return false;
    }
    return true;
}
