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
    char banderaListaJuegos='n';
    char banderaListaMultijugador='n';
    LinkedList* listaArcades = ll_newLinkedList();
    LinkedList* listaJuegos = ll_newLinkedList();
    LinkedList* listaArcadesMultijugador;

    if(controller_loadFromText("dataArcades.csv",listaArcades)==0)
    {
    	  eleccionUsuario=controller_MainMenu();
    } else
    {
    	printf("Hubo un error. Favor verificar el archivo de origen\n");
    }

    while(banderaCierre!='s')
    {
        switch(eleccionUsuario)
        {
            case 1:
            	if(controller_addArcade(listaArcades)==0)
            	{
            		controller_saveAsText("dataArcades.csv",listaArcades);
            	}
            	eleccionUsuario=controller_MainMenu();
                break;
            case 2:
            	if(controller_editArcade(listaArcades)==0)
            	{
            		controller_saveAsText("dataArcades.csv",listaArcades);
            	}
            	eleccionUsuario=controller_MainMenu();
                break;
            case 3:
            	if(controller_removeArcade(listaArcades)==0)
            	{
            		controller_saveAsText("dataArcades.csv",listaArcades);
            	}
            	eleccionUsuario=controller_MainMenu();
                break;
            case 4:
            	controller_ListArcades(listaArcades);
            	printf("\nLa lista contiene %d elementos",ll_len(listaArcades));
            	eleccionUsuario=controller_MainMenu();
                break;
            case 5:
            	if(banderaListaJuegos=='s')
            	{
            		ll_clear(listaJuegos);
            		if(controller_addJuego(listaArcades,listaJuegos)==0)
					{
						banderaListaJuegos='s';
					}
            	} else
            	{
                	if(controller_addJuego(listaArcades,listaJuegos)==0)
                	{
                		banderaListaJuegos='s';
                	}
            	}
            	controller_ListJuego(listaJuegos);
            	printf("\nLa lista contiene %d elementos",ll_len(listaJuegos));
            	eleccionUsuario=controller_MainMenu();
                break;
            case 6:
            	listaArcadesMultijugador=ll_subList(listaArcades,0,ll_len(listaArcades));
            	if(listaArcadesMultijugador!=NULL)
            	{
            		ll_filter(listaArcadesMultijugador,arcade_filtroMultijugador);
                	controller_saveAsText("multijugador.csv",listaArcadesMultijugador);
                	banderaListaMultijugador='s';
            	}
            	controller_ListArcades(listaArcadesMultijugador);
            	printf("\nLa lista contiene %d elementos",ll_len(listaArcadesMultijugador));
            	eleccionUsuario=controller_MainMenu();
                break;
            case 7:
            	if(controller_dobleFichas(listaArcades)==0)
            	{
            		controller_saveAsText("dataArcades.csv",listaArcades);
            	}
            	eleccionUsuario=controller_MainMenu();
                break;
            case 8:
        		printf("Saliendo del sistema....\n");
        		ll_deleteLinkedList(listaArcades);
        		if(banderaListaJuegos=='s')
        			{
        				ll_deleteLinkedList(listaJuegos);
        			}

        		if(banderaListaMultijugador=='s')
        		{
            		ll_deleteLinkedList(listaArcadesMultijugador);
        		}
				banderaCierre='s';
                break;
        }
    }
    return 0;
}

