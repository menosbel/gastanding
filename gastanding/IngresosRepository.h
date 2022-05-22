#pragma once
#include "Ingreso.h"
#include <string>
#include <vector>

using namespace std;

class IngresosRepository 
{
private:
	string _fileName = "ingresos.dat";
public:
	void agregar();
	void eliminar();
	vector<int> buscarPor(float monto);
	vector<int> buscarPor(float montoMin, float montoMax);
	vector<int> buscarPor(Fecha fecha);
	void listarPorMesYAnio(int mes, int anio);
	void listarPorCategoria();
	int cantidadRegistros();
};
