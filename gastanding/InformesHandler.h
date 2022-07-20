#pragma once
#include "MovimientosRepository.h"
#include "CategoriasRepository.h"
#include <map>


class InformesHandler
{
private:
	MovimientosRepository _movimientos;
	CategoriasRepository _categorias;
public:
	InformesHandler(MovimientosRepository mRepo, CategoriasRepository cRepo) {
		_movimientos = mRepo;
		_categorias = cRepo;
	}
	bool exec();
	void evolucionMovimientos();
	void generarInformeEvolucionMovimientos(int categoriaId, Fecha fechaInicio, Fecha fechaFin);
	void mostrarInformeEvolucionMovimientos(map<int, map<int, double>> montoPorMesYAnio);


};

 