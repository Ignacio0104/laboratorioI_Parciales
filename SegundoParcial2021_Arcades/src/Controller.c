/*
 * Controller.c
 *
 *  Created on: 17 nov 2021
 *      Author: Nacho
 */

#include "Controller.h"
#include "parser.h"


#define NOMBRE_LEN 128
#define GAME_LEN 63

int controller_MainMenu (void)
{
	int userChoice=-1;

	 pedirIntIntentosRango(&userChoice, 1, 8, 5,
	"\n====MENU====\n\n"
	"1)Incorporar Arcade.\n"
	"2)Modificar Arcade\n"
	"3)Elimiar Arcade\n"
	"4)Mostrar Arcades\n"
	"5)Generar archivo con JUEGOS\n"
	"6)Generar archivo con arcades Multijugador\n"
	"7)Actualizar cantidad de fichas.\n"
	"8)Salir.\n", "Error, dato ingresado inválido");

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

int controller_addJuego(LinkedList* pArrayListArcades,LinkedList* pArrayJuegos)
{
	int retorno=-1;
	int lenght;
	char nombreJuegoAux[GAME_LEN];
	int criterio;
	Arcade* pArcadeUno;
	Arcade* pArcadeDos;
	Juego* pJuegoAux;


	if(pArrayListArcades!=NULL)
	{
		retorno=0;
		lenght=ll_len(pArrayListArcades);
		controller_sortArcade(pArrayListArcades);
		FILE* f = fopen("juegos.txt","w");
		if(f!=NULL)
		{
			retorno=0;
			for(int i=0;i<lenght;i++)
			{
				pArcadeUno=ll_get(pArrayListArcades,i);
				pArcadeDos=ll_get(pArrayListArcades,i+1);


				criterio=arcade_compareGame(pArcadeUno,pArcadeDos);

					if(criterio==1||criterio==-1)
					{
						arcade_getJuego(pArcadeUno,nombreJuegoAux);
						pJuegoAux=juego_newParametros(nombreJuegoAux);
						if(pJuegoAux!=NULL)
						{
							if(ll_contains(pArrayJuegos, pJuegoAux)==0)
							{
								fprintf(f,"%s\n",nombreJuegoAux);
								ll_add(pArrayJuegos,pJuegoAux);
							} else
							{
								free(pJuegoAux);
								continue;
							}

						}

					} else
					{
						if(pArcadeDos==NULL)
						{
							pArcadeDos=ll_get(pArrayListArcades,i-1);

							if(arcade_compareGame(pArcadeUno,pArcadeDos)==0)
							{
								arcade_getJuego(pArcadeUno,nombreJuegoAux);
								pJuegoAux=juego_newParametros(nombreJuegoAux);
								if(nombreJuegoAux!=NULL)
								{
									fprintf(f,"%s\n",nombreJuegoAux);
									ll_add(pArrayJuegos,pJuegoAux);
									break;
								}
							}
						}
					}


			}

			fclose(f);
		}
	}

    return retorno;
}

int controller_ListJuego(LinkedList* pArrayJuegos)
{
	int retorno=-1;
	int i;
	int length;
	Juego * pJuegoAux;

	if (pArrayJuegos!=NULL)
	{
		retorno=0;
		length=ll_len(pArrayJuegos);
		if(length>0)
		{
			for (i=0;length>i;i++)
			{
				pJuegoAux=ll_get(pArrayJuegos, i);
				if(pJuegoAux!=NULL)
				{
					juego_printJuego(pJuegoAux);
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
		controller_sortArcade(pArrayListArcades);
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
			printf("\nNo hay ningún arcade cargado para mostrar\n");
		}

	}
	else
	{
		printf("\nNo se encontró la lista\n");
	}
	return retorno;
}



int controller_editArcade(LinkedList* pArrayListArcades)
{
	int retorno=-1;
	int idPedida;
	int posicionPedida;
	int lenght;
	Arcade * pArcadeAux;

	lenght=ll_len(pArrayListArcades);

	if(lenght>0)
	{
		controller_ListArcades(pArrayListArcades);

		if(pedirInt(&idPedida, 1, "\n\nIngrese el ID que del arcade que desea modificar: ", "Error, dato ingresado inválido\n")==0)
		{
			posicionPedida=arcade_findById(pArrayListArcades,idPedida);

			if(posicionPedida>=0)
			{
				pArcadeAux=ll_get(pArrayListArcades, posicionPedida);

				if(pArcadeAux!=NULL)
				{
					if(arcade_modify(pArcadeAux,pArrayListArcades)==0)
					{
						retorno=0;
					}
				}
			} else
			{
				printf("No se encontró el arcade solicitado\n\n");
			}
		}


	} else
	{
		printf("\nNo hay ningún arcade cargado para editar\n");
	}



    return retorno;
}

int controller_removeArcade(LinkedList* pArrayListArcades)
{
    int retorno=-1;

    Arcade* pArcadeAux;
    int posicionArcade;
    int idPedida;
	char nacionalidadAux[NOMBRE_LEN];
	char juegoAux[GAME_LEN];
	char salonAux[NOMBRE_LEN];;
	char userChoice;
	int lenght;

	lenght=ll_len(pArrayListArcades);

	if(lenght>0)
	{
		controller_ListArcades(pArrayListArcades);
		if(pedirInt(&idPedida, 1, "Ingrese el ID del arcade que desea borrar: \n", "Error, ID ingresada inválida\n")==0)
		 {
			 posicionArcade=arcade_findById(pArrayListArcades,idPedida);
				if(posicionArcade>=0)
				{
					pArcadeAux=ll_get(pArrayListArcades, posicionArcade);

					if(pArcadeAux!=NULL)
					{
						arcade_getJuego(pArcadeAux,juegoAux);
						arcade_getSalon(pArcadeAux,salonAux);
						arcade_getNacionalidad(pArcadeAux,nacionalidadAux);

						printf("Se va a eliminar al arcade:\n"
								"ID: %d, Juego: %s, Salon: %s, Nacionalidad: %s",idPedida,juegoAux,salonAux,nacionalidadAux);

						pedirCharSiNo(&userChoice, 's', 'n', 2, "\n\n ---------Presione [s] para confirmar o [n] para volver al menu principal---------\n",
													"Error, dato ingresado inválido\n");
						if(userChoice=='s')
						{
							ll_remove(pArrayListArcades,posicionArcade);
							arcade_delete(pArcadeAux);
							printf("\nArcade borrado del sistema\n");
							retorno=0;
						}
						else
						{
							printf("\nNo se borrará el Arcade\n");
							retorno=0;
						}
					}

				}
				else
				{
					printf("\nNo se encontró el arcade en la lista\n");
				}

		 }


		} else
		{
			printf("\nNo hay ningún arcade cargado para borrar\n");
		}


    return retorno;
}
int controller_sortArcade(LinkedList* pArrayListArcades)
{
    int retorno=-1;
	int lenght;

	if (pArrayListArcades!=NULL)
	{
		lenght=ll_len(pArrayListArcades);
		if(lenght>0)
		{
			if(ll_sort(pArrayListArcades,arcade_compareGame,0)==0)
			{
				retorno=0;
			}
		}else
		{
			printf("\nNo hay juegos cargados para ordenar\n");
		}

	}

    return retorno;
}

int controller_dobleFichas(LinkedList* pArrayListArcades)
{
    int retorno=-1;
	int lenght;

	if (pArrayListArcades!=NULL)
	{
		lenght=ll_len(pArrayListArcades);
		if(lenght>0)
		{
			if(ll_map(pArrayListArcades,arcade_doubleToken)==0)
			{
				printf(">>> Fichas de todos los arcades duplicadas <<<");
				retorno=0;
			}
		}else
		{
			printf("\nNo hay juegos cargados para ordenar\n");
		}

	}

    return retorno;
}
