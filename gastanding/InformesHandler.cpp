#include "InformesHandler.h"
#include "rlutil.h"
#include "menues.h"
#include "ingresoDatos.h"
#include "functions.h"
#include "tables.h"
#include "Informes.h"
#include "BilleterasRepository.h"
#include "CategoriasRepository.h"
#include "MovimientosRepository.h"
#include <iostream>
#include <string>
#include <cstdio>



using namespace std;


bool InformesHandler::exec()
{
    int opcion;
    bool seguir = true;
    BilleterasRepository BRepo;
    CategoriasRepository CRepo;
    bool errorarchivo1 = false;
    bool errorarchivo2 = false;
    bool errorarchivo3 = false;


    if (ExisteArchivo("billeteras.dat")==false) {
        errorarchivo1 = true;
    }else{
        if(BRepo.cantidadRegistrosActivos()<=0)
        {
            errorarchivo1 = true;
        }
    }
    if (ExisteArchivo("categorias.dat") == false) {
        errorarchivo2 = true;
    }
    else {
        if (CRepo.cantidadRegistrosActivos() <= 0)
        {
            errorarchivo2 = true;
        }
    }
  if (ExisteArchivo("movimientos.dat") == false) {
        errorarchivo3 = true;
    }

    if(errorarchivo1==true|| errorarchivo2 == true || errorarchivo3 == true)
    {
            rlutil::cls();
            if (errorarchivo1 == true) {
                cout << endl;
                cout << "-Necesita crear una Billetera" << endl << endl;
            }
            else {
                cout << endl;
                cout << "Ya hay Billeteras activas." << endl << endl;
            }
            if (errorarchivo2 == true) {
                cout << "-Necesita crear una Categoria" << endl << endl;
            }
            else {
                cout << "Ya hay Categorias activas." << endl << endl;
            }
            if (errorarchivo3 == true) {
                cout << "-Necesita registrar algun Movimiento" << endl << endl;
            }
            else {
                cout << "Ya hay Movimientos activos." << endl << endl;
            }
            mostrarMensaje("Los informes se generan con Movimientos de Billeteras y Categor�as activas.", 15, 4);
            rlutil::anykey();
            seguir= false;
    }
        while (seguir)
        {
            rlutil::cls();
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
        return false;
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
    rlutil::cls();
    if (categoriaId == -1)
    {
        mostrarMensaje("A�n no existe ninguna categor�a. Ten�s que crear una.", 15, 4);
    }
    else
    {
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

