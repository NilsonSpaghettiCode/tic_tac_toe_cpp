#include "PatronTicTacToe.h"
#include <iostream>
#include "Casilla.h"


PatronTicTacToe::PatronTicTacToe(int id, GameState* game)
{
    this->id = id;
    this->state_patron = PATRON_STATES::ON;
    this->game = game;
}

void PatronTicTacToe::Update(int id)
{
    if (this->state_patron)
    {
        this->addToCount(id);
    }
}

void PatronTicTacToe::addSuject(ISuject*& casilla)
{
    IObserver* observer = this;
    casilla->addObserver(observer);
    this->observed_sujects.push_back(casilla);
}

void PatronTicTacToe::removeSujects()
{
    this->state_patron = PATRON_STATES::OFF;
    this->game->removePatron();
    std::cout << "Patron OFF" << std::endl;
}

void PatronTicTacToe::showCounts()
{
    std::cout << "ID: " << this->id << std::endl;
    std::cout << "J1: " << this->counter_J1 << " | " << "J2: " << this->counter_J2 << std::endl;
    std::cout << "CountPoints: " << this->count_points << " | " << "CountGame: " << this->count_game << std::endl;
}

void PatronTicTacToe::checkPatron()
{
    if (this->count_points >= 2 && this->count_points <= 3)
    {
        //std::cout << "Es posible un triqui, o perdida del patron" << std::endl;
        if (this->count_game == 3)
        {
            std::cout << "El ganador es el jugador #1" << std::endl;
            this->game->setEndGame(ENDGAME_STATE::J1);
        }
        else if (this->count_game == -3)
        {
            std::cout << "El ganador es el jugador #2" << std::endl;
            this->game->setEndGame(ENDGAME_STATE::J2);
        }
        else if (this->count_game <= 1 && this->count_game >= -1)
        {
            std::cout << "El patron: " << this->id << " " << "ya no es posible triqui" << std::endl;
            this->removeSujects();
        }
    }
}

int PatronTicTacToe::getId()
{
    return this->id;
}

void PatronTicTacToe::addToCount(int id)
{
    for (auto it = this->observed_sujects.begin(); it != this->observed_sujects.end(); it++)
    {
        Casilla* tempo = dynamic_cast<Casilla*>((*it));
        if (tempo->id == id)
        {
            this->count_points++;

            if (tempo->getStateActual() == Casilla::CELL_STATE::J1)
            {
                this->counter_J1++;
                this->count_game++;
            } else{
                this->counter_J2++;
                this->count_game--;
            }
            break;
        }
    }
    this->checkPatron();
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



