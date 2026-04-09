//============================================================================
// Name        : main.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>
#include "generacionTablero.h"
#include "movplantas.h"
#include "movherbivoros.h"
using namespace std;

int ciclo = 0;

int main() {
    srand(time(NULL));
    int filas, columnas;
    pedirDimension(&filas, &columnas);
    cout << "Número de Filas: " << filas << " Número de Columnas: " << columnas << endl;

    vector<vector<char>> tablero(filas, vector<char>(columnas));
    generarTablero(tablero, filas, columnas);
    aggPlantas(tablero, filas, columnas, 0);  // estado inicial: planta en posicion aleatoria
    imprimirTablero(tablero, filas, columnas);
    cout << "Estado inicial" << endl;

    while(true) {
        ciclo++;
        std::this_thread::sleep_for(std::chrono::seconds(5));

        // cada 1 ciclos (5 seg): reproduce plantas
        if (ciclo % 1 == 0) {
            reproducirPlantas(tablero, filas, columnas);
        }

        // cada 2 ciclos (10 seg): llega un herbívoro al ecosistema
        if (ciclo % 2 == 0) {
        	aggHerbivoros(tablero, filas, columnas);
        }

        // cada 3 ciclos (15 seg): agrega un carnivoro
        if (ciclo % 3 == 0) {
        	if (herbivorosComen(tablero, filas, columnas)) {
        		cout << "Un herbívoro consumió una planta." << endl;
        	}
        	else {
        		if (herbivorosMueven(tablero, filas, columnas)) {
        			cout << "Un herbívoro se movió a una celda vacía." << endl;
        		}
        	}
        }

        // cada 4 ciclos (10 seg): llega un carnivoro al ecosistema
        if (ciclo % 4 == 0) {

        }


        if (ciclo % 5 == 0) {
        	// carnivorosComenHerbivoros
        }

        imprimirTablero(tablero, filas, columnas);

        cout << "Ciclo actual: " << ciclo << endl;
    }

    return 0;
}
