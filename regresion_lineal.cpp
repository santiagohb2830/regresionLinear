// regresion_lineal.cpp
#include "regresion_lineal.h"
#include <iostream>
#include <cmath>

using namespace std;

Datos* crearDatos(int n) 
{
    Datos* datos = new Datos;
    datos->n = n;
    datos->x.resize(n);
    datos->y.resize(n);
    return datos;
}

void liberarDatos(Datos* datos)
{
    delete datos;
}

void calcularRegresion(Datos* datos, double& m, double& b, double alpha, int epochs) {
    m = 0.0;
    b = 0.0;

    for (int epoch = 0; epoch < epochs; ++epoch) {
        double mse = 0.0;

        // Gradiente descendente
        for (int i = 0; i < datos->n; ++i) {
            double y_pred = m * datos->x[i] + b;
            double error = y_pred - datos->y[i];
            mse += error * error;
            m -= alpha * (2.0 / datos->n) * error * datos->x[i];
            b -= alpha * (2.0 / datos->n) * error;
        }

        mse /= datos->n;

    
        // Imprimir tabla en consola
        cout << "Epoca: " << epoch + 1 << endl;
        cout << "X\tY\tY_pred\tY - Y_pred\tError_Cuad" << endl;
        for (int i = 0; i < datos->n; ++i) {
            double y_pred = m * datos->x[i] + b;
            double error = y_pred - datos->y[i];
            double error_cuad = error * error;
            cout << datos->x[i] << "\t" << datos->y[i] << "\t" << y_pred << "\t" << error << "\t" << error_cuad << endl;
        }
        cout << "MSE: " << mse << endl << endl;
    }
}

