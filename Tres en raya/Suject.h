#pragma once
#include "IObserver.h"

class ISuject
{
public:
	virtual void notifyAllObservers(void) = 0;
	virtual void addObserver(IObserver*& observer) = 0;
	virtual void removeObserver(int id) = 0;
private:

};