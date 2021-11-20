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
    LinkedList* listaJuegos = ll_newLinkedList();
    LinkedList* listaArcadesMultijugador;

   eleccionUsuario=controller_MainMenu();

    while(banderaCierre!='s')
    {
        switch(eleccionUsuario)
        {
            case 1:
            	controller_loadFromText("dataArcades.csv",listaArcades);
                eleccionUsuario=controller_MainMenu();
                break;
            case 2:
            	if(controller_addArcade(listaArcades)==0)
            	{
            		controller_saveAsText("dataArcades.csv",listaArcades);
            	}
            	eleccionUsuario=controller_MainMenu();
                break;
            case 3:
            	if(controller_editArcade(listaArcades)==0)
            	{
            		controller_saveAsText("dataArcades.csv",listaArcades);
            	}
            	eleccionUsuario=controller_MainMenu();
                break;
            case 4:
            	controller_removeArcade(listaArcades);
            	eleccionUsuario=controller_MainMenu();
                break;
            case 5:
            	controller_ListArcades(listaArcades);
            	eleccionUsuario=controller_MainMenu();
                break;
            case 6:
            	controller_addJuego(listaArcades,listaJuegos);
            	controller_ListJuego(listaJuegos);
            	eleccionUsuario=controller_MainMenu();
                break;
            case 7:
            	listaArcadesMultijugador=ll_subList(listaArcades,0,ll_len(listaArcades));
            	if(listaArcadesMultijugador!=NULL)
            	{
            		ll_filter(listaArcadesMultijugador,arcade_filtroMultijugador);
            		printf("Filtrado\n\n");
            	}
            	controller_ListArcades(listaArcadesMultijugador);
            	eleccionUsuario=controller_MainMenu();
                break;
            case 8:
            	ll_map (listaArcades,arcade_doubleToken);
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

