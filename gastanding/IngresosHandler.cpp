#include "IngresosHandler.h"
#include "menues.h"
#include "rlutil.h"
#include "functions.h"
#include "tables.h"

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
            eliminarIngreso();
            break;
        case 3:
            buscarIngresos();
            break;
        case 4:
            listarIngresos();
            break;
        case 0:
            return false;
        default:
            break;
        }
        rlutil::anykey();
        rlutil::cls();
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
}

void IngresosHandler::listarIngresos()
{
    int opcion;
    opcion = renderMenuListas(_nombre);
    rlutil::cls();
    switch (opcion)
    {
    case 1:
        mostrarPorMesYAnio();
        break;
    case 2:
        mostrarPorCategoria();
        break;
    case 0:
        break;
    default:
        break;
    }
}

void IngresosHandler::mostrarRegistrosPor(vector<int> posiciones)
{
    Ingreso aux;
    printIngresosHeader();
    for (int i = 0; i < posiciones.size(); i++)
    {
        aux.leerDeDisco(posiciones[i], _fileName);
        aux.mostrar();
        cout << endl;
    }
}

void IngresosHandler::mostrarPorFecha()
{
    Fecha fecha;
    int dia, mes, anio;
    cout << "Buscar " << _nombre << " por fecha" << endl << endl;
    fecha.cargar();
    cout << endl << endl;
    
    vector<int> posiciones = _ingresos.buscarPor(fecha);
    cout << "Buscar " << _nombre << " por fecha" << endl << endl;
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

    vector<int> posiciones = _ingresos.buscarPor(montoMin, montoMax);
    cout << "Buscar " << _nombre << " por rango de montos" << endl << endl;
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

    vector<int> posiciones = _ingresos.buscarPor(monto);
    cout << "Buscar " << _nombre << " por monto" << endl << endl;
    if (posiciones.empty()) mostrarMensaje("No se encontraron ingresos por ese monto", 15, 4);
    else mostrarRegistrosPor(posiciones);
}

void IngresosHandler::mostrarPorMesYAnio()
{
    int mes, anio;
    bool ok = false;
    cout << "Listar " << _nombre << " por mes y año" << endl << endl;
    
    while (!ok) {
        cout << "Mes (1 al 12): ";
        cin >> mes;
        while (mes < 1 || mes > 12) {
            cout << "Mes inválido. Vuelva a intentar" << endl << endl;
            cout << "Mes (1 al 12): ";
            cin >> mes;
        }
        ok = true;
    }

    ok = false;
    while (!ok) {
        cout << "Año: ";
        cin >> anio;
        int largo_anio = trunc(log10(anio)) + 1;
        while (largo_anio != 4 || anio < 1900) {
            cout << "Año inválido. Vuelva a intentar" << endl << endl;
            cout << "Año: ";
            cin >> anio;
        }
        ok = true;
    }
    cout << endl << endl;

    vector<int> posiciones = _ingresos.listarPor(mes, anio);
    cout << "Listar " << _nombre << " por mes y año" << endl << endl;
    if (posiciones.empty()) mostrarMensaje("No se encontraron ingresos para ese mes y año", 15, 4);
    else mostrarRegistrosPor(posiciones);
}

void IngresosHandler::mostrarPorCategoria()
{
    int categoria;
    cout << "Listar " << _nombre << " por categoría" << endl << endl;
    categoria = renderMenuCategoriasIngresos();

    vector<int> posiciones = _ingresos.listarPor(categoria);
    cout << "Listar " << _nombre << " por categoria" << endl << endl;
    if (posiciones.empty()) mostrarMensaje("No se encontraron ingresos para esa categoría", 15, 4);
    else mostrarRegistrosPor(posiciones);
}

void IngresosHandler::eliminarIngreso()
{
    float monto;
    Fecha fecha;
    int categoria;
    string concepto;
    categoria = renderMenuCategoriasIngresos();
    fecha.cargar();
    cout << "Monto: $";
    cin >> monto;
    cout << "Concepto: ";
    cin >> concepto;
    cout << endl << endl;


    int posicion = _ingresos.buscarPor(monto, fecha, categoria, concepto);
    if (posicion == -1) mostrarMensaje("No se encontró el ingreso", 15, 4);
    else {
        Ingreso aux;
        char confirmacion;
        bool guardo = false;

        aux.leerDeDisco(posicion, _fileName);
        printIngresosHeader();
        aux.mostrar();
        cout << endl << endl;
        cout << "¿Desea eliminar el registro? (S/N): ";
        cin >> confirmacion;
        if (tolower(confirmacion) == 's') {
            aux.setEstado(false);
            guardo = aux.grabarEnDisco(posicion, _fileName);
        }
        rlutil::cls();
        if (guardo) mostrarMensaje("Ingreso eliminado exitosamente", 15, 2);
        else mostrarMensaje("Ocurrió un error. El ingreso no ha sido eliminado", 15, 4);
    }
}
