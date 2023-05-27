#pragma once

#include "IObserver.h"

#include <string>
#include <list>
#include "Suject.h"
#include "GameState.h"

enum PATRON_STATES {OFF, ON};

class PatronTicTacToe : public IObserver
{
private:
    int counter_J1 = 0;
    int counter_J2 = 0;

    int count_points = 0;
    int count_game = 0;
    int id;

    int state_patron;
    std::list<ISuject*> observed_sujects;
    GameState* game;

public:
    PatronTicTacToe(int id, GameState* game);
    void addToCount(int id);
    void Update(int id);
    void addSuject(ISuject*& casilla);
    void removeSujects();
    void showCounts();
    void checkPatron();
    int getId();

};