// Progama que implementa gestión básica de un arreglo

#include <iostream> //archivos de cabecera ESTANDAR
#define EXT 100    //definicion de extension del arreglo (cualquier nombre pero siempre en MAYUSCULAS)
using namespace std;

int main(){
    int array[EXT], n;
    
    int leerN(int lim); //prototipo: cuando la funcion esta abajo del main  RECOMENDABLE porque en programacion estructurada es un pecado declarar variables GLOBALES solo LOCALES
    n = leerN(EXT);
    void leerArray(int z[], int n1);    //prototipo
    leerArray(array, n);
    void mostrarArray(int x[], int n2); //prototipo
    mostrarArray(array, n);

    return 0;
}

int leerN(int lim){
    int x;
    do{
        cout << "Cantidades de valores a procesar [rango: 1 hasta "<< lim << "]: ";
        cin >> x;
    }while((x < 1) || (x > lim));
    return x;
}

void leerArray(int *z, int n1){
    for(int i = 0; i < n1; i++){
        cout << "Digite un numero ["<<i<<"]: ";
        cin >> *z++;
    }
}

void mostrarArray(int x[], int n2){
    cout << endl << "Los datos de la array son: " << endl;
    for(int i = 0; i < n2; i++){
        cout << "Posicion " << i << ": -> " << x[i] << endl;
    }
}