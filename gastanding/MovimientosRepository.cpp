#include "MovimientosRepository.h"
#include "functions.h"
#include "tables.h"
#include "rlutil.h"
#include "Movimiento.h"
#include "Categoria.h"
#include <iostream>

using namespace std;

void MovimientosRepository::agregarA(Billetera billetera, Categoria categoria) 
{
	Movimiento movimiento, aux;
    rlutil::cls();
	movimiento.cargarEn(billetera, categoria);

    int cantRegistros = cantidadRegistros();
    bool existe = false;
    for (int i = 0; i < cantRegistros; i++)
    {
        aux.leerDeDisco(i, _nombreArchivo);
        if (aux.equals(movimiento)) {
            existe = true;
            break;
        };
    }

    if (existe) {
        mostrarMensaje("El movimiento ya existe. No puede volver a agregarse", 15, 4);
    }
    else {
        if (movimiento.grabarEnDisco(_nombreArchivo)) mostrarMensaje("Movimiento agregado exitosamente", 15, 2);
        else mostrarMensaje("No se pudo agregar el movimiento", 15, 4);
    }
};

void MovimientosRepository::eliminar(int pos)
{
    Movimiento aux;
    char confirmacion;
    bool guardo = false;

    aux.leerDeDisco(pos, _nombreArchivo);
    printMovimientosHeader();
    aux.mostrar();
    cout << endl << endl;
    cout << "¿Desea eliminar el registro? (S/N): ";
    cin >> confirmacion;
    if (tolower(confirmacion) == 's') {
        aux.setEstado(false);
        guardo = aux.grabarEnDisco(pos, _nombreArchivo);
    }
    rlutil::cls();
    if (guardo) mostrarMensaje("Registro eliminado exitosamente", 15, 2);
    else mostrarMensaje("Ocurrió un error. El registro no ha sido eliminado", 15, 4);
}

int MovimientosRepository::cantidadRegistros() {
    FILE* p;
    errno_t err;
    err = fopen_s(&p, _nombreArchivo.c_str(), "rb");
    if (err != 0) { return 0; };
    size_t bytes;
    int cant_reg;

    fseek(p, 0, SEEK_END);
    bytes = ftell(p);
    fclose(p);
    cant_reg = bytes / sizeof(Movimiento);
    return cant_reg;
}

int MovimientosRepository::buscarPor(float monto, Fecha fecha, Categoria categoria, string concepto, Billetera billetera)
{
    Movimiento aux;
    int cantRegistros = cantidadRegistros();

    for (int i = 0; i < cantRegistros; i++)
    {
        aux.leerDeDisco(i, _nombreArchivo);
        if (
            aux.getEstado() == true && 
            aux.getMonto() == monto &&
            aux.getFecha().equals(fecha) &&
            aux.getCategoria().equals(categoria) &&
            aux.getConcepto() == concepto &&
            aux.getBilletera().equals(billetera)
            ) {
            return i;
        }
    }
    return -1;
}

vector<int> MovimientosRepository::buscarPor(float monto)
{
    Movimiento aux;
    int cantRegistros = cantidadRegistros();
    vector<int> posiciones;

    for (int i = 0; i < cantRegistros; i++)
    {
        aux.leerDeDisco(i, _nombreArchivo);
        if (aux.getEstado() == true && aux.getMonto() == monto) {
            posiciones.push_back(i);
        }
    }
    return posiciones;
}

vector<int> MovimientosRepository::buscarPor(float montoMin, float montoMax)
{
    Movimiento aux;
    int cantRegistros = cantidadRegistros();
    vector<int> posiciones;

    for (int i = 0; i < cantRegistros; i++)
    {
        aux.leerDeDisco(i, _nombreArchivo);
        if (aux.getEstado() == true) {
            if (aux.getMonto() >= montoMin || aux.getMonto() <= montoMax) {
                posiciones.push_back(i);
            }
        }
    }
    return posiciones;
}

vector<int> MovimientosRepository::buscarPor(Fecha fecha)
{
    Movimiento aux;
    int cantRegistros = cantidadRegistros();
    vector<int> posiciones;

    for (int i = 0; i < cantRegistros; i++)
    {
        aux.leerDeDisco(i, _nombreArchivo);
        if (aux.getEstado() == true && aux.getFecha().equals(fecha)) {
            posiciones.push_back(i);
        }
    }
    return posiciones;
}

vector<int> MovimientosRepository::buscarPor(int mes, int anio)
{
    Movimiento aux;
    int cantRegistros = cantidadRegistros();
    vector<int> posiciones;

    for (int i = 0; i < cantRegistros; i++)
    {
        aux.leerDeDisco(i, _nombreArchivo);
        if (aux.getEstado() == true && aux.getFecha().getAnio() == anio && aux.getFecha().getMes() == mes) {
            posiciones.push_back(i);
        }
    }
    return posiciones;
}

vector<int> MovimientosRepository::buscarPor(Categoria categoria)
{
    Movimiento aux;
    int cantRegistros = cantidadRegistros();
    vector<int> posiciones;

    for (int i = 0; i < cantRegistros; i++)
    {
        aux.leerDeDisco(i, _nombreArchivo);
        if (aux.getEstado() == true && aux.getCategoria().equals(categoria)) {
            posiciones.push_back(i);
        }
    }
    return posiciones;
}

void MovimientosRepository::mostrarRegistrosPor(vector<int> posiciones, Billetera billetera)
{
    Movimiento aux;
    printMovimientosHeader();
    for (int i = 0; i < posiciones.size(); i++)
    {
        aux.leerDeDisco(posiciones[i], _nombreArchivo);
        if (aux.getBilletera().equals(billetera)) {
            aux.mostrar();
            cout << endl;
        }
    }
}