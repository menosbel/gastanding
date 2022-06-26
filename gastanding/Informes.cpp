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

void Informes::BalanceMensual()
{
	cout << "Balance Mensual" << endl;
	
	float ImporteTotal = 0;
	int ContadorMov = 0;
	int ContadorIng = 0;
	int ContadorDeu = 0;

	Fecha Actual;

	int anio = Actual.getAnio();
	int mes = Actual.getMes();
	int dia = Actual.getDia();


	Billetera Billeteras;
	BilleterasRepository BRepo;

	int cantRegB = BRepo.cantidadRegistros();

	for (int i = 0; i < cantRegB;i++)
	{
		int cantMovDeuda = 0;
		int cantMovIngreso = 0;
		float contImpDeu = 0;
		float contImpIng = 0;
		bool RegistraMov = false;
		Billeteras.leerDeDisco(i, "_nombreArchivo");
		
		int idB = Billeteras.getId();

		Movimiento Movimientos;
		MovimientosRepository MRepo;

		int cantRegM = MRepo.cantidadRegistros();
		
		for (int k = 0; k < cantRegM; k++)
		{
			
			Movimientos.leerDeDisco(k, "_nombreArchivo");

			int idM= Movimientos.getBilletera();

			Fecha FMov;

			FMov.setDia(Movimientos.getFecha().getDia());
			FMov.setMes(Movimientos.getFecha().getMes());
			FMov.setAnio(Movimientos.getFecha().getAnio());


			if (idM == idB&&Movimientos.Ultimos30dias(FMov)==true)
			{
				int CatM=Movimientos.getCategoria();

				Categoria Categorias;
				CategoriasRepository CRepo;
				int cantRegC = CRepo.cantidadRegistros();
				int TipoDeMov = 0;
					for (int j = 0; j < cantRegC; j++)
					{
						Categorias.leerDeDisco(j, "_nombreArchivo");

						if (CatM == Categorias.getId() && Categorias.getEstado() == true)
						{
							TipoDeMov = Categorias.getTipoMovimiento();
						}

					}
					if (TipoDeMov == 1)
					{
						cantMovIngreso ++;
						contImpIng += Movimientos.getMonto();
						ImporteTotal += Movimientos.getMonto();
						ContadorMov ++;
						ContadorIng ++;
						RegistraMov = true;

					}else
					{
						cantMovDeuda ++;
						contImpDeu += Movimientos.getMonto();
						ImporteTotal -= Movimientos.getMonto();
						ContadorMov++;
						ContadorDeu ++;
						RegistraMov = true;
					}

			}	

		}
		if (RegistraMov == true) {
			cout << "-----------------------------------" << endl;
			cout << "Su Balance Mensual en la billetera:" << Billeteras.getNombre() << endl;
			cout << "Registra un total de: $" << contImpIng << endl;
			cout << "Entre un total de: " << ContadorIng << " ingreso/s y" << endl;
			cout << "Registra un total de: $" << contImpDeu << endl;
			cout << "Entre un total de: " << ContadorDeu << " deuda/s" << endl;
		}else
		{
			cout << "-----------------------------------" << endl;
			cout << "Su billetera:" << Billeteras.getNombre() << endl;
			cout << " no registra movimientos" << endl;
		}
	}
	cout << "-----------------------------------" << endl;
	cout << "Su Balance de los ultimos 30 dias es de: $"<< ImporteTotal << endl;
	cout << "Registrado en un total de: " << ContadorMov<<" movimientos."<<endl;
	cout << "Separados en: " << endl;
	cout<< ContadorIng << " ingreso/s" << " y..." << endl;
	cout << ContadorDeu << " deuda/s" << endl;
	cout<<"-----------------------------------" << endl;
	rlutil::anykey();
}

void Informes::BalanceAnual()
{
	cout << "Balance Anual" << endl;
	rlutil::anykey();

}

void Informes::PatrimonioNeto()
{
	cout << "Patrimonio neto" << endl;
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
	mostrarVectorCategorias(categorias, montos, 5);

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

	for (int i = 0; i < tam; i++)
	{
		printElement(vec[i].getId(), numWidth);
		printElement(vec[i].getNombre(), nameWidth);
		printElement(montos[i], nameWidth);
		cout << endl;
	}
}
