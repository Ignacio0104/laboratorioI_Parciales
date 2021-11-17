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


int parser_ArcadeFromText(FILE* pFile , LinkedList* pArrayArcades);
//int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee);


#endif /* PARSER_H_ */
