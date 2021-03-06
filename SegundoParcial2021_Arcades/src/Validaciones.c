/*
 * Validaciones.c
 *
 *  Created on: 7 nov 2021
 *      Author: Nacho
 */
#include "Validaciones.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NOMBRE_LEN 128
#define GAME_LEN 63
static int myGets(char pResultado[], int len);


int pedirNombre(char pResultado[],int lenght, int reintentos, char* variableTexto, char* textoError)
{
	int retorno=-1;
	char bufferCadenaAux[NOMBRE_LEN];
	int i;

	if(pResultado != NULL && reintentos >0 && lenght>0 && variableTexto != NULL && textoError != NULL)
	{

		for (i=0; i<=reintentos; i++)
		{
			printf("%s",variableTexto);

			if (myGets(bufferCadenaAux,sizeof(bufferCadenaAux))==0)
			{
				if(esNombre(bufferCadenaAux)==0)
				{

					retorno = 0;
					strncpy (pResultado,bufferCadenaAux,lenght);
					break;
					}else
					{
						printf("%s\n",textoError);
					}

				} else
				{
					printf("%s\n",textoError);
				}

			}

	}
	return retorno;

}


int pedirNombreSalon(char pResultado[],int lenght, int reintentos, char* variableTexto, char* textoError)
{
	int retorno=-1;
	char bufferCadenaAux[NOMBRE_LEN];
	int i;

	if(pResultado != NULL && reintentos >0 && lenght>0 && variableTexto != NULL && textoError != NULL)
	{

		for (i=0; i<=reintentos; i++)
		{
			printf("%s",variableTexto);

			if (myGets(bufferCadenaAux,sizeof(bufferCadenaAux))==0)
			{
				if(esNombreSalonJuego(bufferCadenaAux)==0)
				{

					retorno = 0; // OK
					strncpy (pResultado,bufferCadenaAux,lenght);
					break;
					}else
					{
						printf("%s\n",textoError);
					}

				} else
				{
					printf("%s\n",textoError);
				}

			}

	}
	return retorno;

}

int pedirNombreJuego(char pResultado[],int lenght, int reintentos, char* variableTexto, char* textoError)
{
	int retorno=-1;
	char bufferCadenaAux[GAME_LEN];
	int i;

	if(pResultado != NULL && reintentos >0 && lenght>0 && variableTexto != NULL && textoError != NULL)
	{

		for (i=0; i<=reintentos; i++)
		{
			printf("%s",variableTexto);

			if (myGets(bufferCadenaAux,sizeof(bufferCadenaAux))==0)
			{
				if(esNombreSalonJuego(bufferCadenaAux)==0)
				{

					retorno = 0; // OK
					strncpy (pResultado,bufferCadenaAux,lenght);
					break;
					}else
					{
						printf("%s\n",textoError);
					}

				} else
				{
					printf("%s\n",textoError);
				}

			}

	}
	return retorno;

}

int esNombre(char cadena[])
{
	int retorno;
	int i;

	retorno=-1;
	i=0;

	if(cadena!=NULL&&strlen(cadena)>0)
	{
		retorno=0;
		while(cadena[i]!='\0')
		{
			if((cadena[i]>='A'&&cadena[i]<='z')||cadena[i]=='-'||cadena[i]==32)
			{
				if(cadena[i]>'Z'&&cadena[i]<'a')
				{
					retorno=-1;
					break;
				}
				i++;

			} else
			{
				retorno=-1;
				break;
			}

		}
	}

	return retorno;

}
static int myGets(char pResultado[], int len)
{
	int retorno=-1;
	int indexFinal;
	fflush(stdin);

	if(fgets(pResultado,len,stdin)!=NULL)
	{
		// borro el \n del final
		indexFinal = strlen(pResultado)-1;
		if(pResultado[indexFinal] == '\n')
		{
			pResultado[indexFinal] = '\0';
		}
		retorno = 0;
	}
	return retorno;
}

int esNombreSalonJuego (char cadena[])
{
	int retorno;
	int i;

	retorno=-1;

	if(cadena!=NULL&&strlen(cadena)>0)
	{
		for(i=0;cadena[i]!='\0';i++)
		{
			if((cadena[i]>='A'&& cadena[i]<='z') ||(cadena[i]>='0'&& cadena[i]<='9') || (cadena[i]==32||cadena[i]=='.'||cadena[i]=='-'||cadena[i]=='&'))
			{
				retorno=0;
			} else
			{

				retorno=-1;
				break;
			}
		}
	}


	return retorno;

}

int esTipoSonido (char cadena[])
{
	int retorno;

	retorno=-1;

	if(cadena!=NULL&&strlen(cadena)>0)
	{
		if((strcmp(cadena,"STEREO")==0)||(strcmp(cadena,"MONO")==0))
		{
			retorno=0;
		}
	}


	return retorno;

}






