#pragma once
#include <iostream>
#include <string>
#include "Fecha.h"
#include "tables.h"

using namespace std;

class Inversion
{
private:
	float _monto;
	float _interes;
	char _entidad[40];
	Fecha _fecha_cobro;
	bool _estado;
	float _monto_final;

	void setMontoFinal(float monto, float interes);
public:
	void cargar();
	void mostrar();

	bool leerDeDisco(int pos, string fileName);
	bool grabarEnDisco(string fileName);

	float getMonto();
	float getInteres();
	string getEntidad();
	Fecha getFecha();
	float getMontoFinal();
	bool getEstado();
	
	void setMonto(float monto);
	void setInteres(float interes);
	void setEntidad(string entidad);
	void setFecha();
	void setEstado(bool estado);
};