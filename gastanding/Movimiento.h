#pragma once
#include <string>
using namespace std;
#include "Fecha.h"
#include "Categoria.h"
#include "Billetera.h"

class Movimiento
{
private:
	int _id;
	double _monto;
	char _concepto[40];
	int _categoriaId;
	int _billeteraId;
	Fecha _fecha;
	bool _estado;
public:
	int getId() { return _id; };
	double getMonto() { return _monto; };
	string getConcepto() { return string(_concepto); };
	int getBilletera() { return _billeteraId; };
	Fecha getFecha() { return _fecha; };
	int getCategoria() { return _categoriaId; };
	bool getEstado() { return _estado; };
	void setId(int valor) { _id = valor; };
	void setFecha(Fecha fecha) { _fecha = fecha; };
	void setFecha(int dia, int mes, int anio) { 
		_fecha.setDia(dia); 
		_fecha.setMes(mes); 
		_fecha.setAnio(anio); 
	};
	void setMonto(double valor) { _monto = valor; };
	void setConcepto(string valor) { strcpy_s(_concepto, valor.c_str()); };
	void setCategoria(int valor) { _categoriaId = valor; };
	void setBilletera(int valor) { _billeteraId = valor; };
	void setEstado(bool valor) { _estado = valor; };
	
	void cargarEn(int billeteraId, int categoriaId, int nextId);
	void cargarTransferenciaSalida(int id, int billeteraActual, double monto);
	void cargarTransferenciaEntrada(int id, int billeteraDestino, double monto);
	void mostrar(Categoria categoria);
	bool equals(Movimiento otro);
	bool leerDeDisco(int pos, string fileName);
	bool grabarEnDisco(string fileName);
	bool grabarEnDisco(int pos, string fileName);
	bool Ultimos30dias(Fecha fechaMovimiento);
};