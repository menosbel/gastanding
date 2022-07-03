#pragma once
#include "Billetera.h"
#include "CategoriasRepository.h"

class BilleterasRepository
{
private:
	string _nombreArchivo;
	CategoriasRepository _categorias;
public:
	BilleterasRepository() { _nombreArchivo = ""; CategoriasRepository _categorias; };
	BilleterasRepository(string nombreArchivo, CategoriasRepository categoriasRepository) { 
		_nombreArchivo = nombreArchivo; 
		_categorias = categoriasRepository;
	};
	void agregar();
	void eliminar();
	void listar();
	double calcularSaldoActual(int billeteraId);
	Billetera seleccionar();
	int seleccionarTransferencia(int id);
	int cantidadRegistros();
	Billetera buscarPor(int id);
private:
	bool bajaLogica(int idBilletera);
};

