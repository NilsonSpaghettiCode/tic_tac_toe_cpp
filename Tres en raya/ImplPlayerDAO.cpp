#include "PlayerDAO.h"

#include <bsoncxx/builder/stream/document.hpp>
#include <bsoncxx/builder/basic/document.hpp>

#include <bsoncxx/types.hpp>

using namespace bsoncxx::types;
using namespace bsoncxx::builder::basic;

ImplPlayerDAO::ImplPlayerDAO(IMongoCollection *& collection_player)
{
	this->collection_player = collection_player;
}

ImplPlayerDAO::~ImplPlayerDAO()
{

}


std::list<Player> ImplPlayerDAO::getAllPlayers()
{
	return std::list<Player>();
}

Player* ImplPlayerDAO::getPlayer(long id)
{
	Player *a = new Player("", 'A', 'B');
	return a;
}
/*
* Permite crear un doc jugador desempaquetando sus atributos y agregandolos a un documento de tipo BSON
* donde finalmente se almacena
*/
void ImplPlayerDAO::createPlayer(Player *& player)
{

	//Es posible refactorizar mejorar lo que se realiza en esta función
	
	document player_doc;

	player_doc.append(kvp( "nickname" , player->getNickname() ));

	player_doc.append(kvp("symbol", player->getSymbol()));
	player_doc.append(kvp("alt_symbol", player->getAltSymbol()));
	
	player_doc.append(kvp("count_games", player->getCountGames()));

	player_doc.append(kvp("wins", b_int64{ player->getWins()} ));
	player_doc.append(kvp("losses", b_int64{ player->getLosses()}));


	this->collection_player->getCollection().insert_one(player_doc.view());
}

void ImplPlayerDAO::updatePlayer(Player*& player)
{
}
