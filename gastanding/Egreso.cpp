#include "Egreso.h"
#include "menues.h"
#include "tables.h"
#include "functions.h"
#include <iostream>

using namespace std;

void Egreso::cargar()
{
	int monto, categoria, dia, mes, anio, medioPago;
	string concepto;

	cout << "Categoria: ";
	categoria = renderMenuCategoriasEgresos();
	setCategoria(categoria);
	_fecha.cargar();
	cout << "Monto: $";
	cin >> monto;
	setMonto(monto);
	cout << "Metodo pago: ";
	medioPago = renderMenuMediosPago();
	setMedioPago(medioPago);
	cout << "Concepto: ";
	cin >> concepto;
	setConcepto(concepto);
	setEstado(true);
}

void Egreso::mostrar() {

	const int nameWidth = 25;
	const int numWidth = 15;

	printElement(_monto, numWidth);
	printElement(mediosPagoToString(_medioPago), nameWidth);
	printElement(_concepto, nameWidth);
	printElement(categoriasEgresosToString(_categoria), nameWidth);
	printElement(_fecha.toString(), numWidth);
}

bool Egreso::equals(Egreso otro)
{
	if (
		getMonto() == otro.getMonto() &&
		getFecha().equals(otro.getFecha()) &&
		getCategoria() == otro.getCategoria() &&
		getConcepto() == otro.getConcepto() &&
		getMedioPago() == otro.getMedioPago() &&
		getEstado() == otro.getEstado()
		) return true;
	return false;
}

bool Egreso::grabarEnDisco(string fileName)
{
	FILE* p;
	errno_t err;
	const char* file = fileName.c_str();
	err = fopen_s(&p, file, "ab");
	if (err != 0) { return -1; }
	int escribio = fwrite(this, sizeof(Egreso), 1, p);
	fclose(p);
	return escribio;
}

bool Egreso::grabarEnDisco(int pos, string fileName)
{
	FILE* p;
	errno_t err;
	const char* file = fileName.c_str();
	err = fopen_s(&p, file, "rb+");
	if (err != 0) { return false; }
	fseek(p, pos * sizeof(Egreso), SEEK_SET);
	bool guardo = fwrite(this, sizeof(Egreso), 1, p);
	fclose(p);

	return guardo;
}

bool Egreso::leerDeDisco(int pos, string fileName)
{
	FILE* p;
	errno_t err;
	const char* file = fileName.c_str();
	err = fopen_s(&p, file, "rb");
	if (err != 0) { return -1; }
	fseek(p, sizeof(Egreso) * pos, 0);
	int leyo = fread(this, sizeof(Egreso), 1, p);
	fclose(p);
	return leyo;
}
