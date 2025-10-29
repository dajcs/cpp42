/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemet <anemet@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 09:52:52 by anemet            #+#    #+#             */
/*   Updated: 2025/10/29 13:55:04 by anemet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

// Default constructor implementation
ClapTrap::ClapTrap():
	_name("DefaultClap"),
	_hitPoints(10),
	_energyPoints(10),
	_attackDamage(0)
{
	std::cout << "Default ClapTrap has been created!" << std::endl;
}

// Parametrized constructor
// Constructor, using "initializer list" (the part after ':')
ClapTrap::ClapTrap(const std::string& name) :
	_name(name),
	_hitPoints(10),
	_energyPoints(10),
	_attackDamage(0)
{
	// The body of the constructor runs after the members are initialized
	std::cout << "ClapTrap " << this->_name << " has been created!" << std::endl;
}

// Destructor
ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << this->_name << " has been destroyed!" << std::endl;
}

// ------- member functions ------ remain the same as before in ex00 -------

// attack() function
void ClapTrap::attack(const std::string& target)
{
	//check for hit points and energy points
	if (this->_hitPoints == 0)
	{
		std::cout << "ClapTrap " << this->_name
					<< " can't attack, it has no hit points left!" << std::endl;
		return;
	}
if (this->_energyPoints == 0)
	{
		std::cout << "ClapTrap " << this->_name
					<< " can't attack, it has no energy points left!" << std::endl;
		return;
	}

	// if can attack, print message and decrement the energy points
	this->_energyPoints--;
	std::cout << "ClapTrap " << this->_name << " attacks " << target
				<< ", causing " << this->_attackDamage << " points of damage!" << std::endl;

}

// takeDamage() function
void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPoints == 0)
	{
		std::cout << "ClapTrap " << this->_name
					<< " can't take damage, it's already knocked out!" << std::endl;
		return;
	}
	// decrease hit points, but don't go below 0
	if (amount > this->_hitPoints)
		this->_hitPoints = 0;
	else
		this->_hitPoints -= amount;
	std::cout << "ClapTrap " << this->_name << " takes " << amount
				<< " points of damage! Current hit points: " << this->_hitPoints << std::endl;
}

// beRepaired() function
void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_hitPoints == 0)
	{
		std::cout << "ClapTrap " << this->_name
					<< " can't be repaired, it has no hit points left!" << std::endl;
		return;
	}
	if (this->_energyPoints == 0)
	{
		std::cout << "ClapTrap " << this->_name
					<< " can't be repaired, it has no energy points left!" << std::endl;
		return;
	}
	// repair possible, we decrement energy points and increase hit points
	this->_energyPoints--;
	this->_hitPoints+= amount;
	std::cout << "ClapTrap " << this->_name << " repairs itself, regaining " << amount
				<< " hit points! Current hit points: " << this->_hitPoints << std::endl;
}



