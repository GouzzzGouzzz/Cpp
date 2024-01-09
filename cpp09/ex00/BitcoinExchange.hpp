#pragma once
#include <map>
#include <iostream>
#include <fstream>
#include <cstdlib>

class BitcoinExchange
{
private:
	std::map<std::string, float> database;
	std::map<std::string, float> request;
	void fillInfo(std::string filename);
public:
	BitcoinExchange(std::string);
	~BitcoinExchange();
};
