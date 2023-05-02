/*
    Permitir el ingreso de varios números enteros, y proceder a ordenarlos descendentemente en base a la cantidad
    de dígitos pares que poseen (aplique ordenamiento por inserción en caso de requerirlo)
*/
#include <iostream>
#define EXT 100
using namespace std;

// Prototipos
int leerN(int limInf, int limSup);
void leerArray(int *z, int n1);
void mostrarArray(int z[], int n2);
int cantidadDigitos(int n);
void ordenarArrayDesc(int *z, int n1);

int main(){
    int a[EXT], n;

    n = leerN(1, EXT);
    leerArray(a, n);
    mostrarArray(a, n);

    ordenarArrayDesc(a, n);
    cout << endl << "Los datos de la array ordenados descendentemente por cantidad de digitos pares son: " << endl;
    mostrarArray(a, n);

    return 0;
}

int leerN(int limInf, int limSup){
    int x;  // variable de lectura
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

int cantidadDigitos(int n){
    int count = 0;
    while(n > 0){
        if(n % 2 == 0){
            count++;
        }
        n /= 10;
    }
    return count;
}

void ordenarArrayDesc(int *z, int n1){
    int temp;
    for(int i = 1; i < n1; i++){
        temp = z[i];
        int j = i - 1;
        while(j >= 0 && cantidadDigitos(z[j]) < cantidadDigitos(temp)){
            z[j+1] = z[j];
            j--;
        }
        z[j+1] = temp;
    }
}