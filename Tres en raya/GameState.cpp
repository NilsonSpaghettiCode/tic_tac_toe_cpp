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
		//Método para solicitar entrada de datos jugador
		int box = -1;

		Casilla::CELL_STATE cellStatePlayer = getActualPlayer();
		box = getInputBox();

		this->checkBox(box, cellStatePlayer);
		this->changeShift();
		this->showTablero();
	}

}

Player* GameState::selectPlayer(int number_player)
{
	Player* nw_player = new Player();
	do{
	std::string _id_player = "";
	std::cout << "Jugador #" << number_player << ", digite el _id de su jugador: ";
	std::cin >> _id_player;
	try
	{
		nw_player = this->player_dao->getPlayer(_id_player);
		std::cout <<"Encontrado: "<< nw_player->to_string()<<std::endl;
	}
	catch (const std::exception&)
	{
		std::cout << "Digite un número valida" << std::endl;
	}
	
	} while (nw_player->getId() == "default_id");
	return nw_player;
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
	int c = 1;
	for (auto it = this->tablero.begin(); it != this->tablero.end(); it++)
	{
		
		Casilla* aux = dynamic_cast<Casilla*>((*it));
		if (c == 2 || c == 5 || c == 8)
		{
			std::cout << "|" << aux->getStateActual() << "|";
		}
		else {
			std::cout <<aux->getStateActual();
		}

		if (((c % 3) == 0) )
		{
			std::cout<<std::endl;
			std::cout<<"-----"<< std::endl;
		}
		c++;
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

	if (this->state == GAME_STATE::FINISHED || this->activePatrons == 0)
	{
		isGameFinished = true;
	}

	return isGameFinished;
}

Casilla::CELL_STATE GameState::getActualPlayer()
{
	Casilla::CELL_STATE player = this->actualPlayer;

	return player;

}

void GameState::changeShift()
{
	if (this->actualPlayer == Casilla::J1)
	{
		this->actualPlayer = Casilla::J2;
	}
	else {
		this->actualPlayer = Casilla::J1;
	}
}

void GameState::removePatron()
{
	this->activePatrons--;
}

void GameState::verifyState()
{
	if (this->endgame_state == ENDGAME_STATE::J1)
	{
		this->player_1->increaseWins();
		this->player_2->increaseLosses();

		std::cout << "El ganador es el jugador #1" << std::endl;
	}
	else if (this->endgame_state == ENDGAME_STATE::J2)
	{
		this->player_2->increaseWins();
		this->player_1->increaseLosses();
		
		std::cout << "El ganador es el jugador #2!" << std::endl;
	}
	else {
		std::cout << "Empate!" << std::endl;
	}

	try
	{
		this->player_dao->updatePlayer(player_1);
		this->player_dao->updatePlayer(player_2);

	}
	catch (const std::exception&)
	{
		std::cout << "Error actualizando resultado" << std::endl;
	}
	
}

int GameState::getInputBox()
{
	int positioBox = -1;
	
	std::cout << "Jugador #" << this->actualPlayer << ", digite una celda: ";
	std::cin >> positioBox;

	std::cout << "\n";
	return positioBox;
}

void GameState::onGame()
{
	this->player_1 = this->selectPlayer(1);
	this->player_2 = this->selectPlayer(2);

	this->initGameBoard();
	this->showTablero();

	this->initGame();
	this->verifyState();
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

