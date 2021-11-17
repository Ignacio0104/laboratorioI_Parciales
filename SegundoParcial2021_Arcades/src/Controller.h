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
#include <string.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int controller_MainMenu (void);
int controller_ListArcades(LinkedList* pArrayListArcades);
int controller_loadFromText(char* path , LinkedList* pArrayListArcades);
int controller_addArcade(LinkedList* pArrayListArcades);

#endif /* CONTROLLER_H_ */
