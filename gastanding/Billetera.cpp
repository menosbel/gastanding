#include "Billetera.h"
#include "tables.h"
#include <iostream>
using namespace std;

void Billetera::cargar(int nextId)
{
	string nombre;
	cout << "Nombre: ";
	cin.ignore();
	getline(cin, nombre);
	setNombre(nombre);
	setEstado(true);
	setId(nextId);
}

void Billetera::mostrar()
{
	const int numWidth = 10;
	const int nameWidth = 30;
	printElement(getId(), numWidth);
	printElement(getNombre(), nameWidth);
}

bool Billetera::equals(Billetera otro)
{
	if (getId() == otro.getId()) return true;
	return false;
}

bool Billetera::leerDeDisco(int pos, string fileName)
{
	FILE* p;
	errno_t err;
	const char* file = fileName.c_str();
	err = fopen_s(&p, file, "rb");
	if (err != 0) { return -1; }
	fseek(p, sizeof(Billetera) * pos, 0);
	int leyo = fread(this, sizeof(Billetera), 1, p);
	fclose(p);
	return leyo;
}

bool Billetera::grabarEnDisco(string fileName)
{
	FILE* p;
	errno_t err;
	const char* file = fileName.c_str();
	err = fopen_s(&p, file, "ab");
	if (err != 0) { return -1; }
	int escribio = fwrite(this, sizeof(Billetera), 1, p);
	fclose(p);
	return escribio;
}

bool Billetera::grabarEnDisco(int pos, string fileName)
{
	FILE* p;
	errno_t err;
	const char* file = fileName.c_str();
	err = fopen_s(&p, file, "rb+");
	if (err != 0) { return false; }
	fseek(p, pos * sizeof(Billetera), SEEK_SET);
	bool guardo = fwrite(this, sizeof(Billetera), 1, p);
	fclose(p);
	return guardo;
}
