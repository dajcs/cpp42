/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemet <anemet@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 21:59:54 by anemet            #+#    #+#             */
/*   Updated: 2025/10/24 22:07:04 by anemet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include <iostream>

// Constructor
// Initializing the weapon pointer to 0 (NULL) to signify "unarmed"
HumanB::HumanB(std::string name): _name(name), _weapon(0)
{
	return;
}

HumanB::~HumanB(void)
{
	return;
}

// setWeapon takes a reference to a weapon and stores its address in our pointer.
void HumanB::setWeapon(Weapon& weapon)
{
	this->_weapon = &weapon;
}

void HumanB::attack(void)
{
	// We should check if the pointer is not NULL before using it
	if (this->_weapon)
	{
		std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
	}
	else
	{
		std::cout << this->_name << " attacks with their bare hands" << std::endl;
	}
}
