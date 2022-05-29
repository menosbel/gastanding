#include "CategoriasHandler.h"
#include "rlutil.h"
#include "menues.h"

bool CategoriasHandler::exec()
{
    int opcion, tipoMovimiento;
    bool seguir = true;

    while (seguir)
    {
        rlutil::cls();
        opcion = renderMenuCategorias();
        rlutil::cls();
        switch (opcion)
        {
        case 1:
            _categorias.agregar();
            rlutil::anykey();
            break;
        case 2:
            //eliminar categoria
            rlutil::anykey();
            break;
        case 3:
            tipoMovimiento = renderMenuTiposMovimientos();
            _categorias.listar(tipoMovimiento);
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
