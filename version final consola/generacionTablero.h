/*
 * generacionTablero.h
 *
 *  Created on: 4 abr 2026
 *      Author: marce
 */

#ifndef GENERACIONTABLERO_H_
#define GENERACIONTABLERO_H_
#include <vector>


void pedirDimension(int *filas, int *columnas);
void generarTablero(std::vector<std::vector<char>>& matriz, int filas, int columnas);
void imprimirTablero(const std::vector<std::vector<char>>& matriz, int filas, int columnas);


#endif /* GENERACIONTABLERO_H_ */
