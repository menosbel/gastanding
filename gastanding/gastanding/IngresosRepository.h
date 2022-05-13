#pragma once
#include "Ingreso.h"
#include <string>

using namespace std;

class IngresosRepository 
{
public:
	void agregar();
	void eliminar();
	void buscarPor(int monto);
	void buscarPor(int monto_min, int monto_max);
	void buscarPor(Fecha fecha);
	void listarPorMes(string mes);
	void listarPorCategoria();
};
