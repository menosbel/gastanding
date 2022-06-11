#include <iostream>
#include "menues.h"
#include "rlutil.h"
#include "functions.h"

using namespace std;

int renderMenuBilleteras()
{
    int opcion;
    rlutil::cls();
    cout << "------------------------------------" << endl;
    cout << "\t" << "Menu BILLETERAS" << endl;
    cout << "------------------------------------" << endl;
    cout << endl;
    cout << "- 1. Gestionar billeteras" << endl;
    cout << "- 2. Ingresar a una billetera" << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << "- 0. Salir" << endl;
    cout << endl;
    cout << "------------------------------------" << endl;
    cout << "Ingrese una opci�n: ";
    cin >> opcion;
    while (!(opcion >= 0 && opcion <= 2)) {
        cout << "Ingrese una opcion valida" << endl;

        cin >> opcion;
    }
    rlutil::cls();
    return opcion;
}

int renderMenuGestionarBilletera()
{
    int opcion;
    rlutil::cls();
    cout << "------------------------------------" << endl;
    cout << "\t" << "Gestionar BILLETERAS" << endl;
    cout << "------------------------------------" << endl;
    cout << endl;
    cout << "- 1. Agregar billetera" << endl;
    cout << "- 2. Eliminar billetera" << endl;
    cout << "- 3. Listar billeteras disponibles" << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << "- 0. Salir" << endl;
    cout << endl;
    cout << "------------------------------------" << endl;
    cout << "Ingrese una opci�n: ";
    cin >> opcion;
    while (!(opcion >= 0 && opcion <= 3)) {
        cout << "Ingrese una opcion valida" << endl;

        cin >> opcion;
    }
    rlutil::cls();
    return opcion;
}

int renderMenuDentroDeBilletera(string billetera)
{
    int opcion;
    rlutil::cls();
    cout << "------------------------------------" << endl;
    cout << "\t" << billetera << endl;
    cout << "------------------------------------" << endl;
    cout << endl;
    cout << "- 1. Agregar movimiento" << endl;
    cout << "- 2. Buscar movimientos" << endl;
    cout << "- 3. Hacer una transferencia" << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << "- 0. Salir" << endl;
    cout << endl;
    cout << "------------------------------------" << endl;
    cout << "Ingrese una opci�n: ";
    cin >> opcion;
    while (!(opcion >= 0 && opcion <= 3)) {
        cout << "Ingrese una opcion valida" << endl;

        cin >> opcion;
    }
    rlutil::cls();
    return opcion;
}

int renderMenuInformes() 
{
    int opcion;
    rlutil::cls();
    cout << "------------------------------------" << endl;
    cout << "\t" << "INFORMES" << endl;
    cout << "------------------------------------" << endl;
    cout << endl;
    cout << "- 1. Balance mensual" << endl;
    cout << "- 2. Balance anual" << endl;
    cout << "- 3. Patrimonio neto" << endl;
    cout << "- 4. TOP de Ingresos o Gastos" << endl;
    cout << "- 5. Evolucion de Ingresos o Gastos" << endl;
    cout << endl;
    cout << "- 0. Salir" << endl;
    cout << endl;
    cout << "------------------------------------" << endl;
    cout << "Ingrese una opci�n: ";
    cin >> opcion;
    while (!(opcion >= 0 && opcion <= 5)) {
        cout << "Ingrese una opcion valida" << endl;

        cin >> opcion;
    }
        rlutil::cls();
        return opcion;
    }

int renderMenuBuscar()
{
    int opcion;
    rlutil::cls();
    cout << "------------------------------------" << endl;
    cout << "\t" << "BUSCAR MOVIMIENTOS" << endl;
    cout << "------------------------------------" << endl;
    cout << endl;
    cout << "- 1. Por fecha" << endl;
    cout << "- 2. Por mes y a�o" << endl;
    cout << "- 3. Por rango de montos" << endl;
    cout << "- 4. Por monto exacto" << endl;
    cout << "- 5. Por categoria" << endl;
    cout << endl;
    cout << "- 0. Salir" << endl;
    cout << endl;
    cout << "------------------------------------" << endl;
    cout << "Ingrese una opci�n: ";
    cin >> opcion;
    while (!(opcion >= 0 && opcion <= 5)) {
        cout << "Ingrese una opcion valida" << endl;

        cin >> opcion;
    }
    rlutil::cls();
    return opcion;
}

int renderMenuCategorias()
{
    int opcion;
    rlutil::cls();
    cout << "------------------------------------" << endl;
    cout << "\t" << "CATEGORIAS" << endl;
    cout << "------------------------------------" << endl;
    cout << endl;
    cout << "- 1. Agregar categoria" << endl;
    cout << "- 2. Eliminar categoria" << endl;
    cout << "- 3. Listar categorias" << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << "- 0. Salir" << endl;
    cout << endl;
    cout << "------------------------------------" << endl;
    cout << "Ingrese una opci�n: ";
    cin >> opcion;
    while (!(opcion >= 0 && opcion <= 3)) {
        cout << "Ingrese una opcion valida" << endl;

        cin >> opcion;
    }
    rlutil::cls();
    return opcion;
}

int renderMenuTiposMovimientos() {
    int tipo;
    tipo = menuTipoMovimiento();

    while (tipo != 1 && tipo != 2)
    {
        cout << "La opci�n elegida es invalida. Vuelva a intentarlo" << endl << endl;
        tipo = menuTipoMovimiento();
        rlutil::anykey();
    }

    return tipo;
}

int menuTipoMovimiento()
{
    int tipo;
    rlutil::cls();
    cout << "Eleg� un tipo de movimiento" << endl;
    cout << "1. Ingreso" << endl;
    cout << "2. Gasto" << endl;
    cout << "Ingrese una opci�n: ";
    cin >> tipo;
    rlutil::cls();
    return tipo;
}
