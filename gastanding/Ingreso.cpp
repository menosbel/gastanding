#include <iostream>
#include "Ingreso.h"
#include "menues.h"
#include "functions.h"
#include "rlutil.h"
#include "tables.h"
using namespace std;


void Ingreso::cargar()
{
	int monto, categoria, dia, mes, anio;
	string concepto;

	cout << "Categoria: ";
	categoria = renderMenuCategoriasIngresos();
	setCategoria(categoria);
	_fecha.cargar();
	cout << "Monto: $";
	cin >> monto;
	setMonto(monto);
	cout << "Concepto: ";
	cin >> concepto;
	setConcepto(concepto);
	setEstado(true);
}

void Ingreso::mostrar() {

	const int nameWidth = 30;
	const int numWidth = 15;

	printElement(_monto, numWidth);
	printElement(_concepto, nameWidth);
	printElement(categoriasIngresosToString(_categoria), nameWidth);
	printElement(_fecha.toString(), numWidth);
}

bool Ingreso::equals(Ingreso otro)
{
	if (
		getMonto() == otro.getMonto() &&
		getFecha().equals(otro.getFecha()) &&
		getCategoria() == otro.getCategoria() &&
		getConcepto() == otro.getConcepto()
		) return true;
	return false;
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