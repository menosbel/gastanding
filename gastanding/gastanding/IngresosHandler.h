#pragma once
#include <string>
#include "IngresosRepository.h"

using namespace std;

class IngresosHandler
{
private:
	string _nombre = "INGRESOS";
	IngresosRepository _ingresos = IngresosRepository();
public:
	bool exec();
};

