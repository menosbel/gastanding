#include "EgresosHandler.h"
#include "menues.h"
#include "rlutil.h"
#include "functions.h"
#include "ingresoDatos.h"
#include "tables.h"

bool EgresosHandler::exec()
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
            _egresos.agregar();
            rlutil::anykey();
            break;
        case 2:
            eliminarEgreso();
            rlutil::anykey();
            break;
        case 3:
            buscarEgresos();
            break;
        case 4:
            listarEgresos();
            break;
        case 0:
            return false;
            break;
        default:
            break;
        }
    }
}

void EgresosHandler::buscarEgresos()
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

void EgresosHandler::listarEgresos()
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

void EgresosHandler::mostrarRegistrosPor(vector<int> posiciones)
{
    Egreso aux;
    printEgresosHeader();
    for (int i = 0; i < posiciones.size(); i++)
    {
        aux.leerDeDisco(posiciones[i], _fileName);
        aux.mostrar();
        cout << endl;
    }
}

void EgresosHandler::eliminarEgreso()
{
    float monto;
    Fecha fecha;
    int categoria, medioPago;
    string concepto;
    categoria = renderMenuCategoriasEgresos();
    medioPago = renderMenuMediosPago();
    fecha.cargar();
    monto = ingresoMonto();
    concepto = ingresoConcepto();
    cout << endl << endl;

    int posicion = _egresos.buscarPor(monto, fecha, categoria, concepto, medioPago);
    if (posicion == -1) mostrarMensaje("No se encontró el gasto", 15, 4);
    else {
        _egresos.eliminar(posicion);
    }
}

void EgresosHandler::mostrarPorFecha()
{
    Fecha fecha;
    int dia, mes, anio;
    cout << "Buscar " << _nombre << " por fecha" << endl << endl;
    fecha.cargar();

    vector<int> posiciones = _egresos.buscarPor(fecha);
    if (posiciones.empty()) mostrarMensaje("No se encontraron egresos para esa fecha", 15, 4);
    else {
        cout << endl << endl;
        cout << "Buscar " << _nombre << " por fecha" << endl << endl;
        mostrarRegistrosPor(posiciones);
    }
}

void EgresosHandler::mostrarPorRangoMontos()
{
    float montoMin, montoMax;
    cout << "Buscar " << _nombre << " por rango de montos" << endl << endl;
    montoMin = ingresoMontoMin();
    montoMax = ingresoMontoMax();

    EgresosProps m = EgresosProps::MontoMinMax;
    vector<int> posiciones = _egresos.nuevoBuscarPor(m, montoMin, montoMax);
    if (posiciones.empty()) mostrarMensaje("No se encontraron egresos dentro de ese rango de montos", 15, 4);
    else {
        cout << endl << endl;
        cout << "Buscar " << _nombre << " por rango de montos" << endl << endl;
        mostrarRegistrosPor(posiciones);
    }
}

void EgresosHandler::mostrarPorMonto()
{
    float monto;
    cout << "Buscar " << _nombre << " por monto" << endl << endl;
    monto = ingresoMonto();
    
    EgresosProps m = EgresosProps::Monto;
    vector<int> posiciones = _egresos.nuevoBuscarPor(m, monto);
    if (posiciones.empty()) mostrarMensaje("No se encontraron egresos por ese monto", 15, 4);
    else {
        cout << endl << endl;
        cout << "Buscar " << _nombre << " por monto" << endl << endl;
        mostrarRegistrosPor(posiciones);
    }
}

void EgresosHandler::mostrarPorMesYAnio()
{
    int mes, anio;
    cout << "Listar " << _nombre << " por mes y año" << endl << endl;
    mes = ingresoMes();
    anio = ingresoAnio();
    
    EgresosProps m = EgresosProps::MesAnio;
    vector<int> posiciones = _egresos.nuevoBuscarPor(m, mes, anio);
    if (posiciones.empty()) mostrarMensaje("No se encontraron egresos para ese mes y año", 15, 4);
    else {
        cout << endl << endl;
        cout << "Listar " << _nombre << " por mes y año" << endl << endl;
        mostrarRegistrosPor(posiciones);
    }
}

void EgresosHandler::mostrarPorCategoria()
{
    int categoria;
    cout << "Listar " << _nombre << " por categoría" << endl << endl;
    categoria = renderMenuCategoriasEgresos();

    EgresosProps m = EgresosProps::Categoria;
    vector<int> posiciones = _egresos.nuevoBuscarPor(m, categoria);
    if (posiciones.empty()) mostrarMensaje("No se encontraron ingresos para esa categoría", 15, 4);
    else {
        cout << endl << endl;
        cout << "Listar " << _nombre << " por categoria" << endl << endl;
        mostrarRegistrosPor(posiciones);
    }
}
