#include <iostream>
#include "ingresoDatos.h"
using namespace std;

float movimientoMontoMax()
{
    float montoMax;
    cout << "Monto m�ximo: ";
    cin >> montoMax;
    return montoMax;
}

float movimientoMontoMin()
{
    float montoMin;
    cout << "Monto m�nimo: ";
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
            cout << "Mes inv�lido. Vuelva a intentar" << endl << endl;
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
        cout << "A�o: ";
        cin >> anio;
        int largo_anio = trunc(log10(anio)) + 1;
        while (largo_anio != 4 || anio < 1900) {
            cout << "A�o inv�lido. Vuelva a intentar" << endl << endl;
            cout << "A�o: ";
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

Fecha ingresoMesAnio() 
{
    Fecha fecha;
    int mes, anio;
    mes = ingresoMes();
    anio = ingresoAnio();

    fecha.setDia(1);
    fecha.setMes(mes);
    fecha.setAnio(anio);
    return fecha;
}