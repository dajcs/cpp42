/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemet <anemet@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 20:05:17 by anemet            #+#    #+#             */
/*   Updated: 2025/10/23 23:40:34 by anemet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>  // std::cout
#include "Zombie.hpp" // Zombie class definition

// Default (void) Constructor
Zombie::Zombie(void): _name("")
{
	return;
}

// Parametrized Constructor
Zombie::Zombie(std::string name): _name(name)
{
	// The constructor body is empty because the "member initializer list" did all the work.
	// We could write `this->_name = name;` inside the braces, but better to use the initializer
	return;
}

// The Destructor
Zombie::~Zombie(void)
{
	std::cout << this->_name << ": Destroyed..." << std::endl;
	return;
}

// Code for Member function `announce`
void Zombie::announce(void)
{
	std::cout << this->_name << ": Moar brainz!" << std::endl;
}
