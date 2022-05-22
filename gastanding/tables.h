#pragma once
#include <iomanip>
#include <iostream>

using namespace std;

template<typename T> void printElement(T t, const int& width)
{
	cout << left << setw(width) << setfill(' ') << t;
}

void printIngresosHeader();
