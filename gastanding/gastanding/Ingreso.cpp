#include "Ingreso.h"
#include "menues.h"
#include "functions.h"
#include <iostream>

using namespace std;

void Ingreso::cargar()
{
	cout << "Monto: $";
	cin >> _monto;
	cout << "Concepto: ";
	cin >> _concepto;
	cout << "Categoria: ";
	_categoria = renderMenuCategoriasIngresos();
	cout << "Fecha: " << endl;
	_fecha.cargar();
	_estado = true;

}


void Ingreso::mostrar() {
	cout << "Monto: $" << _monto << endl;
	cout << "Concepto: " << _concepto << endl;
	cout << "Categoria: " << categoriasIngresosToString(_categoria) << endl;
	cout << "Fecha: ";
	_fecha.mostrar();
}

bool Ingreso::grabarEnDisco(string fileName)
{
	FILE* p;
	errno_t err;
	const char* file = fileName.c_str();
	err = fopen_s(&p, file, "ab");
	if (err != 0) { return -1; }
	int escribio = fwrite(this, sizeof(Ingreso), 1, p);
	fclose(p);
	return escribio;
}

bool Ingreso::grabarEnDisco(int pos, string fileName)
{
	FILE* p;
	errno_t err;
	const char* file = fileName.c_str();
	err = fopen_s(&p, file, "rb+");
	if (err != 0) { return false; }
	fseek(p, pos * sizeof(Ingreso), SEEK_SET);
	bool guardo = fwrite(this, sizeof(Ingreso), 1, p);
	fclose(p);

	return guardo;
}

bool Ingreso::leerDeDisco(int pos, string fileName)
{
	FILE* p;
	errno_t err;
	const char* file = fileName.c_str();
	err = fopen_s(&p, file, "rb");
	if (err != 0) { return -1; }
	fseek(p, sizeof(Ingreso) * pos, 0);
	int leyo = fread(this, sizeof(Ingreso), 1, p);
	fclose(p);
	return leyo;
}