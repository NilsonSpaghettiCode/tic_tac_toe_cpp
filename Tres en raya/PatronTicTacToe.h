#pragma once

#include "IObserver.h"

#include <string>
#include <list>
#include "Suject.h"



class PatronTicTacToe : public IObserver
{
private:
    int counter_J1 = 0;
    int counter_J2 = 0;

    int id;

    std::list<ISuject*> observers;

public:
    PatronTicTacToe(int id);
    void addToCount(int id);
    void Update(int id);
    void addSuject(ISuject*& casilla);
    void showCounts();

};