#pragma once
#include <list>
#include <iostream>
#include "Suject.h"
class Casilla : public ISuject
{
private:
    int state;
    char symbol;
    std::list<IObserver*> observadores;

public:
    int id;

    enum CELL_STATE { TVOID, J1, J2 };

    Casilla(int id = 0);
    
    void changeState(CELL_STATE nw_state);

    void showState();

    void showCasilla();

    int getStateActual();

    void notifyAllObservers(void);

    void addObserver(IObserver*& observer);
};
