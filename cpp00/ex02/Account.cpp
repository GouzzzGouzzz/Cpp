#include "Account.hpp"
#include <iostream>

Account::Account( int initial_deposit )
{
	std::cout << "Constructor Account called" << std::endl;
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
}

Account::~Account( void )
{
	std::cout << "Destructor Account called" << std::endl;
}

int Account::getNbAccounts( void )
{
	return _nbAccounts;
}

int Account::getTotalAmount( void )
{
	return _totalAmount;
}

int Account::getNbDeposits( void )
{
	return _totalNbDeposits;
}

int Account::getNbWithdrawals( void )
{
	return _totalNbWithdrawals;
}

void Account::displayAccountsInfos( void )
{
	_displayTimestamp();
}

void Account::makeDeposit( int deposit)
{
	this->_amount += deposit;
	this->_nbDeposits++;
	this->_totalNbDeposits++;
}

bool Account::makeWithdrawal( int withdrawal)
{
	if (withdrawal > _amount)
		return false;
	_amount -= withdrawal;
	_nbWithdrawals++;
	_totalNbWithdrawals++;
	return true;
}

int	checkAmount( void )//co
{
	return 1;
}

void Account::displayStatus( void ) const
{

}

void Account::_displayTimestamp( void )
{
	std::cout << "[" <<"truc"<<"]";
}
