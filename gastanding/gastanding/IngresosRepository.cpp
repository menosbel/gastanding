#include "IngresosRepository.h"
#include "Ingreso.h"
#include <iostream>

using namespace std;

void IngresosRepository::agregar() 
{
	Ingreso ingreso;
	ingreso.cargar();
	if (ingreso.grabarEnDisco("ingresos.dat")) cout << "Ingreso agregado" << endl;
	else cout << "Error en el archivo" << endl;
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
