#pragma once
#include <list>
#include "Player.h"
class PlayerDAO
{
private:

public:
	virtual std::list<Player>getAllPlayers() = 0;
	virtual Player* getPlayer(long id) = 0;
	virtual void createPlayer(Player *& player) = 0;
	virtual void updatePlayer(Player*& player) = 0;
};

class ImplPlayerDAO
{
public:
	ImplPlayerDAO();
	~ImplPlayerDAO();

	std::list<Player>getAllPlayers();
	Player* getPlayer(long id);
	void createPlayer(Player*& player);
	void updatePlayer(Player*& player);

private:


};
