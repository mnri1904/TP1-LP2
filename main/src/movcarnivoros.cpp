/*
 * movcarnivoros.cpp
 *
 *  Created on: 10 abr 2026
 *      Author: marce
 */
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "movcarnivoros.h"
using namespace std;

bool aggCarnivoros(vector<vector<char>>& matriz, int filas, int columnas) {
	/*
	 * Función que se encarga de simular la llegada de un herbívoro al ecosistema a través de las esquinas del tablero
	 *
	 */
	int *esquina;
	if ((esquina = verificarEsquinas(matriz, filas, columnas)) != NULL) {
		matriz[esquina[0]][esquina[1]] = 'C';
		return true;
	}
	return false;
}

bool buscarCarnivoros(vector<vector<char>>& matriz, vector<pair<int,int>>& posicCarnivoros, int filas, int columnas) {
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
			if (matriz[i][j] == 'C') {
				posicCarnivoros.push_back({i,j});	// guardamos cada posicion en el vector en formato de par ordenado
				return true;
			}
		}
	}
	return false;
}

bool carnivorosComen(vector<vector<char>>& matriz, int filas, int columnas, int f, int c) {
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

        		if (matriz[ni][nj] == 'H') {
        			matriz[ni][nj] = 'C';
        			matriz[f][c] = ' ';
        			return true;
        		}
        	}
        }
	}
    return false;
}

bool carnivorosMueven(vector<vector<char>>& matriz, int filas, int columnas, int f, int c) {
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
					matriz[ni][nj] = 'C'; // El herbívoro se mueve a la nueva celda
					matriz[f][c] = ' ';   // Deja su posición original vacía
					return true;          // Se movió con éxito
				}
			}
		}
	}

    return false; // Retorna falso si estaba rodeado o si no encontró herbívoros
}

bool turnoCarnivoros(vector<vector<char>>& matriz, int filas, int columnas) {
	/*
	 * Función que se encarga de realizar las acciones correspondientes a los carnívoros
	 *
	 */

	bool hizoAlgo = false;				// bandera para indicar si un carnívoro ya actuó o no
	vector<pair<int,int>> posicCarnivoros;		// vector donde se guardarán las posiciones de los herbivoros en el tablero en cada ciclo
	if (buscarCarnivoros(matriz, posicCarnivoros, filas, columnas)) {
		/*Los carnivoros se guardaron*/

		for (size_t k = 0; k < posicCarnivoros.size(); k++) {

			/*Se itera sobre el vector con las posiciones de los herbivoros y se guarda el valor de cada coordenada individualmente
			 * en f (fila) y c (columna)*/

			int f = posicCarnivoros[k].first;
			int c = posicCarnivoros[k].second;

			if (matriz[f][c] != 'C') {
				/*En caso que en esa posicion no esté un carnívoro pasamos al siguiente*/
				continue;
			}

			if (carnivorosComen(matriz, filas, columnas, f, c)) {
				hizoAlgo = true;
			}
			else if (carnivorosMueven(matriz, filas, columnas, f, c)) {
				hizoAlgo = true;
			}
		}
		return hizoAlgo;
	}
	return hizoAlgo;
}

