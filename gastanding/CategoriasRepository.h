#pragma once
#include <string>
#include "Billetera.h"
#include "Categoria.h"
using namespace std;

class CategoriasRepository
{
private:
	string _nombreArchivo;
public:
	CategoriasRepository() { _nombreArchivo = ""; };
	CategoriasRepository(string nombreArchivo) { _nombreArchivo = nombreArchivo; };
	void agregar();
	void listar(int tipoMovimiento);
	Categoria seleccionarPor(int tipoMovimiento);
	int cantidadRegistros();
};

