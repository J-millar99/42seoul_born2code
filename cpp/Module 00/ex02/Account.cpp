#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

// public part

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int Account::getNbAccounts()
{
	return (_nbAccounts);
}

int Account::getTotalAmount()
{
	return (_totalAmount);
}

int Account::getNbDeposits()
{
	return (_totalNbDeposits);
}

int Account::getNbWithdrawals()
{
	return (_totalNbWithdrawals);
}

void Account::displayAccountsInfos()
{
	_displayTimestamp();
	std::cout << "account:" << getNbAccounts() << ';'
			  << "total:" << getTotalAmount() << ';'
			  << "deposits:" << getNbDeposits() << ';'
			  << "withdrawals:" << getNbWithdrawals() << std::endl;
	/*
	for(int i = 0; i <= _nbAccounts; i++)
	{
		_displayTimestamp();
		std::cout << "index:" << i << ';' << "amount:" << ....
	}
	*/

}

Account::Account(int initial_deposit)
{
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_accountIndex = _nbAccounts;
	_amount = initial_deposit;
	_totalAmount += _amount;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ';'
			  << "amount:" << _amount << ';'
			  << "created" << std::endl;
	_nbAccounts++;
}

Account::~Account()
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ';'
			  << "amount:" << _amount << ';'
			  << "closed" << std::endl;
}

void Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	_nbDeposits++;
	_totalNbDeposits++;
	std::cout << "index:" << _accountIndex << ';'
			  << "p_amount:" << _amount << ';'
			  << "deposit:" << deposit << ';';
	_amount += deposit;
	_totalAmount += deposit;
	std::cout << "amount:" << _amount << ';'
			  << "nb_deposits:" << _nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ';'
			  << "p_amount:" << _amount << ';';
	if (_amount < withdrawal)
	{
		std::cout << "withdrawal:refused" << std::endl;
		return (false);
	}
	else
	{
		_nbWithdrawals++;
		_totalNbWithdrawals++;
		_amount -= withdrawal;
		_totalAmount -= withdrawal;
		std::cout	<< "withdrawal:" << withdrawal << ';'
			  		<< "amount:" << _amount << ';'
			  		<< "nb_withdrawals:" << _nbDeposits << std::endl;
	}
	return (true);
}

int Account::checkAmount() const
{
	return (1);
}

void Account::displayStatus() const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ';'
			  << "amount:" << _amount << ';'
			  << "deposits:" << _nbDeposits << ';'
			  << "withdrawals:" << _nbWithdrawals << std::endl;
}

// private part

void Account::_displayTimestamp()
{
    std::time_t currentTime = std::time(NULL);
    struct std::tm *localTime = std::localtime(&currentTime);

    std::cout << '['
              << (localTime->tm_year + 1900)
              << std::setw(2) << std::setfill('0') << (localTime->tm_mon + 1)
              << std::setw(2) << std::setfill('0') << localTime->tm_mday << '_'
              << std::setw(2) << std::setfill('0') << localTime->tm_hour
              << std::setw(2) << std::setfill('0') << localTime->tm_min
              << std::setw(2) << std::setfill('0') << localTime->tm_sec << ']'
			  << ' ';
}

Account::Account() {};