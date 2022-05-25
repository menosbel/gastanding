#pragma once
#include "Ingreso.h"
#include <string>
#include <vector>

using namespace std;

class IngresosRepository 
{
private:
	string _fileName;
public:
	IngresosRepository(string value) {
		_fileName = value;
	};
	void agregar();
	int cantidadRegistros();
	int buscarPor(float monto, Fecha fecha, int categoria, string concepto);
	vector<int> buscarPor(float monto);
	vector<int> buscarPor(float montoMin, float montoMax);
	vector<int> buscarPor(Fecha fecha);
	vector<int> listarPor(int mes, int anio);
	vector<int> listarPor(int categoria);
};
