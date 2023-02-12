// Tres en raya.cpp : This file contains the 'main' function. Program execution begins and ends there.
///Intern Utilities
#include "MHeaders.h"


IAplication* app;

int IPlayer::_id = 0;
bool IPlayer::isInitialized = false;

int main()
{
	AplicationState* state_init = nullptr;
	app = new Aplication(state_init);
	app->run();
	
	/*
	ISuject* C1 = new Casilla(1);
	ISuject* C2 = new Casilla(2);
	ISuject* C3 = new Casilla(3);

	ISuject* C4 = new Casilla(4);
	ISuject* C5 = new Casilla(5);
	ISuject* C6 = new Casilla(6);

	ISuject* C7 = new Casilla(7);
	ISuject* C8 = new Casilla(8);
	ISuject* C9 = new Casilla(9);
	
	PatronTicTacToe* H1 = new PatronTicTacToe(1);

	PatronTicTacToe* V1 = new PatronTicTacToe(4);

	H1->addSuject(C1);
	H1->addSuject(C2);
	H1->addSuject(C3);

	V1->addSuject(C1);
	V1->addSuject(C4);
	V1->addSuject(C7);

	Casilla* aux = dynamic_cast<Casilla*>(C1);
	

	aux->changeState(Casilla::J1);

	H1->showCounts();
	V1->showCounts();


	aux = dynamic_cast<Casilla*>(C2);


	H1->showCounts();
	V1->showCounts();

	*/

	return 0;
}
