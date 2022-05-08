#include <iostream>
#include "menues.h"
#include "IngresosRepository.h"

using namespace std;


int renderMenuEntidad(string nombre)
{
    int opcion;
    cout << "---" << nombre << "--- " << endl;
    cout << "1. Anadir" << endl;
    cout << "2. Eliminar" << endl;
    cout << "3. Buscar" << endl;
    cout << "4. Listar" << endl;
    cout << "0. Salir" << endl;
    cout << "Ingrese una opcion: ";
    cin >> opcion;
    return opcion;
}

int renderMenuInformes() 
{
    int opcion;
    system("cls");
    cout << "--- INFORMES --- " << endl;
    cout << "1. Balance mensual" << endl;
    cout << "2. Balance anual" << endl;
    cout << "3. Gastos por categoria" << endl;
    cout << "4. Comparacion de gastos interanual por categoria" << endl;
    cout << "5. Escenario simulado de inversiones" << endl;
    cout << "0. Salir" << endl;
    cout << "Ingrese una opcion: ";
    cin >> opcion;
    return opcion;
}

int renderMenuBuscar(string nombre)
{
    int opcion;
    system("cls");
    cout << "--- BUSCAR " << nombre << " --- " << endl;
    cout << "1. Por categoria" << endl;
    cout << "2. Por concepto" << endl;
    cout << "3. Por monto exacto" << endl;
    cout << "4. Por rango de montos" << endl;
    cout << "0. Salir" << endl;
    cout << "Ingrese una opcion: ";
    cin >> opcion;
    return opcion;
}


int renderMenuListas(string nombre)
{
    int opcion;
    system("cls");
    cout << "--- LISTAR " << nombre << " --- " << endl;
    cout << "1. Por mes" << endl;
    cout << "2. Por categoria" << endl;
    cout << "3. Por concepto" << endl;
    cout << "0. Salir" << endl;
    cout << "Ingrese una opcion: ";
    cin >> opcion;
    return opcion;

}

