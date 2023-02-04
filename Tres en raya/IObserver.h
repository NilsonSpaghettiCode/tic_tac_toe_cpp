#pragma once
//#include "Suject.h"

class IObserver
{
protected:
    //std::list<Casilla*> casillasObservadas;
public:
    virtual void Update(int id) = 0;
    //virtual void addSuject(ISuject*& casilla) = 0;

};
