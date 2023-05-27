#include "Aplication.h"
#include <iostream>
#include "IMongoConection.h"

#include "MainMenuState.h"

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
	this->config_modular = new ConfigDB();
	this->loadConfigs();
	
	//REFACTORIZAME PORFAVOR!

	IMongoCollection* imc = new MongoCollection(this->config_modular->getCollection(), this->config_modular->getDB(), this->config_modular->getUri());
	PlayerDAO* model_player_dao = new ImplPlayerDAO(imc);
	stateInitial = new MainMenuState(model_player_dao);
	
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

void Aplication::loadConfigs()
{
	this->config_modular->load();
	IMongoConection::initInstance();
}

ConfigDB* Aplication::getSystemConfig()
{
	return this->config_modular;
}
