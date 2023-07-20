#include "PhoneBookClass.hpp"
#include <iomanip>

PhoneBook::PhoneBook(void)
{
	std::cout << "PhoneBook constructor called" << std::endl;
	this->_nb_contact = 0;
	this->_target = 0;
}

PhoneBook::~PhoneBook(void)
{
	std::cout << "PhoneBook destructor called" << std::endl;
}

void	PhoneBook::showcontact(int index)
{
	std::cout << "First name     :" << this->_contact[index].get_firstname() << std::endl
	<< "Last name      :" << this->_contact[index].get_lastname() << std::endl
	<< "Nickname       :" << this->_contact[index].get_nickname() << std::endl
	<< "Phone number   :" << this->_contact[index].get_phone() << std::endl
	<< "Darkest secret :" << this->_contact[index].get_secret() << std::endl;
}

void	PhoneBook::showinfo(void)
{
	int index;
	std::string data, first, last, nick;
	index = -1;
	if (this->_nb_contact == 0)
	{
		std::cout << "NO CONTACT FOUND" << std::endl;
		return ;
	}
 	for (int i = 0; i < this->_nb_contact; i++)
	{
		first = this->_contact[i].get_firstname();
		last = this->_contact[i].get_lastname();
		nick = this->_contact[i].get_nickname();
		if (first.length() >= 10)
			first.resize(10); first[9] = '.';
		if (last.length() >= 10)
			last.resize(10); last[9] = '.';
		if (nick.length() >= 10)
			nick.resize(10); nick[9] = '.';
		std::cout << std::setw(10) << i+1 << "|"
		<< std::setw(10) << first << "|"
		<< std::setw(10) << last << "|"
		<< std::setw(10) << nick << "|"<< std::endl;
	}
	std::cout << "Enter an index to display the entry" << std::endl;
	std::cin.ignore();
	std::getline(std::cin, data);
	index = atoi(data.c_str());
	if (index <= 0 || index > this->_nb_contact || (index > this->_target && this->_nb_contact < 8))
	{
		std::cout << "Invalid index" << std::endl;
		return ;
	}
	showcontact(atoi(data.c_str()) - 1);
}

void PhoneBook::add()
{
	int index = this->_target;
	std::string first, last, nick, phone, secret;
	if (this->_target >= 8)
		this->_target = 0;
	std::cin.ignore();
	std::cout << "Enter a first name" << std::endl; //can enter empty field
	std::getline(std::cin, first);
	std::cout << "Enter a last name" << std::endl;
	std::getline(std::cin, last);
	std::cout << "Enter a nickname" << std::endl;
	std::getline(std::cin, nick);
	std::cout << "Enter a phone number" << std::endl;
	std::getline(std::cin, phone);
	std::cout << "Enter the biggest secret you know about him / her" << std::endl;
	std::getline(std::cin, secret);
	if (!last.empty() && !first.empty() && !nick.empty() && !phone.empty() && !secret.empty())
	{
		this->_contact[index].set_firstname(first);
		this->_contact[index].set_lastname(last);
		this->_contact[index].set_nickname(nick);
		this->_contact[index].set_phone(phone);
		this->_contact[index].set_secret(secret);
		if (this->_nb_contact < 8)
		{
			this->_target++;
			this->_nb_contact++;
		}
	}
	else
		std::cout << "A field is empty, the contact will not be saved" << std::endl;
}
