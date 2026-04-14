//============================================================================
// Name        : generacionTablero.cpp
// Author      : Marcelo Romero
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "generacionTablero.h"

using namespace std;

void pedirDimension(int *filas, int *columnas) {
	/*
	 * Función que se encarga de pedir al usuario las dimensiones de la matriz deseada (2 < filas < 10 || 2 < columnas < 10)
	 */
	do {
		cout << "Introduce la dimensión de la matriz" << endl;
		cout << "Filas: ";
		cin >> *filas;
		cout << "Columnas: ";
		cin >> *columnas;
		cout << endl;
	}while((*filas > 10 || *filas < 3) || (*columnas > 10 || *columnas < 3));
}




