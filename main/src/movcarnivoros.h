/*
 * movcarnivoros.h
 *
 *  Created on: 10 abr 2026
 *      Author: marce
 */

#ifndef MOVCARNIVOROS_H_
#define MOVCARNIVOROS_H_
#include <vector>
using namespace std;

bool aggCarnivoros(vector<vector<char>>& matriz, int filas, int columnas);
int *verificarEsquinas(vector<vector<char>>& matriz, int filas, int columnas);
bool buscarCarnivoros(vector<vector<char>>& matriz, vector<pair<int,int>>& posicCarnivoros, int filas, int columnas);
bool carnivorosComen(vector<vector<char>>& matriz, int filas, int columnas, int f, int c);
bool carnivorosMueven(vector<vector<char>>& matriz, int filas, int columnas, int f, int c);
bool turnoCarnivoros(vector<vector<char>>& matriz, int filas, int columnas);

#endif /* MOVCARNIVOROS_H_ */
