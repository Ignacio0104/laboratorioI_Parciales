/*
 * Arcades.h
 *
 *  Created on: 17 nov 2021
 *      Author: Nacho
 */

#ifndef ARCADES_H_
#define ARCADES_H_
#include "Validaciones.h"
#include <string.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {

	char nationality[128];
	int soundType;
	int numberOfPlayers;
	int maximumTokens;
	char gameName[63];
	char salonName[128];
	int idArcade;
	int flagEmpty;

}Arcade;

Arcade* arcade_new();

//// SETTERS Y GETTERS ////
int arcade_setIdTxt(Arcade* this,char* id);
int arcade_getIdTxt(Arcade* this,int* pId);
int arcade_setId(Arcade* this,int id);
int arcade_getId(Arcade* this,int* id);
int arcade_setNacionalidad(Arcade* this,char* nacionalidad);
int arcade_getNacionalidad(Arcade* this,char* nacionalidad);
int arcade_setSonidoTxt(Arcade* this,char* sonido);
int arcade_setSonido(Arcade* this,int sonido);
int arcade_getSonido(Arcade* this,char* sonido);
int arcade_setJugadoresTxt(Arcade* this,char* jugadores);
int arcade_setJugadores(Arcade* this,int jugadores);
int arcade_getJugadores(Arcade* this,int* jugadores);
int arcade_setFichasTxt(Arcade* this,char* fichas);
int arcade_setFichas(Arcade* this,int fichas);
int arcade_getFichas(Arcade* this,int* fichas);
int arcade_setSalon(Arcade* this,char* salon);
int arcade_getSalon(Arcade* this,char* salon);
int arcade_setJuego(Arcade* this,char* juego);
int arcade_getJuego(Arcade* this,char* juego);




#endif /* ARCADES_H_ */
