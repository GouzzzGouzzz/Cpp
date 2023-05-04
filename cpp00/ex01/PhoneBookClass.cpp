#include "PhoneBookClass.hpp"
#include <iomanip>

PhoneBook::PhoneBook(void)
{
	std::cout << "Constructur called" << std::endl;

}

PhoneBook::~PhoneBook(void)
{
	std::cout << "Destructor called" << std::endl;
}

void	PhoneBook::showcontact(int index)
{
	std::cout << this->contact[index].get_firstname() << std::endl
	<< this->contact[index].get_lastname() << std::endl
	<< this->contact[index].get_nickname() << std::endl
	<< this->contact[index].get_phone() << std::endl
	<< this->contact[index].get_secret() << std::endl;
}

void	PhoneBook::showinfo(void)
{
	int index;
	std::string data;
	index = -1;
 	for (int i = 0; i < this->nb_contact; i++)
	{
		//iomanip things to truncate...
		std::cout << std::right << std::setw(10) << i+1 << "|"
		<< std::right << std::setw(10) << this->contact[i].get_firstname() << "|"
		<< std::right << std::setw(10) << this->contact[i].get_lastname() << "|"
		<< std::right << std::setw(10) << this->contact[i].get_nickname() << "|"<< std::endl;
	}
	std::cout << "Enter an index to display the entry" << std::endl;
	std::cin.ignore();
	std::getline(std::cin, data);
	index = atoi(data.c_str());
	if (index <= 0 || index > this->nb_contact || (index > this->target && this->nb_contact < 8))
	{
		std::cout << "Invalid index" << std::endl;
		return ;
	}
	showcontact(atoi(data.c_str()) - 1);
}
