// Programa que determine si una varias palabras de una cadena son PALÍDROMOS de forma recursiva
#include <iostream>
#include <string.h>
#define EXT 25
using namespace std;

int main(){
    char f[EXT];
    char pal[EXT/2][EXT];       //matriz que contiene las palabras
    int np;                     //cantidad de palabras de la cadena

    //Prototipos
    bool esPalindromo(char f[]);
    void pasarAPalabras(char f[], char p[][EXT], int *npal);

    cout << endl << "Ingrese una cadena de caracteres: ";
    cin.getline(f, EXT, '\n');

    pasarAPalabras(f, pal, &np);

    for(int i=0; i<np; i++){    //ciclo de recorrido de las palabras que constan en la matriz
        cout << endl << "La palabra ingresada es: " << pal[i];
        cout << endl << "Esa palabra " << (esPalindromo(pal[i]) ? " SI " : " NO ");
    }
    cout << endl;

    system("pause");

    return 0;
}

bool esPalindromo(char f[]){
    int i, j;

    j = strlen(f) - 1;

    for(i = 0; i < j; i++){
        if(f[i] != f[j]){
            return false;
        }
        j--;
    }
    return true;
}

void pasarAPalabras(char f[], char p[][EXT], int *npal){
    int i, j, k;    //i: recorrer vector, j: filas de matriz, k: columnas de matriz
    j = k = 0;  //inicializar posiciones en matriz

    for(i=0; (i < strlen(f)); i++){ //ciclo de recorrido de la cadena original
        if(((f[i] >= 'A') && (f[i] <= 'Z')) || ((f[i] >= 'a') && (f[i] <= 'z'))){
            p[j][k] = f[i]; //transferir una letra desde la cadena original de la matriz
            k++;            //posicionarse en la siguiente columna de la misma palabra
        }else{              //cuando no se encuentra una letra
            if(((f[i] >= 'A') && (f[i-1] <= 'Z')) || ((f[i-1] >= 'a') && (f[i-1] <= 'z'))){
                p[j][k] = '\0'; //inserta el marcador de fin de cadena
                j++;            //incrementa contador de filas
                k = 0;          //marcador de columna - vuelve a inicio de la palabra
            }
        }
    }
    p[j][k] = '\0';
    j++;
    *npal = j;              //para actualizar cantidad de palabras de la frase
}


