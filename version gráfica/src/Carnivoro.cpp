/*
 * Carnivoro.cpp
 *
 *  Created on: 12 abr 2026
 *      Author: marce
 */

#include "Carnivoro.h"

Carnivoro::Carnivoro(int f, int c) : EntidadViva(f, c, 100) {
}

char Carnivoro::getSimbolo() const {
    return 'C';
}

