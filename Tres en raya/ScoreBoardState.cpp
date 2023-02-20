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
	
	std::list<Player> players = this->player_dao->getAllPlayers();
	std::string title = "Tablero de puntuaciones";
	int width = 50;

	std::cout << std::setw(20) << std::setfill('-') << "" << std::setw(20) << "" << std::setw(10) << "" << std::setfill(' ') << std::endl;
	std::cout << "|" << std::setfill(' ') << std::setw(width / 2 + title.length() / 2) << title << std::setw(width / 2 - title.length() / 2) << "|" << std::endl;
	std::cout << std::setw(20) << std::setfill('-') << "" << std::setw(20) << "" << std::setw(10) << "" << std::setfill(' ') << std::endl;

	fmt::print("| {:<20} | {:<10} | {:<10} |\n", "Nombre", "Victorias", "Derrotas");
	for (auto it = players.begin(); it != players.end(); it++)
	{
		//std::cout << (*it).getNickname() << "\t" << (*it).getWins() << "\t" << (*it).getLosses() <<std::endl;

		fmt::print("| {:<20} | {:<10} | {:<10} |\n", (*it).getNickname(), (*it).getWins(), (*it).getLosses());
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
