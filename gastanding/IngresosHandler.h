#pragma once
#include <string>
#include "IngresosRepository.h"

using namespace std;

class IngresosHandler
{
private:
	string _nombre = "INGRESOS";
	string _fileName = "ingresos.dat";
	IngresosRepository _ingresos = IngresosRepository();
public:
	bool exec();
	void mostrarRegistrosPor(vector<int> posiciones);
	void buscarIngresos();
	void mostrarPorFecha();
	void mostrarPorRangoMontos();
	void mostrarPorMonto();
};
