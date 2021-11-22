/*
 * Validaciones.h
 *
 *  Created on: 7 nov 2021
 *      Author: Nacho
 */

#ifndef VALIDACIONES_H_
#define VALIDACIONES_H_
#include "biblioteca_input.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/// \fn int esNombre(char[])
/// \brief Valida que la cadena sea de formato Nombre (valida letras, espacios y guiones)
///
/// \param cadena Recibe la cadena a evaluar
/// \return Devuelve 0 si el formato es correcto o -1 si hubo un error
int esNombre(char cadena[]);

/// \fn int pedirNombre(char[], int, int, char*, char*)
/// \brief Pide al usuario que ingrese un nombre
///
/// \param pResultado Puntero a variable donde guardará el texto ingresado
/// \param lenght Longitud máxima de la cadena
/// \param reintentos cantidad de reintentos
/// \param variableTexto Texto que verá el usuario antes de cargar
/// \param textoError Texto de error que verá el usuario al equivocarse
/// \return Devuelve 0 si salio bien o -1 si hubo un error
int pedirNombre(char pResultado[],int lenght, int reintentos, char* variableTexto, char* textoError);

/// \fn int esNombreSalonJuego(char[])
/// \brief Valida que la cadena sea de formato Nombre Salon/Juego (valida letras, número, espacios,guiones, puntos y &)
///
/// \param cadena Recibe la cadena a evaluar
/// \return Devuelve 0 si el formato es correcto o -1 si hubo un error
int esNombreSalonJuego (char cadena[]);

/// \fn int pedirNombreJuego(char[], int, int, char*, char*)
/// \brief Pide al usuario que ingrese un nombre de Juego
///
/// \param pResultado Puntero a variable donde guardará el texto ingresado
/// \param lenght Longitud máxima de la cadena
/// \param reintentos cantidad de reintentos
/// \param variableTexto Texto que verá el usuario antes de cargar
/// \param textoError Texto de error que verá el usuario al equivocarse
/// \return Devuelve 0 si salio bien o -1 si hubo un error
int pedirNombreJuego(char pResultado[],int lenght, int reintentos, char* variableTexto, char* textoError);

/// \fn int pedirNombreSalon(char[], int, int, char*, char*)
/// \brief Pide al usuario que ingrese un nombre de Salon
///
/// \param pResultado Puntero a variable donde guardará el texto ingresado
/// \param lenght Longitud máxima de la cadena
/// \param reintentos cantidad de reintentos
/// \param variableTexto Texto que verá el usuario antes de cargar
/// \param textoError Texto de error que verá el usuario al equivocarse
/// \return Devuelve 0 si salio bien o -1 si hubo un error
int pedirNombreSalon(char pResultado[],int lenght, int reintentos, char* variableTexto, char* textoError);

/// \fn int esTipoSonido(char[])
/// \brief Valida que la cadena sea de formato tipo sonido (STEREO O MONO)
///
/// \param cadena Recibe la cadena a evaluar
/// \return Devuelve 0 si el formato es correcto o -1 si hubo un error
int esTipoSonido (char cadena[]);

#endif /* VALIDACIONES_H_ */
