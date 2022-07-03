#pragma once
#include <string>
#include "MovimientosRepository.h"
#include "CategoriasRepository.h"
#include"BilleterasRepository.h"

using namespace std;

class MovimientosHandler
{
private:
	string _nombre = "MOVIMIENTO";
	Billetera _billeteraElegida;
	MovimientosRepository _movimientos;
	CategoriasRepository _categorias;
	BilleterasRepository _billeteras;
public:
	MovimientosHandler() {
		_nombre = "";
		_billeteraElegida = Billetera();
		_movimientos = MovimientosRepository();
		_categorias = CategoriasRepository();
		_billeteras = BilleterasRepository();
	};
	MovimientosHandler(MovimientosRepository mRepo, CategoriasRepository cRepo, BilleterasRepository bRepo) {
		_movimientos = mRepo;
		_categorias = cRepo;
		_billeteras = bRepo;
	}
	void agregarMovimientosA(int billeteraId);
	void buscarMovimientosEn(Billetera billetera);
	void hacerTransferencia(Billetera billetera);
	void mostrarPorFecha();
	void mostrarPorRangoMontos();
	void mostrarPorMonto();
	void mostrarPorMesYAnio();
	void mostrarPorCategoria();
};
