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
	void eliminar(int tipoMovimiento);
	void listar(int tipoMovimiento);
	int seleccionarPor(int tipoMovimiento);
	Categoria buscarPor(int id);
	int cantidadRegistros();
	int cantidadRegistrosActivosPorTipo(int tipo);
private:
	bool bajaLogica(int idCategoria);
};

