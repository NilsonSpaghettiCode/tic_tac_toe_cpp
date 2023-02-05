#pragma once
#include <mongocxx/instance.hpp>
#include <mongocxx/client.hpp>
class IMongoConection
{
public:
	static void initInstance() 
	{
		static mongocxx::instance inst{};
	}
	virtual mongocxx::client*	getConnection()	   = 0;
	virtual mongocxx::database  getDB()            = 0;
	virtual void				setDB(std::string) = 0;
	
private:

};
