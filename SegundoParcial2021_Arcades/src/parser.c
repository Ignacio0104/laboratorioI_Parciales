#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Arcades.h"
#include "Validaciones.h"

#define NOMBRE_LEN 128
#define GAME_LEN 63

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
	char idAux[NOMBRE_LEN];
	char nacionalidadAux[NOMBRE_LEN];
	char tipoSonidoAux[NOMBRE_LEN];
	char jugadoresAux[NOMBRE_LEN];
	char fichasAux[NOMBRE_LEN];
	char salonAux[NOMBRE_LEN];
	char juegoAux[GAME_LEN];
	char banderaError='n';

	if(pFile!=NULL&&pArrayArcades!=NULL)
	{
		fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",idAux,nacionalidadAux,tipoSonidoAux,jugadoresAux,fichasAux,salonAux,juegoAux);
		do
		{
			if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n"
					,idAux,nacionalidadAux,tipoSonidoAux,jugadoresAux,fichasAux,salonAux,juegoAux)==7)
			{
				if(esNumerica(idAux)==0&&esTexto(nacionalidadAux)==0&&esTipoSonido(tipoSonidoAux)==0&&esNumerica(jugadoresAux)==0
						&&esNumerica(fichasAux)==0&&esNombreSalonJuego(salonAux)==0&&esNombreSalonJuego(juegoAux)==0)
				{
					pArcadeAux = arcade_newParametros(idAux,nacionalidadAux,tipoSonidoAux,jugadoresAux,fichasAux,salonAux,juegoAux);
					if(pArcadeAux!=NULL)
					{
						ll_add(pArrayArcades,pArcadeAux);
						retorno=0;
					}
					else
					{
						arcade_delete(pArcadeAux);
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
		printf("Se detectó uno o más errores al importar el archivo. Favor imprimir lista (opción 4) y verificar que esté correcta\n");
	}


    return retorno;
}


