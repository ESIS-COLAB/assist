#include "funciones.h"
#include <iostream>

using namespace std;

void saludar() {
    cout << "Hola, mundo!" << endl;
}

int sumar(int a, int b, int c) {
    return a + b + c;
}

int multiplicar(int a, int b, int c) { // Definición de la nueva función
    return a * b * c;
}
