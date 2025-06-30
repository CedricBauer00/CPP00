#include "Account.hpp"
#include <ctime>
#include <iostream>
#include <iomanip>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account( void ) : _accountIndex(_nbAccounts),
							_amount(0),
							_nbDeposits(0),
							_nbWithdrawals(0)
{
	_nbAccounts++;
	_displayTimestamp();
	std::cout	<< "index:" << _accountIndex
				<< ";amount:" << _amount
				<< ";created"
				<< std::endl;
}

Account::Account( int initial_deposit ) 
: _accountIndex(_nbAccounts), _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0)
{
	_nbAccounts++;
	_totalAmount += initial_deposit;
	_displayTimestamp();
	std::cout	<< "index:" << _accountIndex
				<< ";amount:" << _amount
				<< ";created"
				<< std::endl;
}

Account::~Account( void )
{
	_displayTimestamp();
	std::cout	<< "index:" << _accountIndex
				<< ";amount:" << _amount
				<< ";closed"
				<< std::endl;
}

void	Account::_displayTimestamp( void )
{
	std::time_t now = std::time(nullptr);
	std::tm *time = std::localtime(&now);
	std::cout	<< "[" << 1900 + time->tm_year
				<< std::setw(2) << std::setfill('0') << time->tm_mon + 1
				<< std::setw(2) << std::setfill('0') << time->tm_mday
				<< "_"
				<< std::setw(2) << std::setfill('0') << time->tm_hour
				<< std::setw(2) << std::setfill('0') << time->tm_min
				<< std::setw(2) << std::setfill('0') << time->tm_sec
				<< "] ";
}

void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout	<< "accounts:" << getNbAccounts() 
				<< ";total:" << getTotalAmount()
				<< ";deposits:" << getNbDeposits()
				<< ";withdrawals:" << getNbWithdrawals()
				<< std::endl;
}

void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout	<< "index:" << _accountIndex
				<< ";amount:" << checkAmount()
				<< ";deposits:" << _nbDeposits
				<< ";withdrawals:" << _nbWithdrawals
				<< std::endl;
}

void	Account::makeDeposit( int deposit )
{
	_displayTimestamp();
	std::cout	<< "index:" << _accountIndex
				<< ";p_amount:" << checkAmount()
				<< ";deposit:" << deposit;
	_amount	 += deposit;
	_nbDeposits++;
	std::cout	<< ";amount:" << checkAmount()
				<< ";nb_deposits:" << _nbDeposits
				<< std::endl;
	_totalAmount += deposit;
	_totalNbDeposits++;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	_displayTimestamp();
	if (withdrawal > _amount)
	{
		return (std::cout << "index:" << _accountIndex
				<< ";p_amount:" << checkAmount() << ";withdrawal:refused" << std::endl, 1);
	}
	else
	{
		std::cout	<< "index:" << _accountIndex
					<< ";p_amount:" << checkAmount()
					<< ";withdrawal:" << withdrawal;
		_amount -= withdrawal;
		_nbWithdrawals++;
		std::cout	<< ";amount:" << checkAmount()
					<< ";nb_withdrawals:" << _nbWithdrawals
					<< std::endl;
		_totalAmount -= withdrawal;
		_totalNbWithdrawals++;
	}
	return (0);
}

int	Account::getNbAccounts( void )
{
	return (_nbAccounts);
}

int	Account::getTotalAmount( void )
{
	return (_totalAmount);
}

int	Account::getNbDeposits( void )
{
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals( void )
{
	return (_totalNbWithdrawals);
}

int		Account::checkAmount( void ) const
{
	return (_amount);
}
