#include "GameState.h"
#include "MainMenuState.h"

#include "IObserver.h"
#include "Suject.h"
#include "PatronTicTacToe.h"


#include <iostream>


void GameState::initGame()
{
	while (!isGameFinished())
	{
		/*
		* for (size_t x = 0; x < 3; x++)
		{
			for (size_t y = 0; y < 3; y++)
			{
				std::cout << "X" << " | ";
			}
			std::cout << "" << std::endl;

		}
		std::cout << "Digite en que posición quiere poner su simbolo #J1";

		break;
		
		*/

		
		this->checkBox(1, Casilla::J1);
		this->checkBox(7, Casilla::J2);

		this->checkBox(3, Casilla::J1);
		this->checkBox(2, Casilla::J2);


		this->checkBox(9, Casilla::J1);
		this->checkBox(5, Casilla::J2);


		this->checkBox(4, Casilla::J1);
		this->checkBox(8, Casilla::J2);
		
	
	}

}

void GameState::selectPlayer()
{
}

void GameState::initGameBoard()
{

	//Creación de casillas

	std::cout << "Creando tableros" << std::endl;
	ISuject* C1 = new Casilla(1);
	ISuject* C2 = new Casilla(2);
	ISuject* C3 = new Casilla(3);

	ISuject* C4 = new Casilla(4);
	ISuject* C5 = new Casilla(5);
	ISuject* C6 = new Casilla(6);

	ISuject* C7 = new Casilla(7);
	ISuject* C8 = new Casilla(8);
	ISuject* C9 = new Casilla(9);

	//Creación de patrones horizontales, diagonales y verticales
	PatronTicTacToe* H1 = new PatronTicTacToe(1, this);
	PatronTicTacToe* H2 = new PatronTicTacToe(2, this);
	PatronTicTacToe* H3 = new PatronTicTacToe(3, this);

	PatronTicTacToe* V1 = new PatronTicTacToe(4, this);
	PatronTicTacToe* V2 = new PatronTicTacToe(5, this);
	PatronTicTacToe* V3 = new PatronTicTacToe(6, this);

	PatronTicTacToe* D1 = new PatronTicTacToe(7, this);
	PatronTicTacToe* D2 = new PatronTicTacToe(8, this);

	//Enlace de Casillas a patrones horizontales y verticales

	//Enlace de horizonal #1
	H1->addSuject(C1);
	H1->addSuject(C2);
	H1->addSuject(C3);

	//Enlace de horizontal #2
	H2->addSuject(C4);
	H2->addSuject(C5);
	H2->addSuject(C6);

	//Enlace de Horizontal #3
	H3->addSuject(C7);
	H3->addSuject(C8);
	H3->addSuject(C9);

	//Enlace de Vertical #1
	V1->addSuject(C1);
	V1->addSuject(C4);
	V1->addSuject(C7);

	//Enlace de Vertical #2
	V2->addSuject(C2);
	V2->addSuject(C5);
	V2->addSuject(C8);

	//Enlace de Vertical #3
	V3->addSuject(C3);
	V3->addSuject(C6);
	V3->addSuject(C9);

	//Enlace de diagonales
	
	//Enlace de diagonal #1 Izquierda -> Derecha
	D1->addSuject(C1);
	D1->addSuject(C5);
	D1->addSuject(C9);

	//Enlace de diagonal #1 Derecha -> Izquierda
	D2->addSuject(C3);
	D2->addSuject(C5);
	D2->addSuject(C7);

	//Creación tablero y relaciones de patrones
	this->tablero.push_back(C1);
	this->tablero.push_back(C2);
	this->tablero.push_back(C3);

	this->tablero.push_back(C4);
	this->tablero.push_back(C5);
	this->tablero.push_back(C6);

	this->tablero.push_back(C7);
	this->tablero.push_back(C8);
	this->tablero.push_back(C9);
}

void GameState::showTablero()
{
	for (auto it = this->tablero.begin(); it != this->tablero.end(); it++)
	{
		
		Casilla* aux = dynamic_cast<Casilla*>((*it));
		aux->showCasilla();
	}
}

void GameState::checkBox(int id_box, Casilla::CELL_STATE nw_state)
{
	for (auto it = this->tablero.begin(); it != this->tablero.end(); it++)
	{

		Casilla* aux = dynamic_cast<Casilla*>((*it));
		if (aux->id == id_box)
		{
			aux->changeState(nw_state);
			break;
			//Agregar metodo que actualice patrones descartados, despues de 
			//Cambiar una casilla
		}
	}

	//Se espera que se revise cantidad de patrones descartados
	//Si la cantidad es igual a 8, hay sopa o empate
	//Si 
}

void GameState::setEndGame(ENDGAME_STATE nw_state)
{
	this->endgame_state = nw_state;
	this->state = GAME_STATE::FINISHED;
}

bool GameState::isGameFinished()
{
	bool isGameFinished = false;
	if (this->state == GAME_STATE::FINISHED)
	{
		isGameFinished = true;
	}

	return isGameFinished;
}

void GameState::onGame()
{
	this->initGameBoard();
	//this->showTablero();
	

	this->initGame();
	this->onMainMenu();
}

void GameState::onScoreBoard()
{
}

void GameState::onRegisterPlayer()
{
}

void GameState::onMainMenu()
{
	AplicationState* aux_state = new MainMenuState(this->player_dao);
	this->context->changeState(aux_state);
	this->context->onMainMenu();
}

