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

void MovimientosHandler::hacerTransferencia(Billetera billetera)
{
    int pos = 0;
    int idATransferir;
    double montoATransferir;
    bool tieneFondos = false;

    if (_billeteras.cantidadRegistrosActivos() > 1)
    {
        cout << "Seleccione una billetera donde transferir: " << endl << endl;
        idATransferir = _billeteras.seleccionarTransferencia(billetera.getId());

        if (idATransferir == -1)
        {
            rlutil::cls();
            mostrarMensaje("El ID ingresado no es valido", 15, 4);

            return;
        }
       
        rlutil::cls();
        cout << endl << endl;

        for (;;) 
        {
            cout << "Monto a transferir: $";

            if (cin >> montoATransferir) 
            {
                if (montoATransferir > 0)
                    break;
                else
                    cout << "Por favor, ingresar un monto válido." << endl << endl;
            }
            else 
            {
                cout << "Por favor, ingresar un monto válido." << endl << endl;
                cin.clear();
                cin.ignore(100, '\n');
            }
        }
        rlutil::cls();

        tieneFondos = _billeteras.tieneFondos(billetera.getId(), montoATransferir, _movimientos.cantidadRegistros());

        if (billetera.getCanBeNeg())
        {
            _movimientos.transferir(billetera.getId(), idATransferir, montoATransferir);
            mostrarMensaje("Transferencia efectuada con exito!", 15, 2);
        }
        else if (montoATransferir > 0 && tieneFondos)
        {
            _movimientos.transferir(billetera.getId(), idATransferir, montoATransferir);
            mostrarMensaje("Transferencia efectuada con exito!", 15, 2);
        }
        else if (montoATransferir < 0)
            mostrarMensaje("El monto debe ser mayor a cero", 15, 4);
        else if (!tieneFondos) 
            mostrarMensaje("Fondos insifucientes", 15, 4);
    }
    else
        mostrarMensaje("No se pueden hacer transferecias, ya que no hay destinatarios activos", 15, 4);
        
    rlutil::anykey();
}

void MovimientosHandler::consultarSaldo(Billetera billetera, int cantMovimientos)
{
    cout << "------------------------------------" << endl;
    cout << "\t" << billetera.getNombre() << endl;
    cout << "------------------------------------" << endl;
    cout << endl << endl;
    cout << "Saldo actual: ";
    std::cout.imbue(std::locale(std::cout.getloc(), new locate_miles));
    cout << fixed << setprecision(2);
    cout << "$" << _billeteras.calcularSaldoActual(billetera.getId(), cantMovimientos);
    cout << endl << endl;
}

void MovimientosHandler::agregarMovimientosA(int billeteraId)
{
    int tipoMovimiento = renderMenuTiposMovimientos();
    int categoriaId = _categorias.seleccionarPor(tipoMovimiento);

    if (categoriaId != -1) 
        _movimientos.agregarA(billeteraId, categoriaId);
}

void MovimientosHandler::mostrarPorFecha()
{
    Fecha fecha;
    int dia, mes, anio;
    cout << "Buscar " << _nombre << " por fecha" << endl << endl;
    fecha.cargar();
    
    vector<Movimiento> movimientos = _movimientos.buscarPor(fecha);
    if (movimientos.empty()) 
        mostrarMensaje("No se encontraron movimientos para esa fecha", 15, 4);
    else 
    {
        cout << endl << endl;
        cout << "Buscar " << _nombre << " por fecha" << endl << endl;
        _movimientos.mostrarRegistrosPor(movimientos, _billeteraElegida.getId());
    }
}

void MovimientosHandler::mostrarPorRangoMontos()
{
    double montoMin, montoMax;
    cout << "Buscar " << _nombre << " por rango de montos" << endl << endl;
    montoMin = movimientoMontoMin();
    montoMax = movimientoMontoMax();

    vector<Movimiento> movimientos = _movimientos.buscarPor(montoMin, montoMax);
    if (movimientos.empty()) 
        mostrarMensaje("No se encontraron movimientos dentro de ese rango de montos", 15, 4);
    else 
    {
        cout << endl << endl;
        cout << "Buscar " << _nombre << " por rango de montos" << endl << endl;
        _movimientos.mostrarRegistrosPor(movimientos, _billeteraElegida.getId());
    }
}

void MovimientosHandler::mostrarPorMonto()
{
    double monto;
    cout << "Buscar " << _nombre << " por monto" << endl << endl;
    monto = ingresoMonto();

    vector<Movimiento> movimientos = _movimientos.buscarPor(monto);
    if (movimientos.empty()) 
        mostrarMensaje("No se encontraron movimientos por ese monto", 15, 4);
    else 
    {
        cout << endl << endl;
        cout << "Buscar " << _nombre << " por monto" << endl << endl;
        _movimientos.mostrarRegistrosPor(movimientos, _billeteraElegida.getId());
    }
}

void MovimientosHandler::mostrarPorMesYAnio()
{
    int mes, anio;
    bool ok = false;
    cout << "Listar " << _nombre << " por mes y año" << endl << endl;
    mes = ingresoMes();
    anio = ingresoAnio();

    vector<Movimiento> movimientos = _movimientos.buscarPor(mes, anio);
    if (movimientos.empty()) 
        mostrarMensaje("No se encontraron movimientos para ese mes y año", 15, 4);
    else 
    {
        cout << endl << endl;
        cout << "Listar " << _nombre << " por mes y año" << endl << endl;
        _movimientos.mostrarRegistrosPor(movimientos, _billeteraElegida.getId());
    }
}

void MovimientosHandler::mostrarPorCategoria()
{
    int categoriaId;
    cout << "Listar " << _nombre << " por categoría" << endl << endl;
    int tipoMovimiento = renderMenuTiposMovimientos();
    categoriaId = _categorias.seleccionarPor(tipoMovimiento);

    vector<Movimiento> movimientos = _movimientos.buscarPor(categoriaId);
    if (movimientos.empty()) 
        mostrarMensaje("No se encontraron movimientos para esa categoría", 15, 4);
    else 
    {
        cout << endl << endl;
        cout << "Listar " << _nombre << " por categoria" << endl << endl;
        _movimientos.mostrarRegistrosPor(movimientos, _billeteraElegida.getId());
    }
}
