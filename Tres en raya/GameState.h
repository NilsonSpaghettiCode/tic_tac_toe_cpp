#pragma once
#include "AplicationState.h"
enum GAME_STATE { WAITING, START, FINISHED };

class AplicationState;
class Game : public AplicationState
{
private:
	int state;

public:
	Game();
	void onGame();
	void onScoreBoard();
	void onRegisterPlayer();
	void onMainMenu();
};

