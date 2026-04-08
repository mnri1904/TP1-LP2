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

    while(true) {
        ciclo++;
        std::this_thread::sleep_for(std::chrono::seconds(5));

        // cada ciclo (5 seg): agrega una planta
        aggPlantas(tablero, filas, columnas, ciclo);

        // cada 2 ciclos (10 seg): reproduce plantas existentes
        if (ciclo % 2 == 0) {
            reproducirPlantas(tablero, filas, columnas);
        }

        // cada 2 ciclos (10 seg): agrega un herbivoro
        if (ciclo % 2 == 0) {
            //aggEntidad(tablero, filas, columnas, 'H');
        }

        // cada 4 ciclos (20 seg): agrega un carnivoro
        if (ciclo % 4 == 0) {
            //aggEntidad(tablero, filas, columnas, 'C');
        }

        imprimirTablero(tablero, filas, columnas);
        cout << "Ciclo actual: " << ciclo << endl;
    }

    return 0;
}
