#include <iostream>
#include "menues.h"
#include "IngresosRepository.h"
#include "rlutil.h"

using namespace std;


int renderMenuEntidad(string nombre)
{
    int opcion;
    rlutil::cls();
    cout << "---" << nombre << "--- " << endl;
    cout << "1. A�adir" << endl;
    cout << "2. Eliminar" << endl;
    cout << "3. Buscar" << endl;
    cout << "4. Listar" << endl;
    cout << "0. Salir" << endl;
    cout << "Ingrese una opci�n: ";
    cin >> opcion;
    rlutil::cls();
    return opcion;
}

int renderMenuInformes() 
{
    int opcion;
    rlutil::cls();
    cout << "--- INFORMES --- " << endl;
    cout << "1. Balance mensual" << endl;
    cout << "2. Balance anual" << endl;
    cout << "3. Gastos por categor�a" << endl;
    cout << "4. Comparaci�n de gastos interanual por categor�a" << endl;
    cout << "5. Escenario simulado de inversiones" << endl;
    cout << "0. Salir" << endl << endl;
    cout << "Ingrese una opci�n: ";
    cin >> opcion;
    rlutil::cls();
    return opcion;
}

int renderMenuBuscar(string nombre)
{
    int opcion;
    rlutil::cls();
    cout << "--- BUSCAR " << nombre << " --- " << endl;
    cout << "1. Por categor�a" << endl;
    cout << "2. Por concepto" << endl;
    cout << "3. Por monto exacto" << endl;
    cout << "4. Por rango de montos" << endl;
    cout << "0. Salir" << endl << endl;
    cout << "Ingrese una opci�n: ";
    cin >> opcion;
    rlutil::cls();
    return opcion;
}


int renderMenuListas(string nombre)
{
    int opcion;
    rlutil::cls();
    cout << "--- LISTAR " << nombre << " --- " << endl;
    cout << "1. Por mes" << endl;
    cout << "2. Por categor�a" << endl;
    cout << "3. Por concepto" << endl;
    cout << "0. Salir" << endl << endl;
    cout << "Ingrese una opci�n: ";
    cin >> opcion;
    rlutil::cls();
    return opcion;
}


int renderMenuCategoriasIngresos() {
    int opcion;
    rlutil::cls();
    cout << "Elegi una categoria" << endl;
    cout << "1. Relacion de dependencia" << endl;
    cout << "2. Freelance" << endl;
    cout << "3. Otros" << endl << endl;
    cout << "Ingrese una opci�n: ";
    cin >> opcion;
    rlutil::cls();
    return opcion;
}
