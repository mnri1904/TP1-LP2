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
#include "movcarnivoros.h"
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
    cout << "\n=== ESTADO INICIAL ===" << endl;
    imprimirTablero(tablero, filas, columnas);
    while(true) {
        ciclo++;
        std::this_thread::sleep_for(std::chrono::seconds(5));

        cout << "\n==============================" << endl;
        cout << "CICLO " << ciclo << endl;
        cout << "==============================" << endl;

        /*Las plantas se reproducen en cada ciclo*/

        if (reproducirPlantas(tablero, filas, columnas)) {
        	cout << "Se reprodujo una planta" << endl;
        }

        /*Turno de los herbívoros*/
        if (turnoHerbivoros(tablero, filas, columnas)) {
        	cout << "Un herbívoro actuó" << endl;
        }
        else {
        	cout << "No actuaron herbívoros" << endl;
        }

        /*Turno de los carnívoros*/
        if (turnoCarnivoros(tablero, filas, columnas)) {
            cout << "Un carnívoro actuó" << endl;
        } else {
            cout << "No actuaron carnívoros" << endl;
        }

        /*Agregar herbívoros cada 2 ciclos*/
        if (ciclo % 2 == 0) {
        	if (aggHerbivoros(tablero, filas, columnas)) {
        		cout << "Un herbívoro llegó al ecosistema" << endl;
        	}
        	else {
        		cout << "No hay esquinas libres para que ingrese un herbívoro." << endl;
        	}
        }

        /*Agregar carnivoros cada 4 ciclos*/
        if (ciclo % 4 == 0) {
        	if(aggCarnivoros(tablero, filas, columnas)) {
        		cout << "Llegó un carnívoro al ecosistema." << endl;
        	}
        	else {
        		cout << "No hay esquinas libres para que ingrese un carnívoro." << endl;
        	}
        }

        imprimirTablero(tablero, filas, columnas);
        cout << "Ciclo actual: " << ciclo << endl;
    }

    return 0;
}
