#include "Casilla.h"
#include "IObserver.h"

Casilla::Casilla(int id)
{
    this->id = id;
    this->state = CELL_STATE::TVOID;
    this->symbol = ' ';
}
    
void Casilla::changeState(CELL_STATE nw_state)
{
    if (this->state == CELL_STATE::TVOID && nw_state != CELL_STATE::TVOID)
    {
        this->state = nw_state;
        this->notifyAllObservers();
    }
}


void Casilla::showState()
{
    std::cout << this->state;
}

int Casilla::getStateActual()
{
    return this->state;
}

void Casilla::notifyAllObservers(void)
{
    for (auto it = this->observadores.begin(); it != this->observadores.end(); it++)
    {
        (*it)->Update(this->id);
    }
}

void Casilla::addObserver(IObserver*& observer)
{
    this->observadores.push_back(observer);
}

void Casilla::showCasilla()
{   
    std::cout << "ID" << this->id << std::endl;
    std::cout << "STATE " << this->state << std::endl;
    std::cout << "SYMBOL | " << this->symbol << " |" << std::endl;

}


