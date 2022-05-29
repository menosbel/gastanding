#include "CategoriasRepository.h"
#include "Categoria.h"
#include "functions.h"
#include "tables.h"

using namespace std;

void CategoriasRepository::agregar()
{
    Categoria categoria, aux;
    int cantRegistros = cantidadRegistros();
    categoria.cargar(cantRegistros + 1);

    bool existe = false;
    for (int i = 0; i < cantRegistros; i++)
    {
        aux.leerDeDisco(i, _nombreArchivo);
        if (aux.equals(categoria)) {
            existe = true;
            break;
        };
    }

    if (existe) mostrarMensaje("La categoria ya existe. No puede volver a agregarse", 15, 4);
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
    }
}

int CategoriasRepository::seleccionarPor(int tipoMovimiento)
{
    Categoria aux;
    int opcion, pos = 0;
    int cantRegistros = cantidadRegistros();

    if (cantRegistros > 0) {
        cout << "Elegí una categoría: " << endl << endl;
        while (aux.leerDeDisco(pos++, _nombreArchivo))
        {
            if (aux.getTipoMovimiento() == tipoMovimiento)
            {
                cout << pos + 1 << "- " << aux.getNombre() << endl;
            }

        }
        cout << endl;
        cout << "Opcion: ";
        cin >> opcion;
        aux.leerDeDisco(opcion - 1, _nombreArchivo);
        return aux.getId();
    }
    else {
        mostrarMensaje("Aún no existe ninguna categoría. Tenés que crear una.", 15, 4);
        return 0;
    }
}

Categoria CategoriasRepository::buscarPor(int id)
{
    Categoria aux;
    int pos = 0;

    while (aux.leerDeDisco(pos++, _nombreArchivo))
    {
        if (aux.getId() == id) return aux;
    }
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