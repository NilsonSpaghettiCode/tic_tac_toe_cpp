#pragma once
#include "AplicationState.h"
class RegisterPlayerState : public AplicationState
{
	//Constructor
public:
	RegisterPlayerState(PlayerDAO* & player_dao) : AplicationState(player_dao)
	{

	}

	//States
	void onGame()			override;
	void onScoreBoard()		override;
	void onRegisterPlayer() override;
	void onMainMenu()		override;

private:

};

