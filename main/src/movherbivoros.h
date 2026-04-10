/*
 * movherbivoros.h
 *
 *  Created on: 7 abr 2026
 *      Author: marce
 */

#ifndef MOVHERBIVOROS_H_
#define MOVHERBIVOROS_H_
#include <vector>

bool aggHerbivoros(std::vector<std::vector<char>>& matriz, int filas, int columnas);
bool herbivorosComen(std::vector<std::vector<char>>& matriz, int filas, int columnas, int f, int c);
bool herbivorosMueven(std::vector<std::vector<char>>& matriz, int filas, int columnas, int f, int c);
bool turnoHerbivoros(std::vector<std::vector<char>>& matriz, int filas, int columnas);



#endif /* MOVHERBIVOROS_H_ */
