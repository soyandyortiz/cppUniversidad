// El factorial de cada numero ingresado en el array
#include <iostream>
#define EXT 100  
using namespace std;

int main(){
    int a[EXT];
    int n;
    
    //PROTOTIPOS
    int leerN(int limInf, int limSup);
    void leerArray(int *z, int n1);
    void mostrarArray(int z[], int n2);
    int factorial(int n); // Prototipo de la función factorial

    n = leerN(1, EXT);
    leerArray(a, n);
    mostrarArray(a, n);

    // Calcula el factorial de cada elemento de la matriz y lo muestra en pantalla
    cout << endl << "El factorial de cada elemento de la matriz es:" << endl;
    for(int i = 0; i < n; i++){
        cout << "El factorial de " << a[i] << " es: " << factorial(a[i]) << endl;
    }   

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

int factorial(int n) {
    if(n == 0) {
        return 1;
    }
    else {
        return n * factorial(n - 1);
    }
}