#include "base_functions.h"
#include <iomanip>
#include <sstream>
#include <string>

std::string ZeroPadNumber(int num)
{
	std::ostringstream ss;
	ss << std::setw(2) << std::setfill('0') << num;
	return ss.str();
}

std::string categoriasIngresosToString(int num)
{
	switch (num)
	{
	case 1:
		"Relacion de dependencia";
	case 2:
		"Freelance";
	case 3:
		"Otros";
	default:
		break;
	}
	return std::string();
}
