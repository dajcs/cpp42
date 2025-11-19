/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigint.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemet <anemet@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 16:38:19 by anemet            #+#    #+#             */
/*   Updated: 2025/11/19 15:02:41 by anemet           ###   ########.fr       */
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

	return bigint (*this) += other; // reuse operator+=
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
		result = (char)(sum % 10) + result;
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

