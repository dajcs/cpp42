/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemet <anemet@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 20:34:53 by anemet            #+#    #+#             */
/*   Updated: 2025/10/31 10:20:28 by anemet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

// --- Orthodox Canonical Form ---

// Default Constructor
/* AAnimal:
	The constructor is still implemented as it's called by derived classes
*/
AAnimal::AAnimal(): type("Generic AAnimal")
{
	std::cout << "AAnimal Default Constructor called (Abstract)" << std::endl;
}

// Copy Constructor
AAnimal::AAnimal(const AAnimal &other)
{
	std::cout << "AAnimal Copy Constructor called (Abstract)" << std::endl;
	// the new object gets a copy of the 'other' object's attributes
	*this = other;
}

// Copy Assignment Operator
AAnimal& AAnimal::operator=(const AAnimal &other)
{
	std::cout << "AAnimal Copy Assignment Operator called (Abstract)" << std::endl;
	// Check for self-assignment to avoid issues
	if (this != &other)
	{
		this->type = other.type;
	}
	return *this;
}

// Destructor
/* AAnimal:
	The destructor must also be implemented
*/
AAnimal::~AAnimal()
{
	std::cout << "AAnimal Destructor called (Abstract)\n" << std::endl;
}

// --- Member Functions ---

/* AAbstract:
	NO IMPLEMENTATION for makeSound() here.
	The '= 0' in the header means it's the responsibility of the derived classes.
*/
// void AAnimal::makeSound() const
// {
// 	std::cout << "An indistinct AAnimal sound..." << std::endl;
// }

const std::string& AAnimal::getType() const
{
	return this->type;
}
