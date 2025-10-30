/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemet <anemet@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 20:53:48 by anemet            #+#    #+#             */
/*   Updated: 2025/10/30 13:59:58 by anemet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

// --- Orthodox Canonical Form ----

// The constructor initializes the 'type' inherited from Animal
Dog::Dog()
{
	this->type = "Dog";
	std::cout << "Dog Default Constructor called\n" << std::endl;
}

Dog::Dog(const Dog &other): Animal(other)
{
	std::cout << "Dog Copy Constructor called" << std::endl;
	*this = other;
}

Dog &Dog::operator=(const Dog &other)
{
	std::cout << "Dog Copy Assignment Operator called" << std::endl;
	if (this != &other)
	{
		this->type = other.type;
	}
	return *this;
}

Dog::~Dog()
{
	std::cout << "Dog Destructor called" << std::endl;
}

// --- Member Functions ---

// The Dog's specific implementation of makeSound()
void Dog::makeSound() const
{
	std::cout << "Woof Woof!" << std::endl;
}
