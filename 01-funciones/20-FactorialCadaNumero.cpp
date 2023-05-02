//1. Calcular el Factorial de cada número ingresado
//Autor: Andy Ortiz - 7090
#include <iostream>
#define EXT 25
using namespace std;

int main(){
    system("color A0");
    int a[EXT];
    int n;
    
    //Prototipos
    int leerN(int limInf, int limSup);
    void leerArray(int *z, int n1);
    void mostrarArray(int z[], int n2);
    int factorial(int n);

    //Llamados
    n = leerN(1, EXT);
    leerArray(a, n);
    mostrarArray(a, n);

    // Calcula el factorial de cada elemento de la matriz y lo muestra en pantalla
    int i = 0;
    cout << "El factorial de cada elemento de la matriz es:" << endl;
    do {
        cout << "El factorial de " << a[i] << " es: " << factorial(a[i]) << endl;
        i++;
    } while (i < n);

    system("pause");
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
    if (n1 == 0) {
        return;
    }
    leerArray(z + 1, n1 - 1);
    cout << "Digite un numero [" << n1 - 1 << "]: ";
    cin >> *z;
}

void mostrarArray(int x[], int n2){
    if (n2 == 0) {
        return;
    }
    mostrarArray(x, n2 - 1);
    cout << "Posicion " << n2 - 1 << ": -> " << x[n2 - 1] << endl;
}

int factorial(int n) {
    if(n == 0) {
        return 1;
    }
    else {
        return n * factorial(n - 1);
    }
}
