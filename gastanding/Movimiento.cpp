#include <iostream>
#include "Movimiento.h"
#include "menues.h"
#include "functions.h"
#include "rlutil.h"
#include "tables.h"
#include "Fecha.h"
using namespace std;


void Movimiento::cargarEn(int billeteraId, int categoriaId, int nextId)
{
	int monto, dia, mes, anio, tipoCategoria;
	string concepto;
		
	_fecha.cargar();
	
	cout << "Monto: $";
	cin >> monto;
	setMonto(monto);
	
	cout << "Concepto: ";
	cin >> concepto;
	setConcepto(concepto);
	
	setCategoria(categoriaId);
	setBilletera(billeteraId);
	setEstado(true);
	setId(nextId);
}

void Movimiento::mostrar(Categoria categoria) 
{
	const int nameWidth = 30;
	const int numWidth = 15;

	printElement(_fecha.toString(), numWidth);
	printElement(_monto, numWidth);
	printElement(_concepto, nameWidth);
	printElement(categoria.getNombre(), nameWidth);
}

bool Movimiento::equals(Movimiento otro)
{
	if (getId() == otro.getId()) return true;
	return false;
}

bool Movimiento::grabarEnDisco(string fileName)
{
	FILE* p;
	errno_t err;
	const char* file = fileName.c_str();
	err = fopen_s(&p, file, "ab");
	if (err != 0) { return -1; }
	int escribio = fwrite(this, sizeof(Movimiento), 1, p);
	fclose(p);
	return escribio;
}

bool Movimiento::grabarEnDisco(int pos, string fileName)
{
	FILE* p;
	errno_t err;
	const char* file = fileName.c_str();
	err = fopen_s(&p, file, "rb+");
	if (err != 0) { return false; }
	fseek(p, pos * sizeof(Movimiento), SEEK_SET);
	bool guardo = fwrite(this, sizeof(Movimiento), 1, p);
	fclose(p);

	return guardo;
}

bool Movimiento::leerDeDisco(int pos, string fileName)
{
	FILE* p;
	errno_t err;
	const char* file = fileName.c_str();
	err = fopen_s(&p, file, "rb");
	if (err != 0) { return -1; }
	fseek(p, sizeof(Movimiento) * pos, 0);
	int leyo = fread(this, sizeof(Movimiento), 1, p);
	fclose(p);
	return leyo;
}

bool Movimiento::Ultimos30dias(Fecha fechaMovimiento)
{
	Fecha Actual;
	int dia = Actual.getDia();
	int mes = Actual.getMes();
	int anio = Actual.getAnio();
	int diaMov = fechaMovimiento.getDia();
	int mesMov = fechaMovimiento.getMes();
	int anioMov = fechaMovimiento.getAnio();

	int resto = 30 - dia;
	int op = 0;

		if (anio == anioMov && mes == mesMov && dia >= diaMov)
		{
			op = 1;
		}
		if (mes - mesMov == 1 && anio == anioMov && mesMov == 1 || mesMov == 3 || mesMov == 5 || mesMov == 7 || mesMov == 8 || mesMov == 10 || mesMov == 12 && diaMov >= 31 - resto)
		{
			op = 1;
		}
		if (mes - mesMov == 1 && anio == anioMov && mesMov == 4 || mesMov == 6 || mesMov == 9 || mesMov == 11 && diaMov >= 30 - resto)
		{
			op = 1;
		}
		if (mes - mesMov == 1 && anio == anioMov && mesMov == 2 && fechaMovimiento.anioBiciesto(anioMov) == true && diaMov >= 29 - resto)
		{
			op = 1;
		}
		if (mes - mesMov == 1 && anio == anioMov && mesMov == 2 && fechaMovimiento.anioBiciesto(anioMov) == false && diaMov >= 28 - resto)
		{
			op = 1;
		}
		if (anio - anioMov == 1 && mesMov == 12 && mes == 1 && diaMov >= 31 - resto)
		{
			op = 1;
		}

	switch (op)
	{
	case 0:
		return false;
		break;
	case 1:
		return true;
		break;
	}
}
