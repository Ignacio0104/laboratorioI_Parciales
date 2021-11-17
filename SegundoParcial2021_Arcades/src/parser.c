#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Arcades.h"
#include "Validaciones.h"

#define NOMBRE_LEN 128
#define MAX_LEN 256

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_ArcadeFromText(FILE* pFile , LinkedList* pArrayArcades)
{
	int retorno=-1;
	Arcade* pArcadeAux;
	char idAux[MAX_LEN];
	char nacionalidadAux[NOMBRE_LEN];
	char tipoSonidoAux[MAX_LEN];
	char jugadoresAux[MAX_LEN];
	char fichasAux[MAX_LEN];
	char salonAux[MAX_LEN];
	char juegoAux[MAX_LEN];
	char banderaError='n';

	if(pFile!=NULL&&pArrayArcades!=NULL)
	{
		fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",idAux,nacionalidadAux,tipoSonidoAux,jugadoresAux,fichasAux,salonAux,juegoAux);
		do
		{
			if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n"
					,idAux,nacionalidadAux,tipoSonidoAux,jugadoresAux,fichasAux,salonAux,juegoAux)==7)
			{
				if(esNumerica(idAux)==0&&esTexto(nacionalidadAux)==0&&esTexto(tipoSonidoAux)==0&&esNumerica(jugadoresAux)==0&&esNumerica(fichasAux)==0
						&&esTexto(salonAux)==0&&esTexto(juegoAux)==0)
				{
					pArcadeAux = arcade_newParametros(idAux,nacionalidadAux,tipoSonidoAux,jugadoresAux,fichasAux,salonAux,juegoAux);
					if(pArcadeAux!=NULL)
					{
						ll_add(pArrayArcades,pArcadeAux);
						retorno=0;
					}
					else
					{
						//employee_delete(pArcadeAux);
						retorno=-1;
						break;
					}
				} else
				{
					banderaError='s';
					continue;

				}

			}

		}while(feof(pFile)==0);
	}

	if(banderaError=='s')
	{
		printf("Se detectó uno o más errores al importar el archivo. Favor imprimir lista (opción 6) y verificar que esté correcta\n");
	}


    return retorno;
}


