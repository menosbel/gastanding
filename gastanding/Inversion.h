#pragma once
#include <string>
#include "Fecha.h"

using namespace std;

class Inversion
{
private:
	float _monto;
	float _interes;
	char _entidad[40];
	Fecha _fecha_cobro;
	bool _estado;
public:
	float getMonto();
	float getInteres();
	string getEntidad();
	Fecha getFecha();
	bool getEstado();
	
	void setMonto(float monto);
	void setInteres(float interes);
	void setEntidad(string entidad);
	void setFecha();
	void setEstado(bool estado);

	void cargar();
	void mostrar();

	bool leerDeDisco(int pos, string fileName);
	bool grabarEnDisco(string fileName);
};