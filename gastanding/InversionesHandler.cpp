#include "InversionesHandler.h"

bool InversionesHandler::exec()
{
    int opcion;

    while (true)
    {
        opcion = renderMenuEntidad(_nombre);
        switch (opcion)
        {
        case 1:
            _inversion.agregar();
            break;
        default:
            break;
        }
    }
}
