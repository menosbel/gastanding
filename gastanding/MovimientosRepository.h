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
	void transferir(int billeteraActual, int billeteraDestino, float monto);
	int cantidadRegistros();
	int buscarPor(float monto, Fecha fecha, int categoriaId, string concepto, int billeteraId);
	vector<Movimiento> buscarPor(float monto);
	vector<Movimiento> buscarPor(float montoMin, float montoMax);
	vector<Movimiento> buscarPor(Fecha fecha);
	vector<Movimiento> buscarPor(int mes, int anio);
	vector<Movimiento> buscarPor(int categoriaId);
	vector<Movimiento> buscarPor(int categoriaId, Fecha inicio, Fecha fin);
	void mostrarRegistrosPor(vector<Movimiento> movimientos, int billeteraId);
	void ordenarMovimientos(vector<Movimiento>& movimientos);
};
