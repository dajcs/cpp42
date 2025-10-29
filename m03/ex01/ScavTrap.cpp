/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemet <anemet@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 14:12:21 by anemet            #+#    #+#             */
/*   Updated: 2025/10/29 14:27:34 by anemet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

// ScavTrap Constructor
// In the "member initializer list" first call `ClapTrap(name)`
ScavTrap::ScavTrap(const std::string& name): ClapTrap(name)
{
	// After the ClapTrap constructor has run, we set the specific values for ScavTrap
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;

	// A message to show the ScavTrap constructor is called
	std::cout << "ScavTrap " << this->_name << " has been constructed!" << std::endl;
}

// ScavTrap Destructor
ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << this->_name << " has been destroyed!" << std::endl;
}

// -------------- member functions -----------

// ScavTrap's overridden attack function
// has the same name and parameters as the base class function, but different actions
void ScavTrap::attack(const std::string& target)
{
	if (this->_hitPoints == 0)
	{
		std::cout << "ScavTrap " << this->_name << " can't attack, it's broken!" << std::endl;
		return;
	}
	if (this->_energyPoints == 0)
	{
		std::cout << "ScavTrap " << this->_name << " can't attack, it's out of energy!" << std::endl;
		return;
	}
	// if attack is allowed
	this->_energyPoints--;
	// The attack message is different - as per subject request
	std::cout << "ScavTrap " << this->_name << " fiercely attacks " << target
				<< ", causing " << this->_attackDamage << " points of damage!" << std::endl;
}

// guardGate() -- implementing the special ScavTrap ability
void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << this->_name << " is now in Gate keeper mode!" << std::endl;
}
