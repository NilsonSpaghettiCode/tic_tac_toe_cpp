#pragma once
#include <iostream>
#include "SystemConfig.h"

class ConfigDB : public SystemConfig
{
public:
	//Constructor and destructor
	ConfigDB();
	~ ConfigDB();

	//Methods overrides
	void load() override;
	
	//Natural methods
	std::string getDB();
	std::string getUri();
	std::string getCollection();
private:
	std::string uri;
	std::string collection;
	std::string db;
};
