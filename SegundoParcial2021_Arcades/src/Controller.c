/*
 * Controller.c
 *
 *  Created on: 17 nov 2021
 *      Author: Nacho
 */

#include "Controller.h"
#include "parser.h"
#define NOMBRE_LEN 128

int controller_MainMenu (void)
{
	int userChoice=-1;

	 pedirIntIntentosRango(&userChoice, 1, 9, 5,
	"\n====MENU====\n\n"
	"1)Leer arcades desde archivo csv.\n"
	"2)Incorporar Arcade.\n"
	"3)Modificar Arcade\n"
	"4)Elimiar Arcade\n"
	"5)Mostrar Arcades\n"
	"6)Generar archivo con JUEGOS\n"
	"7)Generar archivo con arcades Multijugador\n"
	"8)Actualizar cantidad de fichas.\n"
	"9)Salir.\n", "Error, dato ingresado inválido");

	 return userChoice;
}

int controller_loadFromText(char* path , LinkedList* pArrayListArcades)
{

	int retorno=-1;

	FILE* f = fopen(path,"r");
	if(f!=NULL&&parser_ArcadeFromText(f, pArrayListArcades)==0)
	{
		printf("\n\n >>> Lista cargada con éxito! <<< \n\n");
		retorno=0;
		fclose(f);
	}


	return retorno;
}

int controller_addArcade(LinkedList* pArrayListArcades)
{
	int retorno=-1;
	int idAux;
	char nacionalidadAux[NOMBRE_LEN];
	int sonidoAux;
	int jugadoresAux;
	int fichasAux;
	char salonAux[NOMBRE_LEN];
	char juegoAux[NOMBRE_LEN];
    Arcade* pArcadeAux;

    pArcadeAux=arcade_new();
	if(pArcadeAux!=NULL)
	{
		if(arcade_askForInformation(nacionalidadAux, &sonidoAux, &jugadoresAux, &fichasAux,salonAux,juegoAux)==0)
		{
			FILE* f = fopen("IdMaxima.txt","r");
			if(f!=NULL)
			{
				idAux=arcade_createNewId(pArrayListArcades);
				fclose(f);
			} else
			{
				idAux=arcade_createFirstId(pArrayListArcades);
			}


			if(arcade_setId(pArcadeAux,idAux)==0)
			{
				if(arcade_setNacionalidad(pArcadeAux,nacionalidadAux)==0)
				{
					if(arcade_setSonido(pArcadeAux,sonidoAux)==0)
					{
						if(arcade_setJugadores(pArcadeAux,jugadoresAux)==0)
						{
							if(arcade_setFichas(pArcadeAux,fichasAux)==0)
							{
								if(arcade_setJuego(pArcadeAux,juegoAux)==0)
								{

									if(arcade_setSalon(pArcadeAux,salonAux)==0)
									{
										ll_add(pArrayListArcades,pArcadeAux);
										printf("\n >>> Arcade cargado con éxito! <<< \n");
										retorno=0;
										FILE* f = fopen("IdMaxima.txt","w");
										if(f!=NULL)
										{
											retorno=0;
											fprintf(f,"%d",idAux);
											fclose(f);
										}
									}
								}
							}

						}
					}
				}
			}
		}
	}
	else
	{
		printf("\nNo se pudo agregar el empleado\n");
	}

    return retorno;
}

int controller_saveAsText(char* path , LinkedList* pArrayListArcades)
{
	Arcade* pArcadeAux;
	int idAux;
	char nacionalidadAux[NOMBRE_LEN];
	int sonidoAux;
	char tipoSonidoTxtAux[NOMBRE_LEN];
	int jugadoresAux;
	int fichasAux;
	char salonAux[NOMBRE_LEN];
	char juegoAux[NOMBRE_LEN];

	int retorno=-1;

	FILE* f = fopen(path,"w");

	if(f!=NULL)
	{
		retorno=0;
		fprintf(f,"ID,Nacionalidad,Tipo de Sonido,Jugadores,Fichas,Salon,Juego\n");
		for(int i=0; i<ll_len(pArrayListArcades); i++)
		{
			pArcadeAux = ll_get(pArrayListArcades,i);
			if(pArcadeAux!=NULL)
			{
				arcade_getId(pArcadeAux,&idAux);
				arcade_getNacionalidad(pArcadeAux,nacionalidadAux);
				arcade_getSonido(pArcadeAux,&sonidoAux);
				if(sonidoAux==1)
				{
					strncpy(tipoSonidoTxtAux,"MONO",NOMBRE_LEN);
				} else
				{
					strncpy(tipoSonidoTxtAux,"ESTEREO",NOMBRE_LEN);
				}
				arcade_getJugadores(pArcadeAux,&jugadoresAux);
				arcade_getFichas(pArcadeAux,&fichasAux);
				arcade_getSalon(pArcadeAux,salonAux);
				arcade_getJuego(pArcadeAux,juegoAux);


				fprintf(f,"%d,%s,%s,%d,%d,%s,%s\n",idAux,nacionalidadAux,tipoSonidoTxtAux,jugadoresAux,fichasAux,salonAux,juegoAux);
			}

		}
		fclose(f);
	}



    return retorno;
}


int controller_ListArcades(LinkedList* pArrayListArcades)
{
	int retorno=-1;
	int i;
	int length;
	Arcade * pArcadeAux;

	if (pArrayListArcades!=NULL)
	{
		retorno=0;
		length=ll_len(pArrayListArcades);
		if(length>0)
		{
			for (i=0;length>i;i++)
			{
				pArcadeAux=ll_get(pArrayListArcades, i);
				if(pArcadeAux!=NULL)
				{
					arcade_printArcade(pArcadeAux);
				}

			}
		} else
		{
			printf("\nNo hay ningún empleado cargado para mostrar\n");
		}

	}
	else
	{
		printf("\nNo se encontró la lista\n");
	}
	return retorno;
}
