/*  
    Programa modular que permite al usuario ingresar una cantidad de
    valores específicos para crear un arreglo, ingresar los valores en
    el arreglo y mostrarlos en pantalla.
*/

#include <iostream> //Archivos de cabecera estándar
#define EXT 100    //Definicion de extensión del arreglo
using namespace std;

int main(){ //Función principal
    //Definir variables
    int arreglo[EXT], n;

    //Prototipos
    int leerN(int lim);
    void leerArray(int a[], int n);
    void mostrarArray(int a[], int n);

    //Llamados de función
    n = leerN(EXT); //Lee la dimensión del arreglo
    leerArray(arreglo, n); //Lee los datos del arreglo
    mostrarArray(arreglo, n); //Mostrar los datos del arreglo

    return 0;
}

//Definiciones de las funciones
int leerN(int lim) {
    int x;
    do{
        cout << "Cantidades de valores a procesar [rango: 1 hasta "<< lim << "]: ";
        cin >> x;
    }while((x < 1) || (x > lim));
    return x;
}

void leerArray(int a[], int n) {
    for(int i = 0; i < n; i++){
        cout << "Digite un numero [" << i+1 << "]: ";
        cin >> a[i];
    }
}

void mostrarArray(int a[], int n) {
    cout << endl << "Los datos de la array son: " << endl;
    for(int i = 0; i < n; i++){
        cout << "Posicion " << i << ": -> " << a[i] << endl;
    }
}