#include "EgresosRepository.h"
#include "functions.h"
#include "Egreso.h"
#include <iostream>

void EgresosRepository::agregar()
{
    Egreso egreso, aux;
    egreso.cargar();

    int cantEgresos = cantidadRegistros();
    bool existe = false;
    for (int i = 0; i < cantEgresos; i++)
    {
        aux.leerDeDisco(i, _fileName);
        if (aux.equals(egreso)) {
            existe = true;
            break;
        };
    }

    if (existe) {
        mostrarMensaje("El gasto ya existe. No puede volver a agregarse", 15, 4);
    }
    else {
        if (egreso.grabarEnDisco(_fileName)) mostrarMensaje("Gasto agregado exitosamente", 15, 2);
        else mostrarMensaje("No se pudo agregar el gasto", 15, 4);
    }
}

int EgresosRepository::cantidadRegistros() {
    FILE* p;
    errno_t err;
    err = fopen_s(&p, _fileName.c_str(), "rb");
    if (err != 0) { return 0; };
    size_t bytes;
    int cant_reg;

    fseek(p, 0, SEEK_END);
    bytes = ftell(p);
    fclose(p);
    cant_reg = bytes / sizeof(Egreso);
    return cant_reg;
}

int EgresosRepository::buscarPor(float monto, Fecha fecha, int categoria, string concepto, int medioPago)
{
    Egreso aux;
    int cantEgresos = cantidadRegistros();

    for (int i = 0; i < cantEgresos; i++)
    {
        aux.leerDeDisco(i, _fileName);
        if (
            aux.getEstado() == true &&
            aux.getMonto() == monto &&
            aux.getFecha().equals(fecha) &&
            aux.getCategoria() == categoria &&
            aux.getConcepto() == concepto &&
            aux.getMedioPago() == medioPago
            ) {
            return i;
        }
    }
    return -1;
}

vector<int> EgresosRepository::buscarPor(Fecha fecha)
{
    Egreso aux;
    int cantEgresos = cantidadRegistros();
    vector<int> posiciones;

    for (int i = 0; i < cantEgresos; i++)
    {
        aux.leerDeDisco(i, _fileName);
        if (aux.getEstado() == true && aux.getFecha().equals(fecha)) {
            posiciones.push_back(i);
        }
    }
    return posiciones;
}
