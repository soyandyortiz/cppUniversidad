/*
    Generar los factores primos de cada uno de varios números ingresados por el usuario
    (aplique el algoritmo de búsqueda binaria y ordenamiento por el método de la burbuja, en caso de requerirlo)
*/
#include <iostream>
#define EXT 100
using namespace std;

int main(){
    int a[EXT], n;

    // Prototipos
    int leerN(int limInf, int limSup);
    void leerArray(int z[], int n1);
    void mostrarArray(int z[], int n2);
    int busquedaBinaria(int a[], int n, int valor);
    void ordenamientoBurbuja(int a[], int n);
    void factoresPrimos(int a[], int n);

    n = leerN(1, EXT);
    leerArray(a, n);
    mostrarArray(a, n);
    cout << "-----------------" << endl;
    factoresPrimos(a, n);

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

void leerArray(int z[], int n1){
    for(int i = 0; i < n1; i++){
        cout << "Digite un numero ["<<i<<"]: ";
        cin >> z[i];
    }
}

void mostrarArray(int x[], int n2){
    cout << endl << "Los datos de la array son: " << endl;
    for(int i = 0; i < n2; i++){
        cout << "Posicion " << i << ": -> " << x[i] << endl;
    }
}

int busquedaBinaria(int a[], int n, int valor){
    int izq = 0, der = n-1, medio;
    while(izq <= der){
        medio = (izq+der)/2;
        if(a[medio] == valor){
            return medio;
        }else if(a[medio] < valor){
            izq = medio+1;
        }else{
            der = medio-1;
        }
    }
    return -1;
}

void ordenamientoBurbuja(int a[], int n){
    int aux;
    for(int i = 0; i < n-1; i++){
        for(int j = i+1; j < n; j++){
            if(a[j] < a[i]){
                aux = a[i];
                a[i] = a[j];
                a[j] = aux;
            }
        }
    }
}

void factoresPrimos(int a[], int n){
    int factores[EXT];
    for(int i = 0; i < n; i++){
        int num = a[i], indice = 0;
        while(num % 2 == 0){
            factores[indice] = 2;
            indice++;
            num /= 2;
        }
        for(int j = 3; j <= num; j+=2){
            while(num % j == 0){
                factores[indice] = j;
                indice++;
                num /= j;
            }
        }
        cout << "Factores primos de " << a[i] << ": ";
        for(int k = 0; k < indice; k++){
            cout << factores[k] << " ";
        }
        cout << endl;
    }
}
