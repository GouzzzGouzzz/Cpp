#include "HarlClass.hpp"

Harl::Harl(void)
{
	std::cout << "Harl constructor called" << std::endl;
}


Harl::~Harl(void)
{
	std::cout << "Harl destructor called" << std::endl;

}

void	Harl::debug(void)
{
	std::cout << "DEBUG : I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}
void	Harl::info(void)
{
	std::cout << "INFO : I cannot believe adding extra bacon costs more money. You didn't putenough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "WARNING : I think I deserve to have some extra bacon for free. I've been coming foryears whereas you started working here since last month." << std::endl;
}

void	Harl::error(void)
{
	std::cout << "ERROR : This is unacceptable! I want to speak to the manager now." << std::endl;
}

void	Harl::complain(std::string level)
{
	std::string comp[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int code = -1;
	for (int i = 0; i < 4; i++)
		if (level == comp[i])
			code = i;
	switch (code)
	{
	case 0:
		debug();
		info();
		warning();
		error();
		break;
	case 1:
		info();
		warning();
		error();
		break;
	case 2:
		warning();
		error();
		break;
	case 3:
		error();
		break;
	default:
		std::cout << "You can't complain about this." << std::endl;
		break;
	}
}
