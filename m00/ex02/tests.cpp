// ************************************************************************** //
//                                                                            //
//                tests.cpp for GlobalBanksters United                        //
//                Created on  : Thu Nov 20 23:45:02 1989                      //
//                Last update : Wed Jan 04 09:23:52 1992                      //
//                Made by : Brad "Buddy" McLane <bm@gbu.com>                  //
//                                                                            //
// ************************************************************************** //

#include <vector>		// std::vector - a dynamic array, can hold objects too
#include <algorithm>	// std::for_each
#include <functional>	// we can turn a class member function into a function object
#include "Account.hpp"


int		main( void ) {

	// defining a collection of Account objects with std::vector dynamic array
	typedef std::vector<Account::t>							  accounts_t;
	// defining a collection of Account objects with std::vector dynamic array
	typedef std::vector<int>								  ints_t;

	// defining a "pair" - similar to a C struct with .first and .second members
	/*
		struct acc_int_s
		{
			first	accounts_t::iterator;
			second	ints_t::iterator;
		}	acc_int_t;
	*/
	typedef std::pair<accounts_t::iterator, ints_t::iterator> acc_int_t;

	int	const				amounts[]	= { 42, 54, 957, 432, 1234, 0, 754, 16576 };
	size_t const			amounts_size( sizeof(amounts) / sizeof(int) );

	/*
	accounts_t is the vector container for the Accounts
	1.) the vector is going to be created using its "range constructor"
		accounts(start address, end address) <- this is the constructor
		which will populate the [start address, end address) with account objects
		note the `start address` inclusive, `end address` exclusive
	2.) the vectors constructor walks throught the input range
												amounts -> amounts + amounts_size
		takes the int values one by one and constructs the account objects using these
	*/
	accounts_t				accounts( amounts, amounts + amounts_size );

	accounts_t::iterator	acc_begin	= accounts.begin();
	accounts_t::iterator	acc_end		= accounts.end();

	int	const			d[]			= { 5, 765, 564, 2, 87, 23, 9, 20 };
	size_t const		d_size( sizeof(d) / sizeof(int) );
	ints_t				deposits( d, d + d_size );
	ints_t::iterator	dep_begin	= deposits.begin();
	ints_t::iterator	dep_end		= deposits.end();

	int	const			w[]			= { 321, 34, 657, 4, 76, 275, 657, 7654 };
	size_t const		w_size( sizeof(w) / sizeof(int) );
	ints_t				withdrawals( w, w + w_size );
	ints_t::iterator	wit_begin	= withdrawals.begin();
	ints_t::iterator	wit_end		= withdrawals.end();

	Account::displayAccountsInfos();
	std::for_each( acc_begin, acc_end, std::mem_fun_ref( &Account::displayStatus ) );

	for ( acc_int_t it( acc_begin, dep_begin );
		  it.first != acc_end && it.second != dep_end;
		  ++(it.first), ++(it.second) ) {

		(*(it.first)).makeDeposit( *(it.second) );
	}

	Account::displayAccountsInfos();
	std::for_each( acc_begin, acc_end, std::mem_fun_ref( &Account::displayStatus ) );

	for ( acc_int_t it( acc_begin, wit_begin );
		  it.first != acc_end && it.second != wit_end;
		  ++(it.first), ++(it.second) ) {

		(*(it.first)).makeWithdrawal( *(it.second) );
	}

	Account::displayAccountsInfos();
	std::for_each( acc_begin, acc_end, std::mem_fun_ref( &Account::displayStatus ) );

	return 0;
}


// ************************************************************************** //
// vim: set ts=4 sw=4 tw=80 noexpandtab:                                      //
// -*- indent-tabs-mode:t;                                                   -*-
// -*- mode: c++-mode;                                                       -*-
// -*- fill-column: 75; comment-column: 75;                                  -*-
// ************************************************************************** //


/*

diff <(cut -d' ' -f 2- 19920104_091532.log) <(cut -d' ' -f 2- file2.txt)

Explanation of the cut approach:

	cut -d' ' -f 2-
		Uses space as delimiter (-d' ')
		and selects from field 2 to the end (-f2-)
	<(...) - Process substitution
		and treats the output as a file
	diff - Compares the two processed outputs

*/
