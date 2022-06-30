#pragma once
#include "Billetera.h"

class BilleterasRepository
{
private:
	string _nombreArchivo;
public:
	BilleterasRepository() { _nombreArchivo = ""; };
	BilleterasRepository(string nombreArchivo) { _nombreArchivo = nombreArchivo; };
	void agregar();
	void eliminar();
	void listar();
	Billetera seleccionar();
	int seleccionarTransferencia(int id);
	int cantidadRegistros();
	Billetera buscarPor(int id);
private:
	bool bajaLogica(int idBilletera);
};

