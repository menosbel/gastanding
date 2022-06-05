#include "InformesHandler.h"
#include "rlutil.h"
#include "menues.h"

bool InformesHandler::exec()
{
    int opcion;
    bool seguir = true;

    while (seguir)
    {
        rlutil::cls();
        opcion = renderMenuInformes();
        rlutil::cls();
        switch (opcion)
        {
        case 1:
            rlutil::anykey();
            break;
        case 2:
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
