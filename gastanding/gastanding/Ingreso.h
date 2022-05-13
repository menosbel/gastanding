#pragma once
#include "Fecha.h"

class Ingreso
{
private:
	float _monto;
	char _concepto[40];
	int _categoria;
	Fecha _fecha;
public:
	void cargar();
	void mostrar();
	int leerDeDisco(int pos, const char* nombre_archivo);
	int grabarEnDisco(const char* nombre_archivo);
};

