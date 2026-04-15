#ifndef GAMECONFIG_H
#define GAMECONFIG_H

#include <QString>

/*
 * Estructura GameSettings
 *
 * Guarda todas las configuraciones del juego seleccionadas por el usuario.
 * Se utiliza como configuración global accesible desde distintas partes del programa (UI, lógica, renderizado).
 */
struct GameSettings {
    int filas = 3; //cantidad de filas
    int columnas = 3; //cantidad de columnas
    int carnivoroVariante = 0;   // 0 = Warwick, 1 = Naafiri
    int herbivoroVariante = 0; // 0 = Teemo, 1 = Fizz
    int plantaVariante = 0; // 0 Honeyfruit, 1 Bloodroses
};
/*
 * Variable global de configuración.
 *
 * Se declara como extern para poder ser utilizada en múltiples archivos.
 */
extern GameSettings gSettings;

#endif
