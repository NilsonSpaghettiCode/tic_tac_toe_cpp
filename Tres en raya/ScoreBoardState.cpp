#include "ScoreBoardState.h"
#include "MainMenuState.h"

#include <iostream>
#include <limits>
#include <Windows.h>

#include <iomanip>
#include <fmt/format.h>

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
	std::cout << "Tablero de puntuaciones"<< std::endl;

	std::list<Player> players = this->player_dao->getAllPlayers();

	//std::cout << std::setw(20) << "Nombre " << std::setw(6) << "Victorias" << std::setw(6) << "Derrotas" << std::endl;

	//std::cout << std::internal << std::setw(5) << "A"<<std::setw(5)<<"B"<< std::endl;

	for (auto it = players.begin(); it != players.end(); it++)
	{
		std::cout << (*it).getNickname() << "\t" << (*it).getWins() << "\t" << (*it).getLosses() <<std::endl;;
	}

	std::cout << "Presiona cualquier tecla para continuar..." << std::endl;
	std::cin.ignore();
	std::cin.get();

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
