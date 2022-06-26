#pragma once
#include<map> //no se si se va a usar pero la dejo
#include "menues.h"
#include "tables.h"
#include "CategoriasRepository.h"
#include "MovimientosRepository.h"

class Informes
	{
	private:
		void llenarVectorCategorias(Categoria* vec, float* montos, int tam, int tipo);
		void ordenarVectorCategorias(Categoria* vec, float* montos, int tam);
		void mostrarVectorCategorias(Categoria* vec, float* montos, int tam);
	public:
		void Balance30dias();
		void BalanceAnual();
		void PatrimonioNeto();
		void TopDeIngresosOGastos(); // mucho harcodeo aca sorrwyy :,( // igual no resuelve.. pero dale que lo sacamossss ?•??•????
		void EvolucionDeIngresosOGastos();
};

