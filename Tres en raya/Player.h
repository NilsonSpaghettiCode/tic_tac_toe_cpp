#pragma once
#include "IEntity.h"
#include <iostream>

enum PLAYER_STATE { IN_GAME, WINNER, LOSER, TIED };


#include <iostream>
#include <fstream>



class IPlayer
{
protected:
	long player_id;
private:
	static int _id;
	static bool isInitialized;

	static void initializeVariable()
	{
		if (!isInitialized)
		{
			std::ifstream file("player_config.txt");
			file >> _id;
			isInitialized = true;
		}
	}

public:
	IPlayer()
	{
		this->increaseVariable();
	}
	static int getVariable()
	{
		initializeVariable();
		return _id;
	}

	static void increaseVariable()
	{
		initializeVariable();
		++_id;
	}

	virtual std::string to_string() = 0;

};


class Player : public IEntity, public IPlayer
{

private:
	std::string nickname;
	char symbol;
	char alt_symbol;
	long wins;
	long losses;
	int count_games;

public:
	
	Player(std::string nickname, char symbol = 'X', char alt_symbol = 'O');


	void increseCountGames();
	void increaseLosses();
	void increaseWins();
	std::string to_string() override;


	//Gets and sets
	std::string getNickname(void);
	void setNickname(std::string nickname);
	

	char getSymbol();
	void setSymbol(char symbol);

	char getAltSymbol();
	void setAltSymbol(char alt_symbol);


	long getWins();
	long getLosses();
	int getCountGames();

};

