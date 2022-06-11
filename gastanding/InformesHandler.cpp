#include "InformesHandler.h"
#include "rlutil.h"
#include "menues.h"
#include "Informes.h"

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
        Informes Informe;
        switch (opcion)
        {

        case 1:

            Informe.BalanceMensual();
            
            break;
        case 2:

            Informe.BalanceAnual();

            break;
           
        case 3:

            Informe.PatrimonioNeto();
            
            break;
        case 4:

            Informe.TopDeIngresosOGastos();

            break;

        case 5:

            Informe.EvolucionDeIngresosOGastos();

            break;
        case 0:
            return false;
            break;

        }
    }
}
