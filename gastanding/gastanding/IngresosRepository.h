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
	void buscarPor(float monto_min, float monto_max);
	void buscarPor(Fecha fecha);
	void listarPorMes(string mes);
	void listarPorCategoria();
	int cantidadRegistros();
};
