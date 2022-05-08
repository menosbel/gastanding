#include <iostream>
#include <string>
#include "menues.h"
#include "IngresosHandler.h"

using namespace std;

int main()
{
    IngresosHandler ingresosHandler;

    int opcion;
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

        string nombre;

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
            return false;
        default:
            break;
        }
        system("cls");
    }
    system("cls");
    cout << "** Muchas gracias por usar Gastanding **" << endl;
    system("pause");

    return 0;
}
