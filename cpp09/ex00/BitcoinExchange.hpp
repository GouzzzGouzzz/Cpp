#pragma once
#include <map>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <algorithm>
#include <ctime>

class BitcoinExchange
{
private:
	std::map<std::string, float> database;
	void fillDB();
	int get_date(std::string buffer) const;
	void output_error() const;
	int is_valid;
public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange &copy);
	BitcoinExchange& operator=(const BitcoinExchange &cpy);
	~BitcoinExchange();
	void operate(std::string filename);
};
