// 4. Generar los N valores múltiplos de X. Calcular el promedio de aquellos valores generados que estén 
// dentro del rango comprendido entre A y B; si no están en ese rango, los valores solo deberán imprimirse.
// Autor: Andy Ortiz - 7090
#include <iostream>
using namespace std;

int main(){
    system("color A0");
    int x;
    int n;
    int a;
    int b;

    // Prototipos
    void leerX(int& x);
    void leerN(int& n);
    void leerRango(int& a, int& b);
    int generarMultiplosRecursivo(int x, int n, int contadorMultiplos = 1);
    void calcularPromedioRecursivo(int x, int a, int b, int suma, int contadorValores, int sumaValoresRango = 0, int cantidadValoresRango = 0);

    // Llamadas a funciones para leer los valores
    leerX(x);
    leerN(n);
    leerRango(a, b);

    // Llamada a función recursiva para generar los múltiplos y calcular el promedio
    int suma = generarMultiplosRecursivo(x, n);
    calcularPromedioRecursivo(x, a, b, suma, n);

    system("pause");
    return 0;
}

// Función para leer el valor de X
void leerX(int& x){
    cout << "Ingrese el valor de X: ";
    cin >> x;
}

// Función para leer la cantidad de valores a generar (N)
void leerN(int& n){
    cout << "Ingrese la cantidad de valores a generar (N): ";
    cin >> n;
}

// Función para leer el rango (A y B)
void leerRango(int& a, int& b){
    cout << "Ingrese el valor de A: ";
    cin >> a;
    cout << "Ingrese el valor de B: ";
    cin >> b;
}

// Función recursiva para generar los múltiplos de X
int generarMultiplos(int x, int n, int contadorMultiplos){
    if(contadorMultiplos <= n){
        int valorActual = x * contadorMultiplos;
        cout << valorActual << endl;
        return valorActual + generarMultiplos(x, n, contadorMultiplos + 1);
    } else {
        return 0;
    }
}

int generarMultiplosRecursivo(int x, int n, int contadorMultiplos){
    if(contadorMultiplos <= n){
        int valorActual = x * contadorMultiplos;
        cout << valorActual << endl;
        return valorActual + generarMultiplosRecursivo(x, n, contadorMultiplos + 1);
    } else {
        return 0;
    }
}

void calcularPromedioRecursivo(int x, int a, int b, int suma, int contadorValores, int sumaValoresRango, int cantidadValoresRango){
    if(contadorValores == 0){
        if(cantidadValoresRango > 0){
            double promedioValoresRango = static_cast<double>(sumaValoresRango) / cantidadValoresRango;
            cout << "El promedio de los valores en el rango [" << a << ", " << b << "] es: " << promedioValoresRango << endl;
        } else {
            cout << "No hay valores en el rango [" << a << ", " << b << "]" << endl;
        }
    } else {
        int valorActual = x * contadorValores;
        if(valorActual >= a && valorActual <= b){
            sumaValoresRango += valorActual;
            cantidadValoresRango++;
        }
        calcularPromedioRecursivo(x, a, b, suma, contadorValores - 1, sumaValoresRango, cantidadValoresRango);
    }
}
