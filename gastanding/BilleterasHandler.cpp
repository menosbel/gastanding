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
            break;

        case 2:
            ingresarABilletera();
            break;

        case 0:
            return false;
            break;

        default:
            break;
        }
        rlutil::anykey();
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
            break;

        case 2:
            _billeteras.eliminar(cantMovimientos);
            break;

        case 3:
            _billeteras.listar(cantMovimientos);
            break;

        case 0:
            return false;
            break;

        default:
            break;
        }
        rlutil::anykey();
    }
}

bool BilleterasHandler::ingresarABilletera()
{
    int opcion;
    bool seguir = true;
    int cantMovimientos = _movimientos.cantidadRegistros();
    
    cout << "Elegí una billetera: " << endl << endl;
    _billeteraElegida = _billeteras.seleccionar(cantMovimientos);

    if (_billeteraElegida.getNombre() != "") 
    {
        while (seguir)
        {
            rlutil::cls();
            opcion = renderMenuDentroDeBilletera(_billeteraElegida.getNombre());
            rlutil::cls();

            switch (opcion)
            {
            case 1:
                _movimientosHandler.agregarMovimientosA(_billeteraElegida.getId());
                break;

            case 2:
                _movimientosHandler.buscarMovimientosEn(_billeteraElegida);
                break;

            case 3:
                _movimientosHandler.hacerTransferencia(_billeteraElegida);
                break;

            case 4:
                _movimientosHandler.consultarSaldo(_billeteraElegida, cantMovimientos);
                break;

            case 0:
                return false;
                break;

            default:
                break;
            }
            rlutil::anykey();
        }
    }
    else 
        return 0;
}


