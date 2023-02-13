#include "ScoreBoardState.h"
#include "MainMenuState.h"

#include <iostream>
#include <Windows.h>
/*
ScoreBoardState::ScoreBoardState() 
{
	std::cout << "Mostrando ScoreBoard" << std::endl;
	this->onScoreBoard();
}
*/
void ScoreBoardState::onGame()
{
	std::cout << "No alcanzable" << std::endl;
}

void ScoreBoardState::onScoreBoard()
{
	std::cout << "Tablero de punteaciones"<< std::endl;

	std::cout << "Presiona cualquier tecla para continuar..." << std::endl;
	getchar();

	this->onMainMenu();
}

void ScoreBoardState::onRegisterPlayer()
{
	std::cout << "No alcanzable" << std::endl;
}

void ScoreBoardState::onMainMenu()
{
	AplicationState* aux_state = new MainMenuState(this->player_dao);
	this->context->changeState(aux_state);
	this->context->onMainMenu();
}
