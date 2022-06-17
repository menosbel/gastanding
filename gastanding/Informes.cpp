#include "Informes.h"
#include "rlutil.h"
using namespace std;

void Informes::BalanceMensual()
{
	cout << "Balance Mensual" << endl;
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
		cout << "No hay ingresados movimientos de este tipo";
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
