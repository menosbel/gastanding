#pragma once
#include "MovimientosRepository.h"
#include "CategoriasRepository.h"

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
	int calcularMesesEntreFechas(Fecha inicio, Fecha fin);
	void generarInformeEvolucionMovimientos(int categoriaId, Fecha fechaInicio, Fecha fechaFin);
};

 