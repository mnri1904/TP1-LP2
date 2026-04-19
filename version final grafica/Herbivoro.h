/*
 * Herbivoro.h
 *
 *  Created on: 12 abr 2026
 *      Author: marce
 */

#ifndef HERBIVORO_H_
#define HERBIVORO_H_

#include "EntidadViva.h"

class Herbivoro : public EntidadViva {
    /*
     * Clase heredada
     */
public:
    Herbivoro(int f, int c);
    char getSimbolo() const override;
};



#endif /* HERBIVORO_H_ */