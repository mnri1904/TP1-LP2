/*
 * Ecosistema.h
 *
 *  Created on: 10 abr 2026
 *      Author: marce
 */

#ifndef ECOSISTEMA_H_
#define ECOSISTEMA_H_

#include <vector>
#include <iostream>
#include <utility>
#include "EntidadViva.h"
using namespace std;


class Ecosistema {
private:
    int filas;
    int columnas;
    int ciclo;
    vector<vector<char>> tablero;
    vector<EntidadViva*> entidades;	// vector de punteros a objetos de tipo EntidadViva
    Ecosistema *eco = nullptr;

public:
    Ecosistema(int f, int c);
    ~Ecosistema();					// destructor para eliminar las cosas creadas dinámicamente

    //getters
    int getFilas() const;
    int getColumnas() const;
    int getCiclo() const;

    //metodos
    void generarTablero();
    void imprimirTablero() const;
    void avanzarCiclo();
    bool aggPlantas();
    bool reproducirPlantas();
    bool aggEntidad(char entidad);
    bool turnoEntidad(char entidad, char presa);
    bool buscarEntidad(char entidad, vector<pair<int,int>>& posicEntidad);
    bool entidadCome(char presa, char entidad, int f, int c);
    bool entidadMueve(int f, int c, char entidad);
    int *verificarEsquinas();
    void contadorEntidad(char entidad);
    void inicializarEstado();
    void mostrarEntidades() const;
    void limpiarMuertas();
    void entidadesEnvejecen();
    void muertePorEdad();
    void restarEnergia();
    void muertePorEnergia();

    /*método auxiliar para fabricar entidades*/
    EntidadViva* crearEntidad(char entidad, int f, int c);

    /*método que sirve para buscar la entidad por posición*/
    EntidadViva* obtenerEntidad(int f, int c) const;

    /*m;etodo para depurar tema de edad energia*/
    void mostrarEstadoEntidades() const;

    const vector<vector<char>>& getTablero() const;
    int contarEntidad(char entidad) const;
    void setEcosistema(Ecosistema *ecoPtr);
};

#endif /* ECOSISTEMA_H_ */