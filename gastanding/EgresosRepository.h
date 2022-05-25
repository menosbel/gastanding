#pragma once
#include "Egreso.h"
#include <string>
#include <vector>

using namespace std;

class EgresosRepository
{
private:
	string _fileName;
public:
	EgresosRepository(string value) { _fileName = value; };
	void agregar();
	int cantidadRegistros();
	int buscarPor(float monto, Fecha fecha, int categoria, string concepto, int medioPago);
	vector<int> buscarPor(Fecha fecha);

	template<typename T>
	vector<int> nuevoBuscarPor(EgresosProps myEnum, T valor, T valor2 = 0) {
		Egreso aux;
		int cantIngresos = cantidadRegistros();
		vector<int> posiciones;

		for (int i = 0; i < cantIngresos; i++)
		{
			aux.leerDeDisco(i, _fileName);
			if (aux.cumpleCondicion(myEnum, valor, valor2)) {
				posiciones.push_back(i);
			}
		}
		return posiciones;
	};
};

