#include "PatronTicTacToe.h"
#include <iostream>
#include "Casilla.h"

PatronTicTacToe::PatronTicTacToe(int id)
{
    this->id = id;
}

void PatronTicTacToe::Update(int id)
{
    //std::cout << "Update: +" << id<<std::endl;
    this->addToCount(id);

}

void PatronTicTacToe::addSuject(ISuject*& casilla)
{
    IObserver* observer = this;
    casilla->addObserver(observer);
    this->observers.push_back(casilla);
}

void PatronTicTacToe::showCounts()
{
    std::cout << "J1: " << this->counter_J1 << " | " << "J2: " << this->counter_J2 << std::endl;
}

void PatronTicTacToe::addToCount(int id)
{
    for (auto it = this->observers.begin(); it != this->observers.end(); it++)
    {
        Casilla* tempo = dynamic_cast<Casilla*>((*it));
        if (tempo->id == id)
        {
            if (tempo->getStateActual() == Casilla::CELL_STATE::J1)
            {
                this->counter_J1++;
            } else{
                this->counter_J2++;
            }
        }
    }
}


/*
void PatronTicTacToe::changeStateCasilla(Casilla::CELL_STATE nw_state, int id)
{
    
    for (int i = 0; i < 3; i++)
    {

        if (casillas[i].id == id && casillas[i].getStateActual() == Casilla::CELL_STATE::TVOID)
        {
            casillas[i].changeState(nw_state);
            if (nw_state == Casilla::CELL_STATE::J1)
            {
                CJ1++;
            }
            else if (nw_state == Casilla::CELL_STATE::J2) {
                CJ2++;
            }

        }
    }
    
*/



