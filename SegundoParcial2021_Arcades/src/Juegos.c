/*
 * Arcades.c
 *
 *  Created on: 17 nov 2021
 *      Author: Nacho
 */
#include "Juegos.h"


#define GAME_LEN 63



Juego* juego_new()
{
	Juego* pJuego=(Juego*)malloc(sizeof(Juego));
	return pJuego;
}

Juego* juego_newParametros(char*juegoStr)
{
	Juego* pJuego=juego_new();

	if(pJuego!=NULL)
	{
		if(juegoStr!=NULL)
		{
			juego_setNombreJuego(pJuego,juegoStr);
		}
	}
	return pJuego;
}


int juego_printJuego(Juego* this)
{
	int retorno;
	char juegoAux[GAME_LEN];

	retorno=-1;

	if(this!=NULL)
	{
		juego_getNombreJuego(this,juegoAux);
		printf("Juego: %s\n",juegoAux);
		retorno=0;
	}

	return retorno;
}


//// SETTERS Y GETTERS ////

int juego_setNombreJuego(Juego* this,char* juego)
{
	int retorno=-1;
	if(this!=NULL&&juego!=NULL)
	{
		retorno=-2;
		if(esTexto(juego)==0)
		{
			strncpy(this->gameName,juego,GAME_LEN);
			retorno=0;
		}
	}

	return retorno;
}

int juego_getNombreJuego(Juego* this,char* juego)
{
	int retorno=-1;
	if(this!=NULL&&juego!=NULL)
	{
		retorno=-2;
		if(esTexto(this->gameName)==0)
		{
			strncpy(juego,this->gameName,GAME_LEN);
			retorno=0;
		}
	}

	return retorno;
}


