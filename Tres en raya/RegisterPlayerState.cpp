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
	
	std::cout << "Para registrar un jugador digite la siguiente información:" << std::endl;
	
	std::cout << "Nickname: ";
	std::cin >> nickname;
	
	std::cout << "Simbolo principal si eres J1: ";
	std::cin >> symbol;
	
	std::cout << "Simbolo segundario si eres J2: ";
	std::cin >> alt_symbol;

	Player new_player(nickname, symbol, alt_symbol);

	
	
	/*
	std::string db_name = "bq3g0huudu0newc";
	std::string collection_player = "players";
	std::string uri = "";
	IMongoCollection* collection_mongo = new MongoCollection(collection_player, db_name, uri);
	PlayerDAO* player_dao = new ImplPlayerDAO(collection_mongo);
	*/

	this->onMainMenu();
}

void RegisterPlayerState::onMainMenu()
{
	AplicationState* next_state = new MainMenuState(this->player_dao);
	this->context->changeState(next_state);
	this->context->onMainMenu();
}
