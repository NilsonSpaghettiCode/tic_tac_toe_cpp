#include "Player.h"
#include <string>

Player::Player(std::string nickname, char symbol, char alt_symbol)
{
	this->player_id = IPlayer::getVariable();

	this->nickname = nickname;
	this->symbol = symbol;
	this->alt_symbol = alt_symbol;

	this->count_games = 0;
	this->wins = 0;
	this->losses = 0;

}


std::string Player::to_string()
{
	return std::to_string(this->player_id) + "\n" + this->nickname + "\n" + this->symbol + "\n" + this->alt_symbol;
}




void Player::setNickname(std::string nickname)
{
	this->nickname = nickname;
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






