/*
 * Planta.cpp
 *
 *  Created on: 12 abr 2026
 *      Author: marce
 */

#include "Planta.h"

Planta::Planta(int f, int c) : EntidadViva(f, c, 0) {
}

char Planta::getSimbolo() const {
    return 'P';
}
