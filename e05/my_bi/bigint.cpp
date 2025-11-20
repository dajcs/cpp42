/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigint.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemet <anemet@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 16:38:19 by anemet            #+#    #+#             */
/*   Updated: 2025/11/20 11:47:47 by anemet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bigint.hpp"

// default constructor
bigint::bigint() : str("0")
{
	// this->str = "0";
}

// parametrized constructor
bigint::bigint(unsigned int n)
{
	std::stringstream ss;
	ss << n;
	this->str = ss.str();
}

// copy constructor
bigint::bigint(const bigint& other)
{
	*this = other;
}

// copy assignment operator
bigint& bigint::operator=(const bigint& other)
{
	if (this != &other)
	{
		this->str = other.str;
	}
	return *this;
}

// destructor
bigint::~bigint() {}


// --- public getter ---
std::string bigint::getStr() const
{
	return this->str;
}


// --- addition ---

// operator+
bigint bigint::operator+(const bigint& other) const
{
	// create new obj temp
	// bigint temp;
	// temp = *this;
	// temp += other;
	// return temp;

	return bigint(*this) += other; // reuse operator+=
}

// operator+=
bigint& bigint::operator+=(const bigint& other)
{
	std::string s1 = this->str;
	std::string s2 = other.str;
	int i = s1.length() - 1;  // s1[i] points to the last digit of s1
	int j = s2.length() - 1;  // s2[j] points to the last digit of s2
	int carry = 0;
	std::string result = "";

	while (i >= 0 || j >= 0 || carry)
	{
		int d1 = (i >= 0) ? s1[i--] - '0' : 0; // numeric value of the digit, i--
		int d2 = (j >= 0) ? s2[j--] - '0' : 0; // numeric value of the digit, j--
		int sum = d1 + d2 + carry;
		carry = sum / 10;
		result = (char)(sum % 10 + '0') + result;
	}
	this->str = result;
	return *this;
}


		//  ++ operators

// pre-increment
bigint& bigint::operator++()
{
	*this += bigint(1);
	return *this;
}

// post-increment
bigint  bigint::operator++(int)
{
	bigint temp(*this);  // create temp as a copy of current object
	++(*this);			// increment this object
	return temp;		// return the copy with the old value
}


		// --- shift with obj


// inplace right-shift
bigint& bigint::operator>>=(const bigint& other)
{
	std::stringstream ss(other.str);
	unsigned int shift = 0;
	ss >> shift;
	if (shift >= this->str.length())
	{
		// if shifting as many or more digits than available -> result "0"
		this->str = "0";
	}
	else
	{
		// erase from str[length - shift] to str end
		this->str.erase(this->str.length() - shift);
	}
	return *this;

}

// right shift, return new obj
bigint bigint::operator>>(const bigint& other) const
{
	bigint temp(*this);
	return temp >>= other;
}

// inplace left-shift
bigint& bigint::operator<<=(const bigint& other)
{
	std::stringstream ss(other.str);
	unsigned int shift = 0;
	ss >> shift;
	// append `shift` 0-s at the end of str
	this->str.append(shift, '0');
	return *this;
}

// left shift, return new obj
bigint bigint::operator<<(const bigint& other) const
{
	bigint temp(*this);
	return temp <<= other;
}


		// --- comparison operators

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
	if (this->str.length() < other.str.length())
		return true;
	if (this->str.length() > other.str.length())
		return false;
	return this->str < other.str; // return alphabetic diff
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


// --- non-member stream insertion operator<<

std::ostream& operator<<(std::ostream& output, const bigint& bi)
{
	output << bi.getStr();
	return output;
}
