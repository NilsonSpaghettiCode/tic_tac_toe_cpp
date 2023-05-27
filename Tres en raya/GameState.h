#pragma once
#include "AplicationState.h"
#include "Suject.h"
#include <list>
#include "Casilla.h"
enum GAME_STATE { WAITING, START, FINISHED };
enum ENDGAME_STATE { J1, J2, TIE };
class AplicationState;

class GameState : public AplicationState
{
private:
	int state;
	int endgame_state;
	Casilla::CELL_STATE actualPlayer;
	std::list<ISuject *> tablero;

public:
	GameState(PlayerDAO* player_dao) : AplicationState(player_dao) 
	{
		this->state = WAITING;
		this->endgame_state = ENDGAME_STATE::TIE;
		this->actualPlayer = Casilla::J1;
	}
	
	void initGameBoard();
	void showTablero();
	void selectPlayer();
	void initGame();
	void checkBox(int id_box, Casilla::CELL_STATE nw_state);
	void setEndGame(ENDGAME_STATE nw_state);

	bool isGameFinished();
	Casilla::CELL_STATE getActualPlayer();
	void changeShift();
	int getInputBox();
	//States
	void onGame()			override;
	void onScoreBoard()		override;
	void onRegisterPlayer() override;
	void onMainMenu()		override;
};

