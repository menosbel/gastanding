#include "Ingreso.h"
#include <iostream>

using namespace std;

void Ingreso::cargar()
{
	cout << "Monto: $";
	cin >> _monto;
	cout << "Concepto: ";
	cin >> _concepto;
	cout << "Fecha: ";
	_fecha.cargar();

}

void mostrarCategoriasIngreso() {
	int opcion;
	cout << "Elegi una categoria" << endl;
	cout << "1. Relacion de dependencia" << endl;
	cout << "2. Freelance" << endl;
	cout << "3. Otros" << endl;
	cout << "Opcion: ";
	cin >> opcion;
}

void Ingreso::mostrar() {
	cout << "Monto: $" << _monto << endl;
	cout << "Concepto: " << _concepto << endl;
	cout << "Fecha: ";
	_fecha.mostrar();
}