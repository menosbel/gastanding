#include "MovimientosHandler.h"
#include "menues.h"
#include "rlutil.h"
#include "functions.h"
#include "ingresoDatos.h"
#include "tables.h"
#include <iostream>
using namespace std;

void MovimientosHandler::buscarMovimientosEn(Billetera billetera)
{
    int opcion;
    _billeteraElegida = billetera;
    opcion = renderMenuBuscar();
    rlutil::cls();
    switch (opcion)
    {
    case 1:
        mostrarPorFecha();
        rlutil::anykey();
        break;
    case 2:
        mostrarPorMesYAnio();
        rlutil::anykey();
        break;
    case 3:
        mostrarPorRangoMontos();
        rlutil::anykey();
        break;
    case 4:
        mostrarPorMonto();
        rlutil::anykey();
        break;
    case 5:
        mostrarPorCategoria();
        rlutil::anykey();
        break;
    case 0:
        break;
    default:
        break;
    }
}

void MovimientosHandler::agregarMovimientosA(int billeteraId)
{
    int tipoMovimiento = renderMenuTiposMovimientos();
    int categoriaId = _categorias.seleccionarPor(tipoMovimiento);
    if (categoriaId != -1) _movimientos.agregarA(billeteraId, categoriaId);
}

void MovimientosHandler::mostrarPorFecha()
{
    Fecha fecha;
    int dia, mes, anio;
    cout << "Buscar " << _nombre << " por fecha" << endl << endl;
    fecha.cargar();
    
    vector<Movimiento> movimientos = _movimientos.buscarPor(fecha);
    if (movimientos.empty()) mostrarMensaje("No se encontraron movimientos para esa fecha", 15, 4);
    else {
        cout << endl << endl;
        cout << "Buscar " << _nombre << " por fecha" << endl << endl;
        _movimientos.mostrarRegistrosPor(movimientos, _billeteraElegida.getId());
    }
}

void MovimientosHandler::mostrarPorRangoMontos()
{
    float montoMin, montoMax;
    cout << "Buscar " << _nombre << " por rango de montos" << endl << endl;
    montoMin = movimientoMontoMin();
    montoMax = movimientoMontoMax();

    vector<Movimiento> movimientos = _movimientos.buscarPor(montoMin, montoMax);
    if (movimientos.empty()) mostrarMensaje("No se encontraron movimientos dentro de ese rango de montos", 15, 4);
    else {
        cout << endl << endl;
        cout << "Buscar " << _nombre << " por rango de montos" << endl << endl;
        _movimientos.mostrarRegistrosPor(movimientos, _billeteraElegida.getId());
    }
}

void MovimientosHandler::mostrarPorMonto()
{
    float monto;
    cout << "Buscar " << _nombre << " por monto" << endl << endl;
    monto = ingresoMonto();

    vector<Movimiento> movimientos = _movimientos.buscarPor(monto);
    if (movimientos.empty()) mostrarMensaje("No se encontraron movimientos por ese monto", 15, 4);
    else {
        cout << endl << endl;
        cout << "Buscar " << _nombre << " por monto" << endl << endl;
        _movimientos.mostrarRegistrosPor(movimientos, _billeteraElegida.getId());
    }
}

void MovimientosHandler::mostrarPorMesYAnio()
{
    int mes, anio;
    bool ok = false;
    cout << "Listar " << _nombre << " por mes y a�o" << endl << endl;
    mes = ingresoMes();
    anio = ingresoAnio();

    vector<Movimiento> movimientos = _movimientos.buscarPor(mes, anio);
    if (movimientos.empty()) mostrarMensaje("No se encontraron movimientos para ese mes y a�o", 15, 4);
    else {
        cout << endl << endl;
        cout << "Listar " << _nombre << " por mes y a�o" << endl << endl;
        _movimientos.mostrarRegistrosPor(movimientos, _billeteraElegida.getId());
    }
}

void MovimientosHandler::mostrarPorCategoria()
{
    int categoriaId;
    cout << "Listar " << _nombre << " por categor�a" << endl << endl;
    int tipoMovimiento = renderMenuTiposMovimientos();
    categoriaId = _categorias.seleccionarPor(tipoMovimiento);

    vector<Movimiento> movimientos = _movimientos.buscarPor(categoriaId);
    if (movimientos.empty()) mostrarMensaje("No se encontraron movimientos para esa categor�a", 15, 4);
    else {
        cout << endl << endl;
        cout << "Listar " << _nombre << " por categoria" << endl << endl;
        _movimientos.mostrarRegistrosPor(movimientos, _billeteraElegida.getId());
    }
}
