#pragma once
#include "AplicationState.h"
class ScoreBoardState : public AplicationState
{
public:
	ScoreBoardState(PlayerDAO* player_dao) : AplicationState(player_dao)
	{

	}

	void onGame() override;
	void onScoreBoard() override;
	void onRegisterPlayer() override;
	void onMainMenu() override;
};

