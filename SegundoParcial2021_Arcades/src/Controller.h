/*
 * Controller.h
 *
 *  Created on: 17 nov 2021
 *      Author: Nacho
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_
#include "Validaciones.h"
#include "LinkedList.h"
#include "Juegos.h"
#include "Arcades.h"
#include <string.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>


/// \fn int controller_MainMenu(void)
/// \brief Muestra el menú principal y toma el número elegido por el usuario
///
/// \return Devuelve -1 si hubo error o elección del usuario
int controller_MainMenu (void);

/// \fn int controller_ListArcades(LinkedList*)
/// \brief Imprime todos los elementos de la lista
///
/// \param pArrayListArcades Recibe puntero a la lista
/// \return Devuelve 0 si salio OK o -1 si hubo un error.
int controller_ListArcades(LinkedList* pArrayListArcades);

/// \fn int controller_loadFromText(char*, LinkedList*)
/// \brief Carga la linkedList desde un archivo de texto
///
/// \param path Recibe la ruta al archivo de donde se sacarán los datos
/// \param pArrayListArcades Recibe puntero a la lista
/// \return Devuelve 0 si salio OK o -1 si hubo un error.
int controller_loadFromText(char* path , LinkedList* pArrayListArcades);

/// \fn int controller_addArcade(LinkedList*)
/// \brief Crea el espacio de memoria para un estructura de tipo Arcade, carga sus datos, y la agrega a la lista
///
/// \param pArrayListArcades Recibe puntero a la lista
/// \return Devuelve 0 si salio OK o -1 si hubo un error.
int controller_addArcade(LinkedList* pArrayListArcades);

/// \fn int controller_addJuego(LinkedList*, LinkedList*)
/// \brief Crea una lista con los nombres de los juegos sin repetir, los guarda en la linkedlist y en un archivo .txt
///
/// \param pArrayListArcades Recibe puntero a la lista de origen
/// \param pArrayJuegos Recibe puntero a la lista donde guardarán los datos
/// \return Devuelve 0 si salio OK o -1 si hubo un error.
int controller_addJuego(LinkedList* pArrayListArcades,LinkedList* pArrayJuegos);

/// \fn int controller_ListJuego(LinkedList*)
/// \brief Imprime todos los juegos cargados
///
/// \param pArrayJuegos Recibe puntero a lista de juegos
/// \return Devuelve 0 si salio OK o -1 si hubo un error.
int controller_ListJuego(LinkedList* pArrayJuegos);

/// \fn int controller_saveAsText(char*, LinkedList*)
/// \brief Guarda la lista en un archivo .csv
///
/// \param path Recibe la ruta del archivo donde se va a guardar
/// \param pArrayListArcades Recibe puntero a la lista que se va a guardar
/// \return Devuelve 0 si salio OK o -1 si hubo un error.
int controller_saveAsText(char* path , LinkedList* pArrayListArcades);

/// \fn int controller_editArcade(LinkedList*)
/// \brief Permite editar los campos jugadores y nombre de juego de cualquier estructura
///
/// \param pArrayListArcades Recibe puntero a la lista
/// \return Devuelve 0 si salio OK o -1 si hubo un error.
int controller_editArcade(LinkedList* pArrayListArcades);

/// \fn int controller_sortArcade(LinkedList*)
/// \brief Ordena la LinkedList por nombre de juego
///
/// \param pArrayListArcades Recibe puntero a la lista
/// \return Devuelve 0 si salio OK o -1 si hubo un error.
int controller_sortArcade(LinkedList* pArrayListArcades);

/// \fn int controller_removeArcade(LinkedList*)
/// \brief Elimina un arcade la lista
///
/// \param pArrayListArcades Recibe puntero a la lista
/// \return Devuelve 0 si salio OK o -1 si hubo un error.
int controller_removeArcade(LinkedList* pArrayListArcades);

/// \fn int controller_dobleFichas(LinkedList*)
/// \brief Recorre toda la lista y duplica el valor del campo de fichas de todas las estructuras
///
/// \param pArrayListArcades Recibe puntero a la lista
/// \return Devuelve 0 si salio OK o -1 si hubo un error.
int controller_dobleFichas(LinkedList* pArrayListArcades);



#endif /* CONTROLLER_H_ */
