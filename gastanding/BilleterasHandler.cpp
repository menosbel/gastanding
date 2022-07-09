#include "BilleterasHandler.h"
#include "Billetera.h"
#include "rlutil.h"
#include "menues.h"
#include "functions.h"

bool BilleterasHandler::exec()
{
    int opcion;
    bool seguir = true;

    while (seguir)
    {
        rlutil::cls();
        opcion = renderMenuBilleteras();
        rlutil::cls();

        switch (opcion)
        {
        case 1:
            gestionarBilleteras();
            rlutil::anykey();
            break;
        case 2:
            ingresarABilletera();
            rlutil::anykey();
            break;
        case 0:
            return false;
            break;
        default:
            break;
        }
    }
}

bool BilleterasHandler::gestionarBilleteras()
{
    int opcion, idBilletera;
    bool seguir = true;
    int cantMovimientos = _movimientos.cantidadRegistros();
    while (seguir)
    {
        rlutil::cls();
        opcion = renderMenuGestionarBilletera();
        rlutil::cls();

        switch (opcion)
        {
        case 1:
            _billeteras.agregar();
            rlutil::anykey();
            break;
        case 2:
            _billeteras.eliminar(cantMovimientos);
            rlutil::anykey();
            break;
        case 3:
            _billeteras.listar(cantMovimientos);
            rlutil::anykey();
            break;
        case 0:
            return false;
            break;
        default:
            break;
        }
    }
    };

bool BilleterasHandler::ingresarABilletera()
{
    int opcion;
    bool seguir = true;
    int cantMovimientos = _movimientos.cantidadRegistros();
    
    cout << "Eleg� una billetera: " << endl << endl;
    _billeteraElegida = _billeteras.seleccionar(cantMovimientos);
    if (_billeteraElegida.getNombre() != "") {
        while (seguir)
        {
            rlutil::cls();
            opcion = renderMenuDentroDeBilletera(_billeteraElegida.getNombre());
            rlutil::cls();
            switch (opcion)
            {
            case 1:
                _movimientosHandler.agregarMovimientosA(_billeteraElegida.getId());
                rlutil::anykey();
                break;
            case 2:
                _movimientosHandler.buscarMovimientosEn(_billeteraElegida);
                rlutil::anykey();
                break;
            case 3:
                _movimientosHandler.hacerTransferencia(_billeteraElegida);
                rlutil::anykey();
                break;
            case 4:
            {
                int cantMovimientos = _movimientos.cantidadRegistros();
                _movimientosHandler.consultarSaldo(_billeteraElegida, cantMovimientos);
                rlutil::anykey();
                break;
            }
            case 0:
                return false;
            default:
                break;
            }
        }
    }
    else {
        return 0;
    }
};


