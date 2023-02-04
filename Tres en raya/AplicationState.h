#pragma once

#include "Aplication.h"

#include <iostream>
class IAplication;

class AplicationState
{
protected:
	IAplication* context;

public:

	//State of Aplication

	virtual void onGame() = 0;
	virtual void onScoreBoard() = 0;
	virtual void onRegisterPlayer() = 0;
	virtual void onMainMenu() = 0;

	virtual void setContext(IAplication*& context) {
		this->context = context;
	};

	virtual ~AplicationState()
	{
		std::cout << "Estado eliminado" << std::endl;
	}

};
