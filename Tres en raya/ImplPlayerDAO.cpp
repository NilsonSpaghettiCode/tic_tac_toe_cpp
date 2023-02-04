#include "PlayerDAO.h"


std::list<Player> ImplPlayerDAO::getAllPlayers()
{
	return std::list<Player>();
}

Player* ImplPlayerDAO::getPlayer(long id)
{
	Player *a = new Player("", 'A', 'B');
	return a;
}

void ImplPlayerDAO::createPlayer(Player *& player)
{

}

void ImplPlayerDAO::updatePlayer(Player*& player)
{
}
