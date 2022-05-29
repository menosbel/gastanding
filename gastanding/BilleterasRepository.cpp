#include "BilleterasRepository.h"
#include "functions.h"
#include "tables.h"

void BilleterasRepository::agregar()
{
    Billetera billetera, aux;
    billetera.cargar();

    int cantRegistros = cantidadRegistros();
    bool existe = false;
    for (int i = 0; i < cantRegistros; i++)
    {
        aux.leerDeDisco(i, _nombreArchivo);
        if (aux.equals(billetera)) {
            existe = true;
            break;
        };
    }

    if (existe) {
        mostrarMensaje("La billetera ya existe. No puede volver a agregarse", 15, 4);
    }
    else {
        if (billetera.grabarEnDisco(_nombreArchivo)) mostrarMensaje("Billetera agregada exitosamente", 15, 2);
        else mostrarMensaje("No se pudo agregar la billetera", 15, 4);
    }
}

void BilleterasRepository::listar()
{
    Billetera aux;
    int cantRegistros = cantidadRegistros();

    printBilleterasHeader();
    for (int i = 0; i < cantRegistros; i++)
    {
        aux.leerDeDisco(i, _nombreArchivo);
        aux.mostrar();
        cout << endl;
    }
}

Billetera BilleterasRepository::seleccionar()
{
    Billetera aux;
    int opcion;
    int cantRegistros = cantidadRegistros();

    for (int i = 0; i < cantRegistros; i++)
    {
        aux.leerDeDisco(i, _nombreArchivo);
        cout << i + 1 << "- " << aux.getNombre() << endl;
        cout << endl;
    }

    cout << "Opcion: ";
    cin >> opcion;

    aux.leerDeDisco(opcion - 1, _nombreArchivo);
    return aux;
}

int BilleterasRepository::cantidadRegistros() {
    FILE* p;
    errno_t err;
    err = fopen_s(&p, _nombreArchivo.c_str(), "rb");
    if (err != 0) { return 0; };
    size_t bytes;
    int cant_reg;

    fseek(p, 0, SEEK_END);
    bytes = ftell(p);
    fclose(p);
    cant_reg = bytes / sizeof(Billetera);
    return cant_reg;
}
