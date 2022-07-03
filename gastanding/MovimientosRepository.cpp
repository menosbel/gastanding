#include "MovimientosRepository.h"
#include "functions.h"
#include "tables.h"
#include "rlutil.h"
#include "Movimiento.h"
#include "Categoria.h"
#include <iostream>
#include <algorithm>

using namespace std;

bool MovimientosRepository::agregarA(int billeteraId, int categoriaId) 
{
	Movimiento movimiento;
    int cantRegistros = cantidadRegistros();
	movimiento.cargarEn(billeteraId, categoriaId, cantRegistros + 1);
    rlutil::cls();
    
    bool existe = chequearSiMovimientoExiste(movimiento);
    if (existe)
    {
        mostrarMensaje("El movimiento ya existe. No puede volver a agregarse", 15, 4);
        return false;
    }
    else {
        if (!(_billeteras.buscarPor(billeteraId).getCanBeNeg()) && _categorias.esEgreso(movimiento.getCategoria()))
        {
            double saldoActual = _billeteras.calcularSaldoActual(billeteraId);
            double nuevoSaldo = saldoActual - movimiento.getMonto();
            if (nuevoSaldo < 0)
            {
                mostrarMensaje("Esta billetera no puede tener saldo negativo.", 15, 4);
                return false;
            }
        }

        if (movimiento.grabarEnDisco(_nombreArchivo))
        {
            mostrarMensaje("Movimiento agregado exitosamente", 15, 2);
            return true;
        }
        else
        {
            mostrarMensaje("No se pudo agregar el movimiento", 15, 4);
            return false;
        }
    }
};

void MovimientosRepository::eliminar(int pos)
{
    Movimiento movimiento;
    Categoria categoria;
    char confirmacion;
    bool guardo = false;

    movimiento.leerDeDisco(pos, _nombreArchivo);
    categoria = _categorias.buscarPor(movimiento.getCategoria());
    printMovimientosHeader();
    movimiento.mostrar(categoria);
    cout << endl << endl;
    cout << "¿Desea eliminar el registro? (S/N): ";
    cin >> confirmacion;
    if (tolower(confirmacion) == 's') {
        movimiento.setEstado(false);
        guardo = movimiento.grabarEnDisco(pos, _nombreArchivo);
    }
    rlutil::cls();
    if (guardo) mostrarMensaje("Registro eliminado exitosamente", 15, 2);
    else mostrarMensaje("Ocurrió un error. El registro no ha sido eliminado", 15, 4);
}

void MovimientosRepository::transferir(int billeteraActual, int billeteraDestino, double monto)
{
    Movimiento movimiento;
    int id = cantidadRegistros();

    movimiento.cargarTransferenciaSalida(id + 1, billeteraActual, monto);
    movimiento.grabarEnDisco(_nombreArchivo);
    //creo y guardo el movimiento trasferencia tipo egreso, para la billetera remitente

    movimiento.cargarTransferenciaEntrada(id + 2, billeteraDestino, monto);
    movimiento.grabarEnDisco(_nombreArchivo);
    //same anterior ingreso billetera destinataria

}

int MovimientosRepository::cantidadRegistros() 
{
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

bool MovimientosRepository::chequearSiMovimientoExiste(Movimiento movimiento)
{
    Movimiento aux;
    int cantRegistros = cantidadRegistros();
    for (int i = 0; i < cantRegistros; i++)
    {
        aux.leerDeDisco(i, _nombreArchivo);
        if (aux.equals(movimiento)) {
            return true;
            break;
        };
    }
    return false;
}

int MovimientosRepository::buscarPor(double monto, Fecha fecha, int categoriaId, string concepto, int billeteraId)
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
            aux.getCategoria() == categoriaId &&
            aux.getConcepto() == concepto &&
            aux.getBilletera() == billeteraId
            ) {
            return i;
        }
    }
    return -1;
}

vector<Movimiento> MovimientosRepository::buscarPor(double monto)
{
    Movimiento aux;
    int cantRegistros = cantidadRegistros();
    vector<Movimiento> movimientos;

    for (int i = 0; i < cantRegistros; i++)
    {
        aux.leerDeDisco(i, _nombreArchivo);
        if (aux.getEstado() == true && aux.getMonto() == monto) {
            movimientos.push_back(aux);
        }
    }
    return movimientos;
}

vector<Movimiento> MovimientosRepository::buscarPor(double montoMin, double montoMax)
{
    Movimiento aux;
    int cantRegistros = cantidadRegistros();
    vector<Movimiento> movimientos;

    for (int i = 0; i < cantRegistros; i++)
    {
        aux.leerDeDisco(i, _nombreArchivo);
        if (aux.getEstado() == true) {
            if (aux.getMonto() >= montoMin || aux.getMonto() <= montoMax) {
                movimientos.push_back(aux);
            }
        }
    }
    return movimientos;
}

vector<Movimiento> MovimientosRepository::buscarPor(Fecha fecha)
{
    Movimiento aux;
    int cantRegistros = cantidadRegistros();
    vector<Movimiento> movimientos;

    for (int i = 0; i < cantRegistros; i++)
    {
        aux.leerDeDisco(i, _nombreArchivo);
        if (aux.getEstado() == true && aux.getFecha().equals(fecha)) {
            movimientos.push_back(aux);
        }
    }
    return movimientos;
}

vector<Movimiento> MovimientosRepository::buscarPor(int mes, int anio)
{
    Movimiento aux;
    int cantRegistros = cantidadRegistros();
    vector<Movimiento> movimientos;

    for (int i = 0; i < cantRegistros; i++)
    {
        aux.leerDeDisco(i, _nombreArchivo);
        if (aux.getEstado() == true && aux.getFecha().getAnio() == anio && aux.getFecha().getMes() == mes) {
            movimientos.push_back(aux);
        }
    }
    return movimientos;
}

vector<Movimiento> MovimientosRepository::buscarPor(int categoriaId)
{
    Movimiento aux;
    int cantRegistros = cantidadRegistros();
    vector<Movimiento> movimientos;

    for (int i = 0; i < cantRegistros; i++)
    {
        aux.leerDeDisco(i, _nombreArchivo);
        if (aux.getEstado() == true && aux.getCategoria() == categoriaId) {
            movimientos.push_back(aux);
        }
    }
    return movimientos;
}

vector<Movimiento> MovimientosRepository::buscarPor(int categoriaId, Fecha inicio, Fecha fin)
{
    Movimiento aux;
    int cantRegistros = cantidadRegistros();
    vector<Movimiento> movimientos;

    int anio, mes;
    for (int i = 0; i < cantRegistros; i++)
    {
        aux.leerDeDisco(i, _nombreArchivo);
        if (aux.getEstado() == true && aux.getCategoria() == categoriaId) 
        {
            anio = aux.getFecha().getAnio();
            mes = aux.getFecha().getMes();
            if (anio >= inicio.getAnio() && mes >= inicio.getMes())
            {
                if (anio <= fin.getAnio() && mes <= fin.getMes())
                {
                    movimientos.push_back(aux);

                }
            }
        }
    }
    return movimientos;
}

void MovimientosRepository::mostrarRegistrosPor(vector<Movimiento> movimientos, int billeteraId)
{
    ordenarMovimientos(movimientos);

    Categoria categoria;
    printMovimientosHeader();
    for (int i = 0; i < movimientos.size(); i++)
    {
        if (movimientos[i].getBilletera() == billeteraId) 
        {
            categoria = _categorias.buscarPor(movimientos[i].getCategoria());
            movimientos[i].mostrar(categoria);
            cout << endl;
        }
    }
}

void MovimientosRepository::ordenarMovimientos(vector<Movimiento>& movimientos)
{
    Movimiento aux;
    for (int i = 0; i < movimientos.size() - 1; ++i) {
        for (int j = 0; j < movimientos.size() - i - 1; ++j) {
            if (movimientos.at(j + 1).getFecha() > movimientos.at(j).getFecha())
                std::swap(movimientos.at(j), movimientos.at(j + 1));
        }
    }
}
