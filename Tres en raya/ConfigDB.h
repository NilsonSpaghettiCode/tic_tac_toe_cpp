#pragma once
#include <iostream>
#include "SystemConfig.h"

class ConfigDB : public SystemConfig
{
public:
	 ConfigDB();
	~ ConfigDB();

	void load() override;
	std::string getUri();

private:
	std::string uri;
};
