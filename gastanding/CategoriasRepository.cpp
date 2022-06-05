#include "CategoriasRepository.h"
#include "Categoria.h"
#include "functions.h"
#include "tables.h"
#include "rlutil.h"

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
	cout << "Seleccione la categoría que desee eliminar: " << endl;
	int categoriaId = seleccionarPor(tipoMovimiento);
	char caracter = 'n';

	cout << "¿Esta seguro de eliminar esta categoria? S/N: ";
	cin >> caracter;

	rlutil::cls();

	if (tolower(caracter) == 's')
	{
		if (bajaLogica(categoriaId))
			mostrarMensaje("Categoria borradada exitosamente", 15, 2);
		else
			mostrarMensaje("No se pudo borrar esta categoria", 15, 4);
	}
	else
		return;
}

void CategoriasRepository::listar(int tipoMovimiento)
{
	Categoria aux;
	int cantRegistros = cantidadRegistros();
	bool hayCategoriasActivas = false;

	printCategoriasHeader();
	for (int i = 0; i < cantRegistros; i++)
	{
		aux.leerDeDisco(i, _nombreArchivo);

		if (aux.getTipoMovimiento() == tipoMovimiento)
		{
			if (aux.getEstado())
			{
				aux.mostrar();
				cout << endl;
				hayCategoriasActivas = true;
			}
		}

	}

	if (!hayCategoriasActivas) 
		mostrarMensaje("Aún no se ha ingresado ninguna categoría", 15, 4);
}

int CategoriasRepository::seleccionarPor(int tipoMovimiento)
{
	Categoria aux;
	int opcion, pos = 0;
	int cantRegistros = cantidadRegistros();
	bool hayCategoriasActivas = false;

	if (cantRegistros > 0) {
		cout << "Elegí una categoría: " << endl << endl;

		while (aux.leerDeDisco(pos++, _nombreArchivo))
		{
			if (aux.getEstado())
			{
				if (aux.getTipoMovimiento() == tipoMovimiento)
				{
					cout << pos + 1 << "- " << aux.getNombre() << endl;
				}

				hayCategoriasActivas = true;
			}
		}
	}

	if (hayCategoriasActivas)
	{
		cout << endl << "Opcion: ";
		cin >> opcion;

		aux.leerDeDisco(opcion - 1, _nombreArchivo);
		return aux.getId();
	}
	else
	{
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
