#pragma once
#include "Movimiento.h"
#include "CategoriasRepository.h"
#include <string>
#include <vector>

using namespace std;

class MovimientosRepository 
{
private:
	string _nombreArchivo;
	CategoriasRepository _categorias;
public:
	MovimientosRepository() { _nombreArchivo = ""; _categorias = CategoriasRepository(); };
	MovimientosRepository(string nombreArchivo, CategoriasRepository categorias) { 
		_nombreArchivo = nombreArchivo;
		_categorias = categorias;
	};
	void agregarA(int billeteraId, int categoriaId);
	void eliminar(int pos);
	int cantidadRegistros();
	int buscarPor(float monto, Fecha fecha, int categoriaId, string concepto, int billeteraId);
	vector<int> buscarPor(float monto);
	vector<int> buscarPor(float montoMin, float montoMax);
	vector<int> buscarPor(Fecha fecha);
	vector<int> buscarPor(int mes, int anio);
	vector<int> buscarPor(int categoriaId);
	void mostrarRegistrosPor(vector<int> posiciones, int billeteraId);
};
