#include "InformesHandler.h"
#include "rlutil.h"
#include "menues.h"
#include "ingresoDatos.h"
#include "functions.h"
#include "tables.h"
#include "Informes.h"
#include <map>

using namespace std;

bool InformesHandler::exec()
{
    int opcion;
    bool seguir = true;
   

    while (seguir)
    {
        rlutil::cls();
        opcion = renderMenuInformes();
        rlutil::cls();
        Informes Informe;
        switch (opcion)
        {

        case 1:

            Informe.BalanceMensual();
            
            break;
        case 2:

            Informe.BalanceAnual();

            break;
           
        case 3:

            Informe.PatrimonioNeto();
            
            break;
        case 4:

            Informe.TopDeIngresosOGastos();

            break;

        case 5:
        {
            int tipoMovimiento, categoriaId;
            Fecha fechaInicio, fechaFin;
            cout << "Vamos a generar un informe sobre la evolución de tus gastos o ingresos en un rango de tiempo." << endl;
            rlutil::anykey();
            rlutil::cls();
            cout << "Primero, tendrás que seleccionar un tipo de movimiento y una categoría." << endl;
            rlutil::anykey();
            rlutil::cls();
            tipoMovimiento = renderMenuTiposMovimientos();
            categoriaId = _categorias.seleccionarPor(tipoMovimiento);
            rlutil::anykey();
            rlutil::cls();
            cout << "Ahora deberas ingresar un rango de fechas (MM/AAA - MM/AAA) para tu consulta." << endl;
            rlutil::anykey();
            rlutil::cls();
            cout << "FECHA DE INICIO" << endl;
            fechaInicio = ingresoMesAnio();
            cout << "FECHA DE FINALIZACION" << endl;
            fechaFin = ingresoMesAnio();
            rlutil::anykey();
            rlutil::cls();

            generarInformeEvolucionMovimientos(categoriaId, fechaInicio, fechaFin);

            rlutil::anykey();
        }
            break;
        case 0:
            return false;
            break;
        default:
            break;
        }
    }
}

int InformesHandler::calcularMesesEntreFechas(Fecha inicio, Fecha fin)
{
    return (fin.getAnio() - inicio.getAnio()) * 12 + abs(fin.getMes() - inicio.getMes());
}

void InformesHandler::generarInformeEvolucionMovimientos(int categoriaId, Fecha fechaInicio, Fecha fechaFin)
{
    Movimiento movimiento;
    int meses = calcularMesesEntreFechas(fechaInicio, fechaFin);
    vector<Movimiento> movimientos = _movimientos.buscarPor(categoriaId, fechaInicio, fechaFin);

    if (movimientos.empty()) mostrarMensaje("No se encontraron movimientos para esa categoría dentro de ese rango de fechas", 15, 4);
    else {
        // sumar por mes y a;o
        map<string, int> montoPorMesYAnio;
        for (int i = 0; i < movimientos.size(); i++)
        {
            string mes = to_string(movimientos[i].getFecha().getMes());
            string anio = to_string(movimientos[i].getFecha().getAnio());
            string mesAnio = mes + "-" + anio;
            if (montoPorMesYAnio.find(mesAnio) == montoPorMesYAnio.end())
            {
                montoPorMesYAnio[mesAnio] = 0;
            }
            montoPorMesYAnio[mesAnio] += movimientos[i].getMonto();
        }

        printInformeEvolucionMovimientosHeader();
        map<string, int>::iterator it =montoPorMesYAnio.begin();

        while (it != montoPorMesYAnio.end())
        {
            string mesAnio = it->first;
            int monto = it->second;
            cout << mesAnio << " :: " << monto << endl;
            it++;
        }

        cout << endl << endl;
    }
}
