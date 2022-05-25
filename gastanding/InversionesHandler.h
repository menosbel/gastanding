#pragma once
#include <string>
#include "InversionesRepository.h"
#include "menues.h"


class InversionesHandler
{
private:
	string _nombre = "INVERSIONES";

	InversionesRepository _inversion_repo;
public:
	bool exec();
};

