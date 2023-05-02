// Crear un programa que nos permita generar las letras Mayúsculas y Minúsculas del alfabeto con recursividad
#include <iostream>
using namespace std;

int main(){
    char letraInicial = 'a';
    char letraFinal = 'z';

    //Prototipo
    void generarLetras(char letra, char final);
    
    // Llamamos a la función para generar las letras minúsculas del alfabeto
    generarLetras(letraInicial, letraFinal);
    
    return 0;
}

void generarLetras(char letra, char final){
    // Caso base: si la letra actual es mayor a la letra final, no hacemos nada
    if(letra > final){
        return;
    }
    // Imprimimos la letra actual en mayúscula y minúscula
    cout << char(toupper(letra)) << char(tolower(letra)) << " ";
    // Llamamos recursivamente a la función, pasando la siguiente letra
    generarLetras(letra + 1, final);
}

