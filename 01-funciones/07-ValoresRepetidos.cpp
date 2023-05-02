/*
    Ingresar varios números enteros, y determinar el (los) valor(es) más repetido(s) que constan entre ellos
    (aplique el algoritmo de búsqueda binaria y ordenamiento por selección, en caso de requerirlo)
*/
#include <iostream>
#include <cmath>
#define EXT 100
using namespace std;

int main(){
    int a[EXT], n, maxCount = 0, count[EXT] = {0};

    //Prototipos
    int leerN(int limInf, int limSup);
    void leerArray(int *z, int n1);
    void mostrarArray(int z[], int n2);
    
    n = leerN(1, EXT);
    leerArray(a, n);
    mostrarArray(a, n);

    // Cuenta cuántas veces aparece cada valor en el arreglo
    for (int i = 0; i < n; i++) {
        count[a[i]]++;
        maxCount = max(maxCount, count[a[i]]);
    }

    // Encuentra los valores más repetidos
    cout << endl << "Los valores mas repetidos son: ";
    for (int i = 0; i < n; i++) {
        if (count[a[i]] == maxCount) {
            cout << a[i] << " ";
        }
    }
    cout << endl;

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
