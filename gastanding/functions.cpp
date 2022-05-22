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
		return "Categoria inválida";
		break;
	};
}

void mostrarMensaje(string mensaje, int color, int colorFondo, int x, int y) {
	rlutil::locate(x, y);
	rlutil::setColor(color);
	rlutil::setBackgroundColor(colorFondo);
	cout << mensaje << endl;
	rlutil::setBackgroundColor(0);
}
