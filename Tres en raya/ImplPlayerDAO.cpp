#include "PlayerDAO.h"

#include <cstdint>
#include <iostream>
#include <vector>
#include <string>

#include <mongocxx/client.hpp>
#include <mongocxx/stdx.hpp>
#include <mongocxx/uri.hpp>
#include <mongocxx/instance.hpp>

#include <bsoncxx/builder/basic/document.hpp>
#include <bsoncxx/builder/stream/document.hpp>
#include <bsoncxx/builder/stream/array.hpp>
#include <bsoncxx/builder/stream/helpers.hpp>
#include <bsoncxx/types.hpp>
#include <bsoncxx/json.hpp>
#include <bsoncxx/stdx/string_view.hpp>
#include <bsoncxx/oid.hpp>


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
	document doc_filter;
	mongocxx::options::find options{};

	options.sort(bsoncxx::from_json("{\"wins\": -1}"));
	options.limit(long(10));

	mongocxx::cursor cursor_players = this->collection_player->getCollection().find(doc_filter.view(), options);
	
	std::list<Player> list_players;

	/*
	* Se accede a los documentos player de la colecciones de players, con la siguiente forma:
	* {
	* "nickane"    : value
	* "symbol"     : value
	* "alt_symbol" : value
	* "count_games": value
	* "wins"       : value
	* "losses"     : value
	* }
	
	*/

	for (auto it = cursor_players.begin(); it != cursor_players.end(); it++) {
		
		bsoncxx::document::view view_player = (*it);
		Player player = toPlayer(view_player);
		list_players.push_back(player);
	}

	return list_players;
}

Player* ImplPlayerDAO::getPlayer(std::string id)
{
	bsoncxx::builder::stream::document filter_builder;
	bsoncxx::oid player_id(id);

	filter_builder << "_id" << player_id;
	auto cursor_players = this->collection_player->getCollection().find_one(filter_builder.view());
	bsoncxx::document::view view_player = *cursor_players;

	Player* player = new Player(toPlayer(view_player));
	return player;
}
/*
* Permite crear un doc jugador desempaquetando sus atributos y agregandolos a un documento de tipo BSON
* donde finalmente se almacena
*/
void ImplPlayerDAO::createPlayer(Player *& player)
{

	//Es posible refactorizar para mejorar lo que se realiza en esta función
	
	document player_doc;

	player_doc.append(kvp( "nickname" , player->getNickname() ));

	player_doc.append(kvp("symbol", player->getSymbol()));
	player_doc.append(kvp("alt_symbol", player->getAltSymbol()));
	
	player_doc.append(kvp("count_games", player->getCountGames()));

	player_doc.append(kvp("wins", b_int64{ player->getWins()} ));
	player_doc.append(kvp("losses", b_int64{ player->getLosses()}));

	std::string nw_id = this->collection_player->getCollection().insert_one(player_doc.view()).get().inserted_id().get_oid().value.to_string();
	player->setId(nw_id);
}

void ImplPlayerDAO::updatePlayer(Player*& player)
{

}

Player ImplPlayerDAO::toPlayer(bsoncxx::document::view view_document)
{
	std::string _id = view_document["_id"].get_oid().value.to_string();

	std::string nickname = std::string(view_document["nickname"].get_utf8().value);

	char symbol = char(view_document["symbol"].get_int32().value);
	char alt_symbol = char(view_document["alt_symbol"].get_int32().value);

	int count_games = int(view_document["count_games"].get_int32().value);

	long wins = long(view_document["wins"].get_int64().value);
	long losses = long(view_document["losses"].get_int64().value);

	return Player(_id, nickname, symbol, alt_symbol, count_games, wins, losses);
}
