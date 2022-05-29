#include "BilleterasHandler.h"
#include "Billetera.h"
#include "rlutil.h"
#include "menues.h"

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
            //eliminar
            rlutil::anykey();
            break;
        case 3:
            _billeteras.listar();
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

bool BilleterasHandler::ingresarABilletera()
{
    int opcion, tipoMovimiento;
    bool seguir = true;

    cout << "Elegí una billetera: " << endl << endl;
    _billeteraElegida = _billeteras.seleccionar();

    while (seguir)
    {
        rlutil::cls();
        opcion = renderMenuDentroDeBilletera(_billeteraElegida.getNombre());
        rlutil::cls();
        switch (opcion)
        {
        case 1:
            tipoMovimiento = renderMenuTiposMovimientos();
            Categoria categoria = _categorias.seleccionarPor(tipoMovimiento);
            _movimientos.agregarA(_billeteraElegida, categoria);
            rlutil::anykey();
            break;
        case 2:
            _movimientosHandler.buscarMovimientosEn(_billeteraElegida);
            rlutil::anykey();
            break;
        case 0:
            // trasnferir
            return false;
            break;
        default:
            break;
        }
    }

}
