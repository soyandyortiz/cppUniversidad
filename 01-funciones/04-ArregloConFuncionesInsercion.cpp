// Progama que implementa gestión básica de un arreglo
#include <iostream> //archivos de cabecera ESTANDAR
#define EXT 100    //definicion de extension del arreglo (cualquier nombre pero siempre en MAYUSCULAS)
using namespace std;

int main(){
    int a[EXT];
    int n;
    
    //PROTOTIPOS
    int leerN(int limInf, int limSup);
    void leerArray(int *z, int n1);
    void mostrarArray(int z[], int n2);
    void insertarElemento(int z[], int *n1);
    void eliminarElemento(int z[], int *n1);    //Nueva Función
    void eliminarElementoPorValor(int z[], int *n1);
    //void eliminarElemento2(int z[], int *n1);

    cout <<endl << "CANTIDAD DE VALORES A PROCESAR" << endl;
    n = leerN(1, EXT);
    leerArray(a, n);
    mostrarArray(a, n);

    insertarElemento(a, &n);
    mostrarArray(a, n);

    eliminarElemento(a, &n); // Llamada a la nueva función
    mostrarArray(a, n);

    eliminarElementoPorValor(a, &n);
    mostrarArray(a, n);

    return 0;
}

int leerN(int limInf, int limSup){
    int x;  // variable de lectura
    do{
        cout << "Ingrese un valor entero comprendido en el rango de "<< limInf << " hasta " << limSup << " para la posicion: ";
        cin >> x;
    }while((x < limInf) || (x > limSup));
    return x;
}

void leerArray(int *z, int n1){
    for(int i = 0; i < n1; i++){
        cout << "Digite un numero ["<<i<<"]: ";
        cin >> *z++;
        //z++; //esta es otra forma de la linea 40
    }
}

void mostrarArray(int x[], int n2){
    cout << endl << "Los datos de la array son: " << endl;
    for(int i = 0; i < n2; i++){
        cout << "Posicion " << i << ": -> " << x[i] << endl;
    }
}

void insertarElemento(int z[], int *n1){
    int val, pos;

    cout << endl << "INSERCION DE UN NUEVO ELEMENTO EN EL ARREGLO";
    cout << endl << "Ingrese el valor a insertar: ";
    cin >> val;

    //cout << endl << "Ingrese la posicion en que desea insertar el valor ";
    pos = leerN(0, (*n1)-1);

    for(int i = *n1; i >= pos; i--){
        z[i] = z[i-1];
    }
    z[pos] = val;
    *n1 = *n1 + 1;
}

void eliminarElemento(int z[], int *n1) {
    int pos;
    cout << endl << "ELIMINACION DE UN ELEMENTO EN EL ARREGLO";
    cout << endl << "Ingrese la posicion del elemento a eliminar: ";
    pos = leerN(0, (*n1)-1);

    for(int i = pos; i < (*n1) - 1; i++) {
        z[i] = z[i+1];
    }
    *n1 = *n1 - 1;
}

void eliminarElementoPorValor(int z[], int *n1) {
    int val, pos;
    bool encontrado = false;

    cout << endl << "ELIMINACION DE UN ELEMENTO EN EL ARREGLO POR VALOR";
    cout << endl << "Ingrese el valor del elemento a eliminar: ";
    cin >> val;

    for(int i = 0; i < *n1; i++) {
        if(z[i] == val) {
            pos = i;
            encontrado = true;
            break;
        }
    }

    if(encontrado) {
        for(int i = pos; i < (*n1) - 1; i++) {
            z[i] = z[i+1];
        }
        *n1 = *n1 - 1;
    }
    else {
        cout << endl << "El valor buscado no se encuentra en el arreglo." << endl;
    }
}