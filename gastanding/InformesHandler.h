#pragma once
#include "MovimientosRepository.h"
#include "CategoriasRepository.h"
#include <map>

class InformesHandler
{
private:
	MovimientosRepository _movimientos;
	CategoriasRepository _categorias;
	BilleterasRepository _billeteras;
public:
	InformesHandler(MovimientosRepository mRepo, CategoriasRepository cRepo, BilleterasRepository bRepo) {
		_movimientos = mRepo;
		_categorias = cRepo;
		_billeteras = bRepo;
	}
	bool exec();
	void evolucionMovimientos();
	void generarInformeEvolucionMovimientos(int categoriaId, Fecha fechaInicio, Fecha fechaFin);
	void mostrarInformeEvolucionMovimientos(map<int, map<int, double>> montoPorMesYAnio);
};

 