//============================================================================
// Name        : generacionTablero.cpp
// Author      : Marcelo Romero
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <time.h>
#include <vector>
using namespace std;

void pedirDimension(int *filas, int *columnas) {
	/*
	 * Función que se encarga de pedir al usuario las dimensiones de la matriz deseada (2 < filas < 10 || 2 < columnas < 10)
	 */
	do {
		cout << "Introduce la dimensión de la matriz" << endl;
		cout << "Filas: ";
		cin >> *filas;
		cout << "Columnas: ";
		cin >> *columnas;
		cout << endl;
	}while((*filas > 10 || *filas < 3) || (*columnas > 10 || *columnas < 3));
}

void generarTablero(vector<vector<char>>& matriz, int filas, int columnas) {
	/*
	 * Funcion que se encarga de generar el tablero de forma aleatoria con caracteres ASCII (letras P, H, C o espacios)
	 * Parámetros:
	 * vector<vector<char>>& matriz -> la direccion del tablero original
	 * filas -> numero de filas del tablero
	 * columnas -> numero de columnas del tablero
	 *
	 */

	int i, j;
	for (i = 0; i < filas; i++) {
		for (j = 0; j < columnas; j++) {
			/*Se genera un numero aleatorio entre 0 y 4, luego a cada número se le hace corresponder un caracter*/
			int num = rand() % 4;

			if (num == 0) {
				matriz[i][j] = ' ';
			}
			else if (num == 1) {
				matriz[i][j] = 'P';
			}
			else if (num == 2) {
				matriz[i][j] = 'H';
			}
			else {
				matriz[i][j] = 'C';
			}
		}
	}
}

void imprimirTablero(vector<vector<char>>& matriz, int filas, int columnas) {
	/*
	 * Funcion que se encarga de imprimir el tablero en pantalla
	 * Parámetros:
	 * vector<vector<char>>& matriz -> la direccion del tablero original
	 * filas -> numero de filas del tablero
	 * columnas -> numero de columnas del tablero
	 *
	 */
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            cout << "+---";
        }
        cout << "+" << endl;

        for (int j = 0; j < columnas; j++) {
            cout << "| " << matriz[i][j] << " ";
        }
        cout << "|" << endl;
    }

    for (int j = 0; j < columnas; j++) {
        cout << "+---";
    }
    cout << "+" << endl;
}

int main() {
	srand(time(NULL));
	int filas, columnas;
	pedirDimension(&filas, &columnas);
	cout << "Número de Filas: " << filas << " Número de Columnas: " << columnas<< endl;
	vector<vector<char>> tablero(filas, vector<char>(columnas));
	generarTablero(tablero, filas, columnas);
	imprimirTablero(tablero, filas, columnas);
	return 0;
}
