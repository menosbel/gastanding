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
	Fecha getFecha() { return _fecha; };
	int getCategoria() { return _categoria; };
	string getConcepto() { return string(_concepto); };
	bool getEstado() { return _estado; };
	void setMonto(float valor) { _monto = valor; };
	void setConcepto(string valor) { strcpy_s(_concepto, valor.c_str()); };
	void setCategoria(int valor) { _categoria = valor; };
	void setEstado(bool valor) { _estado = valor; };
	void cargar();
	void mostrar();
	bool equals(Ingreso otro);
	bool leerDeDisco(int pos, string fileName);
	bool grabarEnDisco(string fileName);
	bool grabarEnDisco(int pos, string fileName);
};

