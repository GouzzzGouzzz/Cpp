#include "BitcoinExchange.hpp"

void BitcoinExchange::fillInfo(std::string filename)
{
	std::ifstream infile (filename.c_str());
	std::ifstream db ("data.csv");
	std::string buffer;
	float temp;
	if (!infile || !db)
	{
		if (infile.is_open())
			infile.close();
		if (db.is_open())
			db.close();
		std::cout << "Failed to open a file\n";
		return ;
	}
	std::getline(infile,buffer,'\n');
	if (buffer != "date | value")
	{
		std::cout << "Invalid format for infile:" << buffer << std::endl;
		return ;
	}
	while (std::getline(infile,buffer,'\n'))
	{
		//need check error for valid date
		if (buffer.find("|") != std::string::npos)
		{
			temp = std::strtof(buffer.substr(buffer.find("|")+1).c_str(), NULL);
			this->request.insert(std::pair<std::string, float>(buffer.substr(0, buffer.find("|")), temp));
		}
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
			temp = std::strtof(buffer.substr(buffer.find(",")+1).c_str(), NULL);
			this->database.insert(std::pair<std::string, float>(buffer.substr(0, buffer.find(",")), temp));
		}
	}
}

BitcoinExchange::BitcoinExchange(std::string filename)
{
	std::cout << "BitcoinExchange created\n";
	fillInfo(filename);
}

BitcoinExchange::~BitcoinExchange()
{
	std::cout << "BitcoinExchange deleted\n";
}
