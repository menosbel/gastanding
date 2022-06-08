#include "InformesHandler.h"
#include "rlutil.h"
#include "menues.h"

using namespace std;

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
            cout << "Balance Mensual" << endl;
            rlutil::anykey();
            
            break;
        case 2:
            cout<<"Balance Anual" << endl;
            rlutil::anykey();
            break;
           
        case 3:
            cout << "Patrimonio neto" << endl;
            rlutil::anykey();
            
            break;
        case 0:
            return false;
            break;

        }
    }
}
