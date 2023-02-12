#pragma once

#include "AplicationState.h"

class MainMenuState : public AplicationState
{
public:
	MainMenuState(PlayerDAO* player_dao) : AplicationState(player_dao) 
	{

	}

	void onGame() override;
	void onScoreBoard() override;
	void onRegisterPlayer() override;
	void onMainMenu() override;
};

