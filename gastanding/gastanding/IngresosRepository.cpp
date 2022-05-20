#include "IngresosRepository.h"
#include "base_functions.h"
#include "Ingreso.h"
#include <iostream>

using namespace std;

void IngresosRepository::agregar() 
{
	Ingreso ingreso;
	ingreso.cargar();
	if (ingreso.grabarEnDisco("ingresos.dat")) mostrarMensaje("Ingreso agregado exitosamente", 15, 2);
	else mostrarMensaje("No se pude agregar el ingreso", 15, 4);
};

void IngresosRepository::eliminar()
{
	cout << "Ingreso eliminado" << endl;
}

void IngresosRepository::buscarPor(int monto)
{
}

void IngresosRepository::buscarPor(int monto_min, int monto_max)
{
}

void IngresosRepository::buscarPor(Fecha fecha)
{
}

void IngresosRepository::listarPorMes(string mes)
{
}

void IngresosRepository::listarPorCategoria()
{
}
