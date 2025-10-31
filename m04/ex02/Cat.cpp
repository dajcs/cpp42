/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemet <anemet@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 11:29:03 by anemet            #+#    #+#             */
/*   Updated: 2025/10/31 10:33:54 by anemet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

// --- Orthodox Canonical Form ---

// Default Constructor
Cat::Cat()
{
	this->type = "Cat";
	this->_brain = new Brain();
	std::cout << "Cat Default Constructor called\n" << std::endl;
}

// Copy Constructor - Deep Copy
// AAnimal: update to call the AAnimal's constructor here
Cat::Cat(const Cat &other) : AAnimal(other)
{
	std::cout << "Cat Copy Constructor called" << std::endl;
	this->_brain = new Brain(*(other._brain));  // invoking Brain Copy Cohstructor
}

// Copy Assignment Operator - Deep Copy
Cat &Cat::operator=(const Cat &other)
{
	std::cout << "Cat Copy Assignment Operator Called" << std::endl;
	if (this != &other)
	{
		this->type = other.type;
		delete this->_brain;
		this->_brain = new Brain(*(other._brain));
	}
	return *this;
}

Cat::~Cat()
{
	delete this->_brain;
	std::cout << "Cat Destructor called" << std::endl;
}

// --- Member functions ---
// The Cat's specific implementation of makeSound()
void Cat::makeSound() const
{
	std::cout << "Meow!" << std::endl;
}

void Cat::setIdea(int index, const std::string& idea)
{
	if (index >=0 && index < 100)
	{
		this->_brain->ideas[index] = idea;
	}
}

const std::string& Cat::getIdea(int index) const
{
	if (index >= 0 && index < 100)
	{
		return this->_brain->ideas[index];
	}
	else
	{
		static std::string empty = "";
		return empty;
	}
}
