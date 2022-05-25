#pragma once
#include <string>
using namespace std;
#include "Fecha.h"

enum class EgresosProps { Monto, MontoMinMax, Categoria, MedioPago, MesAnio };

class Egreso
{
private:
	float _monto;
	char _concepto[40];
	int _categoria;
	int _medioPago;
	Fecha _fecha;
	bool _estado;
public:
	float getMonto() { return _monto; };
	Fecha getFecha() { return _fecha; };
	int getCategoria() { return _categoria; };
	int getMedioPago() { return _medioPago; };
	string getConcepto() { return string(_concepto); };
	bool getEstado() { return _estado; };
	void setMonto(float valor) { _monto = valor; };
	void setConcepto(string valor) { strcpy_s(_concepto, valor.c_str()); };
	void setCategoria(int valor) { _categoria = valor; };
	void setMedioPago(int valor) { _medioPago = valor; };
	void setEstado(bool valor) { _estado = valor; };
	void cargar();
	void mostrar();
	bool equals(Egreso otro);
	bool leerDeDisco(int pos, string fileName);
	bool grabarEnDisco(string fileName);
	bool grabarEnDisco(int pos, string fileName);

	template<typename Type>
	bool cumpleCondicion(EgresosProps propiedad, Type valor, Type valor2 = 0) {
		switch (propiedad)
		{
		case EgresosProps::Monto:
			return this->getMonto() == valor;
		case EgresosProps::Categoria:
			return this->getCategoria() == valor;
		case EgresosProps::MedioPago:
			return this->getMedioPago() == valor;
		case EgresosProps::MontoMinMax:
			return (this->getMonto() >= valor && this->getMonto() <= valor2);
		case EgresosProps::MesAnio:
			return (this->getFecha().getMes() == valor && this->getFecha().getAnio() <= valor2);
		default:
			break;
		}
	}
};

