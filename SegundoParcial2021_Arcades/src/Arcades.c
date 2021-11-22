/*
 * Arcades.c
 *
 *  Created on: 17 nov 2021
 *      Author: Nacho
 */
#include "Arcades.h"

#define NOMBRE_LEN 128
#define GAME_LEN 63
#define TIPO_MONO 1
#define TIPO_ESTEREO 2


Arcade* arcade_new()
{
	Arcade* pArcade=(Arcade*)malloc(sizeof(Arcade));
	return pArcade;
}

Arcade* arcade_newParametros(char* idStr,char* nacionalidadStr,char* sonidoStr,char* jugadoresStr,char*fichasStr,char*salonStr,char*juegoStr)
{
	Arcade* pArcade=arcade_new();

	if(pArcade!=NULL)
	{
		if(idStr!=NULL&&nacionalidadStr!=NULL&&sonidoStr!=NULL&&jugadoresStr!=NULL&&fichasStr!=NULL&&salonStr!=NULL&&juegoStr!=NULL)
		{
			if(arcade_setIdTxt(pArcade,idStr)==0)
			{
				if(arcade_setNacionalidad(pArcade,nacionalidadStr)==0)
				{
					if(arcade_setSonidoTxt(pArcade,sonidoStr)==0)
					{
						if(arcade_setJugadoresTxt(pArcade,jugadoresStr)==0)
						{
							if(arcade_setFichasTxt(pArcade,fichasStr)==0)
							{
								if(arcade_setJuego(pArcade,juegoStr)==0)
								{
									arcade_setSalon(pArcade,salonStr);

								}
							}
						}


					}
				}
			}
		}
	}


	return pArcade;
}

int arcade_askForInformation(char *pNacionalidad, int* pSonido, int* pJugadores,int* pFichas, char* pSalon, char* pJuego)
{
	int retorno=-1;
	char nacionalidadAux[NOMBRE_LEN];
	int sonidoAux;
	int jugadoresAux;
	int fichasAux;
	char salonAux[NOMBRE_LEN];
	char juegoAux[GAME_LEN];

	if(pNacionalidad!=NULL&&pSonido!=NULL&&pJugadores!=NULL&&pFichas!=NULL&&pSalon!=NULL&&pJuego!=NULL)
	{
		if(pedirNombre(nacionalidadAux,NOMBRE_LEN, 3, "Ingrese la nacionalidad del arcade: ", "Error, dato ingresado inválido")==0)
		{
			if(pedirIntIntentosRango(&sonidoAux,1, 2, 3, "Ingrese el tipo de sonido \n"
															"1)MONO\n"
															"2)STEREO\n", "Error, dato ingresado inválido")==0)
			{
				if(pedirIntIntentosRango(&jugadoresAux,1, 6, 3, "Ingrese la cantidad de jugadores: ", "Error, dato ingresado inválido")==0)
				{
					if(pedirIntIntentosRango(&fichasAux,1, INT_MAX, 3, "Ingrese la cantidad de fichas: ", "Error, dato ingresado inválido")==0)
					{
						if(pedirNombreSalon(salonAux,NOMBRE_LEN, 3, "Ingrese el nombre del Salón: ", "Error, dato ingresado inválido")==0)
						{

							if(pedirNombreJuego(juegoAux,GAME_LEN, 3, "Ingrese el juego: ", "Error, dato ingresado inválido")==0)
								{
									strncpy(pNacionalidad,nacionalidadAux,NOMBRE_LEN);
									*pSonido=sonidoAux;
									*pJugadores=jugadoresAux;
									*pFichas=fichasAux;
									strncpy(pJuego,juegoAux,NOMBRE_LEN);
									strncpy(pSalon,salonAux,NOMBRE_LEN);
									retorno=0;
								}
						}
					}
				}
			}
		}
	}

	return retorno;
}

int arcade_createFirstId (LinkedList* pArrayArcade)
{
	int idAnterior;
	int idNueva;
	idAnterior=arcade_findLastId(pArrayArcade);

	if(idAnterior>=0)
	{
		idNueva=idAnterior+1;
	}

	return idNueva;
}


int arcade_createNewId (LinkedList* pArrayArcade)
{
	int idAnterior;
	int idNueva;
	char idAux[100];

	idNueva=-1;

	if(pArrayArcade!=NULL)
	{
		FILE* f = fopen("IdMaxima.txt","r");
			if(f!=NULL)
			{
				fscanf(f,"%s",idAux);

				if(esNumerica(idAux)==0)
				{
					idAnterior=atoi(idAux);
				}
				fclose(f);
			}

			if(idAnterior>=0)
			{
				idNueva=idAnterior+1;
			}
	}


	return idNueva;
}

int arcade_modify(Arcade* this,LinkedList* pArrayArcade)
{
	int retorno=-1;
	char juegoAux[GAME_LEN];
	int jugadoresAux;
	char banderaSalir='n';

	int userChoice;

	if(this!=NULL)
	{
		userChoice=arcade_editMenu();

			if(userChoice<0)
			{
				userChoice=3;
			}

			while(banderaSalir!='s')
			{
				switch (userChoice)
				{
					case 1:
						arcade_mostrarJuegos(pArrayArcade);
						if(pedirTexto(juegoAux,GAME_LEN, 1, "Ingrese el nuevo nombre: ", "Error, dato ingresado inválido\n")==0)
						{
							if(arcade_setJuego(this,juegoAux)==0)
							{
								printf("\n >>> Nombre modificado con éxito <<< \n");
								retorno=0;
							} else
							{
								printf("\nNo se pudo modificar\n");

							}
						}else
						{
							printf("\nError al ingresar los datos\n");
						}

						userChoice=arcade_editMenu();

							if(userChoice<0)
							{
								userChoice=3;
							}


						break;
					case 2:

						if(pedirIntIntentosRango(&jugadoresAux,0, INT_MAX, 1, "Ingrese la cantidad de jugadores: ", "Error, dato ingresado inválido")==0)
						{
							if(arcade_setJugadores(this,jugadoresAux)==0)
							{
								printf("\n >>> Cantidad de jugadores modificada con éxito <<< \n");
								retorno=0;
							}else
							{
								printf("\nNo se pudo modificar\n");

							}
						}else
						{
							printf("\nError al ingresar los datos\n");
						}

						userChoice=arcade_editMenu();

							if(userChoice<0)
							{
								userChoice=3;
							}


						break;
					case 3:
						printf("Volviendo al menú principal\n");
						banderaSalir='s';
						break;

				}
		}
	}


	return retorno;
}

int arcade_editMenu (void)
{
	int userChoice=-1;

	 pedirIntIntentosRango(&userChoice, 1, 3, 5,
			 "\n\nQue dato desea modificar?\n"
			"	1)Nombre del juego\n"
			"	2)Cantidad de jugadores\n"
			"	3)Salir\n", "Error, dato ingresado inválido");

	 return userChoice;
}



int arcade_printArcade(Arcade* this)
{
	int retorno;
	int idAux;
	char nacionalidadAux[NOMBRE_LEN];
	int tipoSonidoAux;
	char tipoSonidoTxtAux[NOMBRE_LEN];
	int jugadoresAux;
	int fichasAux;
	char salonAux[NOMBRE_LEN];
	char juegoAux[NOMBRE_LEN];

	retorno=-1;

	if(this!=NULL)
	{

		arcade_getId(this,&idAux);
		arcade_getNacionalidad(this,nacionalidadAux);
		arcade_getSonido(this,&tipoSonidoAux);
		if(tipoSonidoAux==1)
		{
			strncpy(tipoSonidoTxtAux,"MONO",NOMBRE_LEN);
		} else
		{
			strncpy(tipoSonidoTxtAux,"STEREO",NOMBRE_LEN);
		}
		arcade_getJugadores(this,&jugadoresAux);
		arcade_getFichas(this,&fichasAux);
		arcade_getSalon(this,salonAux);
		arcade_getJuego(this,juegoAux);
		printf("Arcade ID: %d - Nacionalidad: %s - Sonido: %s - Jugadores: %d - Fichas: %d - Salon: %s - Juego: %s\n"
				,idAux,nacionalidadAux,tipoSonidoTxtAux,jugadoresAux,fichasAux,salonAux,juegoAux);
		retorno=0;
	}

	return retorno;
}



int arcade_findById(LinkedList* pArrayArcade,int id)
{
	int retorno;
	Arcade* pElemento;
	int idLista;
	int longitud;

	retorno=-1;

	if(pArrayArcade!=NULL&&id>=0)
	{
		longitud=ll_len(pArrayArcade);
		for(int i=0;i<longitud;i++)
		{
			if(ll_get(pArrayArcade, i)!=NULL)
			{
				pElemento=ll_get(pArrayArcade, i);

				if(arcade_getId(pElemento,&idLista)==0)
				{
					if(idLista==id)
					{
						retorno=i;
						break;
					}
				}

			}

		}

	}

	return retorno;
}


int arcade_findLastId(LinkedList* pArrayArcade)
{
	Arcade* pElemento;
	int idLista;
	int longitud;
	int idMaxima=-1;

	if(pArrayArcade!=NULL)
	{
		idMaxima=0;
		longitud=ll_len(pArrayArcade);
		for(int i=0;i<longitud;i++)
		{
			if(ll_get(pArrayArcade, i)!=NULL)
			{
				pElemento=ll_get(pArrayArcade, i);

				arcade_getId(pElemento,&idLista);

				if(idLista>idMaxima)
				{
					idMaxima=idLista;
				}

			}

		}

	}

	return idMaxima;
}
int arcade_mostrarJuegos(LinkedList* pArrayArcade)
{
	int retorno=-1;
	int lenght;
	Arcade* pArcadeAux;
	Arcade* pArcadeComparacion;
	int criterio;
	char nombreJuegoAux[GAME_LEN];

	if(pArrayArcade!=NULL)
	{
		lenght=ll_len(pArrayArcade);
		ll_sort(pArrayArcade,arcade_compareGame,0);

		if(lenght>0)
		{
			printf("\nJuegos ya cargados en el sistema: \n\n");
			for(int i=0;i<=lenght;i++)
			{
				pArcadeAux=ll_get(pArrayArcade,i);
				pArcadeComparacion=ll_get(pArrayArcade,i+1);
				if(pArcadeAux!=NULL)
				{
					criterio=arcade_compareGame(pArcadeAux,pArcadeComparacion);

					if(criterio==0)
					{
						continue;

					}else
					{
						arcade_getJuego(pArcadeAux,nombreJuegoAux);
						printf("-Juego: %s\n",nombreJuegoAux);

					}
				}

			}

		}
	}

	return retorno;
}

int arcade_filtroMultijugador(void* pArcade)
{
    int retorno=-2;
    Arcade* prueba=(Arcade*)pArcade;
    int jugadoresAux;

    if(pArcade!=NULL)
	{
		arcade_getJugadores(prueba,&jugadoresAux);

		if (jugadoresAux==1)
		{
			retorno=0;
			arcade_delete(pArcade);
		} else
		{
			retorno=1;
		}
	}

    return retorno;
}

int arcade_doubleToken(void* pArcade)
{
    int retorno=-2;
    int fichasAux;

    if(pArcade!=NULL)
	{
    	arcade_getFichas(pArcade,&fichasAux);
    	fichasAux=fichasAux*2;
    	arcade_setFichas(pArcade,fichasAux);
    	retorno=0;

	}

    return retorno;
}

void arcade_delete(Arcade* this)
{
	if(this!=NULL)
	{
		free(this);
		this=NULL;
	}

}



int arcade_compareGame(void* arcadeUno,void* arcadeDos)
{
    int retorno=-2;

    char nombreAuxUno[GAME_LEN];
    char nombreAuxDos[GAME_LEN];

    if(arcadeUno!=NULL&&arcadeDos!=NULL)
	{
		arcade_getJuego((Arcade*)arcadeUno,nombreAuxUno);
		arcade_getJuego((Arcade*)arcadeDos,nombreAuxDos);

		int comparacion = strcmp(nombreAuxUno,nombreAuxDos);
		if (comparacion<0)
		{
			retorno=1;
		}
		else
		{
			if (comparacion>0)
			{
				retorno=-1;
			} else
			{
				retorno=0;
			}
		}
	}

    return retorno;
}



int arcade_cambiarTexto (int sonido, char pTextoConvertido[])
{
	int retorno;

	switch (sonido)
	{
		case TIPO_MONO:
			retorno=0;
			strncpy(pTextoConvertido,"MONO",32);
			break;
		case TIPO_ESTEREO:
			strncpy(pTextoConvertido,"STEREO",32);
			retorno=0;
			break;
	}



	return retorno;
}


//// SETTERS Y GETTERS ////

int arcade_setIdTxt(Arcade* this,char* id)
{
	int retorno=-1;
	int idAux;
	if(this!=NULL&&id!=NULL)
	{
		retorno=-2;

		if(esNumerica(id)==0)
		{
			idAux=atoi(id);
			this->idArcade=idAux;
			retorno=0;

		}

	}

	return retorno;
}


int arcade_getIdTxt(Arcade* this,int* pId)
{
	int retorno=-1;
	if(this!=NULL&&pId!=NULL)
	{
		*pId=this->idArcade;
		retorno=0;
	}

	return retorno;
}


int arcade_setId(Arcade* this,int id)
{
	int retorno=-1;
	if(this!=NULL&&id>=0)
	{
		this->idArcade=id;
		retorno=0;
	}

	return retorno;
}

int arcade_getId(Arcade* this,int* id)
{
	int retorno=-1;
	if(this!=NULL&&id!=NULL)
	{
		*id=this->idArcade;
		retorno=0;
	}

	return retorno;
}

int arcade_setNacionalidad(Arcade* this,char* nacionalidad)
{
	int retorno=-1;
	if(this!=NULL&&nacionalidad!=NULL)
	{
		retorno=-2;
		if(esTexto(nacionalidad)==0)
		{
			strncpy(this->nationality,nacionalidad,NOMBRE_LEN);
			retorno=0;
		}
	}

	return retorno;
}

int arcade_getNacionalidad(Arcade* this,char* nacionalidad)
{
	int retorno=-1;
	if(this!=NULL&&nacionalidad!=NULL)
	{
		retorno=-2;
		if(esTexto(this->nationality)==0)
		{
			strncpy(nacionalidad,this->nationality,NOMBRE_LEN);
			retorno=0;
		}
	}

	return retorno;
}

int arcade_setSonidoTxt(Arcade* this,char* sonido)
{
	int retorno=-1;
	if(this!=NULL&&sonido!=NULL)
	{
		retorno=-2;
		if(esTipoSonido(sonido)==0)
		{
			if(strcmp(sonido,"MONO")==0)
			{
				this->soundType=TIPO_MONO;
				retorno=0;
			} else
			{
				this->soundType=TIPO_ESTEREO;
				retorno=0;
			}

		}
	}

	return retorno;
}


int arcade_setSonido(Arcade* this,int sonido)
{
	int retorno=-1;

	if(this!=NULL && (sonido==1||sonido==2))
	{
		this->soundType=sonido;
		retorno=0;
	}

	return retorno;
}


int arcade_getSonidoTxt(Arcade* this,char* sonido)
{
	int retorno=-1;
	int sonidoAux;
	if(this!=NULL&&sonido!=NULL)
	{
		retorno=-2;
		sonidoAux=this->soundType;

		arcade_cambiarTexto(sonidoAux, sonido);
	}

	return retorno;
}

int arcade_getSonido(Arcade* this,int* sonido)
{
	int retorno=-1;
	if(this!=NULL&&sonido!=NULL)
	{
		*sonido=this->soundType;
		retorno=0;
	}

	return retorno;
}

int arcade_setJugadoresTxt(Arcade* this,char* jugadores)
{
	int retorno=-1;
	int jugadoresAux;
	if(this!=NULL&&jugadores!=NULL)
	{
		retorno=-2;
		if(esNumerica(jugadores)==0)
		{
			jugadoresAux=atoi(jugadores);
			this->numberOfPlayers=jugadoresAux;
			retorno=0;
		}
	}

	return retorno;
}

int arcade_setJugadores(Arcade* this,int jugadores)
{
	int retorno=-1;
	if(this!=NULL&&jugadores>0)
	{
		this->numberOfPlayers=jugadores;
		retorno=0;
	}

	return retorno;
}

int arcade_getJugadores(Arcade* this,int* jugadores)
{
	int retorno=-1;
	if(this!=NULL&&jugadores!=NULL)
	{
		*jugadores=this->numberOfPlayers;
		retorno=0;
	}

	return retorno;
}

int arcade_setFichasTxt(Arcade* this,char* fichas)
{
	int retorno=-1;
	int fichasAux;
	if(this!=NULL&&fichas!=NULL)
	{
		retorno=-2;
		if(esNumerica(fichas)==0)
		{
			fichasAux=atoi(fichas);
			this->maximumTokens=fichasAux;
			retorno=0;
		}
	}

	return retorno;
}

int arcade_setFichas(Arcade* this,int fichas)
{
	int retorno=-1;
	if(this!=NULL&&fichas>0)
	{
		this->maximumTokens=fichas;
		retorno=0;
	}

	return retorno;
}

int arcade_getFichas(Arcade* this,int* fichas)
{
	int retorno=-1;
	if(this!=NULL&&fichas!=NULL)
	{
		*fichas=this->maximumTokens;
		retorno=0;
	}

	return retorno;
}

int arcade_setSalon(Arcade* this,char* salon)
{
	int retorno=-1;
	if(this!=NULL&&salon!=NULL)
	{
		retorno=-2;

		if(esNombreSalonJuego(salon)==0)
		{
			strncpy(this->salonName,salon,NOMBRE_LEN);
			retorno=0;
		}
	}

	return retorno;
}

int arcade_getSalon(Arcade* this,char* salon)
{
	int retorno=-1;
	if(this!=NULL&&salon!=NULL)
	{
		retorno=-2;
		if(esNombreSalonJuego(this->salonName)==0)
		{
			strncpy(salon,this->salonName,NOMBRE_LEN);
			retorno=0;
		}
	}

	return retorno;
}

int arcade_setJuego(Arcade* this,char* juego)
{
	int retorno=-1;
	if(this!=NULL&&juego!=NULL)
	{
		retorno=-2;
		if(esNombreSalonJuego(juego)==0)
		{
			strncpy(this->gameName,juego,GAME_LEN);
			retorno=0;
		}
	}

	return retorno;
}

int arcade_getJuego(Arcade* this,char* juego)
{
	int retorno=-1;
	if(this!=NULL&&juego!=NULL)
	{
		retorno=-2;
		if(esNombreSalonJuego(this->gameName)==0)
		{
			strncpy(juego,this->gameName,GAME_LEN);
			retorno=0;
		}
	}

	return retorno;
}


