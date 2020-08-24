/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashishae <ashishae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 21:24:05 by ashishae          #+#    #+#             */
/*   Updated: 2020/08/23 19:24:16 by ashishae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.class.hpp"
#include <iostream>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

int	Account::getNbAccounts(void)
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

void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts << ";total:" << _totalAmount
	<< ";deposits:" << _totalNbDeposits << ";withdrawals:" 
	<< _totalNbWithdrawals << std::endl;
}

Account::Account( int initial_deposit )
{
	this->_accountIndex = _nbAccounts;
	_nbAccounts += 1;
	_amount = initial_deposit;
	_totalAmount += initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	this->_displayTimestamp();
	std::cout << "index:" << this->_accountIndex <<
	";amount:" << this->_amount << ";created" << std::endl;

}

Account::~Account( void )
{
	this->_displayTimestamp();
	std::cout << "index:" << this->_accountIndex <<
	";amount:" << this->_amount << ";closed" << std::endl;
}

void	Account::makeDeposit( int deposit )
{
	int p_amount = this->_amount;
	this->_amount += deposit;
	_totalAmount += deposit;
	this->_nbDeposits += 1;
	_totalNbDeposits += 1;
	this->_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";p_amount:" << p_amount 
	<< ";deposit:" << deposit << ";amount:" << this->_amount 
	<< ";nb_deposits:" << _nbDeposits << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	int p_amount = this->_amount;
	this->_displayTimestamp();
	if (this->_amount >= withdrawal)
	{
		this->_amount -= withdrawal;
		_totalAmount -= withdrawal;
		this->_nbWithdrawals += 1;
		_totalNbWithdrawals += 1;
		std::cout << "index:" << this->_accountIndex << ";p_amount:" << p_amount 
		<< ";withdrawal:" << withdrawal << ";amount:" << this->_amount 
		<< ";nb_withdrawals:" << _nbWithdrawals << std::endl;
		return (true);
	}
	else
	{
		std::cout << "index:" << this->_accountIndex << ";p_amount:" << p_amount 
		<< ";withdrawal:refused" << std::endl;
		return (false);
	}
}

int		Account::checkAmount( void ) const
{
	return this->_amount;
}

void	Account::displayStatus( void ) const
{
	this->_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount
	<< ";deposits:" << this->_nbDeposits << ";withdrawals:" 
	<< this->_nbWithdrawals << std::endl;
}

void	Account::_displayTimestamp(void)
{
	time_t now;
	struct tm *timeinfo;
	char buffer [80];

	time(&now);
	timeinfo = localtime(&now);

	strftime(buffer, 80, "%Y%m%d_%H%M%S", timeinfo);

	std::cout << "[" << buffer << "] ";
}

Account::Account( void )
{
	_totalAmount = 0;
	_nbAccounts = 0;
	_totalNbDeposits = 0;
	_totalNbWithdrawals = 0;
}