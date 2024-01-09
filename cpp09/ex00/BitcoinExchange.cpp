#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	std::cout << "BitcoinExchange created\n";
	fillDB();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy)
{
	std::cout << "BitcoinExchange created with copy constructor\n";
	this->database = copy.database;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &copy)
{
	std::cout << "BitcoinExchange created with operator constructor\n";
	this->database = copy.database;
	return *this;
}

BitcoinExchange::~BitcoinExchange()
{
	std::cout << "BitcoinExchange deleted\n";
}

void BitcoinExchange::fillDB()
{
	std::ifstream db ("data.csv");
	std::string buffer;
	float value;
	if (!db)
	{
		std::cout << "Failed to open database file\n";
		return ;
	}
	std::getline(db,buffer,'\n');
	if (buffer != "date,exchange_rate")
	{
		std::cout << "Invalid format for database:"<< buffer << std::endl;
		return ;
	}
	while (std::getline(db,buffer,'\n'))
	{
		if (buffer.find(",") != std::string::npos)
		{
			value = std::strtof(buffer.substr(buffer.find(",")+1).c_str(), NULL);
			this->database.insert(std::pair<std::string, float>(buffer.substr(0, buffer.find(",")), temp));
		}
	}
	db.close();
}

void BitcoinExchange::operate(std::string filename)
{
	std::ifstream file(filename);
	std::string buffer;
	float value;
	if (!file.is_open())
	{
		std::cout << "Failed to open file:" << filename << std::endl;
		return
	}
	while (std::getline(file,buffer,'\n'))
	{

	}
	file.close();
}
