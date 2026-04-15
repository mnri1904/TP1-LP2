#ifndef GAMECONFIG_H
#define GAMECONFIG_H

#include <QString>

struct GameSettings {
    int filas = 3;
    int columnas = 3;
    int carnivoroVariante = 0;   // 0 = Warwick, 1 = Naafiri
    int herbivoroVariante = 0; // 0 = Teemo, 1 = Fizz
    int plantaVariante = 0; // 0 Honeyfruit, 1 Bloodroses
};

extern GameSettings gSettings;

#endif