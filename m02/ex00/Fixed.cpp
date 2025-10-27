/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemet <anemet@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 15:28:39 by anemet            #+#    #+#             */
/*   Updated: 2025/10/27 19:42:16 by anemet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// Implementation of the default constructor
// initializes the fixed-point value to 0 and prints a message as required
Fixed::Fixed(void): _fixedPointValue(0)
{
	std::cout << "Default constructor called" << std::endl;
}

// The copy constructor
// Creates a new object as a copy of 'other'
// It initializes the new object's _fixedPointvalue withthe value from 'other'
Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;
	// this->_fixedPointValue = other.getRawBits(); // is also a valid way to do.
	// Here we are going to call the copy assignment operator
	*this = other;
}

// Implementation of the copy assignment operator
// It assigns the value of 'other' to the current object
Fixed& Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	// Check to prevent self assignment (e.g., a = a)
	// good habit, but not really necessary for this simple class
	if (this != &other)
	{
		this->_fixedPointValue = other.getRawBits();
	}
	// Return a reference to the current object to allow for chained assignments
	// like a = b = c;
	return *this;
}

// Implementation of the destructor
// It is called automatically when the object is destroyed
// In this case, we don't have any resources to free (like allocated memory)
// so it just prints a message
Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

// Implementing getRawBits
// It returns the raw integer value of the fixed-point number
int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->_fixedPointValue;
}

// Implementing setRawBits
// It sets the raw integer value of the fixed-point number
void Fixed::setRawBits(int const raw)
{
	this->_fixedPointValue = raw;
}
