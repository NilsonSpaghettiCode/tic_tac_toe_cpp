#pragma once
#include "AplicationState.h"
enum GAME_STATE { WAITING, START, FINISHED };

class AplicationState;

class Game : public AplicationState
{
private:
	int state;

public:
	Game(PlayerDAO* player_dao) : AplicationState(player_dao) 
	{
		this->state = WAITING;
	}
	void onGame();
	void onScoreBoard();
	void onRegisterPlayer();
	void onMainMenu();
};

