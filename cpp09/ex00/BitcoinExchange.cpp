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
		db.close();
		return ;
	}
	while (std::getline(db,buffer,'\n'))
	{
		//will need more check
		if (buffer.find(",") != std::string::npos && std::count(buffer.begin(), buffer.end(), ',') == 1)
		{
			value = std::strtof(buffer.substr(buffer.find(",")+1).c_str(), NULL);
			this->database.insert(std::pair<std::string, float>(buffer.substr(0, buffer.find(",")), value));
			//std::cout << "ADDED:" << buffer.substr(0, buffer.find(",")) << "WITH VAL:" << this->database.at(buffer.substr(0, buffer.find(","))) << std::endl;
		}
	}
	db.close();
}

void BitcoinExchange::operate(std::string filename)
{
	std::ifstream file(filename.c_str());
	std::string buffer, date;

	float value;
	if (!file.is_open())
	{
		std::cout << "Failed to open file:" << filename << std::endl;
		return;
	}
	std::getline(file,buffer,'\n');
	if (buffer != "date | value")
	{
		std::cout << "Invalid format for file:"<< buffer << std::endl;
		file.close();
		return ;
	}
	while (std::getline(file,buffer,'\n'))
	{
		if (buffer.find("|") != std::string::npos && std::count(buffer.begin(), buffer.end(),'|') == 1)
		{
			bool is_valid = true;
			std::string low, forced_lower;
			std::map<std::string, float>::reverse_iterator rit;

			value = std::strtof(buffer.substr(buffer.find("|")+1).c_str(), NULL);
			date = buffer.substr(0, buffer.find("|")-1);
			if (value < 0)//need check que : xxxx-xx-xx et pas autrement
			{
				std::cout << "Error: not a positivie number." << std::endl;
				is_valid = false;
			}
			else if (value > 1000)
			{
				std::cout << "Error: too large a number." << std::endl;
				is_valid = false;
			}
			if (is_valid == true && this->database.find(date) != this->database.end())//la date exact est trouvée
			{
				std::cout << date << "=> " << value << " = " << value * this->database.at(date) << std::endl;
			}
			else if (is_valid == true)// ont prend la plus proche autrement
			{
				low = this->database.lower_bound(date)->first;
				if (low != this->database.begin()->first)
				{
					for (rit = this->database.rbegin(); rit != this->database.rend(); rit++)
					{
						if ((*rit).first == low)
						{
							rit++;
							forced_lower = (*rit).first;
							break;
						}
					}
					// ont converti les dates : 2000-12-02 en jour pour calculer la diff en jour par rapport la date en input
					int low_date[3], forced_date[3], requested[3], low_diff, forced_diff, day_date;
					low_date[0]=atoi(low.substr(0,4).c_str());
					low_date[1]=atoi(low.substr(5,7).c_str());
					low_date[2]=atoi(low.substr(8,10).c_str());
					forced_date[0]=atoi(forced_lower.substr(0,4).c_str());
					forced_date[1]=atoi(forced_lower.substr(5,7).c_str());
					forced_date[2]=atoi(forced_lower.substr(8,10).c_str());
					requested[0]=atoi(date.substr(0,4).c_str());
					requested[1]=atoi(date.substr(5,7).c_str());
					requested[2]=atoi(date.substr(8,10).c_str());
					//need prendre en comptes les annees bisextiles (avec modulo 4 je crois)
					day_date = 365 * requested[0] + 30 * requested[1] + requested[2];
					low_diff = 365 * low_date[0] + 30 * low_date[1] + low_date[2] - day_date;
					forced_diff = day_date - (365 * forced_date[0] + 30 * forced_date[1] + forced_date[2]);
					if (forced_diff < low_diff)
						std::cout << date << " => " << value << " = " << value * (*rit).second << std::endl;
					else
						std::cout << date << " => " << value << " = " << value * this->database.lower_bound(date)->second << std::endl;
				}
			}
		}
		else
			std::cout << "Error: bad input => " << buffer << std::endl;
	}
	file.close();
}
