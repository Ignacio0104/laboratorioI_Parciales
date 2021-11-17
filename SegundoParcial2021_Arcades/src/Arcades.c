/*
 * Arcades.c
 *
 *  Created on: 17 nov 2021
 *      Author: Nacho
 */
#include "Arcades.h"

#define NOMBRE_LEN 128
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
	char juegoAux[NOMBRE_LEN];

	if(pNacionalidad!=NULL&&pSonido!=NULL&&pJugadores!=NULL&&pFichas!=NULL&&pSalon!=NULL&&pJuego!=NULL)
	{
		if(pedirNombre(nacionalidadAux,NOMBRE_LEN, 3, "Ingrese la nacionalidad del arcade: ", "Error, dato ingresado inválido")==0)
		{
			if(pedirIntIntentosRango(&sonidoAux,1, 2, 3, "Ingrese el tipo de sonido 1)MONO 2)ESTEREO: ", "Error, dato ingresado inválido")==0)
			{
				if(pedirIntIntentosRango(&jugadoresAux,1, 6, 3, "Ingrese la cantidad de jugadores: ", "Error, dato ingresado inválido")==0)
				{
					if(pedirIntIntentosRango(&fichasAux,1, INT_MAX, 3, "Ingrese la cantidad de fichas: ", "Error, dato ingresado inválido")==0)
					{
						if(pedirNombre(salonAux,NOMBRE_LEN, 3, "Ingrese el nombre del Salón: ", "Error, dato ingresado inválido")==0)
						{

							if(pedirNombre(juegoAux,NOMBRE_LEN, 3, "Ingrese el juego: ", "Error, dato ingresado inválido")==0)
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
	idAnterior=6;

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
			strncpy(tipoSonidoTxtAux,"ESTEREO",NOMBRE_LEN);
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


/*
int arc_cambiarTexto (Arcade *pArrayArcade, int posicion, char pTextoConvertido[])
{
	int retorno;

	retorno=-1;
	switch(arcadeList[posicion].soundType)
	{
		case TIPO_MONO:
			retorno=0;
			strncpy(pTextoConvertido,"Mono",32);
			break;
		case TIPO_ESTEREO:
			strncpy(pTextoConvertido,"Estereo",32);
			retorno=0;
			break;
	}

	return retorno;
}*/


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
		if(esTexto(sonido)==0)
		{
			if(strcmp(sonido,"MONO")==0)
			{
				this->soundType=2;
				retorno=0;
			} else
			{
				this->soundType=1;
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

		if(sonidoAux==1)
		{
			strncpy(sonido,"MONO",NOMBRE_LEN);
			retorno=0;
		} else
		{
			strncpy(sonido,"ESTEREO",NOMBRE_LEN);
			retorno=0;
		}
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

		if(esTexto(salon)==0)
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
		if(esTexto(this->salonName)==0)
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
		if(esTexto(juego)==0)
		{
			strncpy(this->gameName,juego,NOMBRE_LEN);
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
		if(esTexto(this->gameName)==0)
		{
			strncpy(juego,this->gameName,NOMBRE_LEN);
			retorno=0;
		}
	}

	return retorno;
}


