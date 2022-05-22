#pragma once
#include <string>
#include "InversionesRepository.h"
#include "menues.h"


class InversionesHandler
{
private:
	string _nombre = "INVERSIONES";
	string _fileName = "inversiones.dat";

	InversionesRepository _inversion;
public:
	bool exec();
};

