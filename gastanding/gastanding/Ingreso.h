#pragma once
#include "Fecha.h"

class Ingreso
{
private:
	float _monto;
	char _concepto[40];
	char _categoria[20];
	Fecha _fecha;
public:
	void cargar();
	void mostrar();
};

