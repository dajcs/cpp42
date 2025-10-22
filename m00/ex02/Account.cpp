/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemet <anemet@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 10:29:14 by anemet            #+#    #+#             */
/*   Updated: 2025/10/22 15:53:03 by anemet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctime>	// time functions
#include "Account.hpp"

/* Initialization of static member variables
	These belong to the class itself, not to any one object.
	They must be defined outside the class, in the .cpp file.
*/
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

/* Account::_displayTimestamp()
	This is a private static method used to display the timestamp.
	It's static because it doesn't need to access any specific account's data.
*/
void Account::_displayTimestamp(void)
{
	time_t now = time(0);
	struct tm	tstruct;
	char		buf[16];

	tstruct = *localtime(&now);
	strftime(buf, sizeof(buf), "%Y%m%d_%H%M%S", &tstruct);
	std::cout << "[" << buf << "]";
}

/* Account::Account()
	The Constructor. Called automatically when a new Account is created.
	The 'initial_deposit' is pased from tests.cpp
*/
Account::Account(int initial_deposit)
{
	// Initialize member variables for this specific account object
	// _accountIndex gets the current total number of accounts, assigning a unique ID
	this->_accountIndex = _nbAccounts;
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;

	// Update the static variables that are shared across all accounts
	_nbAccounts++;
	_totalAmount += initial_deposit;

	// Print the log message for creation, as seen in the log file.
	_displayTimestamp();
	std::cout << " index:" << this->_accountIndex
				<< ";amount:" << this->_amount
				<< ";created" << std::endl;
}

/* Account::~Account()
	The Destructor. It's called automatically when an account object
	is destroyed (e.g., when main() finishes)
*/
Account::~Account(void)
{
	// Print the log message for closing an account
	_displayTimestamp();
	std::cout << " index:" << this->_accountIndex
				<< ";amount:" << this->_amount
				<< ";closed" << std::endl;
	// Note: The static variables _nbAccounts and _totalAmount are not
	// decremented here. The log doesn't show a final summary after
	// accounts are closed, so we follow the log's behavior.
	// The program is ending, so the memory is freed anyway.
}

/* --- STATIC GETTER FUNCTIONS ---
	These functions simply return the value of the static private members.
	They are static because they relate to the class as a whole, not one account
*/
int Account::getNbAccounts(void)
{
	return _nbAccounts;
}

int Account::getTotalAmount(void)
{
	return _totalAmount;
}

int Account::getNbDeposits(void)
{
	return _totalNbDeposits;
}

int Account::getNbWithdrawals(void)
{
	return _totalNbWithdrawals;
}

/* --- STATIC DISPLAY FUNCTION ---
	Displays the summary of all accounts.
	The format is taken from the log file.
*/
void Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << " accounts:" << getNbAccounts()
				<< ";total:" << getTotalAmount()
				<< ";deposits:" << getNbDeposits()
				<< ";withdrawals:" << getNbWithdrawals()
				<< std::endl;
}

/* --- NON-STATIC (MEMBER) FUNCTIONS ---
	These functions operate on a specific instance (object) of the Account class.
	- Displays the status of a single account.
	- The 'const' at the end means this function promises not to change
	  any member variables of the object.
*/
void Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << " index:" << this->_accountIndex
				<< ";amount:" << this->_amount
				<< ";deposits:" << this->_nbDeposits
				<< ";withdrawals:" << this->_nbWithdrawals
				<< std::endl;
}

// Handles making a deposit.
void Account::makeDeposit(int deposit)
{
	// Log the "before" state and the deposit amount.
	_displayTimestamp();
	std::cout << " index:" << this->_accountIndex
				<< ";p_amount:" << this->_amount
				<< ";deposit:" << deposit;

	// Update the account's specific data
	this->_amount += deposit;
	this->_nbDeposits++;

	// Update the class-wide static data
	_totalAmount += deposit;
	_totalNbDeposits++;

	// Log the "after" state
	std::cout << ";amount:" << this->_amount
				<< ";nb_deposits:" << this->_nbDeposits
				<< std::endl;
}

// Handles making a withdrawal.
// Returns true on success, false on failure
bool Account::makeWithdrawal(int withdrawal)
{
	// Log the attempt.
	_displayTimestamp();
	std::cout << " index:" << this->_accountIndex
				<< ";p_amount:" << this->_amount
				<< ";withdrawal:";

	// Check if the withdrawal is possible
	if (this->_amount < withdrawal)
	{
		// If not enough funds, log refusal and return false
		std::cout << "refused" << std::endl;
		return false;
	}

	// If withdrawal is possible, log the amount.
	std::cout << withdrawal;

	// Update the account's specific data
	this->_amount -= withdrawal;
	this->_nbWithdrawals++;

	// Update the class-wide static data
	_totalAmount -= withdrawal;
	_totalNbWithdrawals++;

	// Log the "after" state and return true.
	std::cout << ";amount:" << this->_amount
				<< ";nb_withdrawals:" << this->_nbWithdrawals
				<< std::endl;
	return true;
}

// A simple getter for the account's amount
// 'const' because it doesn't modify anything
int Account::checkAmount(void) const
{
	return this->_amount;
}
