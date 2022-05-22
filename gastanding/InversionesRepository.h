#pragma once
#include <iostream>
#include <string>
#include "Inversion.h"
#include "functions.h"

using namespace std;

class InversionesRepository
{
private:
	string _fileName = "inversiones.dat";
public:
	void agregar();
};

