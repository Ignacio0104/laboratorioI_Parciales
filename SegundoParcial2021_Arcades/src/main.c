/*
 ============================================================================
 Name        : SegundoParcial2021_Arcades.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "biblioteca_input.h"


int main()
{
	setbuf(stdout,NULL);
    int eleccionUsuario;
    char banderaCierre='n';
    LinkedList* listaArcades = ll_newLinkedList();

   eleccionUsuario=controller_MainMenu();

    while(banderaCierre!='s')
    {
        switch(eleccionUsuario)
        {
            case 1:
            	printf("En construcción...\n");
            	//controller_loadFromText("data.csv",listaEmpleados);
                eleccionUsuario=controller_MainMenu();
                break;
            case 2:
            	printf("En construcción...\n");
            	//controller_addEmployee(listaEmpleados);
            	eleccionUsuario=controller_MainMenu();
                break;
            case 3:
            	printf("En construcción...\n");
            	//controller_editEmployee(listaEmpleados);
            	eleccionUsuario=controller_MainMenu();
                break;
            case 4:
            	printf("En construcción...\n");
            	//controller_removeEmployee(listaEmpleados);
            	eleccionUsuario=controller_MainMenu();
                break;
            case 5:
            	printf("En construcción...\n");
            	//controller_ListEmployee(listaEmpleados);
            	eleccionUsuario=controller_MainMenu();
                break;
            case 6:
            	printf("En construcción...\n");
            	//controller_saveAsText("data.csv", listaEmpleados);
            	eleccionUsuario=controller_MainMenu();
                break;
            case 7:
            	printf("En construcción...\n");
            	//controller_saveAsText("data.csv", listaEmpleados);
            	eleccionUsuario=controller_MainMenu();
                break;
            case 8:
            	printf("En construcción...\n");
            	//controller_doubleTokens();
            	eleccionUsuario=controller_MainMenu();
                break;
            case 9:
        		printf("Saliendo del sistema....\n");
				banderaCierre='s';
				break;
        }
    }
    return 0;
}

