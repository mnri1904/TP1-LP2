/*
 * Ecosistema.h
 *
 *  Created on: 10 abr 2026
 *      Author: marce
 */

#ifndef ECOSISTEMA_H_
#define ECOSISTEMA_H_

#include <vector>
#include <iostream>
using namespace std;

class Ecosistema {
private:
	int filas;
	int columnas;
	int ciclo;
	vector<vector<char>> tablero;

public:
	Ecosistema(int f, int c);

	/*getters*/
	int getFilas() const;
	int getColumnas() const;
	int getCiclo() const;

	/*métodos*/
	void generarTablero();
	void imprimirTablero() const;
	void avanzarCiclo();
	bool aggPlantas();
	bool reproducirPlantas();
	bool aggEntidad(char entidad);
	bool turnoEntidad(char entidad, char presa);
	bool buscarEntidad(char entidad, vector<pair<int,int>>& posicEntidad);
	bool entidadCome(char presa, char entidad, int f, int c);
	bool entidadMueve(int f, int c, char entidad);
	int *verificarEsquinas();
	void contadorEntidad(char entidad);
	void inicializarEstado();
};


#endif /* ECOSISTEMA_H_ */
