#pragma once
#include "AplicationState.h"
class ScoreBoardState : public AplicationState
{
public:
	//ScoreBoardState();
	void onGame();
	void onScoreBoard();
	void onRegisterPlayer();
	void onMainMenu();
};

