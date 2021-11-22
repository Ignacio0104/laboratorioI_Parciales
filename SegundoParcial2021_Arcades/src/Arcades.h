/*
 * Arcades.h
 *
 *  Created on: 17 nov 2021
 *      Author: Nacho
 */

#ifndef ARCADES_H_
#define ARCADES_H_
#include "Validaciones.h"
#include "LinkedList.h"
#include <string.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#define NOMBRE_LEN 128
#define GAME_LEN 63

typedef struct {

	char nationality[NOMBRE_LEN];
	int soundType;
	int numberOfPlayers;
	int maximumTokens;
	char gameName[GAME_LEN];
	char salonName[NOMBRE_LEN];
	int idArcade;

}Arcade;

/// \fn Arcade arcade_new*()
/// \brief Crea un espacio de memoria para la estructura Arcade
///
/// \return Devuelve el puntero a la estructura o NULL si no pudo crearse
Arcade* arcade_new();

/// \fn Arcade arcade_newParametros*(char*, char*, char*, char*, char*, char*, char*)
/// \brief Crea un espacio de memoria para la estructura Arcade y asigna los valores pasados por parametro en cada campo
///
/// \param idStr ID en formato cadena de char
/// \param nacionalidadStr Nacionalidad en formato cadena de char
/// \param sonidoStr Tipo de sonido en formato cadena de char
/// \param jugadoresStr Cantidad de jugadores en formato cadena de char
/// \param fichasStr Cantidad de fichas en formato cadena de char char
/// \param salonStr Nombre del salno en formato cadena de char
/// \param juegoStr Nombre del juego en formato cadena de char
/// \return
Arcade* arcade_newParametros(char* idStr,char* nacionalidadStr,char* sonidoStr,char* jugadoresStr,char*fichasStr,char*salonStr,char*juegoStr);

/// \fn int arcade_printArcade(Arcade*)
/// \brief Imprime la estructura con todos sus campos
///
/// \param this Recibe la estructura
/// \return Devuelve 0 si pudo imprimir todos los elementos o -1 si hubo un error
int arcade_printArcade(Arcade* this);

/// \fn int arcade_askForInformation(char*, int*, int*, int*, char*, char*)
/// \brief Pide la información necesaria para cargar una estructura
///
/// \param pNacionalidad puntero cadena de char donde se guardará este dato
/// \param pSonido puntero a variable donde se guardará este dato
/// \param pJugadores puntero a variable donde se guardará este dato
/// \param pFichas puntero a variable donde se guardará este dato
/// \param pSalon punter cadena de char donde se guardará este dato
/// \param pJuego punter cadena de char donde se guardará este dato
/// \return Devuelve 0 si pudo guardar todos los elementos o -1 si hubo un error
int arcade_askForInformation(char *pNacionalidad, int* pSonido, int* pJugadores,int* pFichas, char* pSalon, char* pJuego);

/// \fn int arcade_createNewId(LinkedList*)
/// \brief Crea una nueva ID accediendo archivo referencial de ID maxima
///
/// \param pArrayArcade recibe puntero a LinkedList
/// \return Devuelve la ID nueva o -1 si hubo un error
int arcade_createNewId (LinkedList* pArrayArcade);

/// \fn int arcade_createFirstId(LinkedList*)
/// \brief Crea una nueva ID cuando no hay archivo referencial de ID maxima.
///
/// \param pArrayArcade recibe puntero a LinkedList
/// \return Devuelve la ID nueva o -1 si hubo un error
int arcade_createFirstId (LinkedList* pArrayArcade);

/// \fn int arcade_modify(Arcade*, LinkedList*)
/// \brief Modifica los campos que el usuario elija modificar
///
/// \param this Recibe puntero a estructura
/// \param pArrayArcade Recibe puntero a LinkedList
/// \return Devuelve 0 si pudo realizar todas las modificaciones o -1 si hubo un error
int arcade_modify(Arcade* this,LinkedList* pArrayArcade);

/// \fn int arcade_findById(LinkedList*, int)
/// \brief Recorre la LinkedList y busca el ID solicitado
///
/// \param pArrayArcade Recibe puntero a LinkedList
/// \param id Recibe el ID a buscar
/// \return Devuelve la posición del elemento o -1 si hubo un error
int arcade_findById(LinkedList* pArrayArcade,int id);

/// \fn int arcade_compareGame(void*, void*)
/// \brief Compara 2 campos de nombre Juego y establece cual es mayor, menor o si son iguales
///
/// \param arcadeUno Recibe puntero a elemento Uno
/// \param arcadeDos Recibe puntero a elemento Dos
/// \return Devuelve -2 si hubo un error,
/// 		-1 si la cadena Uno es menor que la cadena Dos,
/// 		1 si la cadena Dos es menor que la cadena Dos
/// 		o 0 si son iguales
int arcade_compareGame(void* arcadeUno,void* arcadeDos);

/// \fn int arcade_mostrarJuegos(LinkedList*)
/// \brief Imprime la todos los juegos cargados sin repetir
///
/// \param pArrayArcade Recibe la linkedList de Arcades
/// \return Devuelve 0 si salio bien o -1 si hubo un error
int arcade_mostrarJuegos(LinkedList* pArrayArcade);

/// \fn void arcade_delete(Arcade*)
/// \brief Borrar la estructura que recibe
///
/// \param this Recibe la estructura a borrar
void arcade_delete(Arcade* this);

/// \fn int arcade_filtroMultijugador(void*)
/// \brief Filtra los arcades por cantidad de jugadores
///
/// \param pArcade Recibe puntero a estructura
/// \return Devuelve 0 si el juego tiene solo un jugador, 1 si el juego tiene 2 o mas jugadores o -2 si hubo un error
int arcade_filtroMultijugador(void* pArcade);

/// \fn int arcade_doubleToken(void*)
/// \brief Recorre una estructura y duplica la cantidad de fichas
///
/// \param pArcade Recibe una estructura
/// \return Devuelve 0 si salio bien o -1 si hubo un error
int arcade_doubleToken(void* pArcade);

/// \fn int arcade_findLastId(LinkedList*)
/// \brief Recorre la LinkedList y devuelve el ID máximo
///
/// \param pArrayArcade Recibe la lista
/// \return Devuelva el ID o -1 si hubo un error
int arcade_findLastId(LinkedList* pArrayArcade);

/// \fn int arcade_editMenu(void)
/// \brief Imprime el menú de edición y pide al usuario el número de opción
///
/// \return Devuelve la elección del usuario o -1 si hubo un error
int arcade_editMenu (void);

/// \fn int arcade_cambiarTexto(int, char[])
/// \brief Convierte los valores númericos de sonido en texto
///
/// \param sonido Recibe el número del tipo de sonido
/// \param pTextoConvertido Puntero a cadena donde guardará el tipo de sonido en formato texto
/// \return Devuelve -1 si hubo un error o 0 si salio bien
int arcade_cambiarTexto (int sonido, char pTextoConvertido[]);


//// SETTERS Y GETTERS ////

/// \fn int arcade_setIdTxt(Arcade*, char*)
/// \brief
///
/// \param this
/// \param id
/// \return
int arcade_setIdTxt(Arcade* this,char* id);
int arcade_getIdTxt(Arcade* this,int* pId);
int arcade_setId(Arcade* this,int id);
int arcade_getId(Arcade* this,int* id);
int arcade_setNacionalidad(Arcade* this,char* nacionalidad);
int arcade_getNacionalidad(Arcade* this,char* nacionalidad);
int arcade_setSonidoTxt(Arcade* this,char* sonido);
int arcade_setSonido(Arcade* this,int sonido);
int arcade_getSonidoTxt(Arcade* this,char* sonido);
int arcade_getSonido(Arcade* this,int* sonido);
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
