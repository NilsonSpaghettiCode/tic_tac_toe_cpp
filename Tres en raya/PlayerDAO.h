#pragma once

#include "Player.h"

#include <list>

#include "IMongoCollection.h"


class PlayerDAO
{
private:

public:
	virtual std::list<Player> getAllPlayers()			     = 0;
	virtual Player*			  getPlayer(long id)			 = 0;
	virtual void			  createPlayer(Player *& player) = 0;
	virtual void			  updatePlayer(Player *& player) = 0;
};



class ImplPlayerDAO : public PlayerDAO
{
public:
	ImplPlayerDAO(IMongoCollection *& collection_player);

	~ImplPlayerDAO();

	std::list<Player> getAllPlayers()               override;
	Player*           getPlayer(long id)			override;
	void              createPlayer(Player*& player) override;
	void              updatePlayer(Player*& player) override;

private:
	IMongoCollection* collection_player;


};


