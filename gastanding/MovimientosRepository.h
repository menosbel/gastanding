#pragma once
#include "Movimiento.h"
#include <string>
#include <vector>

using namespace std;

class MovimientosRepository 
{
private:
	string _nombreArchivo;
public:
	MovimientosRepository() { _nombreArchivo = ""; };
	MovimientosRepository(string nombreArchivo) { _nombreArchivo = nombreArchivo; };
	void agregarA(Billetera billetera, Categoria categoria);
	void eliminar(int pos);
	int cantidadRegistros();
	int buscarPor(float monto, Fecha fecha, Categoria categoria, string concepto, Billetera billetera);
	vector<int> buscarPor(float monto);
	vector<int> buscarPor(float montoMin, float montoMax);
	vector<int> buscarPor(Fecha fecha);
	vector<int> buscarPor(int mes, int anio);
	vector<int> buscarPor(Categoria categoria);
	void mostrarRegistrosPor(vector<int> posiciones, Billetera billetera);
};
