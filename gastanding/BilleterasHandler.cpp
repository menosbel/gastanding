#include "BilleterasHandler.h"
#include "Billetera.h"
#include "rlutil.h"
#include "menues.h"
#include "functions.h"
#include "BilleterasRepository.h"

bool BilleterasHandler::exec()
{
   
    BilleterasRepository BRepo;
    int opcion;
    bool seguir = true;
    bool HayBill = BRepo.listar();

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


            if (HayBill) {
                ingresarABilletera();

                rlutil::anykey();
            }
            else {
                mostrarMensaje("Aun no hay Billeteras cargadas", 15, 4);
                rlutil::anykey();
            }
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
    BilleterasRepository BRepo;
    int opcion, idBilletera;
    bool seguir = true;
    bool HayBill = BRepo.listar();



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
                if (HayBill) {
                    _billeteras.eliminar();
                    rlutil::anykey();
                }
                else {
                    mostrarMensaje("Aun no hay Billeteras cargadas", 15, 4);
                    rlutil::anykey();
                }

                break;
            case 3:
                if (HayBill) {
                _billeteras.listar();
                rlutil::anykey();
                }
                else {
                    mostrarMensaje("Aun no hay Billeteras cargadas", 15, 4);
                    rlutil::anykey();
                }
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
    
        cout << "Eleg� una billetera: " << endl << endl;
        _billeteraElegida = _billeteras.seleccionar();
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
                    _movimientosHandler.consultarSaldo(_billeteraElegida);
                    rlutil::anykey();
                    break;
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


