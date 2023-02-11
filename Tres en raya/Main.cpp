// Tres en raya.cpp : This file contains the 'main' function. Program execution begins and ends there.
///Intern Utilities
#include "MHeaders.h"


IAplication* app;

int IPlayer::_id = 0;
bool IPlayer::isInitialized = false;

int main()
{
	//app = new Aplication(new MainMenuState);
	//app->run();
	
	/*
	ISuject* C1 = new Casilla(1);
	ISuject* C2 = new Casilla(2);
	ISuject* C3 = new Casilla(3);

	ISuject* C4 = new Casilla(4);
	ISuject* C5 = new Casilla(5);
	ISuject* C6 = new Casilla(6);

	ISuject* C7 = new Casilla(7);
	ISuject* C8 = new Casilla(8);
	ISuject* C9 = new Casilla(9);
	
	PatronTicTacToe* H1 = new PatronTicTacToe(1);

	PatronTicTacToe* V1 = new PatronTicTacToe(4);

	H1->addSuject(C1);
	H1->addSuject(C2);
	H1->addSuject(C3);

	V1->addSuject(C1);
	V1->addSuject(C4);
	V1->addSuject(C7);

	Casilla* aux = dynamic_cast<Casilla*>(C1);
	

	aux->changeState(Casilla::J1);

	H1->showCounts();
	V1->showCounts();


	aux = dynamic_cast<Casilla*>(C2);


	H1->showCounts();
	V1->showCounts();

	*/

	
	Player* p1 = new Player("Yolovero", 'X', 'O');
	Player* p2 = new Player("JoseYolo",   'X', 'O');
	
	p1->to_string();
	
	std::string db_name = "bq3g0huudu0newc";
	std::string collection_player = "players";
	std::string uri = 

	"mongodb://ua7mz3ffsgh3vgghakje:yZZa32ov8vuRf1ER4cEh@n1-c2-mongodb-clevercloud-customers.services.clever-cloud.com:27017,n2-c2-mongodb-clevercloud-customers.services.clever-cloud.com:27017/bq3g0huudu0newc?replicaSet=rs0";

	IMongoConection::initInstance();
	IMongoCollection* collection_mongo = new MongoCollection(collection_player, db_name, uri);
	
	PlayerDAO* player_dao = new ImplPlayerDAO(collection_mongo);
	player_dao->createPlayer(p1);
	std::cout << "Player creado: "<<p1->getWins();
	

	return 0;
}
