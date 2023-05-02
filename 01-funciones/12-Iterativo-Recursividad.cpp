//Programa que permite generar 10 numeros de forma iterativa y recursiva

#include <iostream>
using namespace std;
#define NR 10 //Constante para definir cantidad de valores a generar

int main(){ //Funcion principal
    //system("color FC");
    
    //Prototipos
    void generarNumeros(int n);

    //Llamados de funciones
    generarNumeros(1);

    //Pausar ventana de ejecución
    cout << endl;
    system("pause");
    return 0;
}

/*void generarNumeros(int n){ //Funcion para generar n valores aleatorios - implementa: ITERACIÓN
    for(int i = 1; i <= n; i++){
        cout << endl << "Valor generado: " << i << endl;
    }
}*/

void generarNumeros(int n){ //Funcion para generar n valores aleatorios - implementa: RECURSIVIDAD
    if(n <= NR){
        cout << endl << "Valor generado: " << n;
        generarNumeros(n+1);
        
    } //Cuando n = 10 YA NO SE HACE NADA
}