#pragma once
#include <string>
using namespace std;

class Billetera
{
private:
	int _id;
	int _estado;
	char _nombre[60];
public:
	int getId() { return _id; };
	string getNombre() { return string(_nombre); };
	bool getEstado() { return _estado; };
	void setId(int valor) { _id = valor; };
	void setNombre(string valor) { strcpy_s(_nombre, valor.c_str()); };
	void setEstado(bool valor) { _estado = valor; };
	
	void cargar(int nextId);
	void mostrar();
	bool equals(Billetera otro);
	bool leerDeDisco(int pos, string fileName);
	bool grabarEnDisco(string fileName);
	bool grabarEnDisco(int pos, string fileName);
};

