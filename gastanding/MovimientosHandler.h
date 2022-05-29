#pragma once
#include <string>
#include "MovimientosRepository.h"
#include "CategoriasRepository.h"

using namespace std;

class MovimientosHandler
{
private:
	string _nombre = "MOVIMIENTO";
	Billetera _billeteraElegida;
	MovimientosRepository _movimientos;
	CategoriasRepository _categorias;
public:
	MovimientosHandler() {
		_nombre = "";
		_billeteraElegida = Billetera();
		_movimientos = MovimientosRepository();
		_categorias = CategoriasRepository();
	};
	MovimientosHandler(MovimientosRepository mRepo, CategoriasRepository cRepo) {
		_movimientos = mRepo;
		_categorias = cRepo;
	}
	void agregarMovimientosA(int billeteraId);
	void buscarMovimientosEn(Billetera billetera);
	void mostrarPorFecha();
	void mostrarPorRangoMontos();
	void mostrarPorMonto();
	void mostrarPorMesYAnio();
	void mostrarPorCategoria();
};
