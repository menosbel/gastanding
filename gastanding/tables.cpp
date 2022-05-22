#include <iomanip>
#include <iostream>
using namespace std;
#include "tables.h"

void printIngresosHeader()
{
const char separator = ' ';
const int nameWidth = 30;
const int numWidth = 15;

cout << left << setw(numWidth) << setfill(separator) << "Monto";
cout << left << setw(nameWidth) << setfill(separator) << "Concepto";
cout << left << setw(nameWidth) << setfill(separator) << "Categoria";
cout << left << setw(numWidth) << setfill(separator) << "Fecha";
cout << endl;
cout << left << setw(110) << setfill('_') << "";
cout << endl << endl;
};