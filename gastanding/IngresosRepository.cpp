#include "IngresosRepository.h"
#include "functions.h"
#include "tables.h"
#include "rlutil.h"
#include "Ingreso.h"
#include <iostream>

using namespace std;

void IngresosRepository::agregar() 
{
	Ingreso ingreso, aux;
	ingreso.cargar();

    int cantIngresos = cantidadRegistros();
    bool existe = false;
    for (int i = 0; i < cantIngresos; i++)
    {
        aux.leerDeDisco(i, _fileName);
        if (aux.equals(ingreso)) {
            existe = true;
            break;
        };
    }

    if (existe) {
        mostrarMensaje("El ingreso ya existe. No puede volver a agregarse", 15, 4);
    }
    else {
        if (ingreso.grabarEnDisco(_fileName)) mostrarMensaje("Ingreso agregado exitosamente", 15, 2);
        else mostrarMensaje("No se pudo agregar el ingreso", 15, 4);
    }
};

void IngresosRepository::eliminar(int pos)
{
    Ingreso aux;
    char confirmacion;
    bool guardo = false;

    aux.leerDeDisco(pos, _fileName);
    printIngresosHeader();
    aux.mostrar();
    cout << endl << endl;
    cout << "¿Desea eliminar el registro? (S/N): ";
    cin >> confirmacion;
    if (tolower(confirmacion) == 's') {
        aux.setEstado(false);
        guardo = aux.grabarEnDisco(pos, _fileName);
    }
    rlutil::cls();
    if (guardo) mostrarMensaje("Ingreso eliminado exitosamente", 15, 2);
    else mostrarMensaje("Ocurrió un error. El ingreso no ha sido eliminado", 15, 4);
}

int IngresosRepository::cantidadRegistros() {
    FILE* p;
    errno_t err;
    err = fopen_s(&p, _fileName.c_str(), "rb");
    if (err != 0) { return 0; };
    size_t bytes;
    int cant_reg;

    fseek(p, 0, SEEK_END);
    bytes = ftell(p);
    fclose(p);
    cant_reg = bytes / sizeof(Ingreso);
    return cant_reg;
}

int IngresosRepository::buscarPor(float monto, Fecha fecha, int categoria, string concepto)
{
    Ingreso aux;
    int cantIngresos = cantidadRegistros();

    for (int i = 0; i < cantIngresos; i++)
    {
        aux.leerDeDisco(i, _fileName);
        if (
            aux.getEstado() == true && 
            aux.getMonto() == monto &&
            aux.getFecha().equals(fecha) &&
            aux.getCategoria() == categoria &&
            aux.getConcepto() == concepto
            ) {
            return i;
        }
    }
    return -1;
}

vector<int> IngresosRepository::buscarPor(float monto)
{
    Ingreso aux;
    int cantIngresos = cantidadRegistros();
    vector<int> posiciones;

    for (int i = 0; i < cantIngresos; i++)
    {
        aux.leerDeDisco(i, _fileName);
        if (aux.getEstado() == true && aux.getMonto() == monto) {
            posiciones.push_back(i);
        }
    }
    return posiciones;
}

vector<int> IngresosRepository::buscarPor(float montoMin, float montoMax)
{
    Ingreso aux;
    int cantIngresos = cantidadRegistros();
    vector<int> posiciones;

    for (int i = 0; i < cantIngresos; i++)
    {
        aux.leerDeDisco(i, _fileName);
        if (aux.getEstado() == true) {
            if (aux.getMonto() >= montoMin || aux.getMonto() <= montoMax) {
                posiciones.push_back(i);
            }
        }
    }
    return posiciones;
}

vector<int> IngresosRepository::buscarPor(Fecha fecha)
{
    Ingreso aux;
    int cantIngresos = cantidadRegistros();
    vector<int> posiciones;

    for (int i = 0; i < cantIngresos; i++)
    {
        aux.leerDeDisco(i, _fileName);
        if (aux.getEstado() == true && aux.getFecha().equals(fecha)) {
            posiciones.push_back(i);
        }
    }
    return posiciones;
}

vector<int> IngresosRepository::listarPor(int mes, int anio)
{
    Ingreso aux;
    int cantIngresos = cantidadRegistros();
    vector<int> posiciones;

    for (int i = 0; i < cantIngresos; i++)
    {
        aux.leerDeDisco(i, _fileName);
        if (aux.getEstado() == true && aux.getFecha().getAnio() == anio && aux.getFecha().getMes() == mes) {
            posiciones.push_back(i);
        }
    }
    return posiciones;
}

vector<int> IngresosRepository::listarPor(int categoria)
{
    Ingreso aux;
    int cantIngresos = cantidadRegistros();
    vector<int> posiciones;

    for (int i = 0; i < cantIngresos; i++)
    {
        aux.leerDeDisco(i, _fileName);
        if (aux.getEstado() == true && aux.getCategoria() == categoria) {
            posiciones.push_back(i);
        }
    }
    return posiciones;
}
