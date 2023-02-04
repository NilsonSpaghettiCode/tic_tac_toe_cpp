#include "Aplication.h"
#include <iostream>


void Aplication::onGame()
{
	this->state_->onGame();
}

void Aplication::onScoreBoard()
{
	this->state_->onScoreBoard();
}

void Aplication::onRegisterPlayer()
{
	this->state_->onRegisterPlayer();
}

void Aplication::onMainMenu()
{
	this->state_->onMainMenu();
}

Aplication::Aplication(AplicationState* stateInitial): state_(nullptr)
{
	this->changeState(stateInitial);
}

Aplication::~Aplication()
{

}

void Aplication::changeState(AplicationState *& state)
{
	IAplication* aux_app = this;
	this->state_ = state;
	this->state_->setContext(aux_app);
}

void Aplication::run()
{
	this->onMainMenu();
}
