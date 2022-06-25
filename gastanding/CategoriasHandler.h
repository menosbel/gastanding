#pragma once
#include "CategoriasRepository.h"
#include <string>
using namespace std;

class CategoriasHandler
{
private:
	string _nombre = "CATEGORIAS";
	CategoriasRepository _categorias;
public:
	CategoriasHandler(CategoriasRepository cRepo) {
		_categorias = cRepo;
	}
	bool exec();
};

