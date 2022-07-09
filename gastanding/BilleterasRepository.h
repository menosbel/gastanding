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
	bool listar();
	double calcularSaldoActual(int billeteraId);
	bool tieneFondos(int billeteraId, double monto);
	Billetera seleccionar();
	int seleccionarTransferencia(int id);
	int cantidadRegistros();
	int cantidadRegistrosActivos();
	Billetera buscarPor(int id);

private:
	bool bajaLogica(int idBilletera);
};

