#include <iostream>
#include "menues.h"
#include "IngresosRepository.h"
#include "rlutil.h"
#include "functions.h"

using namespace std;

int renderMenuEntidad(string nombre)
{
    int opcion;
    rlutil::cls();
    cout << "---------------------------" << endl;
    cout << "\t" << nombre << endl;
    cout << "---------------------------" << endl;
    cout << "1. Añadir" << endl;
    cout << "2. Eliminar" << endl;
    cout << "3. Buscar" << endl;
    cout << "4. Listar" << endl;
    cout << "0. Salir" << endl;
    cout << "Ingrese una opción: ";
    cin >> opcion;
    rlutil::cls();
    return opcion;
}

int renderMenuInformes() 
{
    int opcion;
    rlutil::cls();
    cout << "---------------------------" << endl;
    cout << "\t" << "INFORMES" << endl;
    cout << "---------------------------" << endl;    cout << "1. Balance mensual" << endl;
    cout << "2. Balance anual" << endl;
    cout << "3. Gastos por categoría" << endl;
    cout << "4. Comparación de gastos interanual por categoría" << endl;
    cout << "5. Escenario simulado de inversiones" << endl;
    cout << "0. Salir" << endl << endl;
    cout << "Ingrese una opción: ";
    cin >> opcion;
    rlutil::cls();
    return opcion;
}

int renderMenuBuscar(string nombre)
{
    int opcion;
    rlutil::cls();
    cout << "-------------------------------------" << endl;
    cout << "\t" << "BUSCAR " << nombre << endl;
    cout << "-------------------------------------" << endl;
    cout << "1. Por fecha" << endl;
    cout << "2. Por rango de montos" << endl;
    cout << "3. Por monto exacto" << endl;
    cout << "0. Salir" << endl << endl;
    cout << "Ingrese una opción: ";
    cin >> opcion;
    rlutil::cls();
    return opcion;
}

int renderMenuListas(string nombre)
{
    int opcion;
    rlutil::cls();
    cout << "-------------------------------------" << endl;
    cout << "\t" << "LISTAR " << nombre << endl;
    cout << "-------------------------------------" << endl;
    cout << "1. Por mes y año" << endl;
    cout << "2. Por categoría" << endl;
    cout << "0. Salir" << endl << endl;
    cout << "Ingrese una opción: ";
    cin >> opcion;
    rlutil::cls();
    return opcion;
}

int menuCategoriasIngresos()
{
    int opcion;
    rlutil::cls();
    cout << "Elegi una categoria" << endl;
    cout << "1. Relacion de dependencia" << endl;
    cout << "2. Freelance" << endl;
    cout << "3. Otros" << endl << endl;
    cout << "Ingrese una opción: ";
    cin >> opcion;
    rlutil::cls();
    return opcion;
}

int renderMenuCategoriasIngresos() {
    int opcion;
    opcion = menuCategoriasIngresos();

    while (opcion < 1 || opcion > 3)
    {
        cout << "La opcion elegida es invalida. Vuelva a intentarlo" << endl << endl;
        opcion = menuCategoriasIngresos();
        rlutil::anykey();
    }
    return opcion;
}
