/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemet <anemet@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 09:43:03 by anemet            #+#    #+#             */
/*   Updated: 2025/10/28 10:56:21 by anemet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// --- Orthodox Canonical Form Constructors ---
Fixed::Fixed(void): _fixedPointValue(0) {}
Fixed::Fixed(const int intValue): _fixedPointValue(intValue << _fractionalBits) {}
Fixed::Fixed(const float floatValue): _fixedPointValue(roundf(floatValue * (1 << _fractionalBits))) {}
Fixed::Fixed(const Fixed &other) {*this = other;}
Fixed::~Fixed(void) {}

Fixed& Fixed::operator=(const Fixed &other)
{
	if (this != &other)
	{
		this->_fixedPointValue = other.getRawBits();
	}
	return *this;
}


// ---- Comparison Operators ------
// These simply compare the internal integer representations
bool Fixed::operator>(const Fixed &other) const {return this->_fixedPointValue > other.getRawBits();}
bool Fixed::operator<(const Fixed &other) const {return this->_fixedPointValue < other.getRawBits();}
bool Fixed::operator>=(const Fixed &other) const {return this->_fixedPointValue >= other.getRawBits();}
bool Fixed::operator<=(const Fixed &other) const {return this->_fixedPointValue <= other.getRawBits();}
bool Fixed::operator==(const Fixed &other) const {return this->_fixedPointValue == other.getRawBits();}
bool Fixed::operator!=(const Fixed &other) const {return this->_fixedPointValue != other.getRawBits();}


// --- Arithmetic Operators ---
// These return a *new* Fixed object with the result of the operation
Fixed Fixed::operator+(const Fixed &other) const
{
	return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed &other) const
{
	return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed &other) const
{
	return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed &other) const
{
	return Fixed(this->toFloat() / other.toFloat());
}


// --- Increment/Decrement Operators ---

// Prefix increment: increment the value, then return a reference to the modified object
Fixed& Fixed::operator++(void)
{
	this->_fixedPointValue++;
	return *this;
}

// Postfix increment: create a copy of the object, increment the original, then return the copy
// The dummy 'int' parameter distinguishes this from the prefix version
Fixed Fixed::operator++(int)
{
	Fixed temp(*this);
	this->_fixedPointValue++;
	return temp;
}

// Prefix decrement
Fixed& Fixed::operator--(void)
{
	this->_fixedPointValue--;
	return *this;
}

// Postfix decrement
Fixed Fixed::operator--(int)
{
	Fixed temp(*this);
	this->_fixedPointValue--;
	return temp;
}


// --- Static Min/Max Functions ---
// These take references to two Fixed objects and return a reference to the appropriate one

// Non-const version of min
Fixed& Fixed::min(Fixed &a, Fixed &b)
{
	return a < b ? a : b;
}

// Const version of min
const Fixed& Fixed::min(const Fixed &a, const Fixed &b)
{
	return a < b ? a : b;
}

// Non-const version of max
Fixed& Fixed::max(Fixed &a, Fixed &b)
{
	return a > b ? a : b;
}

// Const version of max
const Fixed& Fixed::max(const Fixed &a, const Fixed &b)
{
	return a > b ? a : b;
}


// ---- Member Functions ------
int Fixed::getRawBits(void) const {return this->_fixedPointValue;}
void Fixed::setRawBits(int const raw) { this->_fixedPointValue = raw;}
float Fixed::toFloat(void) const {return (float)this->_fixedPointValue / (1 << _fractionalBits);}
int Fixed::toInt(void) const {return this->_fixedPointValue << _fractionalBits;}

// ---- Stream Operator ------
std::ostream& operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return out;
}
