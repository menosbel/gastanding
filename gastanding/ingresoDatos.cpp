#include <iostream>
#include "ingresoDatos.h"
using namespace std;

float ingresoMontoMax()
{
    float montoMax;
    cout << "Monto máximo: ";
    cin >> montoMax;
    return montoMax;
}

float ingresoMontoMin()
{
    float montoMin;
    cout << "Monto mínimo: ";
    cin >> montoMin;
    return montoMin;
}

float ingresoMonto()
{
    float monto;
    cout << "Monto: ";
    cin >> monto;
    return monto;
}

int ingresoMes()
{
    int mes;
    bool ok = false;
    while (!ok) {
        cout << "Mes (1 al 12): ";
        cin >> mes;
        while (mes < 1 || mes > 12) {
            cout << "Mes inválido. Vuelva a intentar" << endl << endl;
            cout << "Mes (1 al 12): ";
            cin >> mes;
        }
        ok = true;
    }
    return mes;
}

int ingresoAnio()
{
    int anio;
    bool ok = false;
    while (!ok) {
        cout << "Año: ";
        cin >> anio;
        int largo_anio = trunc(log10(anio)) + 1;
        while (largo_anio != 4 || anio < 1900) {
            cout << "Año inválido. Vuelva a intentar" << endl << endl;
            cout << "Año: ";
            cin >> anio;
        }
        ok = true;
    }
    return anio;
}

string ingresoConcepto()
{
    string concepto;
    cout << "Concepto: ";
    cin >> concepto;
    return concepto;
}