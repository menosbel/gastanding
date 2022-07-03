#include "EntradaDatosHandler.h"
#include "Billetera.h"
#include "Movimiento.h"
#include "rlutil.h"
#include "menues.h"

using namespace std;

bool EntradaDatosHandler::exec()
{
    int opcion;
    bool seguir = true;

    while (seguir)
    {
        rlutil::cls();
        opcion = renderMenuEntradaDatos();
        rlutil::cls();
        switch (opcion)
        {
        case 1:
            entradaBilleteras();
            rlutil::anykey();
            break;
        case 2:
            entradaCategorias();
            rlutil::anykey();
            break;
        case 3:
            entradaMovimientos();
            rlutil::anykey();
            break;
        case 0:
            return false;
            break;
        default:
            break;
        }
    }
}

void EntradaDatosHandler::entradaBilleteras()
{
    bool canBeNeg;
    string nombre;
    Billetera billetera;

    int cant;
    cout << "Cantidad a cargar: ";
    cin >> cant;
    cin.ignore();
    for (int i = 0; i < 5; i++)
    {
        cin >> canBeNeg;
        getline(cin, nombre);
        billetera.setId(i + 1);
        billetera.setNombre(nombre);
        billetera.setEstado(true);
        billetera.setCanBeNeg(canBeNeg);
        billetera.grabarEnDisco("billeteras.dat");
    }
}

void EntradaDatosHandler::entradaCategorias()
{
    int cant;
    Categoria categoria;
    string nombre;
    int tipo;

    cout << "Cantidad a cargar: ";
    cin >> cant;
    cin.ignore();
    for (int i = 0; i < cant; i++)
    {
        cin >> tipo;
        getline(cin, nombre);
        categoria.setId(i + 1);
        categoria.setNombre(nombre);
        categoria.setTipoMovimiento(tipo);
        categoria.setEstado(true);
        categoria.grabarEnDisco("categorias.dat");
    }
}

void EntradaDatosHandler::entradaMovimientos()
{
    int cant;
    Movimiento movimiento;
    string concepto;
    int catId, billId, dia, mes, anio;
    double monto;
    string fechaInput;

    cout << "Cantidad a cargar: ";
    cin >> cant;
    cin.ignore();
    for (int i = 0; i < cant; i++)
    {

        cin >> dia;
        cin >> mes;
        cin >> anio;
        movimiento.setFecha(dia, mes, anio);
        cin >> monto;
        cin >> catId;
        cin >> billId;
        getline(cin, concepto);
        movimiento.setCategoria(catId);
        movimiento.setBilletera(billId);
        movimiento.setMonto(monto);
        movimiento.setConcepto(concepto);
        movimiento.setId(i + 1);
        movimiento.setEstado(true);
        movimiento.grabarEnDisco("movimientos.dat");
    }
}
