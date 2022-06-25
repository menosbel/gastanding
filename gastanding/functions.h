#pragma once
#include <string>

using namespace std;

std::string ZeroPadNumber(int num);
std::string categoriasIngresosToString(int num);
std::string categoriasEgresosToString(int num);
std::string mediosPagoToString(int num);
void mostrarMensaje(string mensaje, int color = 15, int colorFondo = 0, int x = 1, int y = 10);
void vectorEnCero(int* vector, int cant);
