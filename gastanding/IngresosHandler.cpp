#include "IngresosHandler.h"
#include "menues.h"
#include "rlutil.h"
#include "functions.h"
#include "ingresoDatos.h"
#include "tables.h"
#include <iostream>
using namespace std;

bool IngresosHandler::exec()
{
    int opcion;
    bool seguir = true;

    while (seguir)
    {
        rlutil::cls();
        opcion = renderMenuEntidad(_nombre);
        rlutil::cls();
        switch (opcion)
        {
        case 1:
            _ingresos.agregar();
            rlutil::anykey();
            break;
        case 2:
            eliminarIngreso();
            rlutil::anykey();
            break;
        case 3:
            buscarIngresos();
            break;
        case 4:
            listarIngresos();
            break;
        case 0:
            return false;
            break;
        default:
            break;
        }
    }
}

void IngresosHandler::buscarIngresos()
{
    int opcion;
    opcion = renderMenuBuscar(_nombre);
    rlutil::cls();
    switch (opcion)
    {
    case 1:
        mostrarPorFecha();
        rlutil::anykey();
        break;
    case 2:
        mostrarPorRangoMontos();
        rlutil::anykey();
        break;
    case 3:
        mostrarPorMonto();
        rlutil::anykey();
        break;
    case 0:
        break;
    default:
        break;
    }
}

void IngresosHandler::listarIngresos()
{
    int opcion;
    opcion = renderMenuListas(_nombre);
    rlutil::cls();
    switch (opcion)
    {
    case 1:
        mostrarPorMesYAnio();
        rlutil::anykey();
        break;
    case 2:
        mostrarPorCategoria();
        rlutil::anykey();
        break;
    case 0:
        break;
    default:
        break;
    }
}

void IngresosHandler::eliminarIngreso()
{
    float monto;
    Fecha fecha;
    int categoria;
    string concepto;
    categoria = renderMenuCategoriasIngresos();
    fecha.cargar();
    monto = ingresoMonto();
    concepto = ingresoConcepto();
    cout << endl << endl;

    int posicion = _ingresos.buscarPor(monto, fecha, categoria, concepto);
    if (posicion == -1) mostrarMensaje("No se encontró el ingreso", 15, 4);
    else {
        _ingresos.eliminar(posicion);
    }
}

void IngresosHandler::mostrarRegistrosPor(vector<int> posiciones)
{
    Ingreso aux;
    printIngresosHeader();
    for (int i = 0; i < posiciones.size(); i++)
    {
        aux.leerDeDisco(posiciones[i], _fileName);
        aux.mostrar();
        cout << endl;
    }
}

void IngresosHandler::mostrarPorFecha()
{
    Fecha fecha;
    int dia, mes, anio;
    cout << "Buscar " << _nombre << " por fecha" << endl << endl;
    fecha.cargar();
    
    vector<int> posiciones = _ingresos.buscarPor(fecha);
    if (posiciones.empty()) mostrarMensaje("No se encontraron ingresos para esa fecha", 15, 4);
    else {
        cout << endl << endl;
        cout << "Buscar " << _nombre << " por fecha" << endl << endl;
        mostrarRegistrosPor(posiciones);
    }
}

void IngresosHandler::mostrarPorRangoMontos()
{
    float montoMin, montoMax;
    cout << "Buscar " << _nombre << " por rango de montos" << endl << endl;
    montoMin = ingresoMontoMin();
    montoMax = ingresoMontoMax();

    vector<int> posiciones = _ingresos.buscarPor(montoMin, montoMax);
    if (posiciones.empty()) mostrarMensaje("No se encontraron ingresos dentro de ese rango de montos", 15, 4);
    else {
        cout << endl << endl;
        cout << "Buscar " << _nombre << " por rango de montos" << endl << endl;
        mostrarRegistrosPor(posiciones);
    }
}

void IngresosHandler::mostrarPorMonto()
{
    float monto;
    cout << "Buscar " << _nombre << " por monto" << endl << endl;
    monto = ingresoMonto();

    vector<int> posiciones = _ingresos.buscarPor(monto);
    if (posiciones.empty()) mostrarMensaje("No se encontraron ingresos por ese monto", 15, 4);
    else {
        cout << endl << endl;
        cout << "Buscar " << _nombre << " por monto" << endl << endl;
        mostrarRegistrosPor(posiciones);
    }
}

void IngresosHandler::mostrarPorMesYAnio()
{
    int mes, anio;
    bool ok = false;
    cout << "Listar " << _nombre << " por mes y año" << endl << endl;
    mes = ingresoMes();
    anio = ingresoAnio();

    vector<int> posiciones = _ingresos.listarPor(mes, anio);
    if (posiciones.empty()) mostrarMensaje("No se encontraron ingresos para ese mes y año", 15, 4);
    else {
        cout << endl << endl;
        cout << "Listar " << _nombre << " por mes y año" << endl << endl;
        mostrarRegistrosPor(posiciones);
    }
}

void IngresosHandler::mostrarPorCategoria()
{
    int categoria;
    cout << "Listar " << _nombre << " por categoría" << endl << endl;
    categoria = renderMenuCategoriasIngresos();

    vector<int> posiciones = _ingresos.listarPor(categoria);
    if (posiciones.empty()) mostrarMensaje("No se encontraron ingresos para esa categoría", 15, 4);
    else {
        cout << endl << endl;
        cout << "Listar " << _nombre << " por categoria" << endl << endl;
        mostrarRegistrosPor(posiciones);
    }
}
