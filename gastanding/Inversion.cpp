#include "Inversion.h"

float Inversion::getMonto()
{
	return _monto;
}

float Inversion::getInteres()
{
	return _interes;
}

string Inversion::getEntidad()
{
	return string(_entidad);
}

Fecha Inversion::getFecha()
{
	return _fecha_cobro;
}

bool Inversion::getEstado()
{
	return _estado;
}

void Inversion::setMonto(float monto)
{
	_monto = monto;
}

void Inversion::setInteres(float interes)
{
	_interes = interes;
}

void Inversion::setEntidad(string entidad)
{
	strcpy_s(_entidad, entidad.c_str());
}

void Inversion::setFecha()
{
	_fecha_cobro.cargar();
}

void Inversion::setEstado(bool estado)
{
	_estado = estado;
}

void Inversion::cargar()
{
}

void Inversion::mostrar()
{
}

bool Inversion::leerDeDisco(int pos, string fileName)
{
	return false;
}

bool Inversion::grabarEnDisco(string fileName)
{
	return false;
}
