#include "Informes.h"
#include <string>
#include "rlutil.h"
#include "Fecha.h"
#include "Billetera.h"
#include "BilleterasRepository.h"
#include "Movimiento.h"
#include "MovimientosRepository.h"
#include "Categoria.h"
#include "CategoriasRepository.h"
#include "functions.h"

using namespace std;

void Informes::Balance30dias()
{
	cout << "Su balance de los ultimos 30 dias es: " << endl;

	double ImporteTotal = 0;
	int ContadorMov = 0;
	int ContadorIng = 0;
	int ContadorGas = 0;

	Fecha Actual;

	int anio = Actual.getAnio();
	int mes = Actual.getMes();
	int dia = Actual.getDia();


	Billetera Billeteras;


	bool RegistraMov = false;

	int i = 0;
	while (Billeteras.leerDeDisco(i, "billeteras.dat"))
	{
		if (Billeteras.getEstado() == true)
		{

			int idB = Billeteras.getId();

			Movimiento Movimientos;

			double contImpGas = 0;
			double contImpIng = 0;
			int cantMovGasto = 0;
			int cantMovIngreso = 0;

			int k = 0;

			while (Movimientos.leerDeDisco(k, "movimientos.dat"))
			{


				int idM = Movimientos.getBilletera();

				Fecha FMov;

				FMov.setDia(Movimientos.getFecha().getDia());
				FMov.setMes(Movimientos.getFecha().getMes());
				FMov.setAnio(Movimientos.getFecha().getAnio());

				if (idM == idB && Movimientos.Ultimos30dias(FMov) == true)
				{
					int CatM = Movimientos.getCategoria();

					Categoria Categorias;
					int TipoDeMov = 0;

					int j = 0;
					while (Categorias.leerDeDisco(j, "categorias.dat"))
					{

						if (CatM == Categorias.getId() && Categorias.getEstado() == true)
						{
							TipoDeMov = Categorias.getTipoMovimiento();
						}
						j++;
					}
					if (TipoDeMov == 1)
					{
						cantMovIngreso++;
						contImpIng += Movimientos.getMonto();
						ImporteTotal += Movimientos.getMonto();
						ContadorMov++;
						ContadorIng++;
						RegistraMov = true;

					}
					else
					{
						cantMovGasto++;
						contImpGas += Movimientos.getMonto();
						ImporteTotal -= Movimientos.getMonto();
						ContadorMov++;
						ContadorGas++;
						RegistraMov = true;
					}


				}

				k++;
			}


			if (RegistraMov == true) {
				cout << "-----------------------------------" << endl;
				cout << "En la billetera: " << Billeteras.getNombre() << endl;
				cout << "* * * * * *" << endl;
				cout << "Registra un total de: $" << contImpIng << endl;
				cout << "Entre : " << cantMovIngreso << " Ingreso/s y" << endl;
				cout << "* * * * * *" << endl;
				cout << "Registra un total de: $" << contImpGas << endl;
				cout << "Entre : " << cantMovGasto << " Gasto/s" << endl;
			}

			else
			{
				cout << "-----------------------------------" << endl;
				cout << "Su billetera:" << Billeteras.getNombre() << endl;
				cout << "No registra movimientos" << endl;
				cout << "-----------------------------------" << endl;
			}
		}
		i++;
		
	}

		cout << "------------------------------------------------------------" << endl;
		cout << "El balance TOTAL de los ultimos 30 dias es de: $" << ImporteTotal << endl;
		cout << "* * * * * *" << endl;
		cout << "Registrado en un total de: " << ContadorMov << " movimientos." << endl;
		cout << "Separados en: " << endl;
		cout << ContadorIng << " ingreso/s" << " y " << ContadorGas << " deuda/s" << endl;
		cout << "------------------------------------------------------------" << endl;

		rlutil::anykey();
}

void Informes::balanceAnual()
{
	int anioOP = 0;
	Fecha fecha;
	cout << "Elija el año del balance: ";
	cin >> anioOP;
	while (anioOP > fecha.getAnio() || anioOP < 1900)
	{
		cout << "Año invalido" << endl;
		cout << "Vuelva a ingresar el año: ";
		cin >> anioOP;
	}
	rlutil::cls;

	double importeTotal = 0;
	int contadorMov = 0;
	int contadorIng = 0;
	int contadorGas = 0;

	Billetera billetera;
	bool registraMov = false;

	int i = 0;
	while (billetera.leerDeDisco(i, "billeteras.dat"))
	{
		if (billetera.getEstado() == true)
		{
			int idB = billetera.getId();

			Movimiento movimiento;

			double contImpGas = 0;
			double contImpIng = 0;
			int cantMovGasto = 0;
			int cantMovIngreso = 0;

			int k = 0;

			while (movimiento.leerDeDisco(k, "movimientos.dat"))
			{
				int idM = movimiento.getBilletera();
				if (idM == idB && movimiento.getFecha().getAnio() == anioOP)
				{
					int catM = movimiento.getCategoria();
					Categoria categoria;
					int tipoDeMov = 0;

					int j = 0;
					while (categoria.leerDeDisco(j, "categorias.dat"))
					{
						if (catM == categoria.getId() && categoria.getEstado() == true)
						{
							tipoDeMov = categoria.getTipoMovimiento();
						}
						j++;
					}
					if (tipoDeMov == 1)
					{
						cantMovIngreso++;
						contImpIng += movimiento.getMonto();
						importeTotal += movimiento.getMonto();
						contadorMov++;
						contadorIng++;
						registraMov = true;

					}
					else
					{
						cantMovGasto++;
						contImpGas += movimiento.getMonto();
						importeTotal -= movimiento.getMonto();
						contadorMov++;
						contadorGas++;
						registraMov = true;
					}
				}
				k++;
			}

			if (registraMov == true) {
				cout << endl;
				string mensaje = "Billetera: " + billetera.getNombre();
				mostrarConColor(mensaje, 5);
				std::cout.imbue(std::locale(std::cout.getloc(), new locate_miles));
				cout << fixed << setprecision(2);
				cout << "Registra un total de $" << contImpIng << " entre" << cantMovIngreso << " ingreso/s y $" << contImpGas << " entre " << cantMovGasto << " gasto/s" << endl;
			}
			else
			{
				string mensaje = "Billetera: " + billetera.getNombre();
				mostrarConColor(mensaje, 5);
				cout << "No registra movimientos en ese año" << endl;
			}
		}
		i++;
	}

	cout << endl << endl;
	cout << "------------------------------------------------------------" << endl;
	cout << "El balance TOTAL del año " << anioOP << " es de $" << importeTotal << endl << endl;
	cout << "Registrado en un total de " << contadorMov << " movimientos." << endl;
	cout << "Separados en " << contadorIng << " ingreso/s" << " y " << contadorGas << " gasto/s" << endl;
	cout << "------------------------------------------------------------" << endl;
	rlutil::anykey();
}

void Informes::patrimonioNeto()
{
	cout << "-------------------------" << endl;
	cout << "     PATRIMONIO NETO     " << endl;
	cout << "-------------------------" << endl;

	double importeTotal = 0;
	int contadorMov = 0;
	int contadorIng = 0;
	int contadorGas = 0;
	int contadorBill = 0;

	Billetera billetera;

	bool registraMov = false;

	int i = 0;
	while (billetera.leerDeDisco(i, "billeteras.dat"))
	{
		if (billetera.getEstado() == true)
		{
			int idB = billetera.getId();
			contadorBill++;

			Movimiento movimiento;

			double contImpGas = 0;
			double contImpIng = 0;
			int cantMovGasto = 0;
			int cantMovIngreso = 0;

			int k = 0;
			while (movimiento.leerDeDisco(k, "movimientos.dat"))
			{
				int idM = movimiento.getBilletera();
				if (idM == idB)
				{
					int catM = movimiento.getCategoria();
					Categoria categoria;
					int tipoDeMov = 0;

					int j = 0;
					while (categoria.leerDeDisco(j, "categorias.dat"))
					{
						if (catM == categoria.getId() && categoria.getEstado() == true)
						{
							tipoDeMov = categoria.getTipoMovimiento();
						}
						j++;
					}
					if (tipoDeMov == 1)
					{
						cantMovIngreso++;
						contImpIng += movimiento.getMonto();
						importeTotal += movimiento.getMonto();
						contadorMov++;
						contadorIng++;
						registraMov = true;

					}
					else
					{
						cantMovGasto++;
						contImpGas += movimiento.getMonto();
						importeTotal -= movimiento.getMonto();
						contadorMov++;
						contadorGas++;
						registraMov = true;
					}
				}
				k++;
			}

			if (registraMov == true) {
				cout << endl;
				string mensaje = "Billetera: " + billetera.getNombre();
				mostrarConColor(mensaje, 5);
				cout << "Registra un total de $";
				std::cout.imbue(std::locale(std::cout.getloc(), new locate_miles));
				cout << fixed << setprecision(2);
				cout << contImpIng << " entre " << cantMovIngreso << " ingreso/s" << endl;
				cout << "Registra un total de $" << contImpGas << " entre " << cantMovGasto << " gasto/s" << endl;
			}
			else
			{
				string mensaje = "Billetera: " + billetera.getNombre();
				mostrarConColor(mensaje, 5);
				cout << "Que no registra ningun movimiento hasta la fecha" << endl;

			}
		}
		i++;
	}
	cout << endl;
	cout << "------------------------------------------------------------" << endl;
	cout << "Siendo su patrimonio neto hasta la fecha: $" << importeTotal << endl;
	cout << "Registrado en: " << contadorMov << " movimientos." << endl;
	cout << "Separados en: " << contadorIng << " ingreso/s" << " y " << contadorGas << " gasto/s" << endl;
	cout << "En un total de " << contadorBill << " billetera/s activas."<<endl;
	cout << "------------------------------------------------------------" << endl;
	rlutil::anykey();
}

void Informes::topDeIngresosOGastos()
{
	cout << "TOP 5 de Ingresos o Gastos" << endl;
	rlutil::anykey();
	int tipo = menuTipoMovimiento(); 

	CategoriasRepository aux("categorias.dat");
	int tam = aux.cantidadRegistrosActivosPorTipo(tipo); 
	
	if (!tam)
	{
		cout << "No hay movimientos ingresados de este tipo";
		rlutil::anykey();

		return;
	}

	Categoria* categorias = new Categoria[tam];
	double* montos = new double[tam];
	
	llenarVectorCategorias(categorias, montos, tam, tipo);
	ordenarVectorCategorias(categorias, montos, tam);
	mostrarVectorCategorias(categorias, montos, tam);

	delete[] categorias;
	delete[] montos;
	rlutil::anykey();
}

void Informes::llenarVectorCategorias(Categoria* vec, double* montos, int tam, int tipo)
{
	Categoria aux;
	Movimiento mov;
	int i = 0, pos = 0;
	bool flag = true;

	for (int i = 0; i < tam; i++)
	{
		montos[i] = 0;
	}
	
	while(aux.leerDeDisco(i++, "categorias.dat"))
	{
		if (aux.getEstado() && aux.getTipoMovimiento() == tipo)
		{
			vec[pos].setEstado(true);
			vec[pos].setId(aux.getId());
			vec[pos].setNombre(aux.getNombre());
			vec[pos].setTipoMovimiento(aux.getTipoMovimiento());
			pos++;
		}
	}

	pos = i = 0;

	while (flag)
	{
		while (mov.leerDeDisco(i++, "movimientos.dat"))
		{
			if (vec[pos].getId() == mov.getCategoria())
			{
				montos[pos] += mov.getMonto();
			}
		}

		i = 0;
		pos++;

		if (pos >= tam)
			flag = false;
	}
}

void Informes::ordenarVectorCategorias(Categoria* vec, double* montos, int tam)
{
	Categoria aux;
	double aux2;

	for (int i = 0; i < tam; i++)
	{
		for (int j = i + 1; j < tam; j++)
		{
			if (montos[j] > montos[i]) 
			{
				aux = vec[j];
				aux2 = montos[j];

				vec[j] = vec[i];
				montos[j] = montos[i];

				vec[i] = aux;
				montos[i] = aux2;
			}
		}
	}
}

void Informes::mostrarVectorCategorias(Categoria* vec, double* montos, int tam)
{
	const int nameWidth = 20;
	const int numWidth = 10;

	printElement("ID", numWidth);
	printElement("Nombre categoria", nameWidth);
	printElement("Monto acumulado", numWidth);
	cout << endl << endl;

	if (tam >= 5)
		tam = 5;

	for (int i = 0; i < tam; i++)
	{
		printElement(vec[i].getId(), numWidth);
		printElement(vec[i].getNombre(), nameWidth);
		printElement(montos[i], nameWidth);
		cout << endl;
	}
}
