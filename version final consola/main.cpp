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
#include "Ecosistema.h"
using namespace std;
int main() {
    srand(time(NULL));
    int filas, columnas;
    pedirDimension(&filas, &columnas);
    cout << "Número de Filas: " << filas << " Número de Columnas: " << columnas << endl;

    Ecosistema eco (filas, columnas);

    cout << "\n=== ESTADO INICIAL ===" << endl;
    eco.inicializarEstado();
    eco.imprimirTablero();
    while(true) {
    	this_thread::sleep_for(chrono::seconds(5));
    	eco.avanzarCiclo();
    	eco.imprimirTablero();
    }
    return 0;
}
/*
 * Energia 100 bajar 10 de energia cada ciclo
 * Comer +20 de energia
 * Edad plantas: 20
 * Edad carnívoros: 20
 * Edad herbívoros: 20
 */
