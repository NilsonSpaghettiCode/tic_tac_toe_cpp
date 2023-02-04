#pragma once
#include "AplicationState.h"

class AplicationState;

class IAplication
{
public:
	//Init app
	virtual void run() = 0;

	//All states

	virtual void onGame() = 0;
	virtual void onScoreBoard() = 0;
	virtual void onRegisterPlayer() = 0;
	virtual void onMainMenu() = 0;
	virtual void changeState(AplicationState *& state) = 0;
};

class Aplication : public IAplication
{
private:
	AplicationState* state_;

public:
	
	Aplication(AplicationState * stateInitial);
	
	~Aplication();
	
	void changeState(AplicationState *& state) override;

	void run() override;
	
	//States
	void onGame() override;
	void onScoreBoard() override;
	void onRegisterPlayer() override;
	void onMainMenu() override;

};
