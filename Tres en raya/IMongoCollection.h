#pragma once
#include "IMongoConection.h"
#include <mongocxx/client.hpp>
class IMongoCollection : public IMongoConection
{
public:
	//IMongoCollection : IMongoConection();
	//~IMongoCollection : IMongoConection();

	virtual mongocxx::collection getCollection()                            = 0;
	virtual void				 setCollection(std::string name_collection) = 0;

	virtual void                 setDB(std::string db_name) override        = 0;
	virtual mongocxx::database   getDB() override							= 0;
	virtual mongocxx::client*     getConnection() override					= 0;
	
private:

};

class MongoCollection : public IMongoCollection
{
public:

	MongoCollection(std::string collection_name, std::string db_name, std::string uri);
	~MongoCollection();

	mongocxx::collection	  getCollection()							 override;
	void					  setCollection(std::string name_collection) override;
	void					  setDB(std::string db_name)			     override;
	mongocxx::database		  getDB()									 override;
	virtual mongocxx::client* getConnection()							 override;

private:
	std::string collection_name;
	std::string db_name;
	std::string uri;
	mongocxx::client* conection_mongo;

};

MongoCollection::MongoCollection(std::string collection_name, std::string db_name, std::string uri)
{
	this->collection_name = collection_name;
	this->db_name		  = db_name;
	this->uri			  = uri;
	this->conection_mongo = new mongocxx::client(mongocxx::uri{ this->uri });
}

MongoCollection::~MongoCollection()
{

}

mongocxx::collection MongoCollection::getCollection()
{
	mongocxx::collection collection = this->getDB()[this->collection_name];
	return collection;
}

void MongoCollection::setCollection(std::string name_collection)
{
	this->collection_name = name_collection;
}

mongocxx::database MongoCollection::getDB()
{
	mongocxx::client* client = this->getConnection();
	mongocxx::database db    = client->database(this->db_name);
	return db;
}

mongocxx::client* MongoCollection::getConnection()
{
	
	return this->conection_mongo;
}

void MongoCollection::setDB(std::string db_name)
{
	this->db_name = db_name;
}


