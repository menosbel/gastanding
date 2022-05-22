#pragma once
#include <string>
#include <map>
using namespace std;

enum class MenuNames { Ingresos, Egresos, Deudas };

void menuNamesToString(MenuNames nombre) {
	map<MenuNames, string> names;

	names[nombre] = "INGRESOS";
	names[nombre] = "EGRESOS";
	names[nombre] = "DEUDAS";
}
