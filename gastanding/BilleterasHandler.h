#pragma once
#include "Billetera.h"
#include "BilleterasRepository.h"
#include "MovimientosRepository.h"
#include "MovimientosHandler.h"
#include <string>

using namespace std;

class BilleterasHandler
{
private:
	string _nombre = "BILLETERAS";
	Billetera _billeteraElegida;
	BilleterasRepository _billeteras;
	MovimientosRepository _movimientos;
	CategoriasRepository _categorias;
	MovimientosHandler _movimientosHandler;
public:
	BilleterasHandler(
		BilleterasRepository bRepo,
		MovimientosRepository mRepo,
		CategoriasRepository cRepo,
		MovimientosHandler mHandler
	) {
		_billeteras = bRepo;
		_movimientos = mRepo;
		_categorias = cRepo;
		_movimientosHandler = mHandler;
	}
	bool exec();
	bool gestionarBilleteras();
	bool ingresarABilletera();
};

