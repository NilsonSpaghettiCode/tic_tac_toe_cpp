#include "ConfigDB.h"

ConfigDB::ConfigDB()
{
    this->uri = "";
}

ConfigDB::~ConfigDB()
{
}

void ConfigDB::load()
{
    std::string uri = 
    "mongodb://ua7mz3ffsgh3vgghakje:yZZa32ov8vuRf1ER4cEh@n1-c2-mongodb-clevercloud-customers.services.clever-cloud.com:27017,n2-c2-mongodb-clevercloud-customers.services.clever-cloud.com:27017/bq3g0huudu0newc?replicaSet=rs0";
    
    this->uri = uri;
}

std::string ConfigDB::getUri()
{
    return this->uri;
}
