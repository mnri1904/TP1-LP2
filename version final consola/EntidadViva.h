/*
 * EntidadViva.h
 *
 *  Created on: 12 abr 2026
 *      Author: marce
 */

#ifndef ENTIDADVIVA_H_
#define ENTIDADVIVA_H_

class EntidadViva {
	/*
	 * Clase para representar a cualquier ser vivo del ecosistema
	 */
protected:
    int fila;		// Guarda la fila en la que está la entidad dentro del tablero
    int columna;	// Guarda la columna donde está la entidad
    int energia;
    int edad;
    bool viva;			// cuando energia llega 0 viva = false

public:
    EntidadViva(int f, int c, int e);	// Constructor
    virtual ~EntidadViva();				// Destructor

    int getFila() const;
    int getColumna() const;
    void ponerPosicion(int f, int c);	// Sirve para cambiar la posición de la entidad

    int getEnergia() const;
    void ponerEnergia(int e);		// Sirve para cambiar la energía al comer o al pasar un ciclo

    int getEdad() const;
    void aumentarEdad();				// Sirve para aumentar la edad en cada ciclo

    bool estadoVida() const;			// Devuelve si la entidad sigue viva o no
    void muerte();						// Sirve para marcar la entidad como muerta

    virtual char getSimbolo() const = 0;	// Sirve para que cada clase hija diga qué carácter representa

};



#endif /* ENTIDADVIVA_H_ */
