#pragma once
#include "AplicationState.h"
#include "Suject.h"
#include <list>
#include "Casilla.h"
#define GAME_PATERNS 8

enum GAME_STATE { WAITING, START, FINISHED };
enum ENDGAME_STATE { J1, J2, TIE };
class AplicationState;



class GameState : public AplicationState
{
private:
	int state;
	int endgame_state;
	int activePatrons;
	Casilla::CELL_STATE actualPlayer;
	std::list<ISuject *> tablero;

	Player* player_1;
	Player* player_2;

public:
	GameState(PlayerDAO* player_dao) : AplicationState(player_dao) 
	{
		this->state = WAITING;
		this->endgame_state = ENDGAME_STATE::TIE;
		this->actualPlayer = Casilla::J1;
		this->activePatrons = GAME_PATERNS;
		player_1 = new Player();
		player_2 = new Player();
	}
	
	void initGameBoard();
	void showTablero();
	Player* selectPlayer(int number_player);
	void initGame();
	void checkBox(int id_box, Casilla::CELL_STATE nw_state);
	void setEndGame(ENDGAME_STATE nw_state);

	bool isGameFinished();
	Casilla::CELL_STATE getActualPlayer();
	void changeShift();
	void removePatron();
	void verifyState();
	int getInputBox();

	//States
	void onGame()			override;
	void onScoreBoard()		override;
	void onRegisterPlayer() override;
	void onMainMenu()		override;
};

