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

bool aggPlantas(vector<vector<char>>& matriz, int filas, int columnas, int ciclo) {
	if (ciclo % 2 == 0) {	// cada dos ciclos añadimos una planta
	    int f = rand() % filas;
	    int c = rand() % columnas;
	    // busca desde una posicion aleatoria en adelante
	    for (int i = 0; i < filas; i++) {
	        for (int j = 0; j < columnas; j++) {
	            int ni = (f + i) % filas;
	            int nj = (c + j) % columnas;
	            if (matriz[ni][nj] == ' ') {
	                matriz[ni][nj] = 'P';
	                return true;
	            }
	        }
	    }
	}
	return false;
}

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
	 *
	 */

	int i, j;
	bool existePlantaReproducible = false;

	// Verificar si existe al menos una planta que tenga lugar para reproducirse
	for (i = 0; i < filas; i++) {
		for (j = 0; j < columnas; j++) {
			if (matriz[i][j] == 'P') {
				int hayLugar = 0;

				for (int f = i - 1; f <= i + 1; f++) {	// recorre la fila anterior y posterior
					for (int c = j - 1; c <= j + 1; c++) {	// recorre la columna anterior y posterior
						if (f >= 0 && f < filas && c >= 0 && c < columnas) {	// se valida el rango de la matriz
							if (!(f == i && c == j) && matriz[f][c] == ' ') {	// si el lugar actual no es donde esta la planta y esta vacio
								hayLugar++;
							}
						}
					}
				}

				if (hayLugar > 0) {
					existePlantaReproducible = true;
				}
			}
		}
	}

	if (existePlantaReproducible == false) {

		return false;
	}

	int filaRandom, columnaRandom, hayLugar;

	// Buscar una planta aleatoria que sí tenga al menos un vecino vacío
	do {
		filaRandom = rand() % filas;
		columnaRandom = rand() % columnas;
		hayLugar = 0;

		if (matriz[filaRandom][columnaRandom] == 'P') {
			for (i = filaRandom - 1; i <= filaRandom + 1; i++) {
				for (j = columnaRandom - 1; j <= columnaRandom + 1; j++) {
					if (i >= 0 && i < filas && j >= 0 && j < columnas) {
						if (!(i == filaRandom && j == columnaRandom) && matriz[i][j] == ' ') {
							hayLugar++;
						}
					}
				}
			}
		}

	} while (matriz[filaRandom][columnaRandom] != 'P' || hayLugar == 0);

	int filaDestino, columnaDestino;
	bool reproduccionValida;

	do {
		filaDestino = rand() % filas;
		columnaDestino = rand() % columnas;


		/*la reproducción no es válida si el destino está a más de una fila de distancia por arriba o abajo*/
		if (filaDestino - filaRandom > 1 || filaDestino - filaRandom < -1) {
			reproduccionValida = false;
		}
		/*la reproducción no es válida si el destino está a más de una fila de distancia por derecha o izquierda*/
		else if (columnaDestino - columnaRandom > 1 || columnaDestino - columnaRandom < -1) {
			reproduccionValida = false;
		}
		/*no se puede sobrescribir la misma planta en el mismo lugar*/
		else if (filaDestino == filaRandom && columnaDestino == columnaRandom) {
			reproduccionValida = false;
		}
		else {
			reproduccionValida = true;
		}

	} while (reproduccionValida == false || matriz[filaDestino][columnaDestino] != ' ');

	matriz[filaDestino][columnaDestino] = 'P';
	return true;
}



