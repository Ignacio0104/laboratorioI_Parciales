/*
 * Salon.h
 *
 *  Created on: 16 oct 2021
 *      Author: Nacho
 */

#ifndef SALON_H_
#define SALON_H_
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "biblioteca_input.h"

typedef struct {

	char name[128];
	char address[128];
	int type;
	int idSalon;
	int flagEmpty;

}eSalon;

/// \fn int salon_initList(eSalon*, int)
/// \brief Iniciliza todos los lugares de la lista en INACTIVO
/// \param salonList recibe la lista a recorrer
/// \param lenghtSalon recibe la longitud de la lista
/// \return Devuelve 0 si todo OK o -1 sin algo salio mal [lista o longitud invalida]
int salon_initList(eSalon *salonList,int lenghtSalon);



/// \fn int salon_loadSalon(eSalon*)
/// \brief Solicita los datos y los asigna a las posiciones indicadas de la estructura
/// \param pSalon recibe el puntero a la posicion libre de la estructura
/// \return Devuelve 0 si no hubo error o -1 si hubo error [lista o longitud invalida o datos invalidos]
int salon_loadSalon(eSalon *pSalon);



/// \fn int salon_buscarDisponible(eSalon*, int)
/// \brief Recorrer el array y busca una posición libre.
/// \param salonList recibe la lista a recorrer
/// \param lenghtSalon recibe la longitud de la lista
/// \return Devuelve la posición libre o -1 si hubo error
int salon_buscarDisponible(eSalon *salonList, int lenghtSalon);


/// \fn int salon_askForId(void)
/// \brief Pide un numero y valida que esté dentro de los parametros establecidos
/// \return Devuelve el ID o -1 si hubo error
int salon_askForId (void);



/// \fn int salon_buscarPorId(eSalon*, int, int)
/// \brief
///
/// \pre
/// \post
/// \param salonList
/// \param lenghtSalon
/// \param idIngresada
/// \return
int salon_buscarPorId (eSalon *salonList, int lenghtSalon, int idIngresada);
int salon_imprimirCompleto(eSalon *salonList, int lenghtSalon);
int salon_remove (eSalon *salonList, int lenghtSalon, int idIngresada);
void salon_altaForzada(eSalon *pSalon,char nombre[],char direccion[], int tipo, int id, int indice);
int salon_occupancy (eSalon *salonList, int lenghtSalon, int* pNotEmpty);

#endif /* SALON_H_ */
