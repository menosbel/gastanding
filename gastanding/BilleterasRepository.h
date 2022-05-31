#pragma once
#include "Billetera.h"

class BilleterasRepository
{
private:
	string _nombreArchivo;

	bool bajaLogica(int idBilletera);
public:
	BilleterasRepository() { _nombreArchivo = ""; };
	BilleterasRepository(string nombreArchivo) { _nombreArchivo = nombreArchivo; };
	void agregar();
	void eliminar();
	void listar();
	Billetera seleccionar();
	int cantidadRegistros();
	Billetera buscarPor(int id) { return Billetera(); };
};

