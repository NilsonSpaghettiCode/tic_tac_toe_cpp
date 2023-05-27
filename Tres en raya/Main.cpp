// Tres en raya.cpp : This file contains the 'main' function. Program execution begins and ends there.
///Intern Utilities
#include "MHeaders.h"
IAplication* app;


int main()
{

	AplicationState* state_init = nullptr;
	app = new Aplication(state_init);
	app->run();

	/*
	* Tareas para la proxima vez: 06/04/2023
	* - Crear interfaz interactiva CLI (https://www.youtube.com/watch?v=DtMfkShh03w&list=PL2U2TQ__OrQ8jTf0_noNKtHMuYlyxQl4v&index=5)
	*	- Paquete de VCPKG: https://vcpkg.io/en/packages.html	
	* - Agregar estado a clase IObserver, para verificarlo al momento de realizar update
	* - Y agregar lista de bools que haga referencia a los estados de los patrones
	*	- [0,0,0,0,0,0,0]
	*	- y con cada cambio se obtiene el numero de ON, si es igual a 0, finaliza el juego, considerando empate
	*	- la funcion checkpatron de PatronTicTacToe, se busca en dicha lista, y cambia su estado
	* Agregar funcion de seleccion de jugadores
	* Agregar función de determinar segun endgame, quien gano
	* Agregar función de otorgar puntos
	* Sumar puntos en bd
	*/

	return 0;
}
