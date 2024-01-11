#pragma once
#include <map>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <algorithm>
#include <ctime>

class BitcoinExchange
{
public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange &copy);
	BitcoinExchange& operator=(const BitcoinExchange &cpy);
	~BitcoinExchange();
	void operate(std::string filename);
private:
	std::map<std::string, float> database;
	void fillDB();
	int get_date(std::string buffer) const;
	void output_error(std::string db) const;
	int _is_valid;
	bool init;
	void check_date(std::string date);
};
