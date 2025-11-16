/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigint.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemet <anemet@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 15:29:07 by anemet            #+#    #+#             */
/*   Updated: 2025/11/16 10:34:12 by anemet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BIGINT_HPP
# define BIGINT_HPP

#include <iostream>

// The bigint class will store an arbitrary precisioin unsigned integer
class bigint
{
	private:
		// store the number as a string in base 10
		std::string str;

	public:
		// --- Orthodox Canonical Form ---

		// Default constructor
		bigint();
		// Parametrized constructor from a number
		bigint(long long n);
		// Copy constructor
		bigint(const bigint& other);
		// Copy assignment operator
		bigint& operator=(const bigint& other);
		// Destructor
		~bigint();


		// --- Arithmetic Operators ---

		// Addition operator
		bigint operator+(const bigint& other) const;
		// Addition assignment operator
		bigint& operator+=(const bigint& other);


		// --- Increment Operators ---

		// Pre-increment operator (++a)
		bigint& operator++();
		// Post-increment operator (a++)
		bigint operator++(int);


		// --- Comparison operators ---

		bool operator==(const bigint& other) const;
		bool operator!=(const bigint& other) const;
		bool operator<(const bigint& other) const;
		bool operator<=(const bigint& other) const;
		bool operator>(const bigint& other) const;
		bool operator>=(const bigint& other) const;


		// Dig-shift operators (decimal dig-shift) ---

		bigint operator<<(const bigint& other) const;
		bigint& operator <<=(const bigint& other);
		bigint operator>>(const bigint& other) const;
		bigint& operator >>=(const bigint& other);

		// Public getter to allow access from the stream insertion operator<<
		const std::string& getString() const;

};


/*
	Overload of the stream insertion operator '<<'

	This is a non-member function that allows printing bigint objects to
	an output stream, like std::cout
*/
std::ostream& operator<<(std::ostream& os, const bigint& bi);

#endif
