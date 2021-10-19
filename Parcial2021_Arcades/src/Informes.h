/*
 * Informes.h
 *
 *  Created on: 16 oct 2021
 *      Author: Nacho
 */

#ifndef INFORMES_H_
#define INFORMES_H_
#include "biblioteca_input.h"
#include "Arcade.h"
#include "Salon.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define INACTIVO 1
#define ACTIVO 0


/// \fn int menuOperaciones(void)
/// \brief Imprime el menu de opciones principal y toma un numero
///
/// \return Devuelve el numero ingresado por el usuario
int menuOperaciones (void);



/// \fn char info_subMenuReports(void)
/// \brief Imprime el sub menu de reportes y toma un char
///
/// \return Devuelve el char ingresado por el usuario
char info_subMenuReports (void);



/// \fn int info_contarArcades(eArcade*, int, eSalon*, int)
/// \brief Cuenta todos los arcades ingresados por salon e imprime solo aquellos salones con mas de 4 arcades
///
/// \param arcadeList recibe la lista a recorrer
/// \param lenghtArcade recibe la longitud de la lista
/// \param lenghtSalon recibe la longitud de la lista
/// \param salonList recibe la lista a recorrer
/// \return Devuelve 0 si no hubo error o -1 si hubo error
int info_contarArcades (eArcade *arcadeList, int lenghtArcade,eSalon *salonList,int lenghtSalon);



/// \fn int info_contarJugadores(eArcade*, int, eSalon*, int)
/// \brief Agrupa en un array los arcades para mas de 2 jugadores y luego los imprime
///
/// \param arcadeList recibe la lista a recorrer
/// \param lenghtArcade recibe la longitud de la lista
/// \param lenghtSalon recibe la longitud de la lista
/// \param salonList recibe la lista a recorrer
/// \return Devuelve 0 si no hubo error o -1 si hubo error
int info_contarJugadores (eArcade *arcadeList, int lenghtArcade,eSalon *salonList,int lenghtSalon);



/// \fn int info_imprimirSalonPorId(eArcade*, int, eSalon*, int, int)
/// \brief Recibe un ID e imprime toda la informacino de ese salon
///
/// \param arcadeList recibe la lista a recorrer
/// \param lenghtArcade recibe la longitud de la lista
/// \param lenghtSalon recibe la longitud de la lista
/// \param salonList recibe la lista a recorrer
/// \param idIngresada numero ingresado por el usuario
/// \return Devuelve 0 si no hubo error o -1 si hubo error
int info_imprimirSalonPorId (eArcade *arcadeList, int lenghtArcade,eSalon *salonList,int lenghtSalon, int idIngresada);



/// \fn int info_imprimirArcadePorId(eArcade*, int, eSalon*, int, int)
/// \brief Recibe un ID e imprime toda la informacino de ese arcade
///
/// \param arcadeList recibe la lista a recorrer
/// \param lenghtArcade recibe la longitud de la lista
/// \param lenghtSalon recibe la longitud de la lista
/// \param salonList recibe la lista a recorrer
/// \param idIngresada numero ingresado por el usuario
/// \return Devuelve 0 si no hubo error o -1 si hubo error
int info_imprimirArcadePorId (eArcade *arcadeList, int lenghtArcade,eSalon *salonList,int lenghtSalon, int idIngresada);



/// \fn int info_imprimirSalonMasArcade(eArcade*, int, eSalon*, int)
/// \brief Buscar al salon con mas arcades y lo imprime por pantalla
///
/// \param arcadeList recibe la lista a recorrer
/// \param lenghtArcade recibe la longitud de la lista
/// \param lenghtSalon recibe la longitud de la lista
/// \param salonList recibe la lista a recorrer
/// \return Devuelve 0 si no hubo error o -1 si hubo error
int info_imprimirSalonMasArcade (eArcade *arcadeList, int lenghtArcade,eSalon *salonList,int lenghtSalon);



/// \fn int info_calcularFichasTotal(int, eArcade*, int, eSalon*, int)
/// \brief Calcula la capacidad maxima de fichas de un salon determinado
///
/// \param idIngresada numero ingresado por el usuario
/// \param arcadeList recibe la lista a recorrer
/// \param lenghtArcade recibe la longitud de la lista
/// \param lenghtSalon recibe la longitud de la lista
/// \param salonList recibe la lista a recorrer
/// \return Devuelve 0 si no hubo error o -1 si hubo error
int info_calcularFichasTotal (int idIngresada, eArcade *arcadeList, int lenghtArcade,eSalon *salonList,int lenghtSalon);



/// \fn float info_calcularGananciaTotal(int, float, eArcade*, int, eSalon*, int)
/// \brief Asigna un valor a las fichas, y realiza el calculo de la ganacia total de un salon determinado
///
/// \param idIngresada numero ingresado por el usuario
/// \param valorFicha float que representa el valor de las fichas
/// \param arcadeList recibe la lista a recorrer
/// \param lenghtArcade recibe la longitud de la lista
/// \param lenghtSalon recibe la longitud de la lista
/// \param salonList recibe la lista a recorrer
/// \return Devuelve 0 si no hubo error o -1 si hubo error
float info_calcularGananciaTotal (int idIngresada, float valorFicha,eArcade *arcadeList, int lenghtArcade,eSalon *salonList,int lenghtSalon);



/// \fn int info_juegoEnArcades(eArcade*, int, char[])
/// \brief Recorre todos los arcades para determinar en cuantos arcades se encuentra un determinado juego
///
/// \param arcadeList recibe la lista a recorrer
/// \param lenghtArcade recibe la longitud de la lista
/// \param nombreJuego cadena con el nombre del juego a buscar
/// \return Devuelve 0 si no hubo error o -1 si hubo error
int info_juegoEnArcades (eArcade *arcadeList, int lenghtArcade, char nombreJuego[]);



/// \fn int info_imprimirInformes(eArcade*, int, eSalon*, int, char)
/// \brief submenu interno que recibe la eleccion del usuario y llama a cada una de las funciones de reporte
///
/// \param arcadeList recibe la lista a recorrer
/// \param lenghtArcade recibe la longitud de la lista
/// \param lenghtSalon recibe la longitud de la lista
/// \param salonList recibe la lista a recorrer
/// \param eleccionUsuario recibe el char que eligió el usuario
/// \return Devuelve 0 si no hubo error o -2 si hubo error
int info_imprimirInformes (eArcade *arcadeList, int lenghtArcade,eSalon *salonList,int lenghtSalon, char eleccionUsuario);


#endif /* INFORMES_H_ */
