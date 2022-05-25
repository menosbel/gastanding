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
    cout << "Elegí una categoría" << endl;
    cout << "1. Relación de dependencia" << endl;
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
        cout << "La opción elegida es invalida. Vuelva a intentarlo" << endl << endl;
        opcion = menuCategoriasIngresos();
        rlutil::anykey();
    }
    return opcion;
}

int menuCategoriasEgresos()
{
    int opcion;
    rlutil::cls();
    cout << "Elegí una categoría" << endl;
    cout << "1. Supermercado" << endl;
    cout << "2. Hogar" << endl;
    cout << "3. Personal" << endl;
    cout << "4. Otros" << endl;
    cout << "Ingrese una opción: ";
    cin >> opcion;
    rlutil::cls();
    return opcion;
}

int renderMenuCategoriasEgresos() {
    int opcion;
    opcion = menuCategoriasEgresos();

    while (opcion < 1 || opcion > 4)
    {
        cout << "La opción elegida es invalida. Vuelva a intentarlo" << endl << endl;
        opcion = menuCategoriasEgresos();
        rlutil::anykey();
    }
    return opcion;
}

int menuMediosPago()
{
    int opcion;
    rlutil::cls();
    cout << "Elegí un medio de pago" << endl;
    cout << "1. Efectivo" << endl;
    cout << "2. Tarjeta de débito" << endl;
    cout << "3. Tarjeta de crédito" << endl;
    cout << "4. Otros" << endl << endl;
    cout << "Ingrese una opción: ";
    cin >> opcion;
    rlutil::cls();
    return opcion;
}

int renderMenuMediosPago() {
    int opcion;
    opcion = menuMediosPago();

    while (opcion < 1 || opcion > 4)
    {
        cout << "La opción elegida es invalida. Vuelva a intentarlo" << endl << endl;
        opcion = menuMediosPago();
        rlutil::anykey();
    }
    return opcion;
}
