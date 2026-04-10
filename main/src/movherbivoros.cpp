/*
 * movherbivoros.cpp
 *
 *  Created on: 7 abr 2026
 *      Author: marce
 */
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "movherbivoros.h"
using namespace std;

int *verificarEsquinas(vector<vector<char>>& matriz, int filas, int columnas) {
	/*
	 * Función que se encarga de verificar si las esquinas del tablero están ocupadas por alguna entidad
	 * Valor de retorno:
	 * puntero a vector de int que contiene [i,j]
	 */
	int i, j;
	static int esquina[2];
	int *p = esquina;
	for (i = 0; i < filas; i++) {
		for (j = 0; j < columnas; j++) {
			if (i == 0 && (j == 0 || j == columnas - 1)) {
				if (matriz[i][j] == ' ') {
					esquina[0] = i;
					esquina[1] = j;
					return p;
				}
			}
			else if (i == filas-1 && (j == 0 || j == columnas - 1)) {
				if (matriz[i][j] == ' ') {
					esquina[0] = i;
					esquina[1] = j;
					return p;
				}
			}
		}
	}
	return NULL;
}

bool aggHerbivoros(vector<vector<char>>& matriz, int filas, int columnas) {
	/*
	 * Función que se encarga de simular la llegada de un herbívoro al ecosistema a través de las esquinas del tablero
	 *
	 */
	int *esquina;
	if ((esquina = verificarEsquinas(matriz, filas, columnas)) != NULL) {
		matriz[esquina[0]][esquina[1]] = 'H';
		return true;
	}
	return false;
}

bool buscarHerbivoro(vector<vector<char>>& matriz, vector<pair<int,int>>& posicHerbivoros, int filas, int columnas) {
	/*
	 * Función que se encarga de recorrer la matriz para seleccionar un herbívoro para luego evaluar si puede comer una planta
	 * Parámetros:
	 * matriz -> tablero del simulador
	 * filas -> numero de filas de la matriz
	 *
	 */
	int i,j;
	for (i = 0; i < filas; i++) {
		for (j = 0; j < columnas; j++) {
			if (matriz[i][j] == 'H') {
				posicHerbivoros.push_back({i,j});	// guardamos cada posicion en el vector en formato de par ordenado
				return true;
			}
		}
	}
	return false;
}

bool herbivorosComen(vector<vector<char>>& matriz, int filas, int columnas, int f, int c) {
	/*
	 * Función que se encarga de verificar si el herbívoro correspondiente puede comer una planta
	 * Parámetros:
	 * matriz -> tablero del simulador
	 * filas -> numero de filas de la matriz
	 * columnas -> numero de columnas de la matriz
	 * f -> primera coordenada de la ubicación del herbívoro
	 * c -> segunda coordenada de la ubicación del herbívoro
	 */

	// Buscamos solo en las celdas vecinas (de -1 a +1 en filas y columnas)
	for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {

        	if (i == 0 && j == 0) {
        		/*skipeamos i = 0 y j = 0 porque es la celda actual*/
        		continue;
        	}

        	int ni = f + i;
        	int nj = c + j;

        	// Verificamos que las coordenadas vecinas no se salgan de la matriz
        	if (ni >= 0 && ni < filas && nj >= 0 && nj < columnas) {

        		if (matriz[ni][nj] == 'P') {
        			matriz[ni][nj] = 'H';
        			matriz[f][c] = ' ';
        			return true;
        		}
        	}
        }
	}
    return false;
}

bool herbivorosMueven(vector<vector<char>>& matriz, int filas, int columnas, int f, int c) {
	/*
	 * Función que busca un espacio vacío alrededor de un herbívoro para moverlo.
	 */
	// Buscamos en las celdas vecinas (de -1 a +1)
	for (int i = -1; i <= 1; i++) {
		for (int j = -1; j <= 1; j++) {

			/*skipeamos i = 0 y j = 0 porque es la celda actual*/
			if (i == 0 && j == 0) {
				continue;
			}

			int ni = f + i;
			int nj = c + j;

			/*Verificamos que las coordenadas vecinas no se salgan de la matriz*/
			if (ni >= 0 && ni < filas && nj >= 0 && nj < columnas) {
				if (matriz[ni][nj] == ' ') {
					matriz[ni][nj] = 'H'; // El herbívoro se mueve a la nueva celda
					matriz[f][c] = ' ';   // Deja su posición original vacía
					return true;          // Se movió con éxito
				}
			}
		}
	}

    return false; // Retorna falso si estaba rodeado o si no encontró herbívoros
}

bool turnoHerbivoros(vector<vector<char>>& matriz, int filas, int columnas) {
	/*
	 * Función que se encarga de realizar las acciones correspondientes a los herbívoros
	 *
	 */

	bool hizoAlgo = false;				// bandera para indicar si un herbívoro ya actuó o no
	vector<pair<int,int>> posicHerbivoros;		// vector donde se guardarán las posiciones de los herbivoros en el tablero en cada ciclo
	if (buscarHerbivoro(matriz, posicHerbivoros, filas, columnas)) {
		/*Los herbivoros se guardaron*/

		for (size_t k = 0; k < posicHerbivoros.size(); k++) {

			/*Se itera sobre el vector con las posiciones de los herbivoros y se guarda el valor de cada coordenada individualmente
			 * en f (fila) y c (columna)*/

			int f = posicHerbivoros[k].first;
			int c = posicHerbivoros[k].second;

			if (matriz[f][c] != 'H') {
				/*En caso que en esa posicion no esté un herbívoro pasamos al siguiente*/
				continue;
			}

			if (herbivorosComen(matriz, filas, columnas, f, c)) {
				hizoAlgo = true;
			}
			else if (herbivorosMueven(matriz, filas, columnas, f, c)) {
				hizoAlgo = true;
			}
		}
		return hizoAlgo;
	}
	return hizoAlgo;
}






