/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemet <anemet@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 21:37:11 by anemet            #+#    #+#             */
/*   Updated: 2025/11/01 12:16:10 by anemet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

// --- Orthodox Canonical Form ---

// default constructor
AMateria::AMateria() : _type("default") {}

// "tipized" constructor
AMateria::AMateria(std::string const & type) : _type(type) {}

// copy constructor
AMateria::AMateria(const AMateria& other)
{
	// The note "copying the type does't make sense" is tricky.
	// For a base class copy, we will copy the type. The real polymorphic
	// copy happens via clone()
	*this = other;
}

// assignment copy operator
AMateria& AMateria::operator=(const AMateria& other)
{
	if (this != &other)
	{
		this->_type = other._type;
	}
	return *this;
}

// Destructor
AMateria::~AMateria() {}


// --- Member Functions ----

std::string const & AMateria::getType() const
{
	return this->_type;
}

void AMateria::use(ICharacter& target)
{
	// Default use action can be empty or print a generic message
	// silencing the unused parameter warning.
	(void)target;
	std::cout << "* A generic materia does nothing... *" << std::endl;
}
