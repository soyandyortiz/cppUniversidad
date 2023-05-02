// 3. Ingresar tres números, y proceder a ordenarlos (ascendente o descendentemente, de acuerdo a lo requerido por el usuario)
// Autor: Andy Ortiz - 7090
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    system("color A0");
    int a, b, c;
    int opcion;

    // Prototipos
    void leerTresNumeros(int& a, int& b, int& c);
    void ordenarAscendente(int& a, int& b, int& c);
    void ordenarDescendente(int& a, int& b, int& c);
    int preguntaUsuario(int opcion);

    // Llamados
    leerTresNumeros(a, b, c);

    // Preguntar al usuario si quiere ordenar en forma ascendente o descendente
    opcion = preguntaUsuario(opcion);

    // Ordenar los números en la forma elegida por el usuario
    if(opcion == 1){
        ordenarAscendente(a, b, c);
    } else if(opcion == 2){
        ordenarDescendente(a, b, c);
    } else {
        cout << "Opcion invalida." << endl;
        return 1;
    }

    // Imprimir los resultados
    if(opcion == 1){
        cout << "Los tres numeros ordenados en forma ascendente son: " << a << ", " << b << ", " << c << endl;
    } else if(opcion == 2){
        cout << "Los tres numeros ordenados en forma descendente son: " << a << ", " << b << ", " << c << endl;
    }

    system("pause");
    return 0;
}

// Función para leer tres números enteros
void leerTresNumeros(int& a, int& b, int& c){
    cout << "Ingrese el primer numero: ";
    cin >> a;
    cout << "Ingrese el segundo numero: ";
    cin >> b;
    cout << "Ingrese el tercer numero: ";
    cin >> c;
}

// Preguntar al usuario si quiere ordenar en forma ascendente o descendente
int preguntaUsuario(int opcion){
    cout << "Como quiere ordenar los numeros?" << endl;
    cout << "1. Ascendente" << endl;
    cout << "2. Descendente" << endl;
    cout << "Elija una opcion: ";
    cin >> opcion;
    return opcion;
}

// Función para ordenar tres números enteros de forma ascendente
void ordenarAscendente(int& a, int& b, int& c){
    int numeros[] = {a, b, c};
    sort(numeros, numeros + 3);
    a = numeros[0];
    b = numeros[1];
    c = numeros[2];
}

// Función para ordenar tres números enteros de forma descendente
void ordenarDescendente(int& a, int& b, int& c){
    int numeros[] = {a, b, c};
    sort(numeros, numeros + 3, greater<int>());
    a = numeros[0];
    b = numeros[1];
    c = numeros[2];
}