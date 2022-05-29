#include "Categoria.h"
#include "tables.h"
#include "menues.h"
#include <iostream>
using namespace std;

string Categoria::getTipoToString()
{
	switch (getTipoMovimiento())
	{
	case 1:
		return "Ingreso";
	case 2:
		return "Egreso";
	default:
		break;
	};
}

void Categoria::mostrar()
{
	const int nameWidth = 50;
	printElement(getNombre(), nameWidth);
	printElement(getTipoToString(), nameWidth);
}

void Categoria::cargar()
{
	string nombre;
	cout << "Nombre: ";
	cin.ignore();
	getline(cin, nombre);
	
	int tipo = renderMenuTiposMovimientos();
	
	setTipoMovimiento(tipo);
	setNombre(nombre);
	setEstado(true);
}

bool Categoria::equals(Categoria otro)
{
	if (
		getNombre() == otro.getNombre() &&
		getTipoMovimiento() == otro.getTipoMovimiento() &&
		getEstado() == otro.getEstado()
		) return true;
	return false;
}

bool Categoria::leerDeDisco(int pos, string fileName)
{
	FILE* p;
	errno_t err;
	const char* file = fileName.c_str();
	err = fopen_s(&p, file, "rb");
	if (err != 0) { return -1; }
	fseek(p, sizeof(Categoria) * pos, 0);
	int leyo = fread(this, sizeof(Categoria), 1, p);
	fclose(p);
	return leyo;
}

bool Categoria::grabarEnDisco(string fileName)
{
	FILE* p;
	errno_t err;
	const char* file = fileName.c_str();
	err = fopen_s(&p, file, "ab");
	if (err != 0) { return -1; }
	int escribio = fwrite(this, sizeof(Categoria), 1, p);
	fclose(p);
	return escribio;
}

bool Categoria::grabarEnDisco(int pos, string fileName)
{
	FILE* p;
	errno_t err;
	const char* file = fileName.c_str();
	err = fopen_s(&p, file, "rb+");
	if (err != 0) { return false; }
	fseek(p, pos * sizeof(Categoria), SEEK_SET);
	bool guardo = fwrite(this, sizeof(Categoria), 1, p);
	fclose(p);
	return guardo;
}
