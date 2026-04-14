/*
 * Herbivoro.cpp
 *
 *  Created on: 12 abr 2026
 *      Author: marce
 */

#include "Herbivoro.h"

char Herbivoro::getSimbolo() const {
    return 'H';
}

Herbivoro::Herbivoro(int f, int c) : EntidadViva(f,c,100) {
}


