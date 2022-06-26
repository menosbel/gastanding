#pragma once
#include <string>

class Fecha
{
private:
	int _dia;
	int _mes;
	int _anio;

	int _meses_largos[7] = {1, 3, 5, 7, 8, 10, 12};

public:
	Fecha();
	Fecha(int dia, int mes, int anio);
	Fecha(std::string fecha);
	int setDia(int valor);
	int setMes(int valor);
	int setAnio(int valor);
	int getDia() { return _dia; };
	int getMes() { return _mes; };
	int getAnio() { return _anio; };
	void mostrar();
	std::string toString();
	void cargar();
	std::string dia_semana();
	bool equals(Fecha otraFecha);
	bool anioBiciesto(int anio);
};

