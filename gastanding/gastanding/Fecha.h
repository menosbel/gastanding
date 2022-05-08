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
	void setDia(int valor);
	void setMes(int valor);
	void setAnio(int valor);
	void mostrar();
	void cargar();
	void dia_semana();
};

