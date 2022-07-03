#pragma once
#include <string>
#include <locale>
#include <iostream>
#include <iomanip>

using namespace std;

std::string ZeroPadNumber(int num);
std::string categoriasIngresosToString(int num);
std::string categoriasEgresosToString(int num);
std::string mediosPagoToString(int num);
void mostrarMensaje(string mensaje, int color = 15, int colorFondo = 0, int x = 1, int y = 10);
void vectorEnCero(int* vector, int cant);
struct locate_miles : std::numpunct<char> {
    char_type do_thousands_sep() const override { return ','; }
    char_type do_decimal_point() const override { return '.'; }
    string_type do_grouping() const override { return "\3"; }
};
