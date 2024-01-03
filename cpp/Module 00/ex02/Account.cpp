#include "Account.hpp"
#include <iostream>
#include <chrono>
#include <ctime>

// public part

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
	return (_totalNbDeposits);
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
	std::cout << "index:" << _accountIndex << ';'
			  << "p_amount:" << _amount << ';'
			  << "deposit:" << deposit << ';'
			  << "amount" << _amount + deposit << ';'
			  << "nb_deposits:" << _nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawal)
{
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
    auto currentTime = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    struct std::tm *localTime = std::localtime(&currentTime);

    // 현재 년도, 월, 일, 시간, 분, 초 출력
    std::cout << '['
              << (localTime->tm_year + 1900)
              << (localTime->tm_mon + 1)
              << localTime->tm_mday << '_'
              << localTime->tm_hour
              << localTime->tm_min
              << localTime->tm_sec << ']'
			  << ' ';
}


Account::Account()
{
}