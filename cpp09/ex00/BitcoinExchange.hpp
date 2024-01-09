#pragma once
#include <map>
#include <iostream>
#include <fstream>
#include <cstdlib>


class BitcoinExchange
{
private:
	std::map<std::string, float> database;
	void fillDB();
public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange &copy);
	BitcoinExchange& operator=(const BitcoinExchange &cpy);
	~BitcoinExchange();
	void operate(std::string filename);
};
