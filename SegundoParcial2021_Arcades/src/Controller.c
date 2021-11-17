/*
 * Controller.c
 *
 *  Created on: 17 nov 2021
 *      Author: Nacho
 */

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
