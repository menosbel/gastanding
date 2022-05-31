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

void CategoriasRepository::eliminar(int tipoMovimiento)
{
    int categoriaId = this->seleccionarPor(tipoMovimiento);
    char caracter;

    mostrarMensaje("�Esta seguro de eliminar esta categoria? S/N", 15, 4);
    cin >> caracter;

    if (caracter == 's' || caracter == 'S')
    {
        if(this->bajaLogica(categoriaId))
            mostrarMensaje("Categoria borrada exitosamente", 15, 2);
        else
            mostrarMensaje("No se pudo borrar esta categoria", 15, 2);
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
        cout << "Eleg� una categor�a: " << endl << endl;
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
        mostrarMensaje("A�n no existe ninguna categor�a. Ten�s que crear una.", 15, 4);
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

bool CategoriasRepository::bajaLogica(int idCategoria)
{
    Categoria aux;
    bool reescribio;

    FILE* p;
    errno_t err;
    err = fopen_s(&p, _nombreArchivo.c_str(), "rb+");
    if (err != 0)
        return false;

    while (fread(&aux, sizeof aux, 1, p))
    {
        if (aux.getId() == idCategoria)
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
