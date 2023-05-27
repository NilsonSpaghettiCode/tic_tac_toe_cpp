#pragma once
#include "IEntity.h"
#include <iostream>

enum PLAYER_STATE { IN_GAME, WINNER, LOSER, TIED };


class Player : public IEntity
{

private:
	std::string _id;
	std::string nickname;
	char symbol;
	char alt_symbol;
	long wins;
	long losses;
	int count_games;

public:
	Player(std::string _id = "default_id", std::string nickname = "defaul_user", char symbol = 'X', char alt_symbol = 'O', int count_games = 0, long wins = 0, long losses = 0);
	//Player(std::string nickname, char symbol = 'X', char alt_symbol = 'O');

	void increseCountGames();
	void increaseLosses();
	void increaseWins();
	std::string to_string();


	//Gets and sets
	std::string getNickname(void);
	void setNickname(std::string nickname);
	
	std::string getId();
	void setId(std::string nw_id);

	char getSymbol();
	void setSymbol(char symbol);

	char getAltSymbol();
	void setAltSymbol(char alt_symbol);


	long getWins();
	long getLosses();
	int getCountGames();

};

