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
	std::cout << "Score of DarkWizard es 6000 pts" << std::endl;
	std::cout << "Se volvera al menu en 5 segundos" << std::endl;
	for (size_t i = 0; i < 3; i++)
	{
		std::cout << (i+1) << " Segundo ..." << std::endl;
		Sleep(1000);
		
	}
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
