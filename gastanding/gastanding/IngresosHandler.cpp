#include "IngresosHandler.h"
#include "menues.h"
#include "rlutil.h"

bool IngresosHandler::exec()
{
    int opcion;
    bool seguir = true;

    while (seguir)
    {
        rlutil::cls();
        opcion = renderMenuEntidad(_nombre);
        switch (opcion)
        {
        case 1:
            _ingresos.agregar();
            break;
        case 2:
            _ingresos.eliminar();
            break;
        case 3:
            opcion = renderMenuBuscar(_nombre);
            break;
        case 4:
            opcion = renderMenuListas(_nombre);
            break;
        case 0:
            return false;
        default:
            break;
        }
        rlutil::anykey();
    }
}