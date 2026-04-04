/*
 * movplantas.cpp
 *
 *  Created on: 4 abr 2026
 *      Author: Marcelo Romero
 */
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "movplantas.h"
using namespace std;

bool reproducirPlantas(vector<vector<char>>& matriz, int filas, int columnas) {
	/*
	 * Función que se encarga de verificar si es posible reproducir plantas en el ciclo actual
	 * Parámetros:
	 * vector<vector<char>>& matriz -> tablero
	 * filas -> numero de filas de la matriz
	 * columnas -> numero de columnas de la matriz
	 * Valor de retorno:
	 * true -> si la reproducción es posible
	 * false -> si la reproducción no es posible
	 */
	int filaRandom, columnaRandom;
	do {
		filaRandom = rand() % filas; columnaRandom = rand() % columnas;
	}while(matriz[filaRandom][columnaRandom] != 'P');
	int filaDestino, columnaDestino, hayLugar;
	bool reproduccionValida;

	int i,j;
	/*Se recorre la matriz para saber si hay lugares libres para alguna planta*/
	for (i = 0; i < filas; i++) {
		for (j = 0; j < columnas; j++) {
			if (matriz[i][j] == ' ') {
				hayLugar++;
			}
		}
	}

	if (hayLugar == 0) {
		reproduccionValida = false;
		return reproduccionValida;
	}

	do {
		filaDestino = rand() % filas;
		columnaDestino = rand() % columnas;
		if (filaDestino - filaRandom > 1 || filaDestino - filaRandom < -1) {
		/*la reproduccion no es valida si el destino esta a mas de una fila de distancia por arriba o abajo*/
		reproduccionValida = false;
		} else if (columnaDestino - columnaRandom > 1 || columnaDestino - columnaRandom < -1) {
			/*la reproduccion no es valida si el destino esta a mas de una fila de distancia por derecha o izquierda*/
			reproduccionValida = false;
		} else {
		reproduccionValida = true;
		}
	}while(reproduccionValida == false || matriz[filaDestino][columnaDestino] != ' ');
	matriz[filaDestino][columnaDestino] = 'P';
	return reproduccionValida;

}




