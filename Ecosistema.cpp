/*
 * Ecosistema.cpp
 *
 *  Created on: 10 abr 2026
 *      Author: marce
 */
#include "Ecosistema.h"
Ecosistema::Ecosistema(int f, int c) {
	filas = f;
	columnas = c;
	ciclo = 0;
	tablero = vector<vector<char>>(filas, vector<char>(columnas));
	generarTablero();
}

void Ecosistema::generarTablero() {
	/*
	 * Funcion que se encarga de generar el tablero con espacios
	 *
	 */

	int i, j;
	for (i = 0; i < filas; i++) {
		for (j = 0; j < columnas; j++) {
			tablero[i][j] = ' ';
		}
	}
}

void Ecosistema::imprimirTablero() const {
	/*
	 * Funcion que se encarga de imprimir el tablero en pantalla
	 */
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            cout << "+---";
        }
        cout << "+" << endl;

        for (int j = 0; j < columnas; j++) {
            cout << "| " << tablero[i][j] << " ";
        }
        cout << "|" << endl;
    }

    for (int j = 0; j < columnas; j++) {
        cout << "+---";
    }
    cout << "+" << endl;
}

int* Ecosistema::verificarEsquinas() {
	/*
	 * Función que se encarga de verificar si las esquinas del tablero están ocupadas por alguna entidad
	 * Valor de retorno:
	 * puntero a vector de int que contiene [i,j]
	 */
	int i, j;
	static int esquina[2];
	int *p = esquina;
	for (i = 0; i < filas; i++) {
		for (j = 0; j < columnas; j++) {
			if (i == 0 && (j == 0 || j == columnas - 1)) {
				if (tablero[i][j] == ' ') {
					esquina[0] = i;
					esquina[1] = j;
					return p;
				}
			}
			else if (i == filas-1 && (j == 0 || j == columnas - 1)) {
				if (tablero[i][j] == ' ') {
					esquina[0] = i;
					esquina[1] = j;
					return p;
				}
			}
		}
	}
	return NULL;
}

bool Ecosistema::aggPlantas() {
    int f = rand() % filas;
    int c = rand() % columnas;
    // busca desde una posicion aleatoria en adelante
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            int ni = (f + i) % filas;
            int nj = (c + j) % columnas;
            if (tablero[ni][nj] == ' ') {
                tablero[ni][nj] = 'P';
                return true;
            }
        }
    }
    return false;
}

bool Ecosistema::aggEntidad(char entidad) {
	/*
	 * Función que se encarga de simular la llegada de un herbívoro/carnívoro al ecosistema a través de las esquinas del tablero
	 *
	 */
	int *esquina;
	if ((esquina = verificarEsquinas()) != NULL) {
		tablero[esquina[0]][esquina[1]] = entidad;
		return true;
	}
	return false;
}

bool Ecosistema::reproducirPlantas() {
	/*
	 * Función que se encarga de verificar si es posible reproducir plantas en el ciclo actual
	 * Parámetros:
	 * vector<vector<char>>& matriz -> tablero
	 * filas -> numero de filas de la matriz
	 * columnas -> numero de columnas de la matriz
	 * Valor de retorno:
	 * true -> si la reproducción es posible
	 * false -> si la reproducción no es posible
	 *
	 */

	int i, j;
	bool existePlantaReproducible = false;

	// Verificar si existe al menos una planta que tenga lugar para reproducirse
	for (i = 0; i < filas; i++) {
		for (j = 0; j < columnas; j++) {
			if (tablero[i][j] == 'P') {
				int hayLugar = 0;

				for (int f = i - 1; f <= i + 1; f++) {	// recorre la fila anterior y posterior
					for (int c = j - 1; c <= j + 1; c++) {	// recorre la columna anterior y posterior
						if (f >= 0 && f < filas && c >= 0 && c < columnas) {	// se valida el rango de la matriz
							if (!(f == i && c == j) && tablero[f][c] == ' ') {	// si el lugar actual no es donde esta la planta y esta vacio
								hayLugar++;
							}
						}
					}
				}

				if (hayLugar > 0) {
					existePlantaReproducible = true;
				}
			}
		}
	}

	if (existePlantaReproducible == false) {

		return false;
	}

	int filaRandom, columnaRandom, hayLugar;

	// Buscar una planta aleatoria que sí tenga al menos un vecino vacío
	do {
		filaRandom = rand() % filas;
		columnaRandom = rand() % columnas;
		hayLugar = 0;

		if (tablero[filaRandom][columnaRandom] == 'P') {
			for (i = filaRandom - 1; i <= filaRandom + 1; i++) {
				for (j = columnaRandom - 1; j <= columnaRandom + 1; j++) {
					if (i >= 0 && i < filas && j >= 0 && j < columnas) {
						if (!(i == filaRandom && j == columnaRandom) && tablero[i][j] == ' ') {
							hayLugar++;
						}
					}
				}
			}
		}

	} while (tablero[filaRandom][columnaRandom] != 'P' || hayLugar == 0);

	int filaDestino, columnaDestino;
	bool reproduccionValida;

	do {
		filaDestino = rand() % filas;
		columnaDestino = rand() % columnas;


		/*la reproducción no es válida si el destino está a más de una fila de distancia por arriba o abajo*/
		if (filaDestino - filaRandom > 1 || filaDestino - filaRandom < -1) {
			reproduccionValida = false;
		}
		/*la reproducción no es válida si el destino está a más de una fila de distancia por derecha o izquierda*/
		else if (columnaDestino - columnaRandom > 1 || columnaDestino - columnaRandom < -1) {
			reproduccionValida = false;
		}
		/*no se puede sobrescribir la misma planta en el mismo lugar*/
		else if (filaDestino == filaRandom && columnaDestino == columnaRandom) {
			reproduccionValida = false;
		}
		else {
			reproduccionValida = true;
		}

	} while (reproduccionValida == false || tablero[filaDestino][columnaDestino] != ' ');

	tablero[filaDestino][columnaDestino] = 'P';
	return true;
}

bool Ecosistema::buscarEntidad(char entidad, vector<pair<int,int>>& posicEntidad) {
	/*
	 * Función que se encarga de recorrer la matriz para seleccionar un herbívoro/carnívoro para luego evaluar si puede comer una planta
	 */
	int i,j;
	for (i = 0; i < filas; i++) {
		for (j = 0; j < columnas; j++) {
			if (tablero[i][j] == entidad) {
				posicEntidad.push_back({i,j});	// guardamos cada posicion en el vector en formato de par ordenado
				return true;
			}
		}
	}
	return false;
}

bool Ecosistema::entidadCome(char presa, char entidad, int f, int c) {
	/*
	 * Función que se encarga de verificar si el herbívoro correspondiente puede comer una planta
	 * Parámetros:
	 * matriz -> tablero del simulador
	 * filas -> numero de filas de la matriz
	 * columnas -> numero de columnas de la matriz
	 * f -> primera coordenada de la ubicación del herbívoro
	 * c -> segunda coordenada de la ubicación del herbívoro
	 */

	// Buscamos solo en las celdas vecinas (de -1 a +1 en filas y columnas)
	for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {

        	if (i == 0 && j == 0) {
        		/*skipeamos i = 0 y j = 0 porque es la celda actual*/
        		continue;
        	}

        	int ni = f + i;
        	int nj = c + j;

        	// Verificamos que las coordenadas vecinas no se salgan de la matriz
        	if (ni >= 0 && ni < filas && nj >= 0 && nj < columnas) {

        		if (tablero[ni][nj] == presa) {
        			tablero[ni][nj] = entidad;
        			tablero[f][c] = ' ';
        			return true;
        		}
        	}
        }
	}
    return false;
}

bool Ecosistema::entidadMueve(int f,int c, char entidad) {
	/*
	 * Función que busca un espacio vacío alrededor de un herbívoro/carnívoro para moverlo.
	 */
	// Buscamos en las celdas vecinas (de -1 a +1)
	for (int i = -1; i <= 1; i++) {
		for (int j = -1; j <= 1; j++) {

			/*skipeamos i = 0 y j = 0 porque es la celda actual*/
			if (i == 0 && j == 0) {
				continue;
			}

			int ni = f + i;
			int nj = c + j;

			/*Verificamos que las coordenadas vecinas no se salgan de la matriz*/
			if (ni >= 0 && ni < filas && nj >= 0 && nj < columnas) {
				if (tablero[ni][nj] == ' ') {
					tablero[ni][nj] = entidad; // La entidad se mueve a la nueva celda
					tablero[f][c] = ' ';   // Deja su posición original vacía
					return true;          // Se movió con éxito
				}
			}
		}
	}

    return false; // Retorna falso si estaba rodeado o si no encontró herbívoros
}

bool Ecosistema::turnoEntidad(char entidad, char presa) {
	/*
	 * Función que se encarga de realizar las acciones correspondientes a los carnívoros
	 *
	 */

	bool hizoAlgo = false;				// bandera para indicar si un carnívoro ya actuó o no
	vector<pair<int,int>> posicEntidad;		// vector donde se guardarán las posiciones de los herbivoros/carnivoros en el tablero en cada ciclo
	if (buscarEntidad(entidad, posicEntidad)) {

		for (size_t k = 0; k < posicEntidad.size(); k++) {

			/*Se itera sobre el vector con las posiciones de la entidad y se guarda el valor de cada coordenada individualmente
			 * en f (fila) y c (columna)*/

			int f = posicEntidad[k].first;
			int c = posicEntidad[k].second;

			if (tablero[f][c] != entidad) {
				/*En caso que en esa posicion no esté una entidad pasamos al siguiente*/
				continue;
			}

			if (entidadCome(presa, entidad, f, c)) {
				hizoAlgo = true;
			}
			else if (entidadMueve(f, c, entidad)) {
				hizoAlgo = true;
			}
		}
		return hizoAlgo;
	}
	return hizoAlgo;
}

void Ecosistema::avanzarCiclo() {
    ciclo++;

    cout << "\n==============================" << endl;
    cout << "CICLO " << ciclo << endl;
    cout << "==============================" << endl;

    /*Las plantas se reproducen en cada ciclo*/

    if (reproducirPlantas()) {
    	cout << "Se reprodujo una planta" << endl;
    }

    /*Turno de los herbívoros*/
    if (turnoEntidad('H', 'P')) {
    	cout << "Un herbívoro actuó" << endl;
    }
    else {
    	cout << "No actuaron herbívoros" << endl;
    }

    /*Turno de los carnívoros*/
    if (turnoEntidad('C', 'H')) {
        cout << "Un carnívoro actuó" << endl;
    } else {
        cout << "No actuaron carnívoros" << endl;
    }

    /*Agregar herbívoros cada 2 ciclos*/
    if (ciclo % 2 == 0) {
    	if (aggEntidad('H')) {
    		cout << "Un herbívoro llegó al ecosistema" << endl;
    	}
    	else {
    		cout << "No hay esquinas libres para que ingrese un herbívoro." << endl;
    	}
    }

    /*Agregar carnivoros cada 4 ciclos*/
    if (ciclo % 4 == 0) {
    	if(aggEntidad('C')) {
    		cout << "Llegó un carnívoro al ecosistema." << endl;
    	}
    	else {
    		cout << "No hay esquinas libres para que ingrese un carnívoro." << endl;
    	}
    }
    cout << "Ciclo actual: " << ciclo << endl;
}
