#include "IngresosHandler.h"
#include "menues.h"
#include "rlutil.h"
#include "functions.h"

bool IngresosHandler::exec()
{
    int opcion;
    bool seguir = true;

    while (seguir)
    {
        rlutil::cls();
        opcion = renderMenuEntidad(_nombre);
        rlutil::cls();
        switch (opcion)
        {
        case 1:
            _ingresos.agregar();
            break;
        case 2:
            _ingresos.eliminar();
            break;
        case 3:
            buscarIngresos();
            break;
        case 4:
            opcion = renderMenuListas(_nombre);
            break;
        case 0:
            return false;
        default:
            break;
        }
        rlutil::cls();
    }
}

void IngresosHandler::mostrarRegistrosPor(vector<int> posiciones)
{
    Ingreso aux;

    for (int i = 0; i < posiciones.size(); i++)
    {
        aux.leerDeDisco(i, _fileName);
        aux.mostrar();
        cout << endl;
    }
}

void IngresosHandler::buscarIngresos()
{
    int opcion;
    opcion = renderMenuBuscar(_nombre);
    rlutil::cls();
    switch (opcion)
    {
    case 1:
        mostrarPorFecha();
        break;
    case 2:
        mostrarPorRangoMontos();
        break;
    case 3:
        mostrarPorMonto();
        break;
    case 0:
        break;
    default:
        break;
    }
    rlutil::anykey();
    rlutil::cls();
}

void IngresosHandler::mostrarPorFecha()
{
    Fecha fecha;
    int dia, mes, anio;
    cout << "Buscar " << _nombre << " por categoría" << endl << endl;
    fecha.cargar();
    cout << endl << endl;
    
    vector<int> posiciones;
    posiciones = _ingresos.buscarPor(fecha);

    if (posiciones.empty()) mostrarMensaje("No se encontraron ingresos para esa fecha", 15, 4);
    else mostrarRegistrosPor(posiciones);
}

void IngresosHandler::mostrarPorRangoMontos()
{
    float montoMin, montoMax;
    cout << "Buscar " << _nombre << " por rango de montos" << endl << endl;
    cout << "Monto mínimo: ";
    cin >> montoMin;
    cout << "Monto máximo: ";
    cin >> montoMax;
    cout << endl << endl;

    vector<int> posiciones;
    posiciones = _ingresos.buscarPor(montoMin, montoMax);

    if (posiciones.empty()) mostrarMensaje("No se encontraron ingresos dentro de ese rango de montos", 15, 4);
    else mostrarRegistrosPor(posiciones);
}

void IngresosHandler::mostrarPorMonto()
{
    float monto;
    cout << "Buscar " << _nombre << " por monto" << endl << endl;
    cout << "Monto: ";
    cin >> monto;
    cout << endl << endl;

    vector<int> posiciones;
    posiciones = _ingresos.buscarPor(monto);

    if (posiciones.empty()) mostrarMensaje("No se encontraron ingresos por ese monto", 15, 4);
    else mostrarRegistrosPor(posiciones);
}
