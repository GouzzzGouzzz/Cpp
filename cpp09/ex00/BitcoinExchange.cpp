#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	std::cout << "BitcoinExchange created\n";
	fillDB();
	this->_is_valid = false;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy)
{
	std::cout << "BitcoinExchange created with copy constructor\n";
	this->database = copy.database;
	this->_is_valid = false;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &copy)
{
	std::cout << "BitcoinExchange created with operator constructor\n";
	this->database = copy.database;
	this->_is_valid = false;
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
		}
	}
	db.close();
}

int BitcoinExchange::get_date(std::string buffer) const
{
	int tab[3];
	int leap_year = 0;
	tab[0]=atoi(buffer.substr(0,4).c_str());
	tab[1]=atoi(buffer.substr(5,7).c_str());
	tab[2]=atoi(buffer.substr(8,10).c_str());
	if (tab[0] % 400 == 0)
		leap_year = 1;
	else if (tab[0] % 100 == 0)
		leap_year = 0;
	else if (tab[0] % 4 == 0)
		leap_year = 1;
	if (tab[1] < 1 || tab[1] > 12)
		return -1;
	if (tab[2] < 1 || tab[2] > 31)
		return -1;
	return (365 * tab[0] + 30 * tab[1] + tab[2] + leap_year);
}

void BitcoinExchange::output_error() const
{
	switch (this->_is_valid)
	{
	case 1:
		std::cout << "Error : Invalid year format" << std::endl;
		break;
	case 2:
		std::cout << "Error : Invalid month format" << std::endl;
		break;
	case 3:
		std::cout << "Error : Invalid day format" << std::endl;
		break;
	case 4:
		std::cout << "Error : Invalid format" << std::endl;
		break;
	case 5:
		std::cout << "Error : not a positive number" << std::endl;
		break;
	case 6:
		std::cout << "Error : too large a number" << std::endl;
		break;
	case 7:
		std::cout << "Error : Invalid date" << std::endl;
		break;
	default:
		break;
	}
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
		this->_is_valid = 0;
		if (buffer.find("|") != std::string::npos && std::count(buffer.begin(), buffer.end(),'|') == 1 && buffer[buffer.find("|")+1] == ' ')
		{
			std::string low, forced_lower;
			std::map<std::string, float>::reverse_iterator rit;

			value = std::strtof(buffer.substr(buffer.find("|")+1).c_str(), NULL);
			date = buffer.substr(0, buffer.find("|")-1);
			if (std::count(date.begin(), date.end(), '-') == 2 && date.size() == 10)
			{
				if (date[4] != '-' || date[7] != '-')
					this->_is_valid = 1;
				else
				{
					for (int i = 0; i < 10; i++)
					{
						if (i < 4)
							if (isdigit(date[i]) == 0)
								this->_is_valid = 1;
						if (i > 4 && i < 7)
							if (isdigit(date[i]) == 0)
								this->_is_valid = 2;
						if (i > 7)
							if (isdigit(date[i]) == 0)
								this->_is_valid = 3;
					}
				}
			}
			else
				this->_is_valid = 4;
			if (value < 0)
				this->_is_valid = 5;
			else if (value > 1000)
				this->_is_valid = 6;
			output_error();
			if (this->_is_valid == 0 && this->database.find(date) != this->database.end())
				std::cout << date << "=> " << value << " = " << value * this->database.at(date) << std::endl;
			else if (this->_is_valid == 0)
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
					int low_diff, forced_diff, day_date;
					if (get_date(date) == -1 || get_date(low) == -1 || get_date(forced_lower) == -1)
						this->_is_valid = 7;
					else{
						day_date = get_date(date);
						low_diff = get_date(low) - day_date;
						forced_diff = day_date - get_date(forced_lower);
					}
					output_error();
					if (forced_diff < low_diff && this->_is_valid == 0)
						std::cout << date << " => " << value << " = " << value * (*rit).second << std::endl;
					else if (this->_is_valid == 0)
						std::cout << date << " => " << value << " = " << value * this->database.lower_bound(date)->second << std::endl;
				}
			}
		}
		else
			std::cout << "Error : bad input => " << buffer << std::endl;
	}
	file.close();
}
