#pragma once
#include <string>
#include "EgresosRepository.h"

using namespace std;

class EgresosHandler
{
private:
	string _nombre = "EGRESOS";
	string _fileName = "egresos.dat";
	EgresosRepository _egresos = EgresosRepository(_fileName);
public:
	bool exec();
	void mostrarRegistrosPor(vector<int> posiciones);
	void eliminarEgreso();
	void buscarEgresos();
	void listarEgresos();
	void mostrarPorFecha();
	void mostrarPorRangoMontos();
	void mostrarPorMonto();
	void mostrarPorMesYAnio();
	void mostrarPorCategoria();
};

