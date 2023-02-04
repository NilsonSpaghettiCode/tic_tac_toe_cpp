#include "RegisterPlayerState.h"
#include "MainMenuState.h"

void RegisterPlayerState::onGame()
{

}

void RegisterPlayerState::onScoreBoard()
{

}

void RegisterPlayerState::onRegisterPlayer()
{
	std::cout << "On Register" << std::endl;
	this->onMainMenu();
}

void RegisterPlayerState::onMainMenu()
{
	AplicationState* next_state = new MainMenuState;
	this->context->changeState(next_state);
	this->context->onMainMenu();
}
