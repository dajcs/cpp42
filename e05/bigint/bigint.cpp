/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigint.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemet <anemet@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 15:35:01 by anemet            #+#    #+#             */
/*   Updated: 2025/11/16 10:35:50 by anemet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bigint.hpp"
#include <sstream>	// Required for std::stringstream to convert numbers to strings

// --- Orthodox Canonical Form ---

// Default constructor
bigint::bigint() : str("0")
{
	// initializing the number string to "0"
}

// Constructor from `long long`
// we could use a parameter `int`, but long long provides wider range
// we could use `unsigned long long` but that would result in silently converting
// a negative input to a huge positive number while here we can threat the negative input
bigint::bigint(long long n)
{
	if (n <= 0)
	{
		// we could throw an exception for n < 0, but let's keep it simple here
		this->str = "0";
		return;
	}
	std::stringstream ss;
	ss << n;
	this->str = ss.str();
}

// Copy constructor
bigint::bigint(const bigint& other)
{
	this->str = other.str;  // copies the string from the other object
}

// Copy assignment operator
bigint& bigint::operator=(const bigint& other)
{
	if (this != &other)
	{
		this->str = other.str;
	}
	return *this;  // return a ref to the current object to allow chaining (a = b = c)
}

// Destructor
bigint::~bigint()
{
	// no dynamic memory has been allocated by our class
	// std::string handles its own memory, so nothing to do here
}


// --- Arithmetic Operators ---

// Addition: a + b
bigint bigint::operator+(const bigint& other) const
{
	// create a copy of the current object and use the += operator
	return bigint(*this) += other;
}

// Addition assignment: a += b
bigint& bigint::operator+=(const bigint& other)
{
	std::string s1 = this->str;
	std::string s2 = other.str;
	std::string result = "";
	int carry = 0;

	// iterating from the end of both strings
	int i = s1.length() - 1;
	int j = s2.length() - 1;

	while (i >= 0 || j >= 0 || carry)
	{
		// get digit values
		int digit1 = (i >= 0) ? s1[i--] - '0' : 0;
		int digit2 = (j >= 0) ? s2[j--] - '0' : 0;

		int sum = digit1 + digit2 + carry;
		carry = sum / 10;
		// the new digit is the remainder of the sum % 10
		// we convert it back to a character and prepend it to the result string
		result = static_cast<char>((sum % 10) + '0') + result;
	}
	this->str = result;
	return *this;
}


// --- Increment Operators ---

// Pre-increment: ++a
bigint& bigint::operator++()
{
	// use operator+= to add 1
	*this += bigint(1);
	// return the modified object
	return *this;
}

// Post-increment: a++
bigint bigint::operator++(int)
{
	// Create a temporary copy of the object's state "before" incrementing
	bigint temp(*this);
	// increment the actual object
	++(*this);
	// return the temp object with the old value
	return temp;
}


// --- Comparison Operators ---

bool bigint::operator==(const bigint& other) const
{
	return this->str == other.str;
}

bool bigint::operator!=(const bigint& other) const
{
	return this->str != other.str;
}

bool bigint::operator<(const bigint& other) const
{
	int n1 = this->str.length();
	int n2 = other.str.length();

	if(n1 != n2)
	{
		// if lengths differ, the shorter is the smaller
		return n1 < n2;
	}
	// if lengths are the same, compare them lexicographically
	return this->str < other.str;
}

bool bigint::operator<=(const bigint& other) const
{
	return (*this < other) || (*this == other);
}

bool bigint::operator>(const bigint& other) const
{
	return !(*this <= other);
}

bool bigint::operator>=(const bigint& other) const
{
	return !(*this < other);
}


// --- Digshift Operators ---

// Left digshift: a << n
bigint bigint::operator<<(const bigint& other) const
{
	bigint result(*this);
	// use the <<= operator
	result <<= other;
	return result;
}

// In-place left digshift: a <<= n
bigint& bigint::operator<<=(const bigint& other)
{
	// if str is "0", shifting does nothing
	if (this->str == "0")
	{
		return *this;
	}

	long long shift = 0;
	std::stringstream ss(other.str);
	ss >> shift;
	// Append '0' for each unit of the `shift` amount
	// this->str.insert(this->str.end(), shift, '0');   // str.insert(where, how many, what)
	for (long long i = 0; i < shift; ++i)
	{
		this->str += '0';
	}
	return *this;
}

// Right digshift: a >> n
bigint bigint::operator>>(const bigint& other) const
{
	bigint result(*this);
	// use the >>= operator
	result >>= other;
	return result;
}

// In-place Right dig-shift: a >>= n
bigint& bigint::operator>>=(const bigint& other)
{
	long long shift = 0;
	std::stringstream ss(other.str);
	ss >> shift;
	if (shift >= (long long)this->str.length())
	{
		// if shifting as many or more digits than available, the number becomes 0
		this->str = "0";
	}
	else
	{
		// Remove digits from the end of the string
		this->str.erase(this->str.length() - shift);
	}
	return *this;
}


// --- Stream Insertion Operator

// This operator function is defined outside of the bigint class,
// but it can access its private members if it were declared as `friend`
// However the `friend` is forbidden in 42, so we have 2 options:
// making `str` public, or providing a public getter.
const std::string& bigint::getString() const
{
	return this->str;
}

std::ostream& operator<<(std::ostream& os, const bigint& bi)
{
	// Send the internal representation of the bigint to the output stream
	os << bi.getString();
	return os;
}
