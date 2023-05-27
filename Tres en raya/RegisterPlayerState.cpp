#include "RegisterPlayerState.h"
#include "MainMenuState.h"
#include "PlayerDAO.h"

void RegisterPlayerState::onGame()
{

}

void RegisterPlayerState::onScoreBoard()
{

}

void RegisterPlayerState::onRegisterPlayer()
{
	
	std::string nickname = "";
	char symbol = ' ';
	char alt_symbol = ' ';
	
	std::cout << "Para registrar un jugador digite la siguiente informaci�n:" << std::endl;
	
	std::cout << "Nickname: ";
	std::cin >> nickname;
	
	std::cout << "Simbolo principal si eres J1: ";
	std::cin >> symbol;
	
	std::cout << "Simbolo segundario si eres J2: ";
	std::cin >> alt_symbol;

	Player* new_player = new Player("", nickname, symbol, alt_symbol, 0, 0, 0);

	this->player_dao->createPlayer(new_player);
	std::cout << "Player creado: " <<new_player->getId() << std::endl;
	std::cout << "No olvide su ID!" << std::endl;
	this->onMainMenu();
}

void RegisterPlayerState::onMainMenu()
{
	AplicationState* next_state = new MainMenuState(this->player_dao);
	this->context->changeState(next_state);
	this->context->onMainMenu();
}
