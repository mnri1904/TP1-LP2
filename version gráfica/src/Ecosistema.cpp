/*
 * Ecosistema.cpp
 *
 *  Created on: 10 abr 2026
 *      Author: marce
 */
#include "Ecosistema.h"
#include "Planta.h"
#include "Herbivoro.h"
#include "Carnivoro.h"
#include <cstdlib>

Ecosistema::Ecosistema(int f, int c) {
    filas = f;
    columnas = c;
    ciclo = 0;
    tablero = vector<vector<char>>(filas, vector<char>(columnas));
    generarTablero();
}

int Ecosistema::getFilas() const {
    return filas;
}

int Ecosistema::getColumnas() const {
    return columnas;
}

int Ecosistema::getCiclo() const {
    return ciclo;
}

Ecosistema::~Ecosistema() {
    /*
     * Destructor para cada objeto del ecosistema
     */
    for (size_t i = 0; i < entidades.size(); i++) {
        delete entidades[i];
    }
}

EntidadViva* Ecosistema::crearEntidad(char entidad, int f, int c) {
    /*
     * Función que, según el caracter pasado como parámetro, crea el objeto correspondiente
     */
    if (entidad == 'P') {
        return new Planta(f, c);
    }
    else if (entidad == 'H') {
        return new Herbivoro(f, c);
    }
    else if (entidad == 'C') {
        return new Carnivoro(f, c);
    }
    return NULL;
}

EntidadViva* Ecosistema::obtenerEntidad(int f, int c) const {
    /*
     * Función que busca la entidad por posición
     * Cuando una entidad se mueve o come se modifica el objeto correspondiente
     */
    for (size_t i = 0; i < entidades.size(); i++) {
        if (entidades[i]->getFila() == f && entidades[i]->getColumna() == c && entidades[i]->estadoVida()) {
            return entidades[i];
        }
    }
    return NULL;
}

void Ecosistema::entidadesEnvejecen() {
    for (size_t i = 0; i < entidades.size(); i++) {
        if (entidades[i]->estadoVida()) {
            entidades[i]->aumentarEdad();
        }
    }
}

void Ecosistema::muertePorEdad() {
    for (size_t i = 0; i < entidades.size(); i++) {
        if (entidades[i]->estadoVida()) {
            char simbolo = entidades[i]->getSimbolo();
            int edad = entidades[i]->getEdad();

            if ((simbolo == 'P' && edad >= 20) || (simbolo == 'H' && edad >= 20) || (simbolo == 'C' && edad >= 20)) {
                int f = entidades[i]->getFila();
                int c = entidades[i]->getColumna();

                tablero[f][c] = ' ';
                entidades[i]->muerte();
            }
        }
    }
}

void Ecosistema::restarEnergia() {
    for (size_t i = 0; i < entidades.size(); i++) {
        if (entidades[i]->estadoVida()) {
            char simbolo = entidades[i]->getSimbolo();

            if (simbolo == 'H' || simbolo == 'C') {
                int energiaActual = entidades[i]->getEnergia();
                entidades[i]->ponerEnergia(energiaActual - 10);
            }
        }
    }
}

void Ecosistema::mostrarEstadoEntidades() const {
    for (size_t i = 0; i < entidades.size(); i++) {
        cout << entidades[i]->getSimbolo() << " en (" << entidades[i]->getFila() << "," << entidades[i]->getColumna() << ")"
             << " edad=" << entidades[i]->getEdad() << " energia=" << entidades[i]->getEnergia() << " viva=" << entidades[i]->estadoVida() << endl;
    }
}


void Ecosistema::muertePorEnergia() {
    for (size_t i = 0; i < entidades.size(); i++) {
        if (entidades[i]->estadoVida()) {
            char simbolo = entidades[i]->getSimbolo();

            if ((simbolo == 'H' || simbolo == 'C') && entidades[i]->getEnergia() <= 0) {
                int f = entidades[i]->getFila();
                int c = entidades[i]->getColumna();

                tablero[f][c] = ' ';
                entidades[i]->muerte();
            }
        }
    }
}

const vector<vector<char>>& Ecosistema::getTablero() const {
    return tablero;
}

int Ecosistema::contarEntidad(char entidad) const {
    int contador = 0;
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            if (tablero[i][j] == entidad) {
                contador++;
            }
        }
    }
    return contador;
}

void Ecosistema::generarTablero() {
    int i, j;
    for (i = 0; i < filas; i++) {
        for (j = 0; j < columnas; j++) {
            tablero[i][j] = ' ';
        }
    }
}

void Ecosistema::imprimirTablero() const {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            std::cout << "+---";
        }
        std::cout << "+" << std::endl;

        for (int j = 0; j < columnas; j++) {
            std::cout << "| " << tablero[i][j] << " ";
        }
        std::cout << "|" << std::endl;
    }

    for (int j = 0; j < columnas; j++) {
        std::cout << "+---";
    }
    std::cout << "+" << std::endl;
}

void Ecosistema::inicializarEstado() {
    generarTablero();
    ciclo = 0;
    aggPlantas();
}

int* Ecosistema::verificarEsquinas() {
    int i, j;
    static int esquina[2];
    int *p = esquina;

    for (i = 0; i < filas; i++) {
        for (j = 0; j < columnas; j++) {
            if (i == 0 && (j == 0 || j == columnas - 1)) {
                if (tablero[i][j] == ' ') {
                    esquina[0] = i;
                    esquina[1] = j;
                    return p;
                }
            }
            else if (i == filas - 1 && (j == 0 || j == columnas - 1)) {
                if (tablero[i][j] == ' ') {
                    esquina[0] = i;
                    esquina[1] = j;
                    return p;
                }
            }
        }
    }
    return NULL;
}

bool Ecosistema::aggPlantas() {
    int f = rand() % filas;
    int c = rand() % columnas;

    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            int ni = (f + i) % filas;
            int nj = (c + j) % columnas;
            if (tablero[ni][nj] == ' ') {
                tablero[ni][nj] = 'P';

                EntidadViva* nuevaPlanta = crearEntidad('P', ni, nj);
                if (nuevaPlanta != NULL) {
                    entidades.push_back(nuevaPlanta);
                }
                return true;
            }
        }
    }
    return false;
}

bool Ecosistema::aggEntidad(char entidad) {
    int *esquina;
    if ((esquina = verificarEsquinas()) != NULL) {
        tablero[esquina[0]][esquina[1]] = entidad;

        EntidadViva* nuevaEntidad = crearEntidad(entidad, esquina[0], esquina[1]);
        if (nuevaEntidad != NULL) {
            entidades.push_back(nuevaEntidad);
        }
        return true;
    }
    return false;
}

void Ecosistema::mostrarEntidades() const {
    /*
     * Función para mostrar las entidades guardadas (depuración)
     */
    for (size_t i = 0; i < entidades.size(); i++) {
        cout << entidades[i]->getSimbolo() << " en (" << entidades[i]->getFila() << "," << entidades[i]->getColumna() << ")" << endl;
    }
}

bool Ecosistema::reproducirPlantas() {
    int i, j;
    bool existePlantaReproducible = false;

    for (i = 0; i < filas; i++) {
        for (j = 0; j < columnas; j++) {
            if (tablero[i][j] == 'P') {
                int hayLugar = 0;

                for (int f = i - 1; f <= i + 1; f++) {
                    for (int c = j - 1; c <= j + 1; c++) {
                        if (f >= 0 && f < filas && c >= 0 && c < columnas) {
                            if (!(f == i && c == j) && tablero[f][c] == ' ') {
                                hayLugar++;
                            }
                        }
                    }
                }

                if (hayLugar > 0) {
                    existePlantaReproducible = true;
                }
            }
        }
    }

    if (existePlantaReproducible == false) {
        return false;
    }

    int filaRandom, columnaRandom, hayLugar;

    // Buscar una planta aleatoria que sí tenga al menos un vecino vacío
    do {
        filaRandom = rand() % filas;
        columnaRandom = rand() % columnas;
        hayLugar = 0;

        if (tablero[filaRandom][columnaRandom] == 'P') {
            for (i = filaRandom - 1; i <= filaRandom + 1; i++) {
                for (j = columnaRandom - 1; j <= columnaRandom + 1; j++) {
                    if (i >= 0 && i < filas && j >= 0 && j < columnas) {
                        if (!(i == filaRandom && j == columnaRandom) && tablero[i][j] == ' ') {
                            hayLugar++;
                        }
                    }
                }
            }
        }

    } while (tablero[filaRandom][columnaRandom] != 'P' || hayLugar == 0);

    int filaDestino, columnaDestino;
    bool reproduccionValida;

    do {
        filaDestino = rand() % filas;
        columnaDestino = rand() % columnas;

        if (filaDestino - filaRandom > 1 || filaDestino - filaRandom < -1) {
            reproduccionValida = false;
        }
        else if (columnaDestino - columnaRandom > 1 || columnaDestino - columnaRandom < -1) {
            reproduccionValida = false;
        }
        else if (filaDestino == filaRandom && columnaDestino == columnaRandom) {
            reproduccionValida = false;
        }
        else {
            reproduccionValida = true;
        }

    } while (reproduccionValida == false || tablero[filaDestino][columnaDestino] != ' ');

    tablero[filaDestino][columnaDestino] = 'P';

    EntidadViva* nuevaPlanta = crearEntidad('P', filaDestino, columnaDestino);
    if (nuevaPlanta != NULL) {
        entidades.push_back(nuevaPlanta);
    }

    return true;
}

bool Ecosistema::buscarEntidad(char entidad, std::vector<std::pair<int,int>>& posicEntidad) {
    int i, j;
    for (i = 0; i < filas; i++) {
        for (j = 0; j < columnas; j++) {
            if (tablero[i][j] == entidad) {
                posicEntidad.push_back({i, j});
            }
        }
    }
    return !posicEntidad.empty();
}

bool Ecosistema::entidadCome(char presa, char entidad, int f, int c) {
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (i == 0 && j == 0) {
                continue;
            }

            int ni = f + i;
            int nj = c + j;

            if (ni >= 0 && ni < filas && nj >= 0 && nj < columnas) {
                if (tablero[ni][nj] == presa) {

                    EntidadViva* depredador = obtenerEntidad(f,c);
                    EntidadViva* victima = obtenerEntidad(ni,nj);

                    tablero[ni][nj] = entidad;
                    tablero[f][c] = ' ';

                    if (depredador != NULL) {
                        depredador->ponerPosicion(ni,nj);

                        int energiaActual = depredador->getEnergia();
                        depredador->ponerEnergia(energiaActual + 20);
                    }
                    if (victima != NULL) {
                        victima->muerte();
                    }
                    return true;
                }
            }
        }
    }
    return false;
}

void Ecosistema::limpiarMuertas() {
    /*
     * Función para sacar los objetos del vector de entidades
     */
    for (size_t i = 0; i < entidades.size();) {
        if (!entidades[i]->estadoVida()) {
            delete entidades[i];
            entidades.erase(entidades.begin()+i);
        }
        else {
            i++;
        }
    }
}


bool Ecosistema::entidadMueve(int f, int c, char entidad) {
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (i == 0 && j == 0) {
                continue;
            }

            int ni = f + i;
            int nj = c + j;

            if (ni >= 0 && ni < filas && nj >= 0 && nj < columnas) {
                if (tablero[ni][nj] == ' ') {
                    tablero[ni][nj] = entidad;
                    tablero[f][c] = ' ';

                    EntidadViva* entidadAmover = obtenerEntidad(f,c);
                    if (entidadAmover != NULL) {
                        entidadAmover->ponerPosicion(ni,nj);
                    }

                    return true;
                }
            }
        }
    }

    return false;
}

void Ecosistema::contadorEntidad(char entidad) {
    int contador = 0;
    int i, j;
    for (i = 0; i < filas; i++) {
        for (j = 0; j < columnas; j++) {
            if (tablero[i][j] == entidad) {
                contador++;
            }
        }
    }

    if (entidad == 'H') {
        cout << "La cantidad de herbívoros es: " << contador << std::endl;
    }
    else if (entidad == 'C') {
        cout << "La cantidad de carnívoros es: " << contador << std::endl;
    }
    else {
        cout << "La cantidad de plantas es: " << contador << std::endl;
    }
}

bool Ecosistema::turnoEntidad(char entidad, char presa) {
    bool hizoAlgo = false;
    vector<pair<int,int>> posicEntidad;

    if (buscarEntidad(entidad, posicEntidad)) {
        for (size_t k = 0; k < posicEntidad.size(); k++) {
            int f = posicEntidad[k].first;
            int c = posicEntidad[k].second;

            if (tablero[f][c] != entidad) {
                continue;
            }

            if (entidadCome(presa, entidad, f, c)) {
                hizoAlgo = true;
            }
            else if (entidadMueve(f, c, entidad)) {
                hizoAlgo = true;
            }
        }
        return hizoAlgo;
    }

    return hizoAlgo;
}

void Ecosistema::avanzarCiclo() {
    ciclo++;

    cout << "\n==============================" << endl;
    cout << "CICLO " << ciclo << endl;
    cout << "==============================" << endl;

    entidadesEnvejecen();
    restarEnergia();
    muertePorEdad();
    muertePorEnergia();

    cout << "\n--- Estado despues de edad y energia ---" << endl;
    mostrarEstadoEntidades();

    //las plantas se reproducen en cada ciclo
    if (reproducirPlantas()) {
        cout << "Se reprodujo una planta" << endl;
    }

    //turno de los herbivoros
    if (turnoEntidad('H', 'P')) {
        cout << "Actuaron herbívoros" << endl;
    }
    else {
        cout << "No actuaron herbívoros" << endl;
    }

    //Turno de los carnivoros
    if (turnoEntidad('C', 'H')) {
        cout << "Actuaron carnívoros" << endl;
    }
    else {
        cout << "No actuaron carnívoros" << endl;
    }

    /*Agregar herbívoros cada 2 ciclos*/
    if (ciclo % 2 == 0) {
        if (aggEntidad('H')) {
            limpiarMuertas();
            mostrarEntidades();
            cout << "Un herbívoro llegó al ecosistema" << endl;
        }
        else {
            cout << "No hay esquinas libres para que ingrese un herbívoro." << endl;
        }
    }

    /*Agregar carnivoros cada 4 ciclos*/
    if (ciclo % 4 == 0) {
        if(aggEntidad('C')) {
            limpiarMuertas();
            mostrarEntidades();
            cout << "Llegó un carnívoro al ecosistema." << endl;
        }
        else {
            cout << "No hay esquinas libres para que ingrese un carnívoro." << endl;
        }
    }

    contadorEntidad('H');
    contadorEntidad('C');
    contadorEntidad('P');

    cout << "Ciclo actual: " << ciclo << endl;

    limpiarMuertas();

    cout << "\n--- Estado final de entidades vivas ---" << endl;
    mostrarEstadoEntidades();
}
