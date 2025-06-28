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
	//printen
}

Account::Account( int initial_deposit ) 
: _accountIndex(_nbAccounts), _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0)
{
	_nbAccounts++;
	_totalAmount += initial_deposit;
	//printen
}

Account::~Account( void ) {} ///printen

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

void	Account::_displayTimestamp( void )//printen
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

void	Account::displayAccountsInfos( void )//printen
{
	_displayTimestamp();
	std::cout	<< "accounts:" << getNbAccounts() 
				<< ";total:" << getTotalAmount()
				<< ";deposits:" << getNbDeposits()
				<< ";withdrawals:" << getNbWithdrawals()
				<< std::endl;
}

void	Account::makeDeposit( int deposit )
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
}
[19920104_091532] index:0;p_amount:42;deposit:5;amount:47;nb_deposits:1


bool	Account::makeWithdrawal( int withdrawal )

[19920104_091532] index:6;amount:763;deposits:1;withdrawals:0


int		Account::checkAmount( void ) const



void	Account::displayStatus( void ) const //printen
{
	_displayTimestamp();
	std::cout	<< "index:" << _accountIndex
				<< ";amount:" << _amount
				<< ";created"
				<< std::endl;
}


