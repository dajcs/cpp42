/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemet <anemet@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 22:06:05 by anemet            #+#    #+#             */
/*   Updated: 2025/10/27 23:06:18 by anemet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// Default constructor
Fixed::Fixed(void): _fixedPointValue(0)
{
	std::cout << "Default constructor called" << std::endl;
}

// New constructor: from a constant integer
// It converts the integer value in the integer part to our fixed-point format
Fixed::Fixed(const int intValue)
{
	std::cout << "Int constructor called" << std::endl;
	// The int value is shifted left by the number of fractional bits
	this->_fixedPointValue = intValue << _fractionalBits;
}

// New constructor from a constant float
// it converts the float to a fixed-point value
Fixed::Fixed(const float floatValue)
{
	std::cout << "Float constructor called" << std::endl;
	// We multiply the float by 2^_fractionalBits (which is 256)
	// This scales the number up including the floating fractions
	// roundf() is used to get the nearest integer value
	this->_fixedPointValue = roundf(floatValue * (1 << _fractionalBits));
}
// Copy constructor
Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

// Copy assignment operator
Fixed& Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->_fixedPointValue = other.getRawBits();
	}
	return *this;
}

// Destructor
Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

// toFloat: Converts the fixed-point value to a float
float Fixed::toFloat(void) const
{
	// We divide the fixed-point value by 2^_fractionalBits (256)
	// (this is the reverse from float constructor where we multiplied by 256)
	return (float)this->_fixedPointValue / (1 << _fractionalBits);
}

// toInt: Converts the fixed-point value to int
int Fixed::toInt(void) const
{
	// We right-shift the fixed-point value, which discards the fractional bits.
	// This is equivalent to an integer division by 2^_fractionalBits
	return this->_fixedPointValue >> _fractionalBits;
}

// getRawBits
int Fixed::getRawBits(void) const
{
	// No need to print messages here according to the new main's output
	return this->_fixedPointValue;
}

// setRawBits
void Fixed::setRawBits(int const raw)
{
	this->_fixedPointValue = raw;
}

// Implementation of the insertion operator (<<) overload.
// This function defines how a Fixed object should be printed to an output stream
std::ostream& operator<<(std::ostream &out, const Fixed &fixed)
{
	// We use the toFloat() member function to get the floating-point representation
	// and insert it into the output stream.
	out << fixed.toFloat();
	return out;
}
