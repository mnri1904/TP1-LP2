/*
 * EntidadViva.cpp
 *
 *  Created on: 12 abr 2026
 *      Author: marce
 */
#include "EntidadViva.h"

EntidadViva::EntidadViva(int f, int c, int e) {
    fila = f;
    columna = c;
    energia = e;
    edad = 0;
    viva = true;
}

EntidadViva::~EntidadViva() {
}

int EntidadViva::getFila() const {
    return fila;
}

int EntidadViva::getColumna() const {
    return columna;
}

void EntidadViva::ponerPosicion(int f, int c) {
    fila = f;
    columna = c;
}

int EntidadViva::getEnergia() const {
    return energia;
}

void EntidadViva::ponerEnergia(int energ) {
    energia = energ;
}

int EntidadViva::getEdad() const {
    return edad;
}

void EntidadViva::aumentarEdad() {
    edad++;
}

bool EntidadViva::estadoVida() const {
    return viva;
}

void EntidadViva::muerte() {
    viva = false;
}


