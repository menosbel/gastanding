#pragma once
#include <string>
using namespace std;

class Categoria
{
private:
	bool _estado;
	char _nombre[40];
	int _tipoMovimiento;
public:
	string getNombre() { return string(_nombre); };
	int getTipoMovimiento() { return _tipoMovimiento; };
	string getTipoToString();
	bool getEstado() { return _estado; };
	void setNombre(string valor) { strcpy_s(_nombre, valor.c_str()); };
	void setTipoMovimiento(int valor) { _tipoMovimiento = valor; };
	void setEstado(bool valor) { _estado = valor; };
	void mostrar();
	void cargar();
	bool equals(Categoria otro);
	bool leerDeDisco(int pos, string fileName);
	bool grabarEnDisco(string fileName);
	bool grabarEnDisco(int pos, string fileName);
};

