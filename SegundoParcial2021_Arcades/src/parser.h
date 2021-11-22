/*
 * parcer.h
 *
 *  Created on: 7 nov 2021
 *      Author: Nacho
 */

#ifndef PARSER_H_
#define PARSER_H_
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Arcades.h"


/// \fn int parser_ArcadeFromText(FILE*, LinkedList*)
/// \brief  Parsea los datos los datos de los arcades desde el archivo dataArcades.csv (modo texto).
///
/// \param pFile Ruta de acceso archivo.csv
/// \param pArrayArcades Puntero a la lista
/// \return Devuelve 0 si salió bien o -1 si hubo un error
int parser_ArcadeFromText(FILE* pFile , LinkedList* pArrayArcades);



#endif /* PARSER_H_ */
