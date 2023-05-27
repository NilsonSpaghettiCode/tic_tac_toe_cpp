#include "Casilla.h"
#include "IObserver.h"
#include "PatronTicTacToe.h"
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
    for (auto it = this->observers.begin(); it != this->observers.end(); it++)
    {
        (*it)->Update(this->id);
    }
}

void Casilla::addObserver(IObserver*& observer)
{
    this->observers.push_back(observer);
}

void Casilla::removeObserver(int id)
{
    std::list<IObserver*>::iterator to_remove;
    for (auto it = this->observers.begin(); it != this->observers.end(); it++)
    {
        PatronTicTacToe* patron_to_remove = dynamic_cast<PatronTicTacToe*>((*it));
        if (patron_to_remove->getId() == id)
        {
            to_remove = it;
            break;
        }
    }
    
    this->observers.erase(to_remove);
    std::cout << "Eliminado" << std::endl;
}

void Casilla::showCasilla()
{   
    std::cout << "ID" << this->id << std::endl;
    std::cout << "STATE " << this->state << std::endl;
    std::cout << "SYMBOL | " << this->symbol << " |" << std::endl;

}


