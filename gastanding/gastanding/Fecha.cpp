#include "Fecha.h"
#include "base_functions.h"
#include <algorithm> // for std::find
#include <iterator> // for std::begin, std::end
#include<cmath>
#include <iostream>
#include <ctime>
#include <string.h>
#include <vector>
#include <sstream>

Fecha::Fecha() {
	time_t rawtime;
	time(&rawtime);

	struct tm timeinfo;
	localtime_s(&timeinfo, &rawtime);

	_anio = timeinfo.tm_year + 1900;
	_mes = timeinfo.tm_mon + 1;
	_dia = timeinfo.tm_mday;
}

Fecha::Fecha(int dia, int mes, int anio) {
	setMes(mes);
	setDia(dia);
	setAnio(anio);
}

Fecha::Fecha(std::string fecha) {
	std::stringstream prueba(fecha);
	std::string segmento;
	std::vector<std::string> segmentos_lista;

	while (std::getline(prueba, segmento, '/'))
	{
		segmentos_lista.push_back(segmento);
	}

	setDia(std::stoi(segmentos_lista[0]));
	setMes(std::stoi(segmentos_lista[1]));
	setAnio(std::stoi(segmentos_lista[2]));
}


void Fecha::setDia(int valor)
{
	bool es_mes_largo = std::find(std::begin(_meses_largos), std::end(_meses_largos), _mes) != std::end(_meses_largos);
	
	if (_mes == 2) {
		if (valor >= 1 && valor <= 28) _dia = valor;
		else std::cout << "Numero de dia invalido" << std::endl;
	}
	else if (!es_mes_largo) {
		if (valor >= 1 && valor <= 30) _dia = valor;
		else std::cout << "Numero de dia invalido" << std::endl;
	}
	else {
		if (valor >= 1 && valor <= 31) _dia = valor;
		else std::cout << "Numero de dia invalido" << std::endl;
	}
}

void Fecha::setMes(int valor)
{
	if (valor >= 1 && valor <= 12) _mes = valor;
	else std::cout << "Numero de mes invalido" << std::endl;
}

void Fecha::setAnio(int valor)
{
	int largo_anio = trunc(log10(valor)) + 1;

	if (largo_anio == 4 && valor > 1900) _anio = valor;
	else std::cout << "Numero de año invalido" << std::endl;
}

void Fecha::mostrar()
{
	std::cout << ZeroPadNumber(_dia) << "/" << ZeroPadNumber(_mes) << "/" << _anio << std::endl;
}

void Fecha::cargar()
{
	std::cout << "Fecha de nacimiento" << std::endl;
	std::cout << "Dia: ";
	std::cin >> _dia;
	std::cout << "Mes: ";
	std::cin >> _mes;
	std::cout << "Año: ";
	std::cin >> _anio;

}

void Fecha::dia_semana()
{
	
}

