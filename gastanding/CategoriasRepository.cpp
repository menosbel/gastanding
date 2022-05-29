#include "CategoriasRepository.h"
#include "Categoria.h"
#include "functions.h"
#include "tables.h"

void CategoriasRepository::agregar()
{
    Categoria categoria, aux;
    categoria.cargar();

    int cantRegistros = cantidadRegistros();
    bool existe = false;
    for (int i = 0; i < cantRegistros; i++)
    {
        aux.leerDeDisco(i, _nombreArchivo);
        if (aux.equals(categoria)) {
            existe = true;
            break;
        };
    }

    if (existe) {
        mostrarMensaje("La categoria ya existe. No puede volver a agregarse", 15, 4);
    }
    else {
        if (categoria.grabarEnDisco(_nombreArchivo)) mostrarMensaje("Categoria agregada exitosamente", 15, 2);
        else mostrarMensaje("No se pudo agregar la categoria", 15, 4);
    }
}

void CategoriasRepository::listar(int tipoMovimiento)
{
    Categoria aux;
    int cantRegistros = cantidadRegistros();

    printCategoriasHeader();
    for (int i = 0; i < cantRegistros; i++)
    {
        if (aux.getTipoMovimiento() == tipoMovimiento) {
            aux.leerDeDisco(i, _nombreArchivo);
            aux.mostrar();
            cout << endl;
        }
        aux.leerDeDisco(i, _nombreArchivo);
        aux.mostrar();
        cout << endl;
    }
}

Categoria CategoriasRepository::seleccionarPor(int tipoMovimiento)
{
    Categoria aux;
    int opcion;
    int cantRegistros = cantidadRegistros();

    cout << "Elegí una categoría: " << endl << endl;
    for (int i = 0; i < cantRegistros; i++)
    {
        aux.leerDeDisco(i, _nombreArchivo);
        if (aux.getTipoMovimiento() == tipoMovimiento)
        {
            cout << i + 1 << "- " << aux.getNombre() << endl;
        }

    }
    cout << endl;
    cout << "Opcion: ";
    cin >> opcion;
    aux.leerDeDisco(opcion - 1, _nombreArchivo);
    return aux;
}



int CategoriasRepository::cantidadRegistros() {
    FILE* p;
    errno_t err;
    err = fopen_s(&p, _nombreArchivo.c_str(), "rb");
    if (err != 0) { return 0; };
    size_t bytes;
    int cant_reg;

    fseek(p, 0, SEEK_END);
    bytes = ftell(p);
    fclose(p);
    cant_reg = bytes / sizeof(Categoria);
    return cant_reg;
}