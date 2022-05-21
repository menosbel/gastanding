#pragma once
#include <string>
using namespace std;
#include "Fecha.h"

class Ingreso
{
private:
	float _monto;
	char _concepto[40];
	int _categoria;
	Fecha _fecha;
	bool _estado;
public:
	float getMonto() { return _monto; };
	void cargar();
	void mostrar();
	bool leerDeDisco(int pos, string fileName);
	bool grabarEnDisco(string fileName);
	bool grabarEnDisco(int pos, string fileName);
};

