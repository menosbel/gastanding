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


int Fecha::setDia(int valor)
{
	bool es_mes_largo = std::find(std::begin(_meses_largos), std::end(_meses_largos), _mes) != std::end(_meses_largos);
	
	if (_mes == 2) {
		if (valor >= 1 && valor <= 28) _dia = valor;
		else {
			std::cout << "Numero de dia invalido" << std::endl;
			return 0;
		}
	}
	else if (!es_mes_largo) {
		if (valor >= 1 && valor <= 30) _dia = valor;
		else {
			std::cout << "Numero de dia invalido" << std::endl;
			return 0;
		}
	}
	else {
		if (valor >= 1 && valor <= 31) _dia = valor;
		else {
			std::cout << "Numero de dia invalido" << std::endl;
			return 0;
		}
	}
	return 1;
}

int Fecha::setMes(int valor)
{
	if (valor >= 1 && valor <= 12) _mes = valor;
	else {
		std::cout << "Numero de mes invalido" << std::endl;
		return 0;
	}
	return 1;
}

int Fecha::setAnio(int valor)
{
	int largo_anio = trunc(log10(valor)) + 1;

	if (largo_anio == 4 && valor > 1900) _anio = valor;
	else {
		std::cout << "Numero de año invalido" << std::endl;
		return 0;
	}
	return 1;
}

void Fecha::mostrar()
{
	std::cout << ZeroPadNumber(_dia) << "/" << ZeroPadNumber(_mes) << "/" << _anio << std::endl;
}

void Fecha::cargar()
{
	int dia, mes, anio;
	bool guardo_dia = false;
	bool guardo_mes = false;
	bool guardo_anio = false;

	while (!guardo_dia) {
		std::cout << "Dia: ";
		std::cin >> dia;
		guardo_dia = setDia(dia);
	};

	while (!guardo_mes) {
		std::cout << "Mes: ";
		std::cin >> mes;
		guardo_mes = setMes(mes);
	};

	while (!guardo_anio) {
		std::cout << "Anio: ";
		std::cin >> anio;
		guardo_anio = setAnio(anio);
	};

}
