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
		cout << "Un herbívoro llegó al ecosistema por " << *esquina << ", " << *(esquina+1) << endl;
		return true;
	}
	return false;
}

int *buscarHerbivoro(vector<vector<char>>& matriz, int filas, int columnas) {
	/*
	 * Función que se encarga de recorrer la matriz para seleccionar un herbívoro para luego evaluar si puede comer una planta
	 * Parámetros:
	 * matriz -> tablero del simulador
	 * filas -> numero de filas de la matriz
	 *
	 */
	int f, c;
		static int posicion[2];
		int *p = posicion;

		int intentos = 0;
		int max_intentos = filas * columnas; // Límite de veces que intentará buscar al azar

		do {
			f = rand() % filas;
			c = rand() % columnas;
			intentos++;

			if (intentos > max_intentos) {
				return NULL;
			}

		} while(matriz[f][c] != 'H');

		if (matriz[f][c] == 'H') {
			posicion[0] = f;
			posicion[1] = c;
			return p;
		}
		return NULL;
}

bool herbivorosComen(vector<vector<char>>& matriz, int filas, int columnas) {
	/*
	 * Función que se encarga de verificar si el herbívoro correspondiente puede comer una planta
	 * Parámetros:
	 * matriz -> tablero del simulador
	 * filas -> numero de filas de la matriz
	 * columnas -> numero de columnas de la matriz
	 * f -> primera coordenada de la ubicación del herbívoro
	 * c -> segunda coordenada de la ubicación del herbívoro
	 */
	int *posicHerbivoro;	// puntero al vector con la posicion del herbivoro
	if ((posicHerbivoro = buscarHerbivoro(matriz,filas,columnas)) != NULL) {

		int f = posicHerbivoro[0];
		int c = posicHerbivoro[1];

	    // Buscamos solo en las celdas vecinas (de -1 a +1 en filas y columnas)

	    for (int i = -1; i <= 1; i++) {
	        for (int j = -1; j <= 1; j++) {

	            // Saltamos la posición central porque es donde ya está parado el herbívoro
	            if (i == 0 && j == 0) continue;

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
	}
    return false;
}

bool herbivorosMueven(vector<vector<char>>& matriz, int filas, int columnas) {
	/*
	 * Función que busca un espacio vacío alrededor de un herbívoro para moverlo.
	 */
	int *posicHerbivoro;
	if ((posicHerbivoro = buscarHerbivoro(matriz, filas, columnas)) != NULL) {

		int f = posicHerbivoro[0];
		int c = posicHerbivoro[1];

	    // Buscamos en las celdas vecinas (de -1 a +1)
	    for (int i = -1; i <= 1; i++) {
	        for (int j = -1; j <= 1; j++) {

	            // Saltamos la posición central
	            if (i == 0 && j == 0) continue;

	            int ni = f + i;
	            int nj = c + j;

	            // Verificamos que no se salga de la matriz
	            if (ni >= 0 && ni < filas && nj >= 0 && nj < columnas) {

                    // Si encuentra un espacio vacío...
	                if (matriz[ni][nj] == ' ') {
	                    matriz[ni][nj] = 'H'; // El herbívoro se mueve a la nueva celda
	                    matriz[f][c] = ' ';   // Deja su posición original vacía
	                    return true;          // Se movió con éxito
	                }
	            }
	        }
	    }
	}
    return false; // Retorna falso si estaba rodeado o si no encontró herbívoros
}







