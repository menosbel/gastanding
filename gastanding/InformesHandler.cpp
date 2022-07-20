#include "InformesHandler.h"
#include "rlutil.h"
#include "menues.h"
#include "ingresoDatos.h"
#include "functions.h"
#include "tables.h"
#include "Informes.h"

using namespace std;

bool InformesHandler::exec()
{
    int opcion;
    bool seguir = true;

    int cantBilleterasActivas = _billeteras.cantidadRegistrosActivos();
    int cantCategoriasActivas = _categorias.cantidadRegistrosActivos();
    int cantMovimientos = _movimientos.cantidadRegistros();
   

    while (seguir)
    {
        rlutil::cls();

        if (cantBilleterasActivas <= 0 || cantCategoriasActivas <= 0 || cantMovimientos <= 0)
        {
            mostrarMensaje("Para generar un informe, deben existir movimientos, categorias y billeteras", 15, 4);
            seguir = false;
            rlutil::anykey();
        }
        else
        {
            opcion = renderMenuInformes();
            rlutil::cls();
            Informes Informe;
            switch (opcion)
            {
            case 1:
                Informe.Balance30dias();
                break;
            case 2:
                Informe.balanceAnual();
                break;
            case 3:
                Informe.patrimonioNeto();
                break;
            case 4:
                Informe.topDeIngresosOGastos();
                break;
            case 5:
                evolucionMovimientos();
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
}

void InformesHandler::evolucionMovimientos()
{
    int tipoMovimiento, categoriaId;
    Fecha fechaInicio, fechaFin;
    cout << "Vamos a generar un informe sobre la evoluci�n de tus gastos o ingresos en un rango de tiempo." << endl;
    rlutil::anykey();
    rlutil::cls();
    cout << "Primero, tendr�s que seleccionar un tipo de movimiento y una categor�a." << endl;
    rlutil::anykey();
    rlutil::cls();
    tipoMovimiento = renderMenuTiposMovimientos();
    categoriaId = _categorias.seleccionarPor(tipoMovimiento);
    if (categoriaId == -1) return;
    rlutil::cls();
    cout << "Ahora deberas ingresar un rango de fechas para tu consulta." << endl;
    rlutil::anykey();
    rlutil::cls();
    cout << "FECHA DE INICIO" << endl;
    fechaInicio = ingresoMesAnio();
    cout << endl;
    cout << "FECHA DE FINALIZACION" << endl;
    fechaFin = ingresoMesAnio();
    rlutil::cls();

    generarInformeEvolucionMovimientos(categoriaId, fechaInicio, fechaFin);
}

void InformesHandler::generarInformeEvolucionMovimientos(int categoriaId, Fecha fechaInicio, Fecha fechaFin)
{
    Movimiento movimiento;
    vector<Movimiento> movimientos = _movimientos.buscarPor(categoriaId, fechaInicio, fechaFin);

    if (movimientos.empty()) mostrarMensaje("No se encontraron movimientos para esa categor�a dentro de ese rango de fechas", 15, 4);
    else {
        map<int, map<int, double>> montoPorMesYAnio;
        for (int i = 0; i < movimientos.size(); i++)
        {
            int mes = movimientos[i].getFecha().getMes();
            int anio = movimientos[i].getFecha().getAnio();
            montoPorMesYAnio[anio][mes] += movimientos[i].getMonto();
        }    
        mostrarInformeEvolucionMovimientos(montoPorMesYAnio);
    }
}


void InformesHandler::mostrarInformeEvolucionMovimientos(map<int, map<int, double>> montoPorMesYAnio)
{
    printInformeEvolucionMovimientosHeader();
    map<int, map<int, double>>::iterator anioDict = montoPorMesYAnio.begin();

    while (anioDict != montoPorMesYAnio.end())
    {
        int anio = anioDict->first;
        map<int, double> mesMonto = anioDict->second;

        string nuevoAnio = "- " + to_string(anio) + " -";
        printElement(nuevoAnio, 10);
        cout << endl << endl;

        map<int, double>::iterator mesDict = mesMonto.begin();
        while (mesDict != mesMonto.end())
        {
            int mes = mesDict->first;
            int monto = mesDict->second;

            const int width = 10;
            string fecha = ZeroPadNumber(mes) + "/" + to_string(anio);
            printElement(fecha, width);
            cout << fixed;
            cout << setprecision(2);
            printElement(monto, width);
            cout << endl << endl;
            mesDict++;
        }
        anioDict++;
    }

    cout << endl << endl;
}
