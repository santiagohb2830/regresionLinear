// main.cpp
#include <iostream>
#include "regresion_lineal.h"

using namespace std;

int main() {
    int n = 5;
    Datos* datos = crearDatos(n);

    // Datos de ejemplo
    datos->x = {1, 2, 3, 4, 5};
    datos->y = {3.01, 5.11, 7.01, 8.95, 10.89};

    double m, b;
    double alpha = 0.001;
    int epochs = 500;

    calcularRegresion(datos, m, b, alpha, epochs);

    cout << "Pendiente (m): " << m << endl;
    cout << "Intersección (b): " << b << endl;

    liberarDatos(datos);
    return 0;
}
