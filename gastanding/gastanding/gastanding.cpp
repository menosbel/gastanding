#include <iostream>
#include <string>
#include "menues.h"
#include "IngresosHandler.h"
#include "rlutil.h"
#include "base_functions.h"

using namespace std;

int main()
{
    IngresosHandler ingresosHandler;

    rlutil::setColor(rlutil::WHITE);
    mostrarMensaje("** Bienvenidx a Gastanding **", 15, 13);
    rlutil::anykey();
    rlutil::cls();

    int opcion, confirmarSalida;
    while (true)
    {
        cout << "--- MENU PRINCIPAL ---" << endl;
        cout << "1. Ingresos" << endl;
        cout << "2. Egresos" << endl;
        cout << "3. Deudas" << endl;
        cout << "4. Informes" << endl;
        cout << "0. Salir" << endl;
        cout << "Ingrese una opcion: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            ingresosHandler.exec();
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 0:
            cout << "¿Confirma que desea salir? (S/N): ";
            cin >> confirmarSalida;
            if (tolower(confirmarSalida) == 's') {
                return 0;
            }
            break;
        default:
            break;
        }
        rlutil::cls();
        mostrarMensaje("** Muchas gracias por usar Gastanding **", 15, 13);
    }

    rlutil::anykey();

    return 0;
}
