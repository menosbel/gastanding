#include <iomanip>
#include <iostream>
using namespace std;
#include "tables.h"

void printMovimientosHeader()
{
const char separator = ' ';
const int nameWidth = 30;
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

	cout << left << setw(nameWidth) << setfill(separator) << "Nombre";
	cout << endl;
	cout << left << setw(110) << setfill('_') << "";
	cout << endl << endl;
}

void printCategoriasHeader()
{
	const char separator = ' ';
	const int nameWidth = 20;

	cout << left << setw(nameWidth) << setfill(separator) << "Nombre";
	cout << left << setw(nameWidth) << setfill(separator) << "Tipo";
	cout << endl;
	cout << left << setw(110) << setfill('_') << "";
	cout << endl << endl;
}
