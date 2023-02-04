// Tres en raya.cpp : This file contains the 'main' function. Program execution begins and ends there.
///Intern Utilities
#include "MHeaders.h"

#include <mongocxx/client.hpp>
#include <mongocxx/instance.hpp>
#include <bsoncxx/builder/basic/document.hpp>
#include <bsoncxx/builder/stream/document.hpp>
IAplication* app;

int IPlayer::_id = 0;
bool IPlayer::isInitialized = false;

int main()
{
	//app = new Aplication(new MainMenuState);
	//app->run();
	
	Player* p1 = new Player("DarkWizardGM", 'X', 'O');
	std::cout << p1->to_string() + "\n";

	Player* p2 = new Player("DarkLordGM", 'X', 'O');
	std::cout << p2->to_string();
	

	std::string db_name = "bq3g0huudu0newc";
	std::string db_collection_player = "players";

	mongocxx::instance inst{}; // This should be done only once.
	mongocxx::client conn{
	   mongocxx::uri{
		  "mongodb://ua7mz3ffsgh3vgghakje:yZZa32ov8vuRf1ER4cEh@n1-c2-mongodb-clevercloud-customers.services.clever-cloud.com:27017,n2-c2-mongodb-clevercloud-customers.services.clever-cloud.com:27017/bq3g0huudu0newc?replicaSet=rs0"
	   }
	};
	mongocxx::database db = conn[db_name];
	mongocxx::collection collection_players =  db.collection(db_collection_player);
	
	bsoncxx::builder::stream::document doc1{};

	doc1 << "Nickname" << p1->getNickname();
	doc1 << "Symbol" << p1->getSymbol();
	doc1 << "AltSymbol" << p1->getAltSymbol();

	//collection_players.insert_one(doc1.view());
	//collection_players.insert_one()
	char x(88);
	std::cout << "Symbol" << x;
}
