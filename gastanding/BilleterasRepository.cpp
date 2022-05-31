#include "BilleterasRepository.h"
#include "functions.h"
#include "tables.h"

void BilleterasRepository::agregar()
{
    Billetera billetera, aux;
    int cantRegistros = cantidadRegistros();
    billetera.cargar(cantRegistros + 1);

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

void BilleterasRepository::eliminar()
{
   mostrarMensaje("Seleccione la billetera que desee eliminar", 15, 4);
   Billetera billeteraEliminar = this->seleccionar();
   char caracter;

   mostrarMensaje("¿Esta seguro de eliminar esta billetera? S/N", 15, 4);
   cin >> caracter;

   if (caracter == 's' || caracter == 'S')
   {
       if(this->bajaLogica(billeteraEliminar.getId()))
           mostrarMensaje("Billetera borrada exitosamente", 15, 2);
       else
           mostrarMensaje("No se pudo borrar esta billetera", 15, 2);
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
        if(aux.getEstado())
            aux.mostrar();
        cout << endl;
    }
}

Billetera BilleterasRepository::seleccionar()
{
    Billetera aux;
    int opcion;
    int cantRegistros = cantidadRegistros();

    if (cantRegistros != 0) {
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
    else
    {
        mostrarMensaje("Aún no existe ninguna billetera. Tenés que crear una.", 15, 4);
        return Billetera();
    }
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

bool BilleterasRepository::bajaLogica(int idBilletera)
{
    Billetera aux;
    bool reescribio;

    FILE* p;
    errno_t err;
    err = fopen_s(&p, _nombreArchivo.c_str(), "rb+");
    if (err != 0)  
        return false; 

    while (fread(&aux, sizeof aux, 1, p))
    {
        if (aux.getId() == idBilletera)
        {
            aux.setEstado(false);
            fseek(p, ftell(p) - sizeof aux, 0);
            reescribio = fwrite(&aux, sizeof aux, 1, p);
            fclose(p);
            return reescribio;
        }
    }
    fclose(p);
    return false;
}

