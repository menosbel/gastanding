#pragma once
#include <string>
using namespace std;
#include "Fecha.h"
#include "Categoria.h"
#include "Billetera.h"

class Movimiento
{
private:
	float _monto;
	char _concepto[40];
	Categoria _categoria;
	Billetera _billetera;
	Fecha _fecha;
	bool _estado;
public:
	float getMonto() { return _monto; };
	string getConcepto() { return string(_concepto); };
	Billetera getBilletera() { return _billetera; };
	Fecha getFecha() { return _fecha; };
	Categoria getCategoria() { return _categoria; };
	bool getEstado() { return _estado; };
	void setMonto(float valor) { _monto = valor; };
	void setConcepto(string valor) { strcpy_s(_concepto, valor.c_str()); };
	void setCategoria(Categoria valor) { _categoria = valor; };
	void setBilletera(Billetera valor) { _billetera = valor; };
	void setEstado(bool valor) { _estado = valor; };
	void cargarEn(Billetera billetera, Categoria categoria);
	void mostrar();
	bool equals(Movimiento otro);
	bool leerDeDisco(int pos, string fileName);
	bool grabarEnDisco(string fileName);
	bool grabarEnDisco(int pos, string fileName);
};

