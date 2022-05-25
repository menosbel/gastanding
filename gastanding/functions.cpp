#include "functions.h"
#include "rlutil.h"
#include <iomanip>
#include <sstream>
#include <string>

using namespace std;

string ZeroPadNumber(int num)
{
	ostringstream ss;
	ss << setw(2) << setfill('0') << num;
	return ss.str();
}

string categoriasIngresosToString(int num)
{
	switch (num)
	{
	case 1:
		return "Relacion de dependencia";
	case 2:
		return "Freelance";
	case 3:
		return "Otros";
	default:
		return "Categoria inv�lida";
	};
}

std::string categoriasEgresosToString(int num)
{
	switch (num)
	{
	case 1:
		return "Supermercado";
	case 2:
		return "Hogar";
	case 3:
		return "Personal";
	case 4:
		return "Otros";
	default:
		return "Categoria inv�lida";
	};
}

std::string mediosPagoToString(int num)
{
	switch (num)
	{
	case 1:
		return "Efectivo";
	case 2:
		return "Tarjeta de d�bito";
	case 3:
		return "Tarjeta de cr�dito";
	case 4:
		return "Otros";
	default:
		return "Categoria inv�lida";
	};
}

void mostrarMensaje(string mensaje, int color, int colorFondo, int x, int y) {
	rlutil::locate(x, y);
	rlutil::setColor(color);
	rlutil::setBackgroundColor(colorFondo);
	cout << mensaje << endl;
	rlutil::setBackgroundColor(0);
}
