/*
    Progama que implementa gestión básica de un arreglo
    Autor: Andy Ortiz - 7090

    Nota:
        El nombre de un arreglo es ya un apuntador

    Deber:
        Aritmetica de punteros (revisar)
*/
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
    void eliminarElemento(int z[], int *n1);
    void eliminarElementoPorValor(int z[], int *n1);
    int buscarBinaria(int v, int z[], int n1);
    //void eliminarElemento2(int z[], int *n1);

    cout <<endl << "CANTIDAD DE VALORES A PROCESAR" << endl;
    n = leerN(1, EXT);
    leerArray(a, n);
    mostrarArray(a, n);
/*
    insertarElemento(a, &n);
    mostrarArray(a, n);

    eliminarElemento(a, &n); // Llamada a la nueva función
    mostrarArray(a, n);

    eliminarElementoPorValor(a, &n);
    mostrarArray(a, n);
*/
    int encontrado = buscarBinaria(10, a, n);

    //operador ternario
    cout << endl << "El valor 10 " << ((encontrado >= 0) ? "SI" : "NO") << " se encuentra en el arreglo...";    //es lo mismo en lo que esta abajo
    /*if(encontrado >= 0){
        cout << endl << "Felicitaciones: el valor 10 se encuentra en la posicion: " << encontrado << endl;
    } else {
        cout << endl << "Lo siento... El valor 10 no se encuentra en el arreglo" << endl;
    }*/

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

/*
int buscar(){
    for(int i = 0; i < n1; i++){
        if(v == z[i]){
            return i;
        }
    }
    return -1;
}
*/

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

int buscarBinaria(int v, int z[], int n1){
    int ini, fin, med;
    ini = 0;         //posicion inicial del arreglo
    fin = n1 - 1;   //posicion final del arreglo

    while(ini <= fin) { //mientras posicion de ref inicial esta a la izq de pos de referencia final
        med = (ini + fin) / 2;
        if(z[med] == v){
            return med; //posicion en la que se encuentra u
        } else{ //no encontrado v en pos med
            if(z[med] > v){ //cuando elemento pos central es mayor que v
                fin = med - 1;  //nuevo valor final de ref es el anterior a med
            } else {    //cuando elemento pos central es menor que v
                ini = med + 1; //nuevo valor inicial de referencia es el posterior a med
            }
        }
    }
    return -1; //devolver valor de no encontrado

    for(int i = 0; i < n1; i++) {
        if(v == z[i]){
            return i;
        }
    }
    return -1;
}