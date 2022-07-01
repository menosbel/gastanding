#include <iostream>
#include <string>
#include "rlutil.h"
#include "functions.h"
#include "MovimientosHandler.h"
#include "BilleterasHandler.h"
#include "CategoriasHandler.h"
#include "InformesHandler.h"

using namespace std;

int main()
{
    string billeterasArchivo = "billeteras.dat";
    string movimientosArchivo = "movimientos.dat";
    string categoriasArchivo = "categorias.dat";

    BilleterasRepository billeteras(billeterasArchivo);
    CategoriasRepository categorias(categoriasArchivo);
    MovimientosRepository movimientos(movimientosArchivo, categorias);

    MovimientosHandler movimientosHandler(movimientos, categorias);
    BilleterasHandler billeterasHandler(billeteras, movimientos, categorias, movimientosHandler);
    CategoriasHandler categoriasHandler(categorias);

    InformesHandler informesHandler(movimientos, categorias);

    setlocale(LC_ALL, "spanish");
    rlutil::setColor(rlutil::WHITE);
    mostrarMensaje("** Bienvenidx a Gastanding **", 15, 13);
    rlutil::anykey();

    int opcion;
    char confirmarSalida;
    while (true)
    {
        rlutil::cls();
        cout << "------------------------------------" << endl;
        cout << "\t MENU PRINCIPAL" << endl;
        cout << "------------------------------------" << endl;
        cout << endl;
        cout << "- 1. Billeteras" << endl;
        cout << "- 2. Categorias" << endl;
        cout << "- 3. Informes" << endl;
        cout << endl;
        cout << endl;
        cout << endl;
        cout << "- 0. Salir" << endl;
        cout << endl;
        cout << "------------------------------------" << endl;
        cout << "Ingrese una opci�n: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            billeterasHandler.exec();
            break;
        case 2:
            categoriasHandler.exec();
            break;
        case 3:
            informesHandler.exec();
            break;
        case 0:
            cout << "�Confirma que desea salir? (S/N): ";
            cin >> confirmarSalida;
            if (tolower(confirmarSalida) == 's') {
                rlutil::cls();
                mostrarMensaje("** Muchas gracias por utilizar Gastanding **", 15, 13);
                return 0;
            }
            break;
        default:
                mostrarMensaje("** Ingrese una opcion valida **", 15, 13);
                rlutil::anykey();
            break;
        }
    }
    return 0;
}
