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

/// \fn Juego juego_new*()
/// \brief Crea un espacio de memoria para la estructura Juego
///
/// \return Devuelve el puntero a la estructura o NULL si no pudo crearse
Juego* juego_new();

/// \fn Juego juego_newParametros*(char*)
/// \brief Crea un espacio de memoria para la estructura Juego y asigna los valores pasados por parametro en cada campo
///
/// \param juegoStr Nombre del juego en formato cadena de char
/// \return Devuelve el puntero a la estructura o NULL si no pudo crearse
Juego* juego_newParametros(char*juegoStr);

/// \fn int juego_printJuego(Juego*)
/// \brief Imprime la estructura con todos sus campos
///
/// \param this Recibe la estructura
/// \return Devuelve 0 si pudo imprimir todos los elementos o -1 si hubo un error
int juego_printJuego(Juego* this);


//// SETTERS Y GETTERS ////

/// \fn int juego_setNombreJuego(Juego*, char*)
/// \brief Setea el valor pasado por parametro en el campo indicado de la estructura
///
/// \param this Recibe el puntero a la estructura
/// \param juego Recibe el nombre del juego a setear en formato cadena de char
/// \return Devuelve -1 si los punteros son inválidos, -2 si la cadena no es compatible o 0 si salió bien
int juego_setNombreJuego(Juego* this,char* juego);

/// \fn int juego_getNombreJuego(Juego*, char*)
/// \brief Consigue el nombre de juego desde la estructura
///
/// \param this Recibe el puntero a la estructura
/// \param juego Recibe puntero a variable donde se guardará el juego
/// \return Devuelve -1 si los punteros son inválidos, -2 si la cadena no es compatible o 0 si salió bien
int juego_getNombreJuego(Juego* this,char* juego);




#endif /* ARCADES_H_ */
