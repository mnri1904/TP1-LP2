/*
 * Planta.h
 *
 *  Created on: 12 abr 2026
 *      Author: marce
 */

#ifndef PLANTA_H_
#define PLANTA_H_
#include "EntidadViva.h"

class Planta : public EntidadViva {
	/*
	 * Clase heredada
	 */
public:
    Planta(int f, int c);
    char getSimbolo() const override;
};
#endif /* PLANTA_H_ */
