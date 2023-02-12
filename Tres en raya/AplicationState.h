#pragma once

#include "Aplication.h"
#include "PlayerDAO.h"

#include <iostream>
class IAplication;

class AplicationState
{
protected:
	IAplication* context;
	PlayerDAO* player_dao;

public:

	//State of Aplication

	virtual void onGame() = 0;
	virtual void onScoreBoard() = 0;
	virtual void onRegisterPlayer() = 0;
	virtual void onMainMenu() = 0;

	virtual void setContext(IAplication*& context) {
		this->context = context;
	};

	AplicationState(PlayerDAO* player_dao): player_dao(nullptr)
	{
		this->player_dao = player_dao;
	}

	virtual ~AplicationState()
	{
		std::cout << "Estado eliminado" << std::endl;
	}

	
	
};
