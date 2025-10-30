/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemet <anemet@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 11:29:03 by anemet            #+#    #+#             */
/*   Updated: 2025/10/30 14:00:12 by anemet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

// --- Orthodox Canonical Form ---

Cat::Cat()
{
	this->type = "Cat";
	std::cout << "Cat Default Constructor called\n" << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other)
{
	std::cout << "Cat Copy Constructor called" << std::endl;
	*this = other;
}

Cat &Cat::operator=(const Cat &other)
{
	std::cout << "Cat Copy Assignment Operator Called" << std::endl;
	if (this != &other)
	{
		this->type = other.type;
	}
	return *this;
}

Cat::~Cat()
{
	std::cout << "Cat Destructor called" << std::endl;
}

// --- Member functions ---
// The Cat's specific implementation of makeSound()
void Cat::makeSound() const
{
	std::cout << "Meow!" << std::endl;
}
