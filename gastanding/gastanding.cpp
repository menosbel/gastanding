#include <iostream>
#include <string>
#include "rlutil.h"
#include "functions.h"
#include "IngresosHandler.h"

using namespace std;

int main()
{
    IngresosHandler ingresosHandler;

    setlocale(LC_ALL, "spanish");
    rlutil::setColor(rlutil::WHITE);
    mostrarMensaje("** Bienvenidx a Gastanding **", 15, 13);
    rlutil::anykey();

    int opcion;
    char confirmarSalida;
    while (true)
    {
        rlutil::cls();
        cout << "----------------------------------" << endl;
        cout << "\t MENU PRINCIPAL" << endl;
        cout << "----------------------------------" << endl;
        cout << "1. Ingresos" << endl;
        cout << "2. Egresos" << endl;
        cout << "3. Deudas" << endl;
        cout << "4. Informes" << endl;
        cout << "0. Salir" << endl;
        cout << "Ingrese una opción: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            rlutil::setBackgroundColor(1);
            ingresosHandler.exec();
            rlutil::setBackgroundColor(0);
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
                rlutil::cls();
                mostrarMensaje("** Muchas gracias por usar Gastanding **", 15, 13);
                return 0;
            }
            break;
        default:
            break;
        }
    }
    return 0;
}
