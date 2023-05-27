#include "Player.h"
#include <string>

/*
Player::Player(std::string nickname, char symbol, char alt_symbol)
{
	this->nickname = nickname;
	this->symbol = symbol;
	this->alt_symbol = alt_symbol;

	this->count_games = 0;
	this->wins = 0;
	this->losses = 0;

}
*/

Player::Player(std::string _id, std::string nickname, char symbol, char alt_symbol, int count_games, long wins, long losses)
{
	this->_id = _id;
	this->nickname = nickname;
	this->symbol = symbol;
	this->alt_symbol = alt_symbol;
	this->count_games = count_games;
	this->wins = wins;
	this->losses = losses;
}


std::string Player::to_string()
{
	return "\n" + this->nickname + "\n" + this->symbol + "\n" + this->alt_symbol;
}




void Player::setNickname(std::string nickname)
{
	this->nickname = nickname;
}

std::string Player::getId()
{
	return this->_id;
}

void Player::setId(std::string nw_id)
{
	this->_id = nw_id;
}

void Player::setSymbol(char symbol)
{
	this->symbol = symbol;
}

void Player::setAltSymbol(char alt_symbol)
{
	this->alt_symbol = alt_symbol;
}


std::string Player::getNickname(void)
{
	return this->nickname;
}

char Player::getSymbol()
{
	return this->symbol;
}

char Player::getAltSymbol()
{
	return this->alt_symbol;
}

long Player::getWins()
{
	return this->wins;
}

long Player::getLosses()
{
	return this->losses;
}

int Player::getCountGames()
{
	return this->count_games;
}


void Player::increaseLosses()
{
	this->losses++;
}

void Player::increaseWins()
{
	this->wins++;
}




void Player::increseCountGames()
{
	this->count_games++;
}






