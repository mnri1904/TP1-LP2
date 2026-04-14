/*
 * Carnivoro.h
 *
 *  Created on: 12 abr 2026
 *      Author: marce
 */

#ifndef CARNIVORO_H_
#define CARNIVORO_H_

#include "EntidadViva.h"

class Carnivoro : public EntidadViva {
	/*
	 * Clase heredada
	 */
public:
    Carnivoro(int f, int c);
    char getSimbolo() const override;
};



#endif /* CARNIVORO_H_ */
