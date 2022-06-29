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

using namespace std;

void Informes::Balance30dias()
{
	cout << "Su balance de los ultimos 30 dias es: " << endl;
	
	float ImporteTotal = 0;
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

		int idB = Billeteras.getId();

		Movimiento Movimientos;

		float contImpGas = 0;
		float contImpIng = 0;
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
			cout << "Entre : " << cantMovGasto << " Gasto/s"<< endl;
		}

		else
		{
			cout << "-----------------------------------" << endl;
			cout << "Su billetera:" << Billeteras.getNombre() << endl;
			cout << "No registra movimientos" << endl;

		}

	i++;
	}

		cout << "------------------------------------------------------------" << endl;
		cout << "El Balance TOTAL de los ultimos 30 dias es de: $" << ImporteTotal << endl;
		cout << "* * * * * *" << endl;
		cout << "Registrado en un total de: " << ContadorMov << " movimientos." << endl;
		cout << "Separados en: " << endl;
		cout << ContadorIng << " ingreso/s" << " y " << ContadorGas << " deuda/s" << endl;
		cout << "------------------------------------------------------------" << endl;		
		
		rlutil::anykey();
		
}


void Informes::BalanceAnual()
{
	int anioOP = 0;
	Fecha Actual;
		cout << "Elija el año del Balance: " << endl;
		cin >> anioOP;
		while (anioOP > Actual.getAnio() || anioOP < 1990)
		{
			cout << "*Año ingresado no valido*" << endl;
			cout << "Vuelva a ingresar el año: ";
			cin >> anioOP;
		}
		system("cls");

		cout << "Su Balance durante el año " << anioOP << " es..."<<endl;
		float ImporteTotal = 0;
		int ContadorMov = 0;
		int ContadorIng = 0;
		int ContadorGas = 0;


		Billetera Billeteras;


		bool RegistraMov = false;

		int i = 0;
		while (Billeteras.leerDeDisco(i, "billeteras.dat"))
		{

			int idB = Billeteras.getId();

			Movimiento Movimientos;

			float contImpGas = 0;
			float contImpIng = 0;
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
				int diaM=FMov.getDia();
				int mesM=FMov.getMes();
				int anioM= FMov.getAnio();

				if (idM == idB && anioM==anioOP)
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
				cout << "No registra movimientos en ese año" << endl;

			}

			i++;
		}

		cout << "------------------------------------------------------------" << endl;
		cout << "El Balance TOTAL del año "<<anioOP<< " es de: $ " << ImporteTotal << endl;
		cout << "* * * * * *" << endl;
		cout << "Registrado en un total de: " << ContadorMov << " movimientos." << endl;
		cout << "Separados en: " << endl;
		cout << ContadorIng << " ingreso/s" << " y " << ContadorGas << " deuda/s" << endl;
		cout << "------------------------------------------------------------" << endl;

		rlutil::anykey();

}

void Informes::PatrimonioNeto()
{
	cout << "------------------------------------------------------------" << endl;
	cout << "-----PATRIMONIO NETO-----" << endl;
	cout << "Separado por billeteras: " << endl;
	cout << "------------------------------------------------------------" << endl;

	float ImporteTotal = 0;
	int ContadorMov = 0;
	int ContadorIng = 0;
	int ContadorGas = 0;
	int ContadorBill = 0;


	Billetera Billeteras;


	bool RegistraMov = false;

	int i = 0;
	while (Billeteras.leerDeDisco(i, "billeteras.dat"))
	{

		int idB = Billeteras.getId();
		ContadorBill++;

		Movimiento Movimientos;

		float contImpGas = 0;
		float contImpIng = 0;
		int cantMovGasto = 0;
		int cantMovIngreso = 0;

		int k = 0;

		while (Movimientos.leerDeDisco(k, "movimientos.dat"))
		{


			int idM = Movimientos.getBilletera();

			if (idM == idB)
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
			cout << "Billetera: " << Billeteras.getNombre() << endl;
			cout << "* * * * * *" << endl;
			cout << "Registra un total de: $" << contImpIng << endl;
			cout << "Entre : " << cantMovIngreso << " Ingreso/s y" << endl;
			cout << "* * * * * *" << endl;
			cout << "Registra un total de: $" << contImpGas << endl;
			cout << "Entre : " << cantMovGasto << " Gasto/s" << endl;
		}

		else
		{
			cout << "------------------------------------------------------------" << endl;
			cout << "Billetera:" << Billeteras.getNombre() << endl;
			cout << "Que no registra ningun movimiento hasta la fecha" << endl;

		}

		i++;
	}

	cout << "------------------------------------------------------------" << endl;
	cout << "-----PATRIMONIO NETO TOTAL-----" << endl;
	cout << "------------------------------------------------------------" << endl;
	cout << "Siendo su Patrimonio neto hasta la fecha..." << endl;
	cout << "...un total de: $" << ImporteTotal << endl;
	cout << "* * * * * *" << endl;
	cout << "Registrado en: " << ContadorMov << " movimientos." << endl;
	cout << "Separados en: " << endl;
	cout << ContadorIng << " ingreso/s" << " y " << ContadorGas << " deuda/s" << endl;
	cout << "En un total de " << ContadorBill << " billetera/s registrada/s."<<endl;

	cout << "------------------------------------------------------------" << endl;

	rlutil::anykey();

}

void Informes::TopDeIngresosOGastos()
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
	float* montos = new float[tam];
	
	llenarVectorCategorias(categorias, montos, tam, tipo);
	ordenarVectorCategorias(categorias, montos, tam);
	mostrarVectorCategorias(categorias, montos, tam);

	delete[] categorias;
	delete[] montos;
	rlutil::anykey();
}

void Informes::EvolucionDeIngresosOGastos()
{
	cout << "Evolucion de sus Ingresos o Gastos" << endl;
	rlutil::anykey();

}

void Informes::llenarVectorCategorias(Categoria* vec, float* montos, int tam, int tipo)
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

void Informes::ordenarVectorCategorias(Categoria* vec, float* montos, int tam)
{
	Categoria aux;
	float aux2;

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

void Informes::mostrarVectorCategorias(Categoria* vec, float* montos, int tam)
{
	const int nameWidth = 20;
	const int numWidth = 10;

	printElement("ID", numWidth);
	printElement("Nombre categoria", nameWidth);
	printElement("Monto acumulado", numWidth);
	cout << endl << endl;

	if (tam > 5)
		tam = 5;

	for (int i = 0; i < tam; i++)
	{
		printElement(vec[i].getId(), numWidth);
		printElement(vec[i].getNombre(), nameWidth);
		printElement(montos[i], nameWidth);
		cout << endl;
	}
}
