#include "Inversion.h"

void Inversion::cargar()
{
	float monto, interes;
	string entidad;

	cout << "Monto invertido: $";
	cin >> monto;
	this->setMonto(monto);

	cout << "Tasa de interes: %";
	cin >> interes;
	this->setInteres(interes);

	_fecha_cobro.cargar();

	cout << "Entidad: ";
	cin.ignore();
	getline(cin, entidad);
	cin.ignore();
	this->setEntidad(entidad);

	setEstado(true);
}

void Inversion::mostrar()
{
	const int nameWidth = 30;
	const int numWidth = 15;

	printElement(_monto, numWidth);
	printElement(_interes, numWidth);
	printElement(_entidad, nameWidth);
	printElement(_fecha_cobro.toString(), numWidth);
}

bool Inversion::grabarEnDisco(string fileName)
{
	char* file = new char[fileName.length() + 1]; 
	strcpy_s(file, fileName.length() + 1, fileName.c_str());

	FILE* p;
	errno_t err = fopen_s(&p, file, "ab");
	if (err != 0) 
		return false;

	bool guardo = fwrite(this, sizeof(Inversion), 1, p);
	fclose(p);

	delete[] file;

	return guardo;
}

bool Inversion::leerDeDisco(int pos, string fileName)
{
	char* file = new char[fileName.length() + 1];
	strcpy_s(file, fileName.length() + 1, fileName.c_str());

	FILE* p;
	errno_t err = fopen_s(&p, file, "ab");
	if (err != 0)
		return false;

	fseek(p, sizeof(Inversion) * pos, 0);
	int leyo = fread(this, sizeof(Inversion), 1, p);
	fclose(p);

	delete[] file;
	return leyo;
}

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
	strcpy_s(_entidad, 40, entidad.c_str());
}

void Inversion::setFecha()
{
	_fecha_cobro.cargar();
}

void Inversion::setEstado(bool estado)
{
	_estado = estado;
}
