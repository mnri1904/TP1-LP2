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

        cout << "\n=== CICLO " << ciclo << " ===" << endl;

        if (reproducirPlantas(tablero, filas, columnas)) {
        	cout << "Se reprodujo una planta" << endl;
        }

        if (turnoHerbivoros(tablero, filas, columnas)) {
        	cout << "Un herbívoro actuó" << endl;
        }

        /*Flujo carnivoros*/

        if (ciclo % 2 == 0) {
        	aggHerbivoros(tablero, filas, columnas);
        }

        /*Agregar carnivoros en ciclo % 4 == 0*/

        imprimirTablero(tablero, filas, columnas);

        cout << "Ciclo actual: " << ciclo << endl;
    }

    return 0;
}
