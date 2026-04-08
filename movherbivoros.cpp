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

bool aggHerbivoros(vector<vector<char>>& matriz, int filas, int columnas) {
    int f = rand() % filas;
    int c = rand() % columnas;
    // busca desde una posicion aleatoria en adelante
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            int ni = (f + i) % filas;
            int nj = (c + j) % columnas;
            if (matriz[ni][nj] == ' ') {
                matriz[ni][nj] = 'H';
                return true;
            }
        }
    }
	return false;
}

bool herbivorosComen(vector<vector<char>>& matriz, int filas, int columnas) {
    int f = rand() % filas;
    int c = rand() % columnas;
    // busca desde una posicion aleatoria en adelante
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            int ni = (f + i) % filas;
            int nj = (c + j) % columnas;
            if (matriz[ni][nj] == 'P') {
                matriz[ni][nj] = 'H';
                matriz[f][c] = ' ';
                return true;
            }
        }
    }
	return false;
}

