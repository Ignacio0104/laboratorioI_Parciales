/*
 * Arcades.h
 *
 *  Created on: 17 nov 2021
 *      Author: Nacho
 */

#ifndef JUEGOS_H_
#define JUEGO_H_
#include "Validaciones.h"
#include "LinkedList.h"
#include <string.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#define GAME_LEN 63

typedef struct {

	char gameName[GAME_LEN];

}Juego;

Juego* juego_new();
Juego* juego_newParametros(char*juegoStr);
int juego_printJuego(Juego* this);


//// SETTERS Y GETTERS ////
int juego_setNombreJuego(Juego* this,char* juego);
int juego_getNombreJuego(Juego* this,char* juego);




#endif /* ARCADES_H_ */
