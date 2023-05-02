/*
    Generar un listado ordenado descendentemente con los valores que contienen una cantidad impar de dígitos,
    tomados de entre varios números enteros ingresados por el usuario (aplíquese el algoritmo de ordenamiento
    por inserción)
*/
#include <iostream>
#define EXT 100
using namespace std;

int main(){
    int a[EXT], n;

    //Prototipos
    int leerN(int limInf, int limSup);
    void leerArray(int *z, int n1);
    void mostrarArray(int z[], int n2);
    void obtenerImpares(int x[], int n2);

    n = leerN(1, EXT);
    leerArray(a, n);
    mostrarArray(a, n);
    obtenerImpares(a, n);

    return 0;
}

int leerN(int limInf, int limSup){
    int x;
    do{
        cout << "Cuantos numeros quiere ingresar, rango de ["<< limInf << " hasta " << limSup << "]: ";
        cin >> x;
    }while((x < limInf) || (x > limSup));
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

void obtenerImpares(int x[], int n2){   //SE AÑADE EL ORDENAMIENTO POR INSERCIÓN
    cout << endl << "Los numeros impares en el arreglo son (ordenados de forma descendente): " << endl;
    for(int i = 1; i < n2; i++){
        int j = i - 1;
        int temp = x[i];
        while(j >= 0 && x[j] < temp){
            x[j+1] = x[j];
            j--;
        }
        x[j+1] = temp;
    }
    for(int i = 0; i < n2; i++){
        if(x[i] % 2 != 0){
            cout << x[i] << endl;
        }
    }
}