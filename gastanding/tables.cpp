#include <iomanip>
#include <iostream>
using namespace std;
#include "tables.h"

void printMovimientosHeader()
{
const char separator = ' ';
const int nameWidth = 27;
const int numWidth = 15;

cout << left << setw(numWidth) << setfill(separator) << "Fecha";
cout << left << setw(numWidth) << setfill(separator) << "Monto";
cout << left << setw(nameWidth) << setfill(separator) << "Concepto";
cout << left << setw(nameWidth) << setfill(separator) << "Categoria";
cout << endl;
cout << left << setw(110) << setfill('_') << "";
cout << endl << endl;
}

void printBilleterasHeader()
{
	const char separator = ' ';
	const int nameWidth = 25;
	const int numWidth = 10;

	cout << left << setw(numWidth) << setfill(separator) << "ID";
	cout << left << setw(nameWidth) << setfill(separator) << "Nombre";
	cout << left << setw(nameWidth) << setfill(separator) << "Saldo actual";
	cout << endl;
	cout << left << setw(50) << setfill('_') << "";
	cout << endl << endl;
}

void printCategoriasHeader()
{
	const char separator = ' ';
	const int nameWidth = 40;
	const int numWidth = 10;

	cout << left << setw(numWidth) << setfill(separator) << "ID";
	cout << left << setw(nameWidth) << setfill(separator) << "Nombre";
	cout << left << setw(numWidth) << setfill(separator) << "Tipo";
	cout << endl;
	cout << left << setw(70) << setfill('_') << "";
	cout << endl << endl;
}

void printInformeEvolucionMovimientosHeader()
{
	const char separator = ' ';
	const int width = 10;

	cout << left << setw(width) << setfill(separator) << "Fecha";
	cout << left << setw(width) << setfill(separator) << "Monto";
	cout << endl;
	cout << left << setw(50) << setfill('_') << "";
	cout << endl << endl;
}
