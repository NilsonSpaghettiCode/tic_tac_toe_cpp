#include "MainMenuState.h"
#include "ScoreBoardState.h"
#include "RegisterPlayerState.h"
#include <iostream>
/*
MainMenuState::MainMenuState()
{
	std::cout << "Comportandose como MainMenuState" << std::endl;
}
*/
void MainMenuState::onGame()
{
	std::cout << "No implementado" << std::endl;
}

void MainMenuState::onScoreBoard()
{
	AplicationState* aux_state = new ScoreBoardState;
	this->context->changeState(aux_state);
	this->context->onScoreBoard();
}

void MainMenuState::onRegisterPlayer()
{
	AplicationState* aux_state = new RegisterPlayerState;
	this->context->changeState(aux_state);
	this->context->onRegisterPlayer();
}

void MainMenuState::onMainMenu()
{
	std::cout << "Tic Tac Toe" << std::endl;
	std::cout << "1. Jugar" << std::endl;
	std::cout << "2. Tablero de puntuaciones" << std::endl;
	std::cout << "3. Registrar jugador" << std::endl;
	std::cout << "4. Salir" << std::endl;
	std::cout << "Por favor digite una opción" << std::endl;
	std::cout << ">> ";
	int option = 0;
	std::cin >> option;

	switch (option)
	{
	case 1:
		this->onGame();
		break;
	case 2:
		this->onScoreBoard();
		break;
	case 3:
		this->onRegisterPlayer();
		break;
	case 4:
		std::cout << "Cerrando" << std::endl;
		exit(0);
		break;
	default:
		std::cout << "Elemento no reconocido" << std::endl;
		this->onMainMenu();
		break;
	}
}
