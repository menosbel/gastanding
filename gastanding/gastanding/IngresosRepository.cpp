#include "IngresosRepository.h"
#include "base_functions.h"
#include "Ingreso.h"
#include <iostream>

using namespace std;

void IngresosRepository::agregar() 
{
	Ingreso ingreso;
	ingreso.cargar();
	if (ingreso.grabarEnDisco(_fileName)) mostrarMensaje("Ingreso agregado exitosamente", 15, 2);
	else mostrarMensaje("No se pude agregar el ingreso", 15, 4);
};

void IngresosRepository::eliminar()
{
	cout << "Ingreso eliminado" << endl;
}

vector<int> IngresosRepository::buscarPor(float monto)
{
    Ingreso aux;
    int cantIngresos = cantidadRegistros();
    vector<int> posiciones;

    for (int i = 0; i < cantIngresos; i++)
    {
        aux.leerDeDisco(i, _fileName);
        if (aux.getMonto() == monto) {
            posiciones.push_back(i);
        }
    }

    return posiciones;
}

void IngresosRepository::buscarPor(float monto_min, float monto_max)
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

int IngresosRepository::cantidadRegistros() {
    FILE* p;
    errno_t err;
    err = fopen_s(&p, "ingresos.dat", "rb");
    if (err != 0) { return 0; };
    size_t bytes;
    int cant_reg;

    fseek(p, 0, SEEK_END);
    bytes = ftell(p);
    fclose(p);
    cant_reg = bytes / sizeof(Ingreso);
    return cant_reg;
}
