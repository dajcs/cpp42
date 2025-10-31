/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemet <anemet@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 20:53:48 by anemet            #+#    #+#             */
/*   Updated: 2025/10/30 20:50:32 by anemet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

// --- Orthodox Canonical Form ----

// The constructor initializes the 'type' inherited from Animal
Dog::Dog()
{
	this->type = "Dog";
	this->_brain = new Brain(); // Resource Acquisition
	std::cout << "Dog Default Constructor called\n" << std::endl;
}

// Copy constructor performs a DEEP copy
Dog::Dog(const Dog &other): Animal(other)
{
	std::cout << "Dog Copy Constructor called" << std::endl;
	// Instead of copying the pointer (shallow copy like `_brain = other._brain;`),
	// we create a NEW Brain that is a copy of the other dog's brain
	// This invokes the Brain's copy constructor
	this->_brain = new Brain(*(other._brain));

}

// Copy Assignment Operator - performing DEEP Copy
Dog &Dog::operator=(const Dog &other)
{
	std::cout << "Dog Copy Assignment Operator called" << std::endl;
	if (this != &other)
	{
		// 1. Copy the base class part
		this->type = other.type;
		// 2. Delete the old brain to prevent a memory leak
		delete this->_brain;
		// 3. Allocate a new brain and copy the content from the other brain.
		this->_brain = new Brain(*(other._brain));  // using Brain's Copy Constructor
													// in C *array refers to array[0] only
													// in C++ *(other._brain) refers to the whole _brain object
													// therefore the Brain's Copy Constructor will be invoked
	}
	return *this;
}

// Destructor - cleans up the allocated memory for the Brain
Dog::~Dog()
{
	delete this->_brain; // Resource release
	std::cout << "Dog Destructor called" << std::endl;
}


// --- Member Functions ---

// The Dog's specific implementation of makeSound()
void Dog::makeSound() const
{
	std::cout << "Woof Woof!" << std::endl;
}

// setIdea()
void Dog::setIdea(int index, const std::string& idea)
{
	if (index >= 0 && index < 100)
	{
		this->_brain->ideas[index] = idea;
	}
}

// getIdea()
const std::string& Dog::getIdea(int index) const
{
	if (index >= 0 && index < 100)
	{
		return this->_brain->ideas[index];
	}
	else
	{
		// return static empty string for invalid index to avoid errors
		static std::string empty = ""; // we need static variable because function return type is string&
										// reference, and the 'static' variable continue to exist
										// after the function returns, so we don't get a dangling reference
		return empty;
	}
}
