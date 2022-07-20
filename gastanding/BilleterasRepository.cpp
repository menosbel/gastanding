#include "BilleterasRepository.h"
#include "MovimientosRepository.h"
#include "Billetera.h"
#include "Movimiento.h"
#include "functions.h"
#include "menues.h"
#include "tables.h"
#include "rlutil.h"

void BilleterasRepository::agregar()
{
	Billetera billetera, aux;
	int cantRegistros = cantidadRegistros();
	billetera.cargar(cantRegistros + 1);

	bool existe = false;
	for (int i = 0; i < cantRegistros; i++)
	{
		aux.leerDeDisco(i, _nombreArchivo);
		
		if (aux.equals(billetera))
		{
			existe = true;
			break;
		}
	}

	if (existe) 
		mostrarMensaje("La billetera ya existe. No puede volver a agregarse", 15, 4);
	
	else if (billetera.grabarEnDisco(_nombreArchivo)) 
		mostrarMensaje("Billetera agregada exitosamente", 15, 2);
	else 
		mostrarMensaje("No se pudo agregar la billetera", 15, 4);
}

void BilleterasRepository::eliminar(int cantMovimientos)
{
	cout << "Seleccione la billetera que desee eliminar:" << endl << endl;
	Billetera billeteraEliminar = seleccionar(cantMovimientos);
	char caracter = 'n';
	bool confirmar = false;
	if (billeteraEliminar.getEstado())
	{
		cout << "¿Esta seguro de eliminar esta billetera? S/N: ";
		cin >> caracter;
		confirmar = confirmarAccion(caracter);
		rlutil::cls();
	}

	if (confirmar)
	{
		if (bajaLogica(billeteraEliminar.getId())) mostrarMensaje("Billetera borrada exitosamente", 15, 2);
		else mostrarMensaje("No se pudo borrar esta billetera", 15, 4);
	}
}

bool BilleterasRepository::listar(int cantMovimientos)
{
	Billetera aux;
	int cantRegistros = cantidadRegistros();
	bool hayBilleterasActivas = false;

	printBilleterasHeader();

	for (int i = 0; i < cantRegistros; i++)
	{
		aux.leerDeDisco(i, _nombreArchivo);

		if (aux.getEstado())
		{
			double saldo = calcularSaldoActual(aux.getId(), cantMovimientos);
			aux.mostrar();
			std::cout.imbue(std::locale(std::cout.getloc(), new locate_miles));
			cout << fixed << setprecision(2);
			cout << "$" << saldo;
			cout << endl;

			hayBilleterasActivas = true;
		}
	}

	if (!hayBilleterasActivas) mostrarMensaje("Aún no se ha ingresado ninguna billetera", 15, 4);
	return hayBilleterasActivas;
}


double BilleterasRepository::calcularSaldoActual(int billeteraId, int cantMovimientos)
{
	double saldoActual = 0;
	Movimiento movimiento;

	for (int i = 0; i < cantMovimientos; i++)
	{
		movimiento.leerDeDisco(i, "movimientos.dat");

		if (movimiento.getBilletera() == billeteraId)
		{
			if (_categorias.esIngreso(movimiento.getCategoria()))
			{
				saldoActual += movimiento.getMonto();
			}
			else if (_categorias.esEgreso(movimiento.getCategoria()))
			{
				saldoActual -= movimiento.getMonto();
			}
		}
	}

	return saldoActual;
}

bool BilleterasRepository::tieneFondos(int billeteraId, double montoATransferir, int cantMovimientos)
{
	double saldoActual = calcularSaldoActual(billeteraId, cantMovimientos);
	
	if ((saldoActual - montoATransferir) >= 0 ) 
		return true;
	
	return false;
}

Billetera BilleterasRepository::seleccionar(int cantMovimientos)
{
	Billetera aux;
	int opcion;
	int cantBilleterasActivas = cantidadRegistrosActivos();
	bool idValido = false;

	if (cantBilleterasActivas > 0)
	{
		listar(cantMovimientos);
		cout << endl << endl;
		while (!idValido)
		{
			cout << "Opcion: ";
			cin >> opcion;

			aux = buscarPor(opcion);
			if (aux.getId() == opcion)
			{
				idValido = true;
				return aux;
			}
			else
			{
				cout << endl;
				cout << "El ID ingresado es inválido." << endl;
				cout << "Por favor, vuelva a intentarlo" << endl << endl;
			}
		}
	}
	else
	{
		mostrarMensaje("Aún no existe ninguna billetera. Tenés que crear una.", 15, 4);
		return aux;
	}
}

int BilleterasRepository::seleccionarTransferencia(int billeteraActualId)
{
	Billetera aux;
	int opcion;
	bool hayBilleterasActivas = false;
	bool ok = false;
	int cantRegistros = cantidadRegistros();

	if (cantRegistros > 0)
	{
		cout << left << setw(10) << setfill(' ') << "ID";
		cout << left << setw(20) << setfill(' ') << "NOMBRE" << endl;

		for (int i = 0; i < cantRegistros; i++)
		{
			aux.leerDeDisco(i, _nombreArchivo);

			if (aux.getEstado() && aux.getId() != billeteraActualId)
			{
				cout << left << setw(10) << setfill(' ') << aux.getId();
				cout << left << setw(20) << setfill(' ') << aux.getNombre() << endl;
			}
		}
		cout << endl << endl;
	}
	else 
		return -1;
	
	cout << "Opcion: ";
	cin >> opcion;

	for (int i = 0; i < cantRegistros; i++)
	{
		aux.leerDeDisco(i, _nombreArchivo);

		if (opcion == billeteraActualId)
			break;

		else if (opcion > cantRegistros)
			break;

		else if (aux.getEstado() && aux.getId() != billeteraActualId)
			ok = true;

		else
			ok = false;
	}

	if (ok) 
		return opcion;
	else 
		return -1;
}

int BilleterasRepository::cantidadRegistros() {
	FILE* p;
	errno_t err;
	err = fopen_s(&p, _nombreArchivo.c_str(), "rb");
	if (err != 0)  return 0; 
	size_t bytes;
	int cant_reg = 0;

	fseek(p, 0, SEEK_END);
	bytes = ftell(p);
	fclose(p);
	cant_reg = bytes / sizeof(Billetera);
	return cant_reg;
}

int BilleterasRepository::cantidadRegistrosActivos()
{
	Billetera obj;
	int cantBilleterasActivas = 0, pos = 0;
	int cantidadBilleteras = cantidadRegistros();
	for (size_t i = 0; i < cantidadBilleteras; i++)
	{
		obj.leerDeDisco(i, _nombreArchivo);
		if (obj.getEstado()) cantBilleterasActivas++;

	}
	return cantBilleterasActivas;
}

Billetera BilleterasRepository::buscarPor(int id)
{
	Billetera aux;
	int pos = 0;
	while (aux.leerDeDisco(pos++, _nombreArchivo))
	{
		if (aux.getId() == id) return aux;
	}
	return aux;
}

bool BilleterasRepository::bajaLogica(int idBilletera)
{
	Billetera aux;
	bool reescribio;

	FILE* p;
	errno_t err;
	err = fopen_s(&p, _nombreArchivo.c_str(), "rb+");
	if (err != 0) return false;

	while (fread(&aux, sizeof aux, 1, p))
	{
		if (aux.getId() == idBilletera)
		{
			aux.setEstado(false);
			fseek(p, ftell(p) - sizeof aux, 0);
			reescribio = fwrite(&aux, sizeof aux, 1, p);
			fclose(p);
			return reescribio;
		}
	}
	fclose(p);
	return false;
}

