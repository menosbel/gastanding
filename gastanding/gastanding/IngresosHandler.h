#pragma once
#include <string>
#include "IngresosRepository.h"

using namespace std;

class IngresosHandler
{
private:
	string _nombre = "INGRESOS";
	Ingresos _ingresos = Ingresos();
public:
	bool exec();
};

