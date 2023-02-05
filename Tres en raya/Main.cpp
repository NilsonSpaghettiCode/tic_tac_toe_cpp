// Tres en raya.cpp : This file contains the 'main' function. Program execution begins and ends there.
///Intern Utilities
#include "MHeaders.h"

#include <mongocxx/client.hpp>
#include <mongocxx/instance.hpp>
#include <bsoncxx/builder/basic/document.hpp>
#include <bsoncxx/builder/stream/document.hpp>
#include <mongocxx/exception/bulk_write_exception.hpp>

IAplication* app;

int IPlayer::_id = 0;
bool IPlayer::isInitialized = false;

int main()
{
	//app = new Aplication(new MainMenuState);
	//app->run();
	
	Player* p1 = new Player("DarkWizardGM", 'X', 'O');
	Player* p2 = new Player("DarkLordGM",   'X', 'O');
	

	std::string db_name = "bq3g0huudu0newc";
	std::string collection_player = "players";
	std::string uri = 

	"mongodb://ua7mz3ffsgh3vgghakje:yZZa32ov8vuRf1ER4cEh@n1-c2-mongodb-clevercloud-customers.services.clever-cloud.com:27017,n2-c2-mongodb-clevercloud-customers.services.clever-cloud.com:27017/bq3g0huudu0newc?replicaSet=rs0";

	IMongoConection::initInstance();
	IMongoCollection* collection_mongo = new MongoCollection(collection_player, db_name, uri);
	
	bsoncxx::builder::stream::document doc1{};

	collection_mongo->getCollection().insert_one(doc1.view());
	//mongocxx::client c = collection_mongo->getConnection();
	//mongocxx::client c1 = collection_mongo->getConnection();
	//mongocxx::database bd = (c1)[db_name];
	//mongocxx::collection coll =  bd[collection_player];

	//
	
	
	/*
	
	
	
	bsoncxx::builder::stream::document doc1{};

	doc1 << "Nickname" << p2->getNickname();
	doc1 << "Symbol" << p2->getSymbol();
	doc1 << "AltSymbol" << p2->getAltSymbol();
	try
	{
		mongo_collection->getCollection().insert_one(doc1.view());
		std::cout << "NO Error";
	}
	catch (const mongocxx::bulk_write_exception& a)
	{
		std::cout << "Error" << a.what();
	}
	*/
	
	return 0;
}
