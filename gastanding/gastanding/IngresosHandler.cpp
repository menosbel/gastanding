#include "IngresosHandler.h"
#include "menues.h"
#include "rlutil.h"
#include "base_functions.h"

bool IngresosHandler::exec()
{
    int opcion;
    bool seguir = true;
    while (seguir)
    {
        rlutil::cls();
        opcion = renderMenuEntidad(_nombre);
        rlutil::cls();
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
            switch (opcion)
            {
            case 1:
                break;
            case 2:
                break;
            case 3:
                mostrarPorMonto();
                break;
            case 4:
                break;
            case 0:
                break;
            default:
                break;
            }
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
        rlutil::cls();

    }
}

void IngresosHandler::mostrarPorMonto()
{
    float monto;
    cout << "Monto: ";
    cin >> monto;
    cout << endl << endl;

    vector<int> posiciones;
    posiciones = _ingresos.buscarPor(monto);

    if (posiciones.empty()) mostrarMensaje("No se encontraron ingresos por ese monto", 15, 4);
    else {
        Ingreso aux;

        for (int i = 0; i < posiciones.size(); i++)
        {
            aux.leerDeDisco(i, _fileName);
            aux.mostrar();
            cout << endl;
        }
    }
}
