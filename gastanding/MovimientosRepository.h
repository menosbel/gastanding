#pragma once
#include "Movimiento.h"
#include "CategoriasRepository.h"
#include "BilleterasRepository.h"
#include <string>
#include <vector>

using namespace std;

class MovimientosRepository 
{
private:
	string _nombreArchivo;
	CategoriasRepository _categorias;
	BilleterasRepository _billeteras;
public:
	MovimientosRepository() { _nombreArchivo = ""; _categorias = CategoriasRepository(); _billeteras = BilleterasRepository(); };
	MovimientosRepository(string nombreArchivo, CategoriasRepository categorias, BilleterasRepository billeteras) {
		_nombreArchivo = nombreArchivo;
		_categorias = categorias;
		_billeteras = billeteras;
	};
	bool agregarA(int billeteraId, int categoriaId);
	void eliminar(int pos);
	void transferir(int billeteraActual, int billeteraDestino, double monto);
	int cantidadRegistros();
	bool chequearSiMovimientoExiste(Movimiento movimiento);
	int buscarPor(double monto, Fecha fecha, int categoriaId, string concepto, int billeteraId);
	vector<Movimiento> buscarPor(double monto);
	vector<Movimiento> buscarPor(double montoMin, double montoMax);
	vector<Movimiento> buscarPor(Fecha fecha);
	vector<Movimiento> buscarPor(int mes, int anio);
	vector<Movimiento> buscarPor(int categoriaId);
	vector<Movimiento> buscarPor(int categoriaId, Fecha inicio, Fecha fin);
	void mostrarRegistrosPor(vector<Movimiento> movimientos, int billeteraId);
	void ordenarMovimientos(vector<Movimiento>& movimientos);
};
