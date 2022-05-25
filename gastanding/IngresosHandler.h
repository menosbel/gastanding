#pragma once
#include <string>
#include "IngresosRepository.h"

using namespace std;

class IngresosHandler
{
private:
	string _nombre = "INGRESOS";
	string _fileName = "ingresos.dat";
	IngresosRepository _ingresos = IngresosRepository(_fileName);
public:
	bool exec();
	void eliminarIngreso();
	void mostrarRegistrosPor(vector<int> posiciones);
	void buscarIngresos();
	void listarIngresos();
	void mostrarPorFecha();
	void mostrarPorRangoMontos();
	void mostrarPorMonto();
	void mostrarPorMesYAnio();
	void mostrarPorCategoria();
};
