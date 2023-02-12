#pragma once
#include "AplicationState.h"
#include "SystemConfig.h"
#include "ConfigDB.h"

class AplicationState;

class IAplication
{
public:
	//Init app
	virtual void run()                                = 0;
	virtual void loadConfigs()                        = 0;
	virtual void changeState(AplicationState*& state) = 0;

	//All states
	virtual void onGame()            = 0;
	virtual void onScoreBoard()      = 0;
	virtual void onRegisterPlayer()  = 0;
	virtual void onMainMenu()        = 0;

	
};
class Aplication : public IAplication
{
private:
	AplicationState* state_;
	ConfigDB * config_modular;

public:
	//Constructor and desctructor
	Aplication(AplicationState * stateInitial);
	~Aplication();
	

	void      changeState(AplicationState *& state) override;
	void      run()								   override;
	void	  loadConfigs()						   override;
	ConfigDB* getSystemConfig();
	
	//States
	void onGame()           override;
	void onScoreBoard()     override;
	void onRegisterPlayer() override;
	void onMainMenu()       override;

};

