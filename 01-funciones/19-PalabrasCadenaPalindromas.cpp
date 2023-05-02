#include <iostream>
#include <limits>
#include <cstring>
#define LONG 100
using namespace std;

//Prototipos
void LeerCadena(char cadena[]);
bool esPalindromoRecursivo(char cadena[], int inicio, int fin);
bool esPalindromoPalabra(char palabra[]);
bool existePalindromo(char cadena[]);

int main() {
    char cadena[LONG];

    LeerCadena(cadena);

    // Convertir la cadena a minúsculas
    int longitud = strlen(cadena);
    for(int i=0; i < longitud; i++) {
        cadena[i] = tolower(cadena[i]);
    }

    // Dividir la cadena en palabras
    char* palabra = strtok(cadena, " ,.-");

    // Verificar si al menos una palabra es un palíndromo
    if(existePalindromo(cadena)) {
        cout << "La cadena contiene al menos una palabra que es un palindromo." << endl;
    } else {
        cout << "La cadena no contiene ninguna palabra que sea un palindromo." << endl;
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

bool esPalindromoPalabra(char palabra[]) {
    int longitud = strlen(palabra);
    return esPalindromoRecursivo(palabra, 0, longitud - 1);
}

bool existePalindromo(char cadena[]) {
    // Dividir la cadena en palabras
    char* palabra = strtok(cadena, " ,.-");

    // Verificar si al menos una palabra es un palíndromo
    while(palabra != NULL) {
        if(esPalindromoPalabra(palabra)) {
            return true;
        }
        palabra = strtok(NULL, " ,.-");
    }

    return false;
}
