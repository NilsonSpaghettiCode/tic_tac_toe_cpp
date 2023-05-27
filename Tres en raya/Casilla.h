#pragma once
#include <list>
#include <iostream>
#include "Suject.h"
class Casilla : public ISuject
{
private:
    int                   state;
    char                  symbol;
    std::list<IObserver*> observers;

public:

    int id;
    enum CELL_STATE { TVOID, J1, J2 };
    
    //Constructor
    Casilla(int id = 0);
    
    //Metodos

    int  getStateActual();

    void showState();
    void showCasilla();

   
    void changeState(CELL_STATE nw_state);
    void notifyAllObservers(void);
    void addObserver(IObserver*& observer);
    void removeObserver(int id) override;
};
