/*
    Permitir el ingreso de dos arreglos de valores enteros, y calcular la unión de los mismos
    (aplique método de búsqueda lineal y ordenamiento por selección en caso de requerirlos)
*/
#include <iostream>
#define EXT 100
using namespace std;

int main(){
    int arr1[EXT], arr2[EXT], arrUnion[EXT];
    int n1, n2, nUnion = 0;

    //Prototipos
    int leerN(int limInf, int limSup);
    void leerArreglo(int arr[], int n);
    void unirArreglos(int arr1[], int arr2[], int n1, int n2, int arrUnion[], int &nUnion);
    void mostrarArreglo(int arr[], int n);
    
    // Leer tamaño del primer arreglo
    n1 = leerN(1, EXT);
    // Leer elementos del primer arreglo
    leerArreglo(arr1, n1);

    // Leer tamaño del segundo arreglo
    n2 = leerN(1, EXT);
    // Leer elementos del segundo arreglo
    leerArreglo(arr2, n2);

    // Unir los arreglos
    unirArreglos(arr1, arr2, n1, n2, arrUnion, nUnion);

    // Mostrar el arreglo unido
    mostrarArreglo(arrUnion, nUnion);

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

void leerArreglo(int arr[], int n){
    for(int i=0; i<n; i++){
        cout << "Ingrese el elemento " << i+1 << ": ";
        cin >> arr[i];
    }
}

void unirArreglos(int arr1[], int arr2[], int n1, int n2, int arrUnion[], int &nUnion){
    // Copiar los elementos del primer arreglo al arreglo unido
    for(int i=0; i<n1; i++){
        arrUnion[i] = arr1[i];
    }
    nUnion = n1;

    // Copiar los elementos del segundo arreglo al arreglo unido
    for(int i=0; i<n2; i++){
        bool encontrado = false;
        // Buscar si el elemento del segundo arreglo ya está en el arreglo unido
        for(int j=0; j<nUnion; j++){
            if(arr2[i] == arrUnion[j]){
                encontrado = true;
                break;
            }
        }
        // Si el elemento no está en el arreglo unido, se agrega
        if(!encontrado){
            arrUnion[nUnion] = arr2[i];
            nUnion++;
        }
    }

    // Ordenar el arreglo unido utilizando el método de selección
    for(int i=0; i<nUnion-1; i++){
        int minIndex = i;
        for(int j=i+1; j<nUnion; j++){
            if(arrUnion[j] < arrUnion[minIndex]){
                minIndex = j;
            }
        }
        int temp = arrUnion[i];
        arrUnion[i] = arrUnion[minIndex];
        arrUnion[minIndex] = temp;
    }
}

void mostrarArreglo(int arr[], int n){
    cout << "Arreglo unido: ";
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}