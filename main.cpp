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
#include "Ecosistema.h"
using namespace std;

int ciclo = 0;

int main() {
    srand(time(NULL));
    int filas, columnas;
    pedirDimension(&filas, &columnas);
    cout << "Número de Filas: " << filas << " Número de Columnas: " << columnas << endl;

    Ecosistema eco (filas, columnas);

    //aggPlantas(tablero, filas, columnas, 0);  // estado inicial: planta en posicion aleatoria
    cout << "\n=== ESTADO INICIAL ===" << endl;
    eco.aggPlantas();
    eco.imprimirTablero();
    while(true) {
    	this_thread::sleep_for(chrono::seconds(5));
    	eco.avanzarCiclo();
    	eco.imprimirTablero();

    }

    return 0;
}
