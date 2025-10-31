/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemet <anemet@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 19:02:15 by anemet            #+#    #+#             */
/*   Updated: 2025/10/30 19:10:35 by anemet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

// --- Orthodox Canonical Form ---

Brain::Brain()
{
	std::cout << "Brain Default Constructor called: A new brain is formed." << std::endl;
}

// Copy Constructor: This is crucial for deep copying
Brain::Brain(const Brain &other)
{
	std::cout << "Brain Copy Constructor called: Cloning a brain." << std::endl;
	// We call the assignment operator (to avoid duplicate code)
	*this = other;
}

// Copy Assignment Operator
Brain &Brain::operator=(const Brain &other)
{
	std::cout << "Brain Copy Assignment Operator called: Transferring thougts" << std::endl;
	if (this != &other)
	{
		// We must copy each element of the array individually.
		// If we just copied the pointer, it would be a shallow copy
		for (int i = 0; i < 100; ++i)
		{
			this->ideas[i] = other.ideas[i];
		}
	}
	return *this;
}

// Destructor
Brain::~Brain()
{
	std::cout << "Brain Destructor called: The brain fades away." << std::endl;
}
