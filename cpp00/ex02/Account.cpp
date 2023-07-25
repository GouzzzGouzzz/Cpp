#include "Account.hpp"
#include <iostream>
#include <ctime>

//Initialize static var

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

//Constructor

Account::Account(int initial_deposit) : _amount(initial_deposit), _accountIndex(_nbAccounts)
{
	Account::_displayTimestamp();
	std::cout << "index:"<< this->_accountIndex
			<< ";amount:" << this->_amount
			<< ";created\n";
	_nbAccounts++;
	_totalAmount+= initial_deposit;
}

Account::~Account()
{
	Account::_displayTimestamp();
	std::cout << "index:"<< this->_accountIndex
		<< ";amount:" << this->_amount << ";closed\n";
}

//Setter/Getter

int	Account::getNbAccounts( void ) {return (_nbAccounts);}

int	Account::getTotalAmount( void ) {return (_totalAmount);}

int	Account::getNbDeposits( void ) {return (_totalNbDeposits);}

int	Account::getNbWithdrawals( void ) {return (_totalNbWithdrawals);}

int Account::checkAmount( void ) const {return (this->_amount); }

//Functions

void Account::makeDeposit(int deposit)
{
	int p_amount = this->_amount;
	this->_nbDeposits++;
	this->_amount += deposit;
	_totalAmount += deposit;
	_totalNbDeposits++;
	Account::_displayTimestamp();
	std::cout << "index:"<<this->_accountIndex
	<<";p_amount:" <<p_amount
	<<";deposit:"<<deposit
	<<";amount:"<< this->_amount
	<<";nb_deposit:" << this->_nbDeposits << "\n";
}

bool Account::makeWithdrawal( int withdrawal )
{
	int p_amount = this->_amount;
	if (withdrawal > this->_amount)
	{
		Account::_displayTimestamp();
		std::cout << "index:"<<this->_accountIndex
		<<";p_amount:"<< p_amount
		<<";withdrawal:refused\n";
		return (false);
	}
	this->_amount -= withdrawal;
	_totalNbWithdrawals++;
	_totalAmount -= withdrawal;
	this->_nbWithdrawals++;
	Account::_displayTimestamp();
	std::cout << "index:"<< this->_accountIndex
	<<";p_amount:"<< p_amount
	<<";withdrawal:"<< withdrawal
	<<";amount:"<< this->_amount
	<<";nb_withdrawals:" << this->_nbWithdrawals << "\n";
	return (true);
}

void Account::displayStatus() const
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
		<<";amount:" << this->_amount
		<<";deposits:" << this->_nbDeposits
		<<";withdrawals:" << this->_nbWithdrawals << "\n";
}

void	Account::displayAccountsInfos( void )
{
	Account::_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts
		<<";total:" << _totalAmount
		<<";deposits:" << _totalNbDeposits
		<<";withdrawals:" << _totalNbWithdrawals << "\n";
}

void	Account::_displayTimestamp( void )
{
	std::time_t time = std::time(0);
	std::tm* loctime = std::localtime(&time);
	std::cout << "["
	<< loctime->tm_year + 1900
	<< loctime->tm_mon + 1
	<< loctime->tm_mday
	<< "_"
	<< loctime->tm_hour
	<< loctime->tm_min
	<< loctime->tm_sec << "] ";
}
