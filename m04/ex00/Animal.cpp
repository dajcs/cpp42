/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemet <anemet@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 20:34:53 by anemet            #+#    #+#             */
/*   Updated: 2025/10/30 14:00:26 by anemet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

// --- Orthodox Canonical Form ---

// Default Constructor
Animal::Animal(): type("Generic Animal")
{
	std::cout << "Animal Default Constructor called" << std::endl;
}

// Copy Constructor
Animal::Animal(const Animal &other)
{
	std::cout << "Animal Copy Constructor called" << std::endl;
	// the new object gets a copy of the 'other' object's attributes
	*this = other;
}

// Copy Assignment Operator
Animal& Animal::operator=(const Animal &other)
{
	std::cout << "Animal Copy Assignment Operator called" << std::endl;
	// Check for self-assignment to avoid issues
	if (this != &other)
	{
		this->type = other.type;
	}
	return *this;
}

// Destructor
Animal::~Animal()
{
	std::cout << "Animal Destructor called\n" << std::endl;
}

// --- Member Functions ---

void Animal::makeSound() const
{
	std::cout << "An indistinct animal sound..." << std::endl;
}

const std::string& Animal::getType() const
{
	return this->type;
}
