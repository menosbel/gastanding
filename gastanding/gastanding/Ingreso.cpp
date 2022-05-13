#include "Ingreso.h"
#include "menues.h"
#include "base_functions.h"
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

}


void Ingreso::mostrar() {
	cout << "Monto: $" << _monto << endl;
	cout << "Concepto: " << _concepto << endl;
	cout << "Categoria: " << categoriasIngresosToString(_categoria) << endl;
	cout << "Fecha: ";
	_fecha.mostrar();
}

int Ingreso::grabarEnDisco(const char *nombre_archivo)
{
	FILE* p;
	errno_t err;
	err = fopen_s(&p, nombre_archivo, "ab");
	if (err != 0) { return -1; }
	int escribio = fwrite(this, sizeof(Ingreso), 1, p);
	fclose(p);
	return escribio;
}

int Ingreso::leerDeDisco(int pos, const char* nombre_archivo)
{
	FILE* p;
	errno_t err;
	err = fopen_s(&p, nombre_archivo, "rb");
	if (err != 0) { return -1; }
	fseek(p, sizeof(Ingreso) * pos, 0);
	int leyo = fread(this, sizeof(Ingreso), 1, p);
	fclose(p);
	return leyo;
}