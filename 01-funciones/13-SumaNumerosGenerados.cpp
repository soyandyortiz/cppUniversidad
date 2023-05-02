//Programa que permite generar 10 numeros y sumarlos entre sí
#include <iostream>
using namespace std;
#define NR 10

int main(){ //Funcion principal
    system("color FC");
    
    //Prototipos
    void generarNumeros(int n, int &suma);

    //Variables
    int suma = 0;

    //Llamados de funciones
    generarNumeros(1, suma);

    //Imprimir la suma total de los valores generados
    cout << endl << "La suma de los valores generados es: " << suma;

    //Pausar ventana de ejecución
    cout << endl;
    system("pause");
    return 0;
}

//Funcion para generar n valores aleatorios - implementa: RECURSIVIDAD
void generarNumeros(int n, int &suma){
    if(n <= NR){
        cout << endl << "Valor generado: " << n;
        suma += n;
        generarNumeros(n+1, suma);
        
    }
}